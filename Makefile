CC=clang++
CFLAGS=-std=c++23

install:
	rm -rf /usr/include/tiny/
	mkdir -p /usr/include/tiny/
	cp inc/*.h /usr/include/tiny/