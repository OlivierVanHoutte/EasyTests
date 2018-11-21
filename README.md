# EasyTests
A very basic testing implementation.
_______
## basics

example:

    int main() {

        /// Setting up tests
        TestContainer testContainer({

        TEST(TestName1, testContainer) {	// will succeed without errors
            ASSERT(true, "true1");
            ASSERT(true, "true2");

        };  // ';' is necessary

        TEST(TestName2, testContainer) {	// will report first assertion
            ASSERT(false, "false");
            ASSERT(true, "true");

        };

        ///....


        testContainer.runAllTests();

    }

### Testing

Currently implemented are:
    - ASSERT(bool, char*);          // Check if a condition is true, test fails if not.
    - REQUIRE(bool, char*);         // Check if a condition is true, sends exception if not. Can be used to force quit function calls.
    - EXPECTCRASH(function, char*); // Check if a function "crashes" with the given input. Additional info follows.
    - EXPECTSAFE(function char*);   // Check if a function doesn't "crash" with the given input. Test fails if it does

### Using REQUIRE:

Let's say you want to check at the beginning of your function if the parameters are valid.
You can use the REQUIRE "function" for that.

Example:

	int f(int a){
    	REQUIRE(a != 0, "Require failed fTest()");
		return 1/a;
	};

This can then be checked for during tests like this:

	EXPECTCRASH(fTest(0), "CrashTest1");
	EXPECTSAFE(fTest(5), "CrashTest2");

Be sure to pay attention to your REQUIRE() statements.
If you call the previouse function example outside of your tests, your program will most likely fail due to an ignored exception.
You can try and catch it just like normal exceptions, so if you want to prevent crashes,
try that,
or just always comply with your REQUIRE statements.

Note: Due to the fact that REQUIRE throws an exception, multipple failing REQUIRE statements will only show the top one failing.

Example:

    REQUIRE(false, "checked");
    REQUIRE(false, "not checkes");

Only the first one will be checked. It then throws an excpetion causing the program to exit function calls until it finds a try - catch.
(That's about as far as my knowledge of exceptions goes.)

__________________________

Note: This is mainly usefull for small projects that need fast and easy (maybe a bit dirty) testing.
    If your project ends up being reasonably big, consider using Gtest or some other, maybe a bit more stable, testing library.
