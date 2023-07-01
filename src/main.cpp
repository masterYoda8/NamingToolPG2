#include <iostream>
#include <filesystem>
#include <string>
#include <cstring>

#include "Libs/utils.h"
#include "Libs/flags.h"
#include "Libs/fileData.h"


int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 6){
	    std::cerr << COLOR_YELLOW << "Usage: " << BASH_NAME << " filepath" << std::endl;
	    std::cerr << "No files have been changed" << COLOR_RESET << std::endl;
	    std::exit(1);
    }
    
    // Init fileData via c'tor
    fileData file = fileData(argv[1]);

    // Check and apply flags
    flags::checkForFlags(argc, argv, file);
    flags::applyFlags(file);

    file.newFileName = createFileName(file);
    
    std::rename(file.fileToRename.c_str(), file.newFileName.c_str());
    
    std::cout << ((flags::isSet(flags::cFlag)) ? "Copied: ": "Renamed: ");
    std::cout << argv[1] << " --> " << COLOR_GREEN << file.newFileName << COLOR_RESET << std::endl;

    return 0;
}


