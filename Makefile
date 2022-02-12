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
		src/Application.cpp \
		src/ApplicationEventsImpl.cpp \
		src/main.cpp \
		src/game/Game.cpp \
		src/game/Player.cpp \
		src/structs/Events.cpp \
		src/structs/Geometry.cpp \
		src/textures/SizeManager.cpp \
		src/textures/TextureManager.cpp \
		src/ui/Window.cpp \
		src/ui/WindowImpl.cpp

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

