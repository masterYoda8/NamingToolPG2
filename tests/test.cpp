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
    std::string filePathWithPractiseNumber1 = "test/this/u49/seven/eight";
    std::string filePathWithPractiseNumber2 = "test/this/u03/seven/eight";

    ASSERT_THAT(extractPractiseNumber(filePathWithPractiseNumber1), Eq("49"));
    ASSERT_THAT(extractPractiseNumber(filePathWithPractiseNumber2), Eq("03"));
}

TEST(extractTaskNumber, returnsTaskNumberString) {
    std::string filePathWithTaskNumber1 = "test/this/a9/seven/eight";
    std::string filePathWithTaskNumber2 = "test/this/a3/seven/eight";

    ASSERT_THAT(extractTaskNumber(filePathWithTaskNumber1), Eq("9"));
    ASSERT_THAT(extractTaskNumber(filePathWithTaskNumber2), Eq("3"));
}
