//
// Created by olivi on 21-11-2018.
//

#ifndef POLYCODE_TEST_H
#define POLYCODE_TEST_H

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

namespace easyTest {

/// Main Test Class
    class Test {

        string testGroup;

    public:

        function<void(bool &)> funct;

        explicit Test(const string &testGroup);

        bool run();

    };

/// Test Container
    class TestContainer {

    public:

        vector<Test *> tests;

        TestContainer();

        virtual ~TestContainer();

        void add(Test *t);

        void runAllTests();

    };

/// Default Exception
    struct TestException : public std::exception {
        string errorMessage;

        explicit TestException(string &errorMessage) : errorMessage(errorMessage) {}

        explicit TestException(const char *errorMessage) : errorMessage(errorMessage) {}

        const char *what() const noexcept override;

    };

/// Crash Exception
    struct RequireException : public TestException {
        explicit RequireException(string &errorMessage) : TestException(errorMessage) {}

        explicit RequireException(const char *errorMessage) : TestException(errorMessage) {}

        const char *what() const noexcept override;

    };

#define TEST(testName, tc)\
    auto* test_##testName = new easyTest::Test(#testName);\
    tc.add(test_##testName);\
    test_##testName->funct = [](bool &fullSucces)

#define EXPECTCRASH(funct, str){\
            bool a = false;\
            try {\
                funct;\
            }catch(...){ \
                a = true;\
            }\
            if (!a){ \
                cout << "\t[[NO CRASH OCCURED!!: " << str << "]]\n";\
                fullSucces = false;\
            };\
        }

#define EXPECTSAFE(funct, str)\
    try {\
        funct;\
    }catch(exception &e){\
        cout << "\t[[CRASH OCCURED!!: " << str << e.what() << "]]\n";\
        fullSucces = false;\
    }

#define ASSERT(req, str)\
    if (!req) {\
        cout <<  "\t[[ASSERTION FAILED!!: " << str << "]]\n";\
        fullSucces = false;\
    }

#define REQUIRE(req, str)\
    if (!req) {\
        throw easyTest::RequireException(str);\
    }

}

#endif //POLYCODE_TEST_H
