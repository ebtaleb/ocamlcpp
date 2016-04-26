#!/usr/bin/env sh

ocamlopt -c main.ml -o main.cmx
ocamlopt -output-obj -o camlcode.o main.cmx
gcc -c b.c  -I"`ocamlc -where`"
gcc -o prog b.o  camlcode.o -L"`ocamlc -where`" -lm -lasmrun -ldl
