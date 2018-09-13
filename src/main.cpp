#include <boost/filesystem.hpp>
#include <iostream> // std::cout

using namespace std;
namespace fs = boost::filesystem;

void resucure_path(fs::path const& path){
	if (fs::is_directory(path))
	{
		fs::directory_iterator tmp_directory_end;
		fs::directory_iterator tmp_dir_it(path);
		for (; tmp_dir_it != tmp_directory_end; ++tmp_dir_it)
			resucure_path(tmp_dir_it->path());
	}else if(fs::is_regular_file(path))
		cout << path << endl;
}

int main(int argc, char* argv[]){
	cout << "Current path: " << fs::current_path() << endl;
	if (argc < 2)
	{
		cerr << "Usage: listfiles directory" << endl;
		return -1;
	}
	fs::path path(argv[1]);
	resucure_path(path);
	return 0;
}
