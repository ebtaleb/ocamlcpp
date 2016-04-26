let print_hello () =
      print_endline "Hello World"

let rec fib n = if n < 2 then 1 else fib(n-1) + fib(n-2)

let format_result n = Printf.sprintf "Result is: %d\n" n

let () =
      Callback.register "Hello callback" print_hello;
      Callback.register "fib" fib;
      Callback.register "format_result" format_result
