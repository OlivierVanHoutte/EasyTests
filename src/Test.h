//
// Created by olivi on 21-11-2018.
//

#ifndef POLYCODE_TEST_H
#define POLYCODE_TEST_H

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

/// Main Test Class
class Test {

    string testGroup;
    function<void ()> funct;

public:

    Test(const string &testGroup, const function<void()> &funct);
    void run();

};

/// Test Container
class TestContainer {

    vector<Test*> tests;

public:

    explicit TestContainer(const vector<Test*> &tests);
    virtual ~TestContainer();

    void runAllTests();

};

/// Default Exception
struct TestException : public std::exception
{
    string errorMessage;
    explicit TestException(string &errorMessage): errorMessage(errorMessage){}

    virtual string error () const noexcept;

};

/// Require Exception
struct RequireException : public TestException
{
    explicit RequireException(string &errorMessage) : TestException(errorMessage) {}

    string error () const noexcept override;

};

/// Crash Exception
struct CrashException : public TestException
{
    explicit CrashException(string &errorMessage) : TestException(errorMessage) {}

    string error () const noexcept override;

};

/// Require helper function
void require(bool a, string errorMessage);

/// Check if a function crashes, helper function
void excpectNoCrash(function<void()> funct, string errorMessage);


#endif //POLYCODE_TEST_H
