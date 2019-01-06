#!/usr/bin/make -f


################################################################################
# directories

MAIN_DIR	= $(CURDIR)

MODULES_DIR	= $(CURDIR)/modules/
MODULES_OBJ_DIR	= $(CURDIR)/modules/obj/

OBJ_DIR		= $(CURDIR)/obj/
BIN_DIR		= $(CURDIR)/bin/

export	MAIN_DIR
export	MODULES_DIR


################################################################################
# executables

BIN_NAME	= calculadora

export	BIN_NAME


################################################################################
# Make variables (CC, etc...)

CC		= gcc
LD		= ld

export	CC
export	LD


################################################################################
# cflags & libs

CFLAGS		=
LIBS		= -l m

export	CFLAGS
export	LIBS


################################################################################
# target: dependencies
#	action

PHONY := all
all: binary


PHONY += modules
modules:
	cd $(MODULES_OBJ_DIR) && $(MAKE) && cd $(MAIN_DIR)

PHONY += object
object: modules
	cd $(OBJ_DIR) && $(MAKE) && cd $(MAIN_DIR)

PHONY += binary
binary: object modules
	cd $(BIN_DIR) && $(MAKE) && cd $(MAIN_DIR)

PHONY += clean
clean:
	cd $(MODULES_OBJ_DIR) && $(MAKE) clean && cd $(MAIN_DIR)
	cd $(OBJ_DIR) && $(MAKE) clean && cd $(MAIN_DIR)


################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)


################################################################################
######## End of file ###########################################################
################################################################################
