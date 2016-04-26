#include <cstdio>
#include <caml/callback.h>

extern "C" {
    extern int fib(int n);
    extern char * format_result(int n);
}

int main(int argc, char ** argv)
{
    int result;

    caml_startup(argv);
    result = fib(10);
    printf("fib(10) = %s", format_result(result));
    return 0;
}
