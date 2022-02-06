# Executable file name
EXECUTABLE=ignea_insania

# Compiler
CC=clang

# Compiler flags
CFLAGS=\
	   -c \
	   -std=c++2a \
	   -Wall -Wextra \
	   -O2 -fno-rtti \
	   -fno-exceptions

# Linker flags
LDFLAGS=

# Libtaris
LIBS=\
	 -lstdc++ \
	 -lSDL2 \
	 -lSDL2_image

# Project source files
SOURCES=\
		src/application.cpp \
		src/application_events_impl.cpp \
		src/main.cpp \
		src/game/game.cpp \
		src/game/player.cpp \
		src/structs/events.cpp \
		src/structs/geometry.cpp \
		src/textures/size_manager.cpp \
		src/textures/texture_manager.cpp \
		src/ui/window.cpp \
		src/ui/window_impl.cpp

# Additional include path
INCLUDE=-I/usr/include/SDL2

OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@

.cpp.o:
	$(CC) $(INCLUDE) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS)
	rm $(EXECUTABLE)
