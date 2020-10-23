CC = gcc 
CFLAGS = -g -w -std=c99
TARGET = oss
TARGET1 = user
OBJS = oss.o
OBJS1 = user.o
LOG = logfile.txt
.SUFFIXES: .c .o

all : $(TARGET) $(TARGET1) 

$(TARGET1): $(OBJS1)
	$(CC) -o $@ $(OBJS1) -lpthread

$(TARGET): $(OBJS)
	$(CC)-o $@ $(OBJS) -lpthread -lm

.c.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *.log *~ *.txt $(LIB) $(TARGET) $(TARGET1) $(LOG) 

