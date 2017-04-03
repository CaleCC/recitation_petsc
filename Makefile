################################################################
####
#### This makefile is part of the tutorial
#### `Introduction to the PETSc library'
#### by Victor Eijkhout eijkhout@tacc.utexas.edu
####
#### copyright Victor Eijkhout 2012-7
####
################################################################

info ::
	@echo "do:"
	@echo "  make SOURCE"
	@echo "    where SOURCE is one of ${SOURCES}"

include ${PETSC_DIR}/lib/petsc/conf/variables
include ${PETSC_DIR}/lib/petsc/conf/rules
LOCDIR = csolutions

SOURCE = hello
SOURCES = hello vec matvec ksp grid helloworldpetsc
#grid mat ksp shell ex46 ex46a
CFLAGS = ${PETSC_CC_INCLUDES} -std=gnu99

.SECONDEXPANSION:
${SOURCES} : $$@.o
	${CLINKER} -o $@ $@.o ${PETSC_LIB}

info ::
	@echo "make listexercises"
.PHONY: listexercises
listexercises :
	@echo ${SOURCES}


info ::
	@echo "make clean"
.PHONY: clean
clean ::
	@/bin/rm -f *.o ${SOURCES} *~
