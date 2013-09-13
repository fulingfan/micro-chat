# Makefile for 'micor-chat utility'
# date: 2013/6/15
# author:zhangyun
# complie by gcc 4.8.0
# version: 0.1

# @mysql_config --libs (to display requried option of library)
# @mysql_config --cflags ( this option can find include file and critical compiler flags
# and defines used when compiling the libmysqclient library)

OBJ = manipulate_db.o  dameon.o error_functions.o  get_num.o inet_sockets.o userinfo.o usage.o \
	client.o server.o
LIB = dameon.h manipulate_db.h echo.h ename.c.inc get_num.h usage.h userinfo.h tlpi_hdr.h inet_sockets.h \
      error_functions.h

MYSQL_LIB = `mysql_config --libs`
MYSQL_CFLAGS = `mysql_config --cflags`
FLAGS = -g -o -Wall

client : $(OBJ)
	cc -o  client client.o $(MYSQL_LIB)
server : $(OBJ)
	cc -o  server server.o $(MYSQL_LIB) 
anipulate_db.o : $(LIB)
	cc $(MYSQL_CFLAGS) $(FLAGS)   -O  manipulate_db.o  -c manipulate_db.c
#error_functions.o : $(LIB)
#	cc $(FLAGS) error_functions.o  -c error_functions.c
get_num.o : $(LIB)
	cc $(FLAGS) get_num.o -c get_num.c
inet_sockets.o : $(LIB)
	cc $(FLAGS) inet_sockets.o -c inet_sockets.c
userinfo.o : $(LIB)
	cc $(FLAGS) $(MYSQL_CFLAGS) userinfo.o -c userinfo.c
usage.o : $(LIB) 
	cc $(FLAGS) usage.o -c usage.c
dameon.o : $(LIB)
	cc $(FLAGS) dameon.o -c dameon.c
client.o : $(LIB))
	cc $(FLAGS) $(MYSQL_CFLAGS) client.o -c client.c
server.o : $(LIB)
	cc $(FLAGS) $(MYSQL_CFLAGS) server.o -c server.c
.PHONY: clean
clean:
	-rm $(OBJ) micro-chat
