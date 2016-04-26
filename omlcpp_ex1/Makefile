BIN_NAME := prog

CXX ?= g++
SRC_EXT = cpp
SRC_PATH = .
LIBS = -L`ocamlc -where` -lm -lasmrun -ldl
CXXFLAGS = -std=c++11 -Wall -Wextra -g
INCLUDES = -I`ocamlc -where`

OCAMLOPT = ocamlopt

SHELL = /bin/bash
SOURCES = $(shell find $(SRC_PATH) -name '*.$(SRC_EXT)' -printf '%T@\t%p\n' \
			| sort -k 1nr | cut -f2-)

OBJECTS = $(SOURCES:%.$(SRC_EXT)=%.o)
DEPS = $(OBJECTS:.o=.d)

export V := true
export CMD_PREFIX := @
ifeq ($(V),true)
CMD_PREFIX :=
endif

all: $(BIN_NAME)

camlcode.o: main.ml
	$(OCAMLOPT) -c $^ -o main.cmx
	$(OCAMLOPT) -output-obj -o $@ main.cmx

$(BIN_NAME): camlcode.o $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS)

.PHONY: clean

clean:
	rm *.d *.cmx *.cmi *.o $(BIN_NAME)

-include $(DEPS)

%.o: %.$(SRC_EXT)
	@echo "Compiling: $< -> $@"
	$(CMD_PREFIX)$(CXX) $(CXXFLAGS) -MP -MMD -c $< -o $@ $(INCLUDES)

#DSO code
#ocamlopt -fPIC -output-obj -o libldb.so -ccopt "-fPIC -I`ocamlc -where`" dynlink.cmxa b.c main.ml
#remove fPIC opts
#ld cml.o -o derp -L"`ocamlc -where`" -ldl -lasmrun
