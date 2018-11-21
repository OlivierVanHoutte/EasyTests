//
// Created by olivi on 21-11-2018.
//


#include <iostream>
#include <iostream>
#include "../src/Test.h"

using namespace std;

void testFunct (){

    TestException *a = nullptr;
    //a->what();

};

TestContainer testContainer({

    new Test("thisTest", [](){
        require(true, "true1");
        require(true, "true2");
        excpectNoCrash(testFunct, "crahTest");

    }),

    new Test("thisTest2", [](){
        require(false, "false");
        require(true, "true");

    })

});

int main()
{
    testContainer.runAllTests();

}