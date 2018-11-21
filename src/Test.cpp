//
// Created by olivi on 21-11-2018.
//

#include "Test.h"

Test::Test(const string &testGroup, const function<void()> &funct) : testGroup(testGroup), funct(funct) {}

void Test::run() {
    cout << "- Started testing group: " << testGroup << "." << endl;
    funct();

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
            cout << "\t" << e.error() << "\n";

        }

        countTests += 1;
        cout << "\n";
    }

    cout << "[" << countTests << " tests ran]\n";
    cout << "[" << countTestsFailed << " tests failed]\n";

}

TestContainer::TestContainer(const vector<Test*> &tests) : tests(tests) {}

TestContainer::~TestContainer() {

    for (auto &i: tests){
        delete i;
    }

}

void require(bool a, string errorMessage){
    if (!a){
        throw(RequireException(errorMessage));

    }

};

void excpectNoCrash(function<void()> funct, string errorMessage){

    try{
        funct();

    }catch(...){
        throw(CrashException(errorMessage));

    }

};

string TestException::error() const noexcept {
    string str = "[[TEST FAILED!!: " + errorMessage + "]]";
    return str;
}

string RequireException::error() const noexcept {
    string str = "[[REQUIRE FAILED!!: " + errorMessage + "]]";
    return str;
}

string CrashException::error() const noexcept {
    string str = "[[CRASH OCCURED!!: " + errorMessage + "]]";
    return str;
}
