include ../Makefile.common

all: compilejava compilec

compilec:
	cc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/recipeNo056_PassObject.c -o lib/libPassObject.$(EXT)


compilejava:
	$(JAVA_HOME)/bin/javac -h c -cp target -d target java/recipeNo056/PassObject.java

test:
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target recipeNo056.PassObject

clean: clean-common
	$(call rm-test,c/recipeNo056_PassObject.h)

include ../Makefile.clean
