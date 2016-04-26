BIN_NAME := c_main_calls_ocaml

CC ?= gcc
SRC_EXT = c
SRC_PATH = .
LIBS = -L`ocamlc -where` -lm -lasmrun -ldl
CFLAGS = -std=c99 -Wall -Wextra -g
INCLUDES = -I $(SRC_PATH) -I`ocamlc -where`

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

camlcode.o: ocaml_called_from_c.ml
	ocamlopt -g -c $^ -o ocaml_called_from_c.cmx
	ocamlopt -g -output-obj -o $@ ocaml_called_from_c.cmx

$(BIN_NAME): camlcode.o $(OBJECTS)
	$(CC) $^ -o $@ $(LIBS)

.PHONY: clean

clean:
	rm *.cmx *.cmi *.o *.d $(BIN_NAME)

-include $(DEPS)

%.o: %.$(SRC_EXT)
	@echo "Compiling: $< -> $@"
	$(CMD_PREFIX)$(CC) $(CFLAGS) -MP -MMD -c $< -o $@ $(INCLUDES)
