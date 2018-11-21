# EasyTests
A very basic testing implementation.

example:

    
    /// Setting up tests
    TestContainer testContainer({

        new Test("Test", [](){
            assert(true, "true1");
            assert(true, "true2");
            assertNoCrash(fTest, "crashTest");

        }),

        new Test("Test2", [](){
            assert(false, "false");
            assert(true, "true");

        })

    });

    int main()
    {
        testContainer.runAllTests();

    }

Info:
When running the tests, a singe test will stop as soon as an error occurs.
for example,
When making a test like this:
        
    new Test("TestExample", [](){
        assert(false, "false1");
        assert(false, "false2");
    })
    
It will only show an error for the first assertion, thus the output will be:

    - Started testing: TestExample.
	[[ASSERTION FAILED!!: false1]]
    
However, This does not occur across tests:

    new Test("TestExample", [](){
        assert(false, "false1");
    }),
    
    new Test("TestExample2", [](){
        assert(false, "false2");
    })

Will show this:

     - Started testing: TestExample.
        [[ASSERTION FAILED!!: false1]]

     - Started testing: TestExample2.
        [[ASSERTION FAILED!!: false2]]




note: This is mainly usefull for small projects that need fast and easy (maybe a bit dirty) testing.
    If your project ends up being reasonably big, consider using Gtest or some other testing library.
