#include <iostream>
#include <dirent.h>
#include <string>
#include <vector>
#include "../include/proj_dir.h"
#include "../include/directory_functions.hpp"


typedef std::vector<std::string> stringvec;

using std::cout;
using std::cin;
using std::endl;
using std::string;


void Proj_dir::find_cpp_files()
{
    DIR* dirp = opendir(dir_path.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {

      string file_name(dp->d_name);
        if( file_name.find(".cpp") != std::string::npos) {
          files.push_back(dp->d_name);
        }
    }
    closedir(dirp);
}



void Proj_dir::find_sub_directories(){
  DIR* dirp = opendir(dir_path.c_str());
  struct dirent * dp;
  while ((dp = readdir(dirp)) != NULL) {

      DIR* dirp2 = NULL;
      std::string full_path = dir_path + "/" + dp->d_name;
      const char * sub_d = full_path.c_str();
      dirp2 = opendir(sub_d);
      std::string dir_name(dp->d_name);

      if( (dirp2 != NULL) &&  (dir_name.find(".") == std::string::npos ) ) {
        sub_dirs.push_back(dir_path + "/" + dp->d_name);
       closedir(dirp2);

     }
  }
  closedir(dirp);
}



void Proj_dir::print_dir_path(){
  cout << "***Directory Path***" << endl;
  cout << "*" << dir_path << endl;
}

void Proj_dir::print_cpp_files(){
  cout << "***Cpp Files***" << endl;
  for(int x = 0; x < files.size(); x++){
    std::cout << "*" << files[x] << endl;
  }
}

void Proj_dir::print_sub_directories(){
  cout << "***Sub Directories***" << endl;
  for(int x = 0; x < sub_dirs.size(); x++){
    std::cout << "*" << sub_dirs[x] << endl;
  }
}

int Proj_dir::get_sub_dir_count(){
  return sub_dirs.size();
}

int Proj_dir::get_cpp_file_count(){
  return files.size();
}

stringvec Proj_dir::get_sub_dirs_vector(){
  //cout << "Address Check " << &sub_dirs[0] << endl;
  return sub_dirs;
}

//constructors
Proj_dir::Proj_dir(){//defualt constructor
  cout << "Add parameters" << endl;
}

Proj_dir::Proj_dir(string my_dir_path){
  dir_path = my_dir_path;
  find_cpp_files();
  find_sub_directories();
}
//destructor
Proj_dir::~Proj_dir(){
//wrap up hear.
}
