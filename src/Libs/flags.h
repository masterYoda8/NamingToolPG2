#ifndef FLAGS_H
#define FLAGS_H

#include <cstdint>
#include <string> 

namespace flags {
    
    typedef enum {
        fFlag,
        aFlag,
        cFlag
    } flag;

    void checkForFlags(int, char**, std::string &);
    void setFlag(flag);
    bool isSet(flag);

}
#endif

