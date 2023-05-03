#include "googletest/googlemock/include/gmock/gmock.h" 
#include "../src/main.h"

TEST(Exampletest, passes) {
    ASSERT_THAT(test(), testing::Eq(10));
}

TEST(test, failes) {
    ASSERT_THAT(test(), testing::Eq(11));
}

