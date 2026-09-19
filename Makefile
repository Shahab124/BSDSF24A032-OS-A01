PREFIX = /usr/local

all:
	make -C src

clean:
	make -C src clean

install: all
	cp bin/client_static $(PREFIX)/bin/client
	mkdir -p $(PREFIX)/share/man/man3
	cp man/man3/*.3 $(PREFIX)/share/man/man3/
	mandb -q
