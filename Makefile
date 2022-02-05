EXECUTABLE=ignea_insania

CC=g++
CFLAGS=-c -Wall -Wextra -O2
LDFLAGS=
LIBS=-lSDL2

SOURCES=src/application.cpp \
		src/application_events_impl.cpp \
		src/main.cpp \
		src/game/game.cpp \
		src/structs/events.cpp \
		src/structs/geometry.cpp \
		src/ui/window.cpp \
		src/ui/window_impl.cpp

OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS)
	rm $(EXECUTABLE)
