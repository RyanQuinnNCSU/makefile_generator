#include <vector>
#include <string>
#include <iterator>
#include <map>

#ifndef proj_dir
#define proj_dir


typedef std::vector<std::string> stringvec;


class Proj_dir{
private:
  std::string dir_path; //full dir path
  stringvec sub_dirs; //list of sub directories
  //stringvec files; //list of cpp files
  std::map<std::string, std::string> files;

  void find_local_cpp_files(std::string current_dir_path);
  void find_local_sub_directories(std::string current_dir_path);
  void find_sub_dirs_find_files();
  int remove_file(std::string dir_name);
public:
  Proj_dir();
  Proj_dir(std::string my_proj_dir); //primary constructor
  void remove_file_from_list(std::string file_name);
  void remove_dir_files_from_list(std::string dir_name);
  void print_dir_path();
  void print_cpp_files();
  void print_sub_directories();
  int get_sub_dir_count();
  int get_cpp_file_count();
  stringvec get_sub_dirs_vector();
  std::map<std::string, std::string>::iterator init_iterator(int get_type);
  std::string parse_file_map(std::map<std::string, std::string>::iterator itr, int column);
  ~Proj_dir(); //destructor
};





#endif
