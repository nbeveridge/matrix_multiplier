IDIR =include
CC=g++
CFLAGS=-I $(IDIR) 

ODIR=obj

SDIR=src

LIBS=-lm

_DEPS = matrix.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o matrix.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


obj/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $(ODIR)/$@ $^ $(CFLAGS) -I ${BLAS_INC} -L ${BLAS_LIB} $(LIBS) -lopenblas

.PHONY: clean

clean:
	rm -f $(ODIR)/* *~ core $(INCDIR)/*~ 