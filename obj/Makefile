#!/usr/bin/make -f


################################################################################
# directories

MODULES_INC_DIR = $(MODULES_DIR)/inc/

SRC_DIR	= $(MAIN_DIR)/src/


################################################################################
# dependencies

ALL	= main.o

MAIN_INC_MODS	= calc.h
MAIN_DEPS	= $(SRC_DIR)/main.c \
			$(patsubst %,$(MODULES_INC_DIR)/%,$(MAIN_INC_MODS))
MAIN_INC_DIRS	= -I $(MODULES_INC_DIR)


################################################################################
# targets

all: $(ALL)



main.o: $(MAIN_DEPS)
	$(CC) $(CFLAGS) $(MAIN_INC_DIRS) -c $< -o $@
	@echo  "\tCC	$@"


clean:
	rm -f *.o


################################################################################
######## End of file ###########################################################
################################################################################
