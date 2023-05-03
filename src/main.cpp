#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "utils.h"


int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 4){
	std::cerr << COLOR_YELLOW << "Usage: " << BASH_NAME << " filepath" << std::endl;
	std::cerr << "No files have been changed" << COLOR_RESET << std::endl;
	std::exit(1);
    }
    
    std::string addon = "";

    if (argc == 4 && !(strcmp(argv[2], "-a"))) {
       addon = "_" + static_cast<std::string>(argv[3]); 
    }

    std::string newFileName = createFileName(addon);

    std::rename(argv[1], newFileName.c_str());
    
    std::cout << "Renamed:  " << argv[1] << " --> " << COLOR_GREEN << newFileName << COLOR_RESET << std::endl;

    return 0;
}


