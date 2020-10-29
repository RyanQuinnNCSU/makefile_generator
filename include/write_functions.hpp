#include <vector>
#include <string>

#ifndef WRITE_FUNCTIONS
#define WRITE_FUNCTIONS

typedef std::vector<std::string> stringvec;

void write_basic_makefile(stringvec object_files_w_path, stringvec object_files, stringvec cpp_files, stringvec library_links, stringvec flags, std::string output_file_name);

#endif
