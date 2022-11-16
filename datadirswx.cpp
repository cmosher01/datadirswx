#include <wx/stdpaths.h>
#include <wx/init.h>
#include <wx/utils.h>
#include <wx/string.h>
#include <wx/wxcrt.h>
#include <cstdio>

int main(int argc, char **argv)
{
    wxInitializer initializer(argc, argv);
    if (!initializer)
    {
        std::fprintf(stderr, "Failed to initialize the wxWidgets library, aborting.\n");
        return 1;
    }



    wxStandardPaths sp = wxStandardPaths::Get();

    sp.UseAppInfo(wxStandardPaths::AppInfo_VendorName | wxStandardPaths::AppInfo_AppName);



    wxString home = ::wxGetHomeDir();
    wxPrintf("%20s: %s\n", "home", home);

    wxString homeuser = ::wxGetUserHome(::wxGetUserId());
    wxPrintf("%20s: %s\n", "user-home", homeuser);

    wxString conf = sp.GetUserConfigDir();
    wxPrintf("%20s: %s\n", "config", conf);

    wxString cache = sp.GetUserLocalDataDir();
    wxPrintf("%20s: %s\n", "cache", cache);

    wxString docs = sp.GetAppDocumentsDir();
    wxPrintf("%20s: %s\n", "documents", docs);
    


    return 0;
}
