SRC_DIR=src
SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
OBJ_FILES=$(SRC_FILES:.c=.o)
LIB_NAME=libchem

test: $(LIB_NAME).a
	gcc test.c -L. -lchem -o test
	./test

$(LIB_NAME).a: $(OBJ_FILES)
	ar rcs $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o
	rm -f $(LIB_NAME).a
	rm -f test