# EasyTests
A very basic testing implementation.
_______
## basics

example:

    /// Setting up tests
    TestContainer testContainer({

        new Test("TestName1", []{	// will succeed without errors
            assert(true, "true1");
            assert(true, "true2");

        }),

        new Test("TestName2", []{	// will report first assertion
            assert(false, "false");
            assert(true, "true");

        }),
	
	///....

    });

    int main()
    {
        testContainer.runAllTests();

    }

### Testing hierarchy

When running the tests, a singe test will stop as soon as an error occurs.

for example,
When making a test like this:
        
    new Test("TestExample", []{
        assert(false, "false1");
        assert(false, "false2");
    })
    
It will only show an error for the first assertion, thus the output will be:

    - Started testing: TestExample.
	[[ASSERTION FAILED!!: false1]]
    
However, This does not occur across tests:

    new Test("TestExample", []{
        assert(false, "false1");
    }),
    
    new Test("TestExample2", []{
        assert(false, "false2");
    })

Will show this:

     - Started testing: TestExample.
        [[ASSERTION FAILED!!: false1]]

     - Started testing: TestExample2.
        [[ASSERTION FAILED!!: false2]]

The reason for this implementation is to encourage the use of many smaller individual tests instead of one big test with way too much code.

Note: The same rule applies to the use of require() 
	for example:
	
	int f(int a){
		require(a != 0, "Require failed fTest()");
		require(a > 1, "Require failed fTest()");
	
		return 1/a;
	};
	
In tests, this will only show the first error if you use f(0)


### Function requirements:

Let's say you want to check at the beginning of your function if the parameters are valid.
You can use the require() function for that.

example:

	int f(int a){
    		require(a != 0, "Require failed fTest()");
		return 1/a;
	};

This can then be checked for during tests like this:

	new Test("Test", []{
		assertCrash(fTest(0), "CrashTest1");
		assertNoCrash(fTest(5), "CrashTest2");
	}),

Be sure to pay attention to your require() statements.
If you call the above function f(0) outside of your tests, your your program will most likely fail due to an ignored exception. You can try and catch these just like normal exceptions, so if you want to prevent crashes, try that.

__________________________

note: This is mainly usefull for small projects that need fast and easy (maybe a bit dirty) testing.
    If your project ends up being reasonably big, consider using Gtest or some other testing library.
