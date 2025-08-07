#COMPILER PREFIX, EMPTY BY DEFAULT. SETS TO EMPTY IF ITS NOT DEFINED
CROSS_COMPILE ?=

#COMPILER AND FLAGS
CC := $(CROSS_COMPILE)gcc #NATIVE : GCC, CROSS COMPILATION AARCH64-NONE-LINUX-GNU-GCC
CFLAGS := -Wall -Wextra -O2 #ENABLE WARNINGS, OPTIMIZE OUTPUT FOR SPEED


#CROSS COMPILER PATH FOR AARCH64
ifeq ($(CROSS_COMPILE),aarch64-none-linux-gnu-)
	#prepend cross compiler path
	export PATH := /home/raqui/Desktop/arm-gnu-toolchain-13.3.rel1-x86_64-aarch64-none-linux-gnu/bin/
endif

SRC := writer.c
	

OBJ := $(SRC:.c=.o)

TARGET := writer

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(TARGET) $(OBJ)
	

.PHONY: all clean


