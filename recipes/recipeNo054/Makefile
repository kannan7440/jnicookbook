include ../Makefile.common

all: download_jna compilec compilescala

dirs:
	mkdir -p jar

compilec:
	c++ -std=c++11 -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/HelloWorld.cc -o lib/libHelloWorld.$(EXT)

compilescala:
	scalac -d target -classpath "./jar/jna-5.4.0.jar" scala/HelloJNA.scala

download_jna: dirs
	curl -s -L -z jar/jna-5.4.0.jar -o jar/jna-5.4.0.jar https://repo1.maven.org/maven2/net/java/dev/jna/jna/5.4.0/jna-5.4.0.jar 

test:
	scala -Djna.library.path="./lib" -classpath "./target:jar/jna-5.4.0.jar" HelloJNA

clean: clean-common
	$(call rm-test,jar)

include ../Makefile.clean
