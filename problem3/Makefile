CC=gcc
CFLAGS=-std=c99 -O2
BDIR=bin
ODIR=obj
build_obj_folder := $(shell mkdir -p $(ODIR))
build_bin_folder := $(shell mkdir -p $(BDIR))


$(BDIR)/euler3: $(ODIR)/main.o
	$(CC) -o $(BDIR)/euler3 $(ODIR)/main.o


$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(ODIR)/*.o $(BDIR)/*

realclean:
	rm -rf $(ODIR) $(BDIR)
