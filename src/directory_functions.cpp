#include <iostream>
#include <dirent.h>
#include <string>
#include "../include/directory_functions.hpp"



#ifdef WINDOWS //possible future windows support
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Function Ripped From https://www.tutorialspoint.com/find-out-the-current-working-directory-in-c-cplusplus
//Don't reinvient the wheel.

std::string get_current_dir() {
   char buff[FILENAME_MAX]; //create string buffer to hold path
   GetCurrentDir( buff, FILENAME_MAX );
   string current_working_dir(buff);
   return current_working_dir;
}

//Funciton derived from: https://stackoverflow.com/questions/18100097/portable-way-to-check-if-directory-exists-windows-linux-c

bool dir_exist(string my_dir){
const char * open_dir = my_dir.c_str();
DIR* dir = opendir(open_dir);
if (dir)
{
    /* Directory exists. */
    cout << "Found project." << endl;
    closedir(dir);
    return true;
}
else if (ENOENT == errno)
{
    /* Directory does not exist. */
    cout << "Directory does not exist. ლ(ಠ益ಠლ)" << endl;
    return false;
}
else
{
    /* opendir() failed for some other reason. */
    cout << "Sorry, but and unexected error occured. (ノಠ益ಠ)ノ彡┻━┻ " << endl;
    return false;
}

}
