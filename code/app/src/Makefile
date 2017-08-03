top_builddir = ../../..
include ${top_builddir}/makeinclude

CPP_SRC = \
	WC_MainWindow.cxx \
	UI_MainWindow.cxx \
	main.cxx

OBJ = ${CPP_SRC:%.cxx=%.o}
DEP = ${CPP_SRC:%.cxx=%.dep}

ifeq (${MAKECMDGOALS}, obj)
include ${DEP}
endif

dep: ${DEP}

obj: ${OBJ}

bin: main

main: $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) $(LIB) -o $@

clean:
	$(RM) $(DEP) $(OBJ) main

.PHONY: dep obj bin clean