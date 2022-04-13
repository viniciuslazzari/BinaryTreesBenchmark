# Generated with: https://solver.assistedcoding.eu/makefilegen
#

OBJS	= src/ABP/main.o src/file/file.o src/AVL/main.o
OUT	= out/parafraseABP,out/parafraseAVL

OBJS0	= out/ABP/main.o out/file/file.o out/ABP/abp.o out/profiling/profiling.o
SOURCE0	= src/ABP/main.c src/file/file.c
HEADER0	= src/ABP/main.h src/file/file.h
OUT0	= out/parafraseABP

OBJS1	= out/AVL/main.o out/file/file.o out/profiling/profiling.o
SOURCE1	= src/AVL/main.c src/file/file.c
HEADER1	= src/AVL/main.h src/file/file.h
OUT1	= out/parafraseAVL

CC	 = gcc
FLAGS	 = -g3 -c -Wall
LFLAGS	 = 
# -g option enables debugging mode 
# -c flag generates object code for separate files


all: out/parafraseABP out/parafraseAVL

out/parafraseABP: $(OBJS0) $(LFLAGS)
	$(CC) -g $(OBJS0) -o $(OUT0)

out/parafraseAVL: $(OBJS1) $(LFLAGS)
	$(CC) -g $(OBJS1) -o $(OUT1)


# create/compile the individual files >>separately<<
out/ABP/main.o: src/ABP/main.c
	$(CC) $(FLAGS) src/ABP/main.c -o out/ABP/main.o

out/ABP/abp.o: src/ABP/abp.c
	$(CC) $(FLAGS) src/ABP/abp.c -o out/ABP/abp.o

out/file/file.o: src/file/file.c
	$(CC) $(FLAGS) src/file/file.c -o out/file/file.o 

out/profiling/profiling.o: src/profiling/profiling.c src/profiling/profiling.h
	$(CC) $(FLAGS) src/profiling/profiling.c -o out/profiling/profiling.o

out/AVL/main.o: src/AVL/main.c
	$(CC) $(FLAGS) src/AVL/main.c -o out/AVL/main.o


# clean house
clean:
	rm -f $(OBJS) $(OUT)

# run the program
runABP: $(OUT0)
	./$(OUT0)

runAVL: $(OUT1)
	./$(OUT1)

# compile program with debugging information
debugABP: $(OUT0)
	gdb $(OUT0)

debugAVL: $(OUT1)
	gdb $(OUT1)

# run program with valgrind for errors
valgrindABP: $(OUT0)
	valgrind $(OUT0)

valgrindAVL: $(OUT1)
	valgrind $(OUT1)

# run program with valgrind for leak checks
valgrind_leakcheckABP: $(OUT0)
	valgrind --leak-check=full $(OUT0)

valgrind_leakcheckAVL: $(OUT1)
	valgrind --leak-check=full $(OUT1)

# run program with valgrind for leak checks (extreme)
valgrind_extremeABP: $(OUT0)
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes $(OUT0)

valgrind_extremeAVL: $(OUT1)
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes $(OUT1)
