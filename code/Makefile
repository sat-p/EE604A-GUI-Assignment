top_builddir = ..
include ${top_builddir}/makeinclude

DIRS = \
	tools \
	algos \
	app

all:
	for dir in ${DIRS}; do \
		${MAKE} -C $${dir} all; \
	done

clean:
	for dir in ${DIRS}; do \
		${MAKE} -C $${dir} clean; \
	done
	rm -rf *~

.PHONY: all clean