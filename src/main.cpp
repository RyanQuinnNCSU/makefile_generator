//Make File Generator main.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "../include/directory_functions.hpp"
#include "../include/proj_dir.h"
#include "../include/write_functions.hpp"

typedef std::vector<std::string> stringvec;

using std::cout;
using std::cin;
using std::endl;
using std::string;




int main(void){
stringvec object_files;
stringvec object_files_w_path;
stringvec cpp_files;
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

//Create list of all Project Files All Cpp files in project dir
cout << "Searching for CPP files in your project." << endl << endl;
Proj_dir base_dir(project_dir); //create dir object

cout << "**********************" << endl;
cout << "**********************" << endl;
cout << "***Find Cpp Files" << endl;
cout << "**********************" << endl;
cout << "**********************" << endl;

base_dir.print_cpp_files();
//base_dir.print_sub_directories();

//Request User to specify any files they don't want included in the make file.
bool done_removing_files = false;

cout << endl << "Above is a list of all the CPP files found in the project directory." << endl << "If you don't want some of these files to be part of the makefile please type out the file names (press ENTER after each file name)." << endl;
cout << "If there is a directory in which you want all all the files to be ignored, please provide the path to that directory. Ex: typing \"./test\" will prevent all files from the \"test\" project sub-directory from being compiled." << endl;
cout << "Type \'LIST\' to see your changes to the files list." << endl;
cout << "After you have typed out all your files you want ignored or if you don't want to ignore any files type \'DONE\'." << endl;

while (!done_removing_files){
  string remove_file;
  cin >> remove_file;
  if(remove_file == "LIST"){
	 base_dir.print_cpp_files();
  }
  else if(remove_file != "DONE"){
	if(remove_file.at(0) != '.'){
    	base_dir.remove_file_from_list(remove_file);
	}
	else{
		base_dir.remove_dir_files_from_list(remove_file);
	}
  }
  else{
    done_removing_files = true;
  }
}
base_dir.print_cpp_files();

//Link Libraries.
cout << "**********************" << endl;
cout << "**********************" << endl;
cout << "***Library Links" << endl;
cout << "**********************" << endl;
cout << "**********************" << endl;
bool library_links_given = false;
stringvec library_links;
cout << "Please provide any library links (paths) for libraries not part of the standard libary." << endl;
cout << "Type one library link then press ENTER befor typing the next. Type \'DONE\' if you require no links or have added all your links." << endl;
cout << "Type \'LIST\' to see the your changes to the link list." << endl;
cout << "If a mistake is made, type \'REMOVE\' to clear the last link provided from the list." << endl;
while (!library_links_given){
  string link_name;
  cin >> link_name;
  if(link_name.size() == 0){
    cout << "Please provide a library link or type DONE if your not using libraries outside of the stardard." << endl;
    }
  else if(link_name == "DONE") {

    library_links_given = true;
  }
  else if(link_name == "REMOVE") {
	if(library_links.size() > 0){
		cout << "Removing last entry in list of links" << endl;
	    library_links.pop_back();
	}
	else{
	 cout << "No links to remove." << endl;
	}
  }
  else if(link_name == "LIST"){
	  cout << "***Library Links***" << endl;
	  if(library_links.size() == 0){
		cout << "*Empty" << endl;
	  }
	  else{
		  for(stringvec::iterator link_it = library_links.begin(); link_it != library_links.end(); link_it++){
			  	cout << *link_it << endl;
			  }
	  }
  }
  else{
    cout << "Adding " + link_name + " to list of links" << endl;
    library_links.push_back(link_name);
  }
}

//Flags.
cout << "**********************" << endl;
cout << "**********************" << endl;
cout << "***Compile Flags" << endl;
cout << "**********************" << endl;
cout << "**********************" << endl;
bool flags_given = false;
stringvec flags;
cout << "Please provide any compilation flags you want to include int final g++ command the make file will execute." << endl;
cout << "Type one compilation flag then press ENTER befor typing the next. Type \'DONE\' if you require no flags or have added all your flags." << endl;
cout << "Type \'LIST\' to see your changes to the flags list." << endl;
cout << "If a mistake is made, type \'REMOVE\' to clear the last flag provided from the list." << endl;
while (!flags_given){
  string flag_name;
  cin >> flag_name;
  if(flag_name.size() == 0){
    cout << "Please provide a compile flag or type DONE if your not using any flags for the g++ command." << endl;
    }
  else if(flag_name == "DONE") {

    flags_given = true;
  }
  else if(flag_name == "REMOVE") {
	  if(flags.size() > 0){
		  cout << "Removing last entry to list of flags" << endl;
  	    flags.pop_back();
  	}
  	else{
  	 cout << "No flags to remove." << endl;
  	}
  }
  else if(flag_name == "LIST"){
	  cout << "***g++ flags***" << endl;
	  if(flags.size() == 0){
		cout << "*Empty" << endl;
	  }
	  else{
		  for(stringvec::iterator flag_it = flags.begin(); flag_it != flags.end(); flag_it++){
			  	cout << *flag_it << endl;
			  }
	  }
  }
  else{
    cout << "Adding " + flag_name + " to list of flags" << endl;
    flags.push_back(flag_name);
  }
}

//name output file
cout << "**********************" << endl;
cout << "**********************" << endl;
cout << "***Name Output File" << endl;
cout << "**********************" << endl;
cout << "**********************" << endl;

bool output_file_name_given = false;
string output_file_name;
cout << "What would you link your output file (the executable) to be called? Please provide the name below." << endl;
while (!output_file_name_given){
  cin >> output_file_name;
  if( output_file_name.length() == 0){
    cout << "Please provide an output file name." << endl;
    }
  else{
    output_file_name_given = true;
  }
}

cout << "Now generating makefile. Output files generated by this file will be built in the /bin directory." << endl;
cout << "If a ./bin directory doesn't exist, one will be created for you." << endl;

//check to see if bin folder exist. If not make one.
make_bin();
//generate makefile
//std::ofstream MyFile("makefile");
//MyFile << "project_objects: ";

cout << "Preparing Object Files" << endl;
//for loop though map to create cpp object files

for (std::map<string, string>::iterator itr = base_dir.init_iterator(0); itr != base_dir.init_iterator(1); itr++) {
     string file_string = base_dir.parse_file_map(itr, 0);
     string dir_string = base_dir.parse_file_map(itr, 1);
     cpp_files.push_back(file_string);
     int end_of_filename = file_string.find(".");
     string object_name = file_string.substr(0,end_of_filename);
     //set up path to object
     string object_path;
     if(dir_string != "./"){
     object_path = dir_string.substr(2);
    }
    else{
      object_path = "";
    }
    object_files_w_path.push_back(object_path + "/" + object_name + ".o");
    object_files.push_back(object_name + ".o");
    cout << object_path + "/" + object_name + ".o" << endl;
  }

//writing makefile.
write_basic_makefile(project_dir, object_files_w_path, object_files, cpp_files, library_links, flags, output_file_name);
cout << "**********************" << endl;
cout << "**********************" << endl;
cout << "***End of Program" << endl;
cout << "**********************" << endl;
cout << "**********************" << endl;
cout << "A makefile has been creating in the project directory." << endl;
cout << "Type \'make\' to build your Cpp project." << endl;

//MyFile.close();
//end of main
}
