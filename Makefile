run: build
	./bin/percentage_calculator

build: build/main.o build/gtk_helper_functions.o
	gcc `pkg-config --libs gtk4` build/*.o -o ./bin/percentage_calculator

build/main.o: src/main.c
	gcc -c -Iinclude `pkg-config --cflags gtk4` src/main.c -o build/main.o

build/gtk_helper_functions.o: include/gtk_helper_functions.h src/gtk_helper_functions.c
	gcc -c -Iinclude `pkg-config --cflags gtk4` src/gtk_helper_functions.c -o build/gtk_helper_functions.o

clean:
	rm build/*o ./bin/percentage_calculator
