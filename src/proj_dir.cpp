#include <iostream>
#include <dirent.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <map>
#include "../include/proj_dir.h"
#include "../include/directory_functions.hpp"
#include <boost/filesystem.hpp>


using namespace boost::system;
namespace filesys = boost::filesystem;
#ifndef USING_BOOST
#define USING_BOOST
#endif

typedef std::vector<std::string> stringvec;

using std::cout;
using std::cin;
using std::endl;
using std::string;


void Proj_dir::find_local_cpp_files(string current_dir_path)
{
    //cout << current_dir_path << endl;
    DIR* dirp = opendir(current_dir_path.c_str());
    //cout << "Find Local Files" << current_dir_path << endl; //for debug only
    struct dirent * dp;
    if(dirp == NULL){
      cout << "Fail to open folder" << endl;
    }

    while ((dp = readdir(dirp)) != NULL) {
      //cout << "In while loop" << endl; //for debug only
      string file_name(dp->d_name);
        if( file_name.find(".cpp") != std::string::npos) {
          //cout << file_name  << endl; //for debug only
          //files.push_back(dp->d_name);
          if(current_dir_path.size() == dir_path.size() ){

            files.insert(std::pair<string, string>(file_name, "./"));
          }
          else if(current_dir_path.size() > dir_path.size()){
            files.insert(std::pair<string, string>(file_name, "." + current_dir_path.substr( dir_path.size() ) ));
          }
          else {
            cout << "Error with Current Dir Path Size" << endl;
            files.insert(std::pair<string, string>(file_name, "X"));
          }

        }
    }
    closedir(dirp);
}



void Proj_dir::find_local_sub_directories(string current_dir_path){
  DIR* dirp = opendir(current_dir_path.c_str());
  struct dirent * dp;
  //cout << "Find Local Directories" << endl; //for debug only
  while ((dp = readdir(dirp)) != NULL) {

      DIR* dirp2 = NULL;
      std::string full_path = dir_path + "/" + dp->d_name;
      const char * sub_d = full_path.c_str();
      dirp2 = opendir(sub_d);
      std::string dir_name(dp->d_name);

      if( (dirp2 != NULL) &&  (dir_name.find(".") == std::string::npos ) ) {
        //cout << dir_name << endl; //for debug only
        sub_dirs.push_back(dir_path + "/" + dp->d_name);
       closedir(dirp2);

     }
  }
  closedir(dirp);
}

//To get all nested dirs and files I used boost based on the following Links
//https://thispointer.com/c-get-the-list-of-all-files-in-a-given-directory-and-its-sub-directories-using-boost-c17/
void Proj_dir::find_sub_dirs_find_files(){
  find_local_cpp_files(dir_path);
  find_local_sub_directories(dir_path);
  // Create a Recursive Directory Iterator object and points to the starting of directory
  filesys::recursive_directory_iterator iter(dir_path);
  // Create a Recursive Directory Iterator object pointing to end.
  filesys::recursive_directory_iterator end;
  // Iterate till end
  while (iter != end)
  {
    //get local dirs and files
    if(filesys::is_directory(iter->path().string() ) ){
    find_local_cpp_files(iter->path().string());
    find_local_sub_directories(iter->path().string());
  }
    //cout << iter->path().string() << endl;
      error_code ec;
      // Increment the iterator to point to next entry in recursive iteration
      iter.increment(ec);
      if (ec) {
          std::cerr << "Error While Accessing : " << iter->path().string() << " :: " << ec.message() << '\n';
      }
  }

}

void Proj_dir::print_dir_path(){
  cout << "***Directory Path***" << endl;
  cout << "*" << dir_path << endl;
}

void Proj_dir::print_cpp_files(){
  cout << "***Cpp Files***" << endl;
  std::map<string, string>::iterator itr;
  for (itr = files.begin(); itr != files.end(); ++itr) {
        cout  << "*" << itr->first << " Directory: " << itr->second << endl;
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
  find_sub_dirs_find_files();
  //find_cpp_files();
  //find_sub_directories();
}
//destructor
Proj_dir::~Proj_dir(){
//wrap up hear.
}
