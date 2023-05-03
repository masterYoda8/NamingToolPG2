#include "googletest/googlemock/include/gmock/gmock.h" 
#include "../src/utils.h"
#include <string>

using testing::Eq;

TEST(getSubjectIndex, returnsIndexForValidSubjectInFilePath) {
    std::string filePathWithPG2 = "blip/blap/blup/pg2/blip/blap/blup";    
    std::string filePathWithDS = "blip/ds/test/d/a/x";
    
    initSubjectVector();
    
    ASSERT_THAT(getSubjectIndex(filePathWithPG2), Eq(1));
    ASSERT_THAT(getSubjectIndex(filePathWithDS), Eq(0));
}

TEST(extractPractiseNumber, returnsPractiseNumberString) {
    std::string filePathWithPractiseNumber = "test/this/u49/seven/eight";

    ASSERT_THAT(extractPractiseNumber(filePathWithPractiseNumber), Eq("49"));
}

