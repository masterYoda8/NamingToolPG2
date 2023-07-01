#include "flags.h"
#include "fileData.h"
#include "utils.h"

using flags::flag;

static uint8_t FLAGS_{};

void flags::setFlag(flag x) {
    uint8_t setter = (1 << x); 
    FLAGS_ |= setter;    
}

bool flags::isSet(flag x){
    uint8_t getter = (1 << x);
    return (FLAGS_ & getter);
}

void flags::checkForFlags(int argc, char* argv[], fileData & file){
    for (int i = 0; i < argc; i++) {
        if (std::strcmp(argv[i], "-f") == 0) { 
            flags::setFlag(fFlag);
        }
        else if (std::strcmp(argv[i], "-a") == 0) { 
            flags::setFlag(aFlag);
            file.addon = "_" + static_cast<std::string>(argv[++i]);
        }
        else if (std::strcmp(argv[i], "-c") == 0) {
            flags::setFlag(cFlag);
        }  
    }
}

void flags::applyFlags(fileData & file) {
    if (!(flags::isSet(flags::fFlag))) {
        addOldFileName(file.filePath);
    } else {
        file.keepExtension();
    } 
    if (flags::isSet(flags::cFlag)) {
        std::filesystem::path newTmpFileName = static_cast<std::filesystem::path>((file.filePathString + "_tmp"));
        std::filesystem::copy_file(file.filePath, newTmpFileName); 
        file.fileToRename = static_cast<std::string>(newTmpFileName);
    }
}
