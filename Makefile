CC=g++
IDIR =include
CFLAGS=-I $(IDIR) 

ODIR=obj

SDIR=src

TDIR=tests

LIBS=-lm

_DEPS = matrix.hpp test_matrices.hpp general_operations.hpp transpose.hpp test_funcs.hpp strassen.hpp test_transpose.hpp test_strassen.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_SHAREDOBJ = matrix.o general_operations.o transpose.o strassen.o test_matrices.o 
SHAREDOBJ = $(patsubst %,$(ODIR)/%,$(_SHAREDOBJ))

_MAINOBJ = main.o 
MAINOBJ = $(patsubst %,$(ODIR)/%,$(_MAINOBJ))

_TESTOBJ = test.o test_funcs.o test_transpose.o test_strassen.o
TESTOBJ = $(patsubst %,$(ODIR)/%,$(_TESTOBJ))

obj/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

obj/%.o: $(TDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(SHAREDOBJ) $(MAINOBJ)
	$(CC) -o $(ODIR)/$@ $^ $(CFLAGS) $(LIBS) 

test: $(TESTOBJ) $(SHAREDOBJ)
	$(CC) -o $(ODIR)/$@ $^ $(CFLAGS) $(LIBS) 
.PHONY: clean

clean:
	rm -f $(ODIR)/* *~ core $(INCDIR)/*~ 