#include <iostream>
#include <dirent.h>
#include <fstream>
#include <string>
#include <vector>
#include "../include/write_functions.hpp"

typedef std::vector<std::string> stringvec;

using std::cout;
using std::cin;
using std::endl;
using std::string;


void write_basic_makefile(stringvec object_files_w_path, stringvec object_files, stringvec cpp_files, stringvec library_links, string output_file_name){
  std::ofstream MyFile("makefile");
  MyFile << "project_objects: ";
  //write first line, list of object files
  for(int i = 0; i < object_files.size(); i++){
    MyFile << object_files_w_path[i] + " ";
  }
  MyFile << endl;
  //write second line, g++ compile command
  MyFile << "\tg++ ";
  for(int i2 = 0; i2 < object_files.size(); i2++){
    MyFile << object_files_w_path[i2] + " ";
  }
  for(int i4 = 0; i4 < library_links.size(); i4++){
    MyFile << library_links[i4] + " ";
  }
  MyFile << " -o " << output_file_name << endl;
  //define each object
  for(int i3 = 0; i3 < object_files.size(); i3++){
    MyFile << object_files[i3] + ": " + cpp_files[i3] << endl;
    MyFile << "\tg++ " + cpp_files[i3] << endl;
  }
  //close file
  MyFile.close();

}
