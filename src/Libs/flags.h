#ifndef FLAGS_H
#define FLAGS_H

#include <cstdint>
#include <string> 
#include "fileData.h"

namespace flags {
    
    typedef enum {
        fFlag,
        aFlag,
        cFlag
    } flag;

    void checkForFlags(int, char**, fileData &);
    void applyFlags(fileData &);
    void setFlag(flag);
    bool isSet(flag);

}
#endif

