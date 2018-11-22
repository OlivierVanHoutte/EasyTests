//
// Created by olivi on 21-11-2018.
//

#include <cstring>
#include "Test.h"

using namespace easyTest;

const char* stringToCharP(const string &str){

    const char *cstr = str.c_str();

    return cstr;

};

bool Test::run() {
    cout << "- Started testing: " << testGroup << ".\n";
    bool succes = true;
    funct(succes);

    if (!succes){

        throw(TestException(testGroup));

    }else{

        cout << "\t[[SUCCES!!: " << testGroup << "]]\n";

    }

}

Test::Test(const string &testGroup): testGroup(testGroup) {

}

TestContainer::~TestContainer() {

    for (auto &i: tests){
        delete i;
    }

}

void TestContainer::runAllTests() {

    cout << "\n[Starting Tests]\n";

    int countTests = 0;
    int countTestsFailed = 0;

    for (auto &i: tests){
        try {
            i->run();

        }catch(TestException &e){
            countTestsFailed += 1;
            cout << "\t" << e.what() << "\n";

        }

        countTests += 1;
        cout << "\n";
    }

    cout << "[" << countTests << " tests ran]\n";
    cout << "[" << countTests - countTestsFailed << " test(s) succeeded]\n";
    cout << "[" << countTestsFailed << " test(s) failed]\n";

}

void TestContainer::add(Test *t) {
    tests.emplace_back(t);

}

TestContainer::TestContainer() = default;

const char* TestException::what() const noexcept {
    string str = "[[FAILED!!: " + errorMessage + "]]";
    return stringToCharP(str);
}

const char* RequireException::what() const noexcept {
    string str = "[[REQUIRE FAILED!!: " + errorMessage + "]]";
    return stringToCharP(str);
}
