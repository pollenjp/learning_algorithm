

CC = gcc


d1 : d_static_sushi.o
	./$< < sampleIn1
d2 : d_static_sushi.o
	./$< < sampleIn2
d3 : d_static_sushi.o
	./$< < sampleIn3
d4 : d_static_sushi.o
	./$< < sampleIn4
d_static_sushi.o : d_static_sushi.c
	$(CC) $< -o $@

