TARGET_LIB = libstk.so

CC 		= gcc
CFLAGS 	= -O3 -fPIC
DEBUG_CFLAGS = -Wall -Werror -pedantic -ggdb3 -Wno-error=unknown-pragmas -fPIC

SRC_DIRS 	= ./src
BUILD_DIR 	= ./build

SRCS = $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
HEADERS = $(shell find $(SRC_DIRS) -name *.h -or -name *.hh)
OBJS = $(SRCS:%=$(BUILD_DIR)/%.o)

INCLUDE_DIR=/usr/local/include/stk/
LIB_DIR=/usr/lib64/

# Program binary
$(BUILD_DIR)/$(TARGET_LIB): $(OBJS)
	$(CC) --shared $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)

ifdef DEBUG
	$(CC) $(DEBUG_CFLAGS) -c $< -o $@
else
	$(CC) $(CFLAGS) -c $< -o $@
endif

install: $(BUILD_DIR)/$(TARGET_LIB)

	mkdir -p $(INCLUDE_DIR)

	cp build/$(TARGET_LIB) $(DEST_DIR)/$(LIB_DIR)
	cp $(HEADERS) $(INCLUDE_DIR)

clean:
	$(RM) -rf $(BUILD_DIR)
