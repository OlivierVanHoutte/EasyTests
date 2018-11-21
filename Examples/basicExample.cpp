//
// Created by olivi on 21-11-2018.
//

#include <iostream>
#include <iostream>
#include "../src/Test.h"

using namespace std;

/// Will always fail.
void fTest (){
    REQUIRE(false, "Require failed fTest()");

};

/// Will never fail.
void fTest2 (){
    REQUIRE(true, "Require failed fTest2()");

};

/// Setting up tests
int main()
{
    easyTest::TestContainer tc = easyTest::TestContainer();

    TEST(Test1, tc){
        ASSERT(true, "true");
        ASSERT(false, "false");
        EXPECTCRASH(fTest(), "CRASHTest1");
        EXPECTCRASH(fTest2(), "CRASHTest1");
        EXPECTSAFE(fTest2(), "CRASHTest2");

    };

    TEST(Test2, tc){
        ASSERT(true, "true1");
        ASSERT(true, "true2");
        EXPECTCRASH(fTest(), "CRASHTest1");
        EXPECTSAFE(fTest2(), "CRASHTest2");
    };

    tc.runAllTests();

}