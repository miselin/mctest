CFLAGS += -I.

OBJS = example.o mctest.o

example: $(OBJS)

clean:
	rm -f $(OBJS) example


