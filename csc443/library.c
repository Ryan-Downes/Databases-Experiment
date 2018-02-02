#include <stdlib.h>
#include <sys/timeb.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/**
 * populate a random array (which is already
 * allocated with enough memory to hold n bytes
 * with random characters from A to Z.
 */
void random_array(char *array,long bytes){

    int i;
    for (i = 0; i < bytes;i++){
        array[i] = 'A' + ( rand() % 26 );
    }
}

     /**
      * file_ptr : the file pointer, ready to be read from.
      * hist: an array to hold 26 long integers.  hist[0] is the
      *       number of 'A', and hist[1] is the number of 'B', etc.
      * block_size: the buffer size to be used.
      * milliseconds: time it took to complete the file scan
      * total_bytes_read: the amount data in bytes read
      *
      * returns: -1 if there is an error.
      */
int make_histogram(
                 FILE *file_ptr, long hist[], int block_size, long *milliseconds, long *total_bytes_read){
     if(file_ptr == NULL){
         fprintf(stdout,"file is not ready to be read from");
         exit(-1);
     }
     char* buffer = (char*)malloc(sizeof(char) * block_size);
     int j;
     for(j = 0; j < 26; j = j + 1){
         hist[j] = 0;
     }
     struct timeb t;
     ftime(&t);
     long start_in_ms = t.time * 1000 + t.millitm;
     int i = 0;
     int index;
     long numread = 0;
     long bytes_read = 0;
     while((numread = fread(buffer,sizeof(char), block_size, file_ptr) )){
         i = 0;
         if( numread == 0){
            break;
         }
         while ( i < numread){

             index = buffer[i] - 'A';

             hist[index] += 1;
             i = i + 1;
             }
         bytes_read += numread;


         }

     ftime (&t);

     long end_in_ms =t.time * 1000 + t.millitm;

     long time_taken = end_in_ms - start_in_ms;
     *total_bytes_read = bytes_read;
     *milliseconds = time_taken;
     return 0;
 }





