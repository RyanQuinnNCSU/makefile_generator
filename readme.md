# makefile_generator
> An opensource makefile generator for C++ projects Linux.

## Table of Contents
1. Project Summary
2. Makefile Generator Release v1.0 Notes
3. Setup Requirements
4. Running the Makefile Generator
5. Break Down of the Code
6. Future Releases
7. Wrap Up
8. Contact info

## 1. Project Summary
The makefile_generator project is designed to be an easy way to create a makefile for C++ projects. This program finds all the C++ files in your project and writes a makefile so they can be compile them. This can be a big time saver if you have lots of projects or have large project with lots of files. Currently this project runs on Linux.

## 2. Makefile Generator Release v1.0 Notes
* Given project directory, program will find all C++ files in all the nested sub directories an list them for compiling.
* After all C++ files are found, user is given prompt to remove directories or files from the compile list.
* After all the files, links, and flags have been determined a makefile will be generated to compile the project.

## 3. Setup Requirements
To execute the pre-compiled version you just need to have a Linux PC. This was compiled and validated on Ubuntu 20.04. Just make sure the file is given executable permissions.

To compile the code yourself you will need to have the standard C++ libraries and boost installed on your PC. To compile with a Linux terminal use either the included makefile, or run ```g++ src/main.cpp src/proj_dir.cpp src/directory_functions.cpp src/write_functions.cpp -lboost_filesystem -o bin/makefile_gen.out```

## 4. Running the Makefile Generator
Whether you run the provide executable you or compile the code yourself, this section will walk through examples of using the code.

### Starting the Program
Open a Linux terminal. Clone this project with ```git clone ```. Once the project repo is on your PC, run  ```cd <your C++ project directory path>```. With the project directory open in the terminal you can now execute the program by running ```./<path to makefile_gen project>/bin/makefile_gen.out ```. For this example I am going to change directory to my makefile_gen project and start the program from there.

```
lab-pc@labpc-ThinkPad-T540p:~/Documents/Cpp_Development/makefile_generator$ ./bin/make_file_gen.out
```

### Set Project Directory:
The first thing the program does is ask if the current directory (from where you ran the execute command) is the project directory the makefile is for.
Type yes "Y/y" or no "N/n".

```
Current Directory = /home/lab-pc/Documents/Cpp_Development/makefile_generator
Is this your project directory: Y/N
y
```
 or

```
Current Directory = /home/lab-pc/Documents/Cpp_Development/makefile_generator
Is this your project directory: Y/N
n
```

if you typed "Y" for yes, then move on to the next section.

If the current directory is not the directory of your C++ project you will need to provide the full directory path. For example, if I want to generate a makefile for TestChain, an opensource blockchain C++ project made by Dave Nash (clone his repo at https://github.com/teaandcode/TestChain), but I am running the program from my makefile_generator directory I need to provide the full file path to the TestChain project.

```
lab-pc@labpc-ThinkPad-T540p:~/Documents/Cpp_Development/makefile_generator$ ./bin/makefile_gen.out
Current Directory = /home/lab-pc/Documents/Cpp_Development/makefile_generator
Is this your project directory: Y/N
N
Please provide the project directory path: /home/lab-pc/Documents/Cpp_Examples/TestChain
Found project.
```

### Select Files to Compile
After the project directory has been established, the program will list all the C++ files it could find in all the nested folders of the project. Below is an example list from the makefile_generator project. You may notice there are extra folders and files here, they have been added for demo purposes.
```
**********************
**********************
***Find Cpp Files
**********************
**********************
***Cpp Files***
*can_u_see_me.cpp In Directory: ./
*directory_functions.cpp In Directory: ./src
*list_files.cpp In Directory: ./test
*main.cpp In Directory: ./src
*main_test.cpp In Directory: ./test
*proj_dir.cpp In Directory: ./src
*secret.cpp In Directory: ./test/nest_test
*write_functions.cpp In Directory: ./src
```
The user is prompted to type files or directories they want removed from the list of files to compile. To remove move a file just type the file name. To remove a whole directory just type the relative directory path. To see your changes to the file list, just type "LIST". After you have remove any files you don't want to compile from the file list, type "DONE". Below is an example of removing files by name releative directory path and by providing the file name.

```
Above is a list of all the CPP files found in the project directory.
If you don't want some of these files to be part of the makefile please type out the file names (press ENTER after each file name).
If there is a directory in which you want all all the files to be ignored, please provide the path to that directory. Ex: typing "./test" will prevent all files from the "test" project sub-directory from being compiled.
Type 'LIST' to see your changes to the files list.
After you have typed out all your files you want ignored or if you don't want to ignore any files type 'DONE'.
./test
Removed file 'list_files.cpp' from compile list.
Removed file 'main_test.cpp' from compile list.
./
Removed file 'can_u_see_me.cpp' from compile list.
secret.cpp
Removed file 'secret.cpp' from compile list.
LIST
***Cpp Files***
*directory_functions.cpp In Directory: ./src
*main.cpp In Directory: ./src
*proj_dir.cpp In Directory: ./src
*write_functions.cpp In Directory: ./src
DONE
```

### Add Library Links
In you C++ project, if you use libraries that are not part of the standard C++ library you will likely need to add a link so the compiler knows where to find your library.

The makefile_generator project uses the boost library to iterate and find C++ files. Boost was installed separately from the reset of the C++ libraries so in order to compile my project I need to include the link "-lboost_filesystem" in the makefile. To add a link simple type out the link and hit Enter.

If you want to see what links you have added type "LIST". Type "REMOVE" to delete the last entry in the list of links (encase you make a mistake). After all your links have been added type "DONE".

See below for an example:

```
**********************
**********************
***Library Links
**********************
**********************
Please provide any library links (paths) for libraries not part of the standard libary.
Type one library link then press ENTER befor typing the next. Type 'DONE' if you require no links or have added all your links.
Type 'LIST' to see the your changes to the link list.
If a mistake is made, type 'REMOVE' to clear the last link provided from the list.
-lboost_filesystem
Adding -lboost_filesystem to list of links
-fake_link
Adding -fake_link to list of links
REMOVE
Removing last entry in list of links
LIST
***Library Links***
-lboost_filesystem
DONE
```



### Add G++ Compile Flags
You may need to added flags to correctly run g++ when compiling.

If you want to see what Flags you have added type "LIST". Type "REMOVE" to delete the last entry in the list of flags (encase you make a mistake). After all your flags have been added type "DONE".

The makefile_generator and the TestChain projects don't need any special g++ flags to compile, but below is an example of adding and removing flags for the makefile.

```
**********************
**********************
***Compile Flags
**********************
**********************
Please provide any compilation flags you want to include int final g++ command the make file will execute.
Type one compilation flag then press ENTER befor typing the next. Type 'DONE' if you require no flags or have added all your flags.
Type 'LIST' to see your changes to the flags list.
If a mistake is made, type 'REMOVE' to clear the last flag provided from the list.
-fake_flag
Adding -fake_flag to list of flags
LIST
***g++ flags***
-fake_flag
REMOVE
Removing last entry to list of flags
LIST
***g++ flags***
*Empty
DONE
```

### Choose Output File Name
The final input required from the user is what they want there compiled file to be called. The makefile will set this file to be stored in the project "bin" folder. If the project does not have a "bin" folder, one will be created. See below for an example of setting the output file name.

```
**********************
**********************
***Name Output File
**********************
**********************
What would you link your output file (the executable) to be called? Please provide the name below.
makefile_gen.out
```
### Generating the Makefile
After the output file name has been provided the makefile will be generated. See below for an example of console output while generating the makefile.

```
Now generating makefile. Output files generated by this file will be built in the /bin directory.
If a ./bin directory doesn't exist, one will be created for you.
Preparing Object Files
src/directory_functions.o
src/main.o
src/proj_dir.o
src/write_functions.o
**********************
**********************
***End of Program
**********************
**********************
A makefile has been creating in the project directory.
Type 'make' to build your Cpp project.
```

### Makefile Examples

Below are example makefiles generated by this program. The first example is the makefile for the makefile_generator project. The second is the makefile for the TestChain project referenced earlier.

#### Makefile for makefile_generator Project
```
CC = g++
LINKS = -lboost_filesystem
FLAGS =
OBJECTS = src/directory_functions.o src/main.o src/proj_dir.o src/write_functions.o
OUTPUT = bin/makefile_gen.out


main: $(OBJECTS)
	$(CC) $(OBJECTS) $(FLAGS) $(LINKS) -o $(OUTPUT)
directory_functions.o:
	g++ -c directory_functions.cpp
main.o:
	g++ -c main.cpp
proj_dir.o:
	g++ -c proj_dir.cpp
write_functions.o:
	g++ -c write_functions.cpp
.PHONY : clean
clean :
	-rm -f $(OBJECTS) $(OUTPUT)
```
#### Makefile for TestChain Project

```
CC = g++
LINKS =
FLAGS =
OBJECTS = Block.o Blockchain.o main.o sha256.o
OUTPUT = bin/testchain.out


main: $(OBJECTS)
	$(CC) $(OBJECTS) $(FLAGS) $(LINKS) -o $(OUTPUT)
Block.o:
	g++ -c Block.cpp
Blockchain.o:
	g++ -c Blockchain.cpp
main.o:
	g++ -c main.cpp
sha256.o:
	g++ -c sha256.cpp
.PHONY : clean
clean :
	-rm -f $(OBJECTS) $(OUTPUT)
```


## 5. Break Down of the Code
Encase anyone wants to improve upon the existing project or reuse part of the code for another project, this section will summarize how the code works and the layout of the files.

### How the Code Works
The intention of this section is not to explain each line of the code. Rather this is a high level summary by the creator to help guide those who want to edit the code for there own purposes.

Ultimately the program is trying to get all the data it needs to generate the make file.
The required data includes:
* The file path of the C++ project the makefile is for.
* A list of all the files and their relative paths within the project directory that need to be compiled.
* Any library links that need to be included.
* Any required g++ flags (if any).
* The file name of the compiled image.

Once all this information has been acquired, it is pretty straight forward to generate the makefile.

Getting this information requires a combination of user input and parsing the C++ project directory. As information is gathered it needs to be held in data structures until it is time to be used.

#### Project File Path
The file path of the C++ project is simply kept in a string called ``` project_dir```.

* From main.cpp
'''
string project_dir;
...
...
...
cout << "Please provide the project directory path: ";
cin >>  project_dir;
'''

#### List of Files and Paths
To get the list of files to compile and their file path I made a class called ```Proj_dir```. Proj_dir (class) takes project_dir (string) as an input parameter and uses member functions (that utilize the boost library) to find all the files within all the sub-directories (no mater how many nested folders there are).

In main.cpp a Proj_dir object called '''base_dir''' is created.
```
Proj_dir base_dir(project_dir); //create dir object
```

In proj_dir.cpp in the main constructor for the Proj_dir class calls member function ```find_sub_dirs_find_files()``` to parse the C++ project directory for .cpp files and their relative paths.
'''
Proj_dir::Proj_dir(string my_dir_path){
  dir_path = my_dir_path;
  find_sub_dirs_find_files();
  ...
  ...
}
'''
The C++ file names and their paths are stored in a private map within the Proj_dir class object. This map uses the file name as the key and the directory path as the data. Using member functions, the program can print the map to the user and remove files based on directory location or file name.

In proj_dir.h map is defined.
```
class Proj_dir{
private:
  ...
  ...
  ...
  std::map<std::string, std::string> files;

```
In main.cpp the base_dir (Proj_dir Object) map is printed and edited with member functions.
```
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
```
#### Library Links, G++ Flags, and Output File name
Both the Library links and the Flags list are stored in separate vector strings which can have entry added or removed based on user input. The output file name is stored as a string variable.

In main.cpp.
```
stringvec library_links;
...
...
...
stringvec flags;
...
...
...
string output_file_name;
```

#### Generating the Makefile
After all the required information is stored in variables the make file can be generated by calling the write_basic_makefile() with the data structures as the input parameters. Note that the map from the Proj_dir class was used to create the function parameters ```object_files_w_path```, ```object_files```, and ```cpp_files```. All of which are vector strings.

In main.cpp.
```
write_basic_makefile(project_dir, object_files_w_path, object_files, cpp_files, library_links, flags, output_file_name);
```


### File layout
* main.cpp :
	* Used to requested required info from user (with cout and cin) and call functions for other files to generate the makefile.

* proj_dir.cpp & proj_dir.h :
	* Contains the implementation of the directory class described in the "How the Code Works" section.

* directory_functions.cpp :
	* Contains functions for finding current directory and checking if directories exist.

* write_functions.cpp :
	* Contains functions for writing the makefile.

## 6. Future Releases
Release v2.0 will be the same features as v1.0 but with a GUI implementation. Expected it around the end of Q1 2021.

Windows Compatibility: At some point I may make a windows compatible version, but no promises. I have no plans to support MAC OS.

## 7. Wrap Up
Hope this helps, best of luck! Feel free to improve upon the code.

## 8. Contact Info
Email: rtquinn2@ncsu.edu
