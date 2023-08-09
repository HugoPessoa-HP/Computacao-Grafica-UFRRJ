INCLUDE_EIGEN	= -I/usr/include/eigen3
INCLUDE_OPENGL	= -I/usr/include/
INCLUDE_LOCAL	= -I.

LIB_OPENGL_DIR		= -L/usr/local/lib

LIBS_DIR				= $(LIB_OPENGL_DIR)

LIB_OPENGL		= $(LIBS_DIR) -lGL -lGLU -lglut

XLIBS=-lX11
LIBS+= $(LIB_OPENGL)
LIBS+=-lm

INCLUDE_DIR= $(INCLUDE_EIGEN) $(INCLUDE_OPENGL) $(INCLUDE_LOCAL)

ALL_BIN=       		trabalho01					\
			trabalho02					\
		 	trabalho03	


ALL_OBJ=		trabalho01.o						\
			trabalho02.o						\
			trabalho03.o			

ALL_TESTE=teste teste.o

.c.o:

	clang -o $@ -c $< $(INCLUDE_DIR)

.cpp.o:

	clang++ -o $@ -c $< $(INCLUDE_DIR)

all: $(ALL_BIN) $(ALL_OBJ)

trabalho01: trabalho01.o

	clang++ -o $@ $> $(INCLUDE_DIR) $(LIBS)

trabalho02: trabalho02.o

	clang++ -o $@ $> $(INCLUDE_DIR) $(LIBS)

trabalho03: trabalho03.o

	clang++ -o $@ $> $(INCLUDE_DIR) $(LIBS)

clean:

	@- rm -rf $(ALL_BIN)
	@- rm -rf $(ALL_OBJ)
	@- rm -rf $(ALL_TESTE)

teste.o: teste.cpp

	@- echo ">> teste.o teste.cpp <<"
	@- echo "@ = " $@
	@- echo "< = " $<
	@- echo "> = " $>
	@- touch teste.o

teste: teste.o

	@- echo ">> teste teste.o <<"
	@- echo "@ = " $@
	@- echo "< = " $<
	@- echo "> = " $>
	@- touch teste
