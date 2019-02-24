#ld helloworld executable when user executes "make"
meshclient:main.o inform_get.o command.o util.o send.o receive.o
	$(CC) $(LDFLAGS) main.o inform_get.o command.o util.o send.o receive.o -o meshclient
main.o:main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
inform_get.o:inform_get.c
	$(CC) $(CFLAGS) -c inform_get.c -o inform_get.o
command.o:command.c
	$(CC) $(CFLAGS) -c command.c -o command.o
util.o:util.c
	$(CC) $(CFLAGS) -c util.c -o util.o
send.o:send.c
	$(CC) $(CFLAGS) -c send.c -o send.o
receive.o:receive.c
	$(CC) $(CFLAGS) -c receive.c -o receive.o
# remove object files and executable when user executes "make clean"
