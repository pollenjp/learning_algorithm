

CC = gcc


d1 : d_static_sushi.o
	./$< < ../data/sampleIn1
d2 : d_static_sushi.o
	./$< < ../data/sampleIn2
d3 : d_static_sushi.o
	./$< < ../data/sampleIn3
d4 : d_static_sushi.o
	./$< < ../data/sampleIn4
d_static_sushi.o : d_static_sushi.c
	$(CC) $< -o $@

clean :
	rm *.o
	rm *.out
