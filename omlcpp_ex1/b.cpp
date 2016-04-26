#include <cstdio>
#include <cstring>
#include <iostream>
#include <caml/mlvalues.h>
#include <caml/callback.h>

int fib(int n)
{
  static value * fib_closure = NULL;
  if (fib_closure == NULL) fib_closure = caml_named_value("fib");
  return Int_val(caml_callback(*fib_closure, Val_int(n)));
}

char *format_result(int n)
{
  static value * format_result_closure = NULL;
  if (format_result_closure == NULL)
    format_result_closure = caml_named_value("format_result");
  return strdup(String_val(caml_callback(*format_result_closure, Val_int(n))));
  /* We copy the C string returned by String_val to the C heap
     so that it remains valid after garbage collection. */
}

void hello_closure()
{
    static value * closure_f = NULL;
    if (closure_f == NULL) {
        closure_f = caml_named_value("Hello callback");
    }
    caml_callback(*closure_f, Val_unit);
}

int main(int argc, char **argv)
{
    caml_main(argv);
    hello_closure();
    int result = fib(10);
    printf("fib(10) = %s", format_result(result));
    std::string s = format_result(result);
    std::cout << s;
    return 0;
}
