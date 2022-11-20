#include <wx/fileconf.h>
#include <wx/stdpaths.h>
#include <wx/init.h>
#include <wx/app.h>
#include <wx/utils.h>

#include <filesystem>
#include <iostream>
#include <cstdio>



int main(int argc, char **argv)
{
    wxInitializer initializer(argc, argv);
    if (!initializer)
    {
        std::fprintf(stderr, "Failed to initialize the wxWidgets library, aborting.\n");
        return 1;
    }



    const std::filesystem::path idApp("nu.mine.mosher.path.to.app");

    wxStandardPaths sp = wxStandardPaths::Get();
    sp.UseAppInfo(wxStandardPaths::AppInfo_VendorName | wxStandardPaths::AppInfo_AppName);
    sp.SetFileLayout(wxStandardPaths::FileLayout_XDG);

    const std::filesystem::path exe = std::filesystem::path(sp.GetExecutablePath().t_str());
    std::cout << exe << std::endl;

    const std::filesystem::path conf = std::filesystem::path(sp.GetUserConfigDir().t_str()) / idApp;
    std::cout << conf << std::endl;

    const std::filesystem::path cache = std::filesystem::path(sp.GetUserDir(wxStandardPaths::Dir_Cache).t_str()) / idApp;
    std::cout << cache << std::endl;

    const std::filesystem::path docs = std::filesystem::path(sp.GetAppDocumentsDir().t_str()) / idApp;
    std::cout << docs << std::endl;



    return 0;
}
