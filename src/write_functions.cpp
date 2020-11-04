#include <iostream>
#include <dirent.h>
#include <fstream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include "../include/write_functions.hpp"

typedef std::vector<std::string> stringvec;

using std::cout;
using std::cin;
using std::endl;
using std::string;

int make_bin(string project_dir){
	string bin_path = project_dir + "/bin";
	DIR* bin = opendir(bin_path.c_str());
	//see if bin exist
	if (bin)
	{
	    /* Directory exists. */
	    closedir(bin);
	}
	else if (ENOENT == errno)
	{
	    /* Directory does not exist. */
		if (mkdir(bin_path.c_str(), 0777) == -1){
        	cout << "Failed to make \"bin\" directory." << endl;
			return 1;
		}
    	else
		{
        	cout << "A \"bin\" directory has been created." << endl;
		}

	}
	else
	{
		cout << "Error while check if ./bin exist." << endl;
		return 1;
	    /* opendir() failed for some other reason. */
	}
	return 0;
}

void write_basic_makefile(string project_dir, stringvec object_files_w_path, stringvec object_files, stringvec cpp_files, stringvec library_links, stringvec flags, string output_file_name){
  string makefile_path = project_dir + "/makefile";
  std::ofstream MyFile(makefile_path);
  //Define complier variable
  MyFile << "CC = g++ " << endl;
  //Define links variable
  MyFile << "LINKS = ";
  for(int i4 = 0; i4 < library_links.size(); i4++){
    MyFile << library_links[i4] + " ";
  }
  MyFile << endl;
  //Define flag variable
  MyFile << "FLAGS = ";
  for(int i5 = 0; i5 < flags.size(); i5++){
    MyFile << flags[i5] + " ";
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
  MyFile << "\t$(CC) $(OBJECTS) $(FLAGS) $(LINKS) -o $(OUTPUT)" << endl;


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
