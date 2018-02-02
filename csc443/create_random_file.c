#include <stdlib.h>
#include <sys/timeb.h>
#include <stdio.h>
#include <string.h>
#include "library.h"

/**
 * argv[] should be formated <filename> <total bytes> <block size>
 */
 int main(int argc, char *argv[]){
    if (argc < 3){
        fprintf(stderr, "more arguments required");
        exit(EXIT_FAILURE);
    }

    int total_bytes = atoi(argv[2]);
    int blocksize = atoi(argv[3]);
    char *buf= malloc(sizeof(char) * blocksize);
    FILE *fp = fopen(argv[1], "w");

    if (fp == NULL){
        fprintf(stderr, "can not open file");
        exit(EXIT_FAILURE);
    }
    struct timeb t;
    ftime(&t);
    long start_in_ms = t.time * 1000 + t.millitm;
    int bytes_written = 0;

    while(bytes_written < total_bytes){

        if (total_bytes - bytes_written < blocksize){

            long btw = total_bytes - bytes_written;
            random_array(buf,btw);

            fwrite(buf, 1,btw , fp);
            fflush(fp);

            bytes_written += btw;

        }
        else{

            random_array(buf, blocksize);

            fwrite(buf, 1, blocksize, fp);
            fflush(fp);


            bytes_written += blocksize;
        }
    }
    ftime (&t);
    long end_in_ms =t.time * 1000 + t.millitm;
    long time_taken = end_in_ms - start_in_ms;

    free(buf);
    fclose(fp);

    // To get the data in a spread shead friendly format uncomment the line below
    //fprintf(stdout, "%d,", (int) time_taken * 1000);

    return (0);
}