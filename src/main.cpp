//Make File Generator main.cpp

#include <iostream>
#include <string>
#include "../include/directory_functions.hpp"
#include "../include/proj_dir.h"



using std::cout;
using std::cin;
using std::endl;
using std::string;




int main(void){
string dir_check;
string project_dir;
bool got_dir = false;
cout << "Current Directory = " << get_current_dir() << endl;
cout << "Is this your project directory: Y/N" << endl;
cin >> dir_check;
//GET Project Directory
while (!got_dir){
  if(dir_check == "yes" || dir_check == "Yes" || dir_check == "yes" || dir_check == "Yes" || dir_check == "YES" || dir_check == "y" || dir_check == "Y"){
    project_dir = get_current_dir();
    cout << "Okay, lets find your project files." << endl;
    got_dir = true;

  }
  else if(dir_check == "no" || dir_check == "No" || dir_check == "NO" || dir_check == "n" || dir_check == "N"){

    cout << "Please provide the project directory path: ";
    cin >>  project_dir;
    got_dir = dir_exist(project_dir);


  }
  else{
    cout << "Is " << get_current_dir() << " your project directory? Please type \"yes\" or \"no\".  " << endl;
    cin >> dir_check;
  }




}

//Find All Cpp files in project dir
Proj_dir base_dir(project_dir); //create dir object

base_dir.print_cpp_files();
base_dir.print_sub_directories();



}
