CC=gcc
BDIR=bin
ODIR=obj
build_obj_folder := $(shell mkdir -p $(ODIR))
build_bin_folder := $(shell mkdir -p $(BDIR))


euler1: $(ODIR)/main.o
	$(CC) -o $(BDIR)/euler1 $(ODIR)/main.o


$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(ODIR)/*.o $(BDIR)/*
