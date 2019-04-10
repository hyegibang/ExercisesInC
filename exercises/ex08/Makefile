ex_compile: ex_compile.c
	gcc ex_compile.c -Wall -o ex_compile `pkg-config --cflags --libs glib-2.0` ex_compile

word_count: word_count.c
	gcc `pkg-config --cflags glib-2.0` word_count.c `pkg-config --libs glib-2.0` -o word_count.o
