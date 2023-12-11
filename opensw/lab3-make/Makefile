
PROJ_DIR = $(PWD)
SRC_DIR = $(PROJ_DIR)/src
INCLUDE_DIR = $(PROJ_DIR)/include
BIN_DIR = $(PROJ_DIR)/bin
OBJ_DIR = $(PROJ_DIR)/obj
LIB_DIR = $(PROJ_DIR)/lib

OBJS = $(addprefix $(OBJ_DIR)/, func1.o func2.o)
LIB_FUNC = funcs

all: $(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(SRC_DIR)/main.c $(LIB_DIR)/lib$(LIB_FUNC).a
	gcc $< -L./lib -l$(LIB_FUNC) -o $@ -I$(INCLUDE_DIR)

$(LIB_DIR)/lib$(LIB_FUNC).a: $(OBJS)
	ar rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $< -o $@ -I$(INCLUDE_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(BIN_DIR)/*
	rm -f $(LIB_DIR)/*

# 	gcc -o $@ $^

# @echo $< # 첫번째 인자 / 앞의 골뱅이는 해당 라인 출력X 실행만 함
# @echo $@ # 타겟
# @echo $^ # 모든 인자

# ./obj/func1.o: ./src/func1.c
# 	gcc -c ./src/func1.c -o ./obj/func1.o -I./include
# ./obj/func2.o: ./src/func2.c
# 	gcc -c ./src/func2.c -o ./obj/func2.o -I./include
# ./obj/main.o: ./src/main.c
# 	gcc -c ./src/main.c -o ./obj/main.o -I./include