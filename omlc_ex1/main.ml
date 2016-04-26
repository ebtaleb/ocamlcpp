let print_hello () =
      print_endline "Hello World"

let () =
      Callback.register "Hello callback" print_hello
