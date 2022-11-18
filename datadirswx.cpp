#include <wx/stdpaths.h>
#include <wx/init.h>
#include <wx/app.h>
#include <wx/utils.h>
#ifdef __WXMSW__
#include <wx/msw/wrapwin.h>
#endif
#include <cstdio>



int main(int argc, char **argv)
{
    wxInitializer initializer(argc, argv);
    if (!initializer)
    {
        std::fprintf(stderr, "Failed to initialize the wxWidgets library, aborting.\n");
        return 1;
    }



    wxApp::GetInstance()->SetVendorName("nu.mine.mosher");
    wxApp::GetInstance()->SetAppName("datadirswx");



    wxStandardPaths sp = wxStandardPaths::Get();

    sp.UseAppInfo(wxStandardPaths::AppInfo_VendorName | wxStandardPaths::AppInfo_AppName);
    sp.SetFileLayout(wxStandardPaths::FileLayout_XDG);



    wxString exe = sp.GetExecutablePath();
    std::printf("%20s: %s\n", "exe", (const char *)exe.c_str());



    wxString home = ::wxGetHomeDir();
    std::printf("%20s: %s\n", "home", (const char *)home.c_str());

    wxString homeuser = ::wxGetUserHome(::wxGetUserId());
    std::printf("%20s: %s\n", "user-home", (const char *)homeuser.c_str());



    wxString conf = sp.GetUserConfigDir();
    std::printf("%20s: %s\n", "config", (const char *)conf.c_str());

#ifdef __WXMSW__
    wxString appdata = sp.MSWGetShellDir(CSIDL_APPDATA);
    std::printf("%20s: %s\n", "appdata", (const char *)appdata.c_str());
#endif

    wxString conffile = sp.MakeConfigFileName("test");
    std::printf("%20s: %s\n", "configfile", (const char *)conffile.c_str());



    wxString cache = sp.GetUserDir(wxStandardPaths::Dir_Cache);
    std::printf("%20s: %s\n", "cache", (const char *)cache.c_str());



    wxString docsroot = sp.GetDocumentsDir();
    std::printf("%20s: %s\n", "documents root", (const char *)docsroot.c_str());

    wxString userdocs = sp.GetUserDir(wxStandardPaths::Dir_Documents);
    std::printf("%20s: %s\n", "userdocs", (const char *)userdocs.c_str());

    wxString docs = sp.GetAppDocumentsDir();
    std::printf("%20s: %s\n", "documents", (const char *)docs.c_str());



    return 0;
}
