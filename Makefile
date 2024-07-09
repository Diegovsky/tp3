CFLAGS :=

tp2: tp2.o instant.o
	gcc $^ -o $@

clean:
	rm -f *.o
	rm -f tp2
