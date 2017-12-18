// http://blog.csdn.net/u012611878/article/details/52534622
/*
1.#
2.##
3.бн __VA_ARGS__
*/
#include <stdio.h>
#define SQUARE(x) printf("the square of "#x" is %d.\n",(x)*(x))
#define TESTNAME(tname) test##tname
#define GTEST_TYPE_PARAMS_(TestCaseName) gtest_type_params_##TestCaseName##_
#define PRINTN(n) printf("test"#n" = %d\n",test##n)
#define OUTPUT(...) printf(__VA_ARGS__)
int main()
{
    char *name = "snoopy";
    int weight = 10;
    int height = 30;
    int TESTNAME(weight) = 11;
    int GTEST_TYPE_PARAMS_(weight) = 12;
    PRINTN(weight);
    OUTPUT("name\n");
    //snoopy
    OUTPUT("weight = %d, height = %d\n", weight, height);
    //weight = 10, height = 30
    SQUARE(weight);
    SQUARE(weight + 1);
    return 0;
}