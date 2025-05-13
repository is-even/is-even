CC = gcc
CFLAGS = -Iinclude
LFLAGS =
TARGET = is_even
SRCS = main.c
OBJECTS_DIR = objs
OBJECTS = $(SRCS:.c=.o)
OBJ_PATHS = $(addprefix $(OBJECTS_DIR)/, $(OBJECTS))


all: $(TARGET)

$(TARGET): $(OBJ_PATHS)
	$(CC) $(OBJ_PATHS) $(LFLAGS) -o $(TARGET)

$(OBJECTS_DIR)/%.o: %.c
	mkdir -p $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS_DIR) $(TARGET) $(TARGET).exe
