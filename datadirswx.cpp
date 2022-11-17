#include <wx/stdpaths.h>
#include <wx/init.h>
#include <wx/utils.h>
//#ifdef __WINDOWS__
//#include <wx/msw/stdpaths.h>
//#include <initguid.h>
//#endif
#include <cstdio>

//#ifdef __WINDOWS__
//DEFINE_GUID(wxFOLDERID_Downloads,
//    0x374de290, 0x123f, 0x4565, 0x91, 0x64, 0x39, 0xc4, 0x92, 0x5e, 0x46, 0x7b);
//DEFINE_GUID(FOLDERID_RoamingAppData,
//    0x3EB685DB, 0x65F9, 0x4CF6, 0xA0, 0x3A, 0xE3, 0xEF, 0x65, 0x72, 0x9F, 0x3D);
//#endif


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

//#ifdef __WINDOWS__
//    wxString appdata = sp.DoGetKnownFolder(FOLDERID_RoamingAppData);
//    std::printf("%20s: %s\n", "appdata", (const char *)appdata.c_str());
//#endif


    return 0;
}
