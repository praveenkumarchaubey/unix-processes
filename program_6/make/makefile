#path
bin=../bin/
obj=../obj/
inc=../include/
src=../source/
#process
$(bin)final:$(obj)main.o
	gcc -o final $(obj)main.o
	mv final $(bin)
$(obj)main.o:$(src)main.c $(inc)header.h
	gcc -c -g $(src)main.c -I./$(inc)
	mv main.o $(obj)

