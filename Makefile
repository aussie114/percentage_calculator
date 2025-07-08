NAME = percentage_calculator
OBJECTS = $(patsubst src/%.c, build/%.o, $(wildcard src/*.c))

run: build
	bin/$(NAME)

build: $(OBJECTS)
	gcc `pkg-config --libs gtk4` $(OBJECTS) -o bin/$(NAME)

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	gcc -Wall -Wextra -Iinclude `pkg-config --cflags gtk4` -c $< -o $@

clean:
	rm -rf build/* bin/$(NAME)
