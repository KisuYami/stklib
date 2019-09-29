INSTALL_DIR=/usr/local/include/stk/
LIB_DIR=/usr/lib/

all:
	mkdir -p build/stk
	#Create objects
	clang -c -o build/stk/sort.o 	include/stk/sort.c
	clang -c -o build/stk/stklib.o include/stk/stklib.c
	clang -c -o build/stk/string.o include/stk/string.c
	#Create shared lib
	clang -shared -o build/libstklib.so build/stk/stklib.o build/stk/string.o build/stk/sort.o

install:
	mkdir -p $(INSTALL_DIR)
	install -g 0 -o 0 -m 0755 build/libstklib.so $(LIB_DIR)
	find include/stk/*.h -type f -exec install -Dm 755 "{}" "$(INSTALL_DIR)" \;
	ldconfig /usr/lib

clean:
	rm -rd build
