#!/usr/bin/make -f


################################################################################
# directories

INC_DIR = $(MODULES_DIR)/inc/
OBJ_DIR = $(MODULES_DIR)/obj/
SRC_DIR	= $(MODULES_DIR)/src/


################################################################################
# dependencies

_ALL	= calc.o input.o print.o
ALL	= $(_ALL) modules.o

CALC_INC	= calc.h input.h print.h
CALC_DEPS	= $(SRC_DIR)/calc.c $(patsubst %,$(INC_DIR)/%,$(CALC_INC))
CALC_INC_DIRS	= -I $(INC_DIR)

INPUT_INC	= input.h calc.h
INPUT_DEPS	= $(SRC_DIR)/input.c $(patsubst %,$(INC_DIR)/%,$(INPUT_INC))
INPUT_INC_DIRS	= -I $(INC_DIR)

PRINT_INC	= print.h calc.h
PRINT_DEPS	= $(SRC_DIR)/print.c $(patsubst %,$(INC_DIR)/%,$(PRINT_INC))
PRINT_INC_DIRS	= -I $(INC_DIR)


################################################################################
# targets

all: $(ALL)


modules.o: $(_ALL)
	$(LD) -r $^ -o $@
	@echo  "\tLD	$@"
	@echo  ""


calc.o: $(CALC_DEPS)
	$(CC) $(CFLAGS) $(CALC_INC_DIRS) -c $< -o $@
	@echo  "\tCC	$@"

input.o: $(INPUT_DEPS)
	$(CC) $(CFLAGS) $(INPUT_INC_DIRS) -c $< -o $@
	@echo  "\tCC	$@"

print.o: $(PRINT_DEPS)
	$(CC) $(CFLAGS) $(PRINT_INC_DIRS) -c $< -o $@
	@echo  "\tCC	$@"


clean:
	rm -f *.o


################################################################################
######## End of file ###########################################################
################################################################################
