CC=clang++
CFLAGS=-g -c -std=c++14 -Wall
LDFLAGS=-L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system

GAMESOURCES=src/simplex_noise.cpp \
						src/perlin_noise.cpp \
						src/terrain_generator.cpp \
						src/gradiant_base.cpp \
						src/gradiant_below.cpp

MAINSOURCES=src/main.cpp \
			$(GAMESOURCES)

TESTSOURCES=src/maintest.cpp \
			$(GAMESOURCES)

MAINOBJECTS=$(MAINSOURCES:.cpp=.o)
MAINEXECUTABLE=generator

TESTOBJECTS=$(TESTSOURCES:.cpp=.o)
TESTEXECUTABLE=generator_test

# tips on the makefile variables
# $@	name of target
# $<	name of first prerequisite
# $^	name of all prerequisites

all: $(MAINSOURCES) $(MAINEXECUTABLE)

test: $(TESTSOURCES) $(TESTEXECUTABLE)

$(MAINEXECUTABLE): $(MAINOBJECTS)
	$(CC) $(LDFLAGS) $(MAINOBJECTS) -o $@

$(TESTEXECUTABLE): $(TESTOBJECTS)
	$(CC) $(LDFLAGS) $(TESTOBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm the_platformer the_platformer_test src/*.o src/commands/*.o
