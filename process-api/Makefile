CC=gcc
CFLAGS=-Wall -Wextra -O2
PROGS=p1_fork p2_wait p3_exec p4_zombie p5_orphan p6_pipe

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGS)
