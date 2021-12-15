#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

void ReadPathsFromINI();
void PrintFile(const fs::directory_entry& entry);
void CopySaveFiles(const fs::path& from, fs::path& to);

int main()
{
    string fromPath = "C:/Users/allen/AppData/Roaming/Citra/sdmc/Nintendo 3DS/00000000000000000000000000000000/00000000000000000000000000000000/title/00040000/000a0500/data/00000001";
    string toPath = "FE_SaveFiles/";
    fs::path from(fromPath);

    if (!fs::is_empty(fs::path(toPath)))


    for (const fs::directory_entry& entry : fs::directory_iterator(from))
    {
        PrintFile(entry);
        fs::path to((toPath + entry.path().filename().string()));
        fs::copy_file(entry.path(), to);
    }
}

void ReadPathsFromINI()
{

}

void PrintFile(const fs::directory_entry& entry)
{
    fs::path file(entry.path());
    cout << "Exists: " << fs::exists(file) << endl;
    cout << "Relative Path: " << file.relative_path() << endl;
    cout << "Parent Path: " << file.parent_path() << endl;
    cout << "File Name: " << file.filename() << endl;
    cout << "Stem: " << file.stem() << endl;
    cout << "Extension: " << file.extension() << endl;
    // cout << "Last Write Time: " << entry.last_write_time().time_since_epoch().count() << endl;
    cout << endl;
}