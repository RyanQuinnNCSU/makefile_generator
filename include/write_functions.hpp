#include <vector>
#include <string>

#ifndef WRITE_FUNCTIONS
#define WRITE_FUNCTIONS

typedef std::vector<std::string> stringvec;

int make_bin(std::string project_dir);
void write_basic_makefile(std::string project_dir,stringvec object_files_w_path, stringvec object_files, stringvec cpp_files, stringvec library_links, stringvec flags, std::string output_file_name);

#endif
