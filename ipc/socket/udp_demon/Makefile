CC:=gcc
CFLAGS:=-Wall -O2
LDFLAGS:= 

.PHONY: all clean

all:server client

server:server.o
	$(CC) -o $@ $^ $(LDFLAGS)
client:client.o
	$(CC) -o $@ $^ $(LDFLAGS)

%*.o:%*.c
	$(CC) -o $@ $^  $(CFLAGS)

clean:
	-rm *.o server client


