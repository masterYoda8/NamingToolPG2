#include "flags.h"

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

void flags::checkForFlags(int argc, char* argv[], std::string & addon){
    for (int i = 0; i < argc; i++) {
        if (std::strcmp(argv[i], "-f") == 0) { 
            flags::setFlag(fFlag);
        }
        else if (std::strcmp(argv[i], "-a") == 0) { 
            flags::setFlag(aFlag);
            addon = "_" + static_cast<std::string>(argv[++i]);
        }
        else if (std::strcmp(argv[i], "-c") == 0) {
            flags::setFlag(cFlag);
        }  
    }
}
