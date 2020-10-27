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
  //Define complier variable
  MyFile << "CC = g++ " << endl;
  //Define links variable
    MyFile << "LINKS = ";
  for(int i4 = 0; i4 < library_links.size(); i4++){
    MyFile << library_links[i4] + " ";
  }
  MyFile << endl;
  //Define file objects variable
  MyFile << "OBJECTS = ";
  for(int i = 0; i < object_files.size(); i++){
    MyFile << object_files_w_path[i] + " ";
  }
  MyFile << endl;
  //Define outputfile
  MyFile << "OUTPUT = bin/" + output_file_name << endl;

  MyFile << endl;
  MyFile << endl;

  MyFile << "main: $(OBJECTS)" << endl;
  MyFile << "\t$(CC) $(OBJECTS) $(LINKS) -o $(OUTPUT)" << endl;


  //define each object
  for(int i3 = 0; i3 < object_files.size(); i3++){
    MyFile << object_files[i3] + ": " + cpp_files[i3] << endl;
    MyFile << "\tg++ " + cpp_files[i3] << endl;
  }

  MyFile << ".PHONY : clean" << endl;
  MyFile << "clean :" << endl;
  MyFile << "\t-rm -f $(OBJECTS)";

  //close file
  MyFile.close();

}
