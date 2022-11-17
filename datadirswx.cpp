#include <wx/stdpaths.h>
#include <wx/init.h>
#include <wx/utils.h>
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
    sp.SetFileLayout(wxStandardPaths::FileLayout_XDG);

    wxString home = ::wxGetHomeDir();
    std::printf("%20s: %s\n", "home", (const char *)home.c_str());

    wxString homeuser = ::wxGetUserHome(::wxGetUserId());
    std::printf("%20s: %s\n", "user-home", (const char *)homeuser.c_str());

    wxString conf = sp.GetUserConfigDir();
    std::printf("%20s: %s\n", "config", (const char *)conf.c_str());

    wxString cache = sp.GetUserDir(wxStandardPaths::Dir_Cache);
    std::printf("%20s: %s\n", "cache", (const char *)cache.c_str());

    wxString docs = sp.GetAppDocumentsDir();
    std::printf("%20s: %s\n", "documents", (const char *)docs.c_str());
    


    return 0;
}
