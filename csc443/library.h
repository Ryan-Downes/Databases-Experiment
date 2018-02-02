#include <stdlib.h>
#include <sys/timeb.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void random_array(char *array,long bytes);
int make_histogram(FILE *file_ptr, long hist[], int block_size, long *milliseconds, long *total_bytes_read);
