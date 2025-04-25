run: build
	./bin/percentage_calculator

build: build/main.o
	gcc build/*.o -o ./bin/percentage_calculator

build/main.o: src/main.c
	gcc -c -Iinclude src/main.c -o build/main.o

clean:
	rm build/*o ./bin/percentage_calculator
