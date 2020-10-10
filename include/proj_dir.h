#include <vector>
#include <string>

#ifndef proj_dir
#define proj_dir


typedef std::vector<std::string> stringvec;


class Proj_dir{
private:
  std::string dir_path; //full dir path
  stringvec sub_dirs; //list of sub directories
  stringvec files; //list of cpp files

  void find_cpp_files();
  void find_sub_directories();
public:
  Proj_dir();
  Proj_dir(std::string my_proj_dir); //primary constructor
  void print_dir_path();
  void print_cpp_files();
  void print_sub_directories();
  int get_sub_dir_count();
  int get_cpp_file_count();
  stringvec get_sub_dirs_vector();
  ~Proj_dir(); //destructor
};





#endif
