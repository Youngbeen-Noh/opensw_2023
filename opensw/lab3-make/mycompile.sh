gcc -c src/func1.c -I./include -o obj/func1.o
gcc -c src/func2.c -I./include -o obj/func2.o
gcc -c src/main.c -I./include -o obj/main.o
gcc -o bin/myapp obj/func1.o obj/func2.o obj/main.o