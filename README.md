# EasyTests
A very basic testing implementation.

example:

    TestContainer testContainer({

        new Test("thisTest", [](){
            require(true, "false1");
            require(true, "true1");
            excpectNoCrash(testFunct, "crahTest");

        }),

        new Test("thisTest2", [](){
            require(false, "false2");
            require(true, "true2");

        })

    });

    int main()
    {
        testContainer.runAllTests();

    }


note: This is mainly usefull for small projects that need fast and easy (maybe a bit dirty) testing.
    If your project ends up being reasonably big, consider using Gtest or some other testing library.
