OBJECTS = $(patsubst src/%.c, build/%.o, $(wildcard src/*.c))

build: $(OBJECTS)
	gcc -lncurses build/*.o -o bin/percentage_calculator

run: build
	@foot --app-id percentage_calculator -W 90x14 /home/admin/Development/percentage_calculator/bin/percentage_calculator 2>/dev/null

build/%.o: src/%.c
	gcc -Wall -Wextra -Iinclude -c $< -o $@

clean:
	rm -rf build/* bin/*
