#include <stdlib.h>
#include <sys/timeb.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "library.h"

int main(int argc, char *argv[]){
    FILE *fp = fopen(argv[1], "r");
    long hist[26];
    int block_size = atoi(argv[2]);
    long milliseconds = 0;
    long filelen = 0;

    int ret = make_histogram(fp,hist,block_size,&milliseconds,&filelen);
    assert(! ret < 0);

//    printf("Computed the histogram in %d ms.\n", (int) milliseconds);
//    for(int i=0; i < 26; i++) {
//        printf("%c : %d\n", 'A' + i, (int) hist[i]);
//    }
//    printf("Data rate: %f Bps\n", (double)filelen/milliseconds * 1000);

    // To get the data in a spread shead friendly format uncomment the line below
    fprintf(stdout, "%d,", (int) (filelen/milliseconds * 1000));

    return 0;
}
