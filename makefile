CFLAGS = -std=c90 -Wall -g
all: ru_na_pandemia

# regras de ligação
ru_na_pandemia: ru_na_pandemia.o libpilha.o liblista.o libfila.o libestudante.o libtck.o
	gcc ru_na_pandemia.o libpilha.o liblista.o libfila.o libestudante.o libtck.o -o ru_na_pandemia $(CFLAGS)
 
# regras de compilação
ru_na_pandemia.o: ru_na_pandemia.c libpilha.h liblista.h libfila.h libestudante.h libtck.h
	gcc -c ru_na_pandemia.c $(CFLAGS)
 
libpilha.o: libpilha.c libpilha.h
	gcc -c libpilha.c $(CFLAGS)

liblista.o: liblista.c liblista.h
	gcc -c liblista.c $(CFLAGS)

libfila.o: libfila.c libfila.h
	gcc -c libfila.c $(CFLAGS)

libestudante.o: libestudante.c libestudante.h
	gcc -c libestudante.c $(CFLAGS)

libtck.o: libtck.c libtck.h
	gcc -c libtck.c $(CFLAGS)
	
# remove arquivos temporários
clean:
	-rm -f *.o *~
