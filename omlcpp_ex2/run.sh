#!/bin/bash

ocamlopt -output-obj -o modcaml.o mod.ml
ocamlopt -c modwrap.c

cp `ocamlc -where`/libasmrun.a mod.a && chmod +w mod.a
ar r mod.a modcaml.o modwrap.o
g++ -o prog -I `ocamlc -where` ex2.cpp mod.a -lm -ldl
rm *.o *.cmx *.cmi *.a
