//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    size_t bytes_read1, bytes_read2;
    int cmp;

    if (argc!= 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(1);
    }

    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((bytes_read1 = fread(buffer1, 1, BUFFER_SIZE, fp1)) > 0) {
        bytes_read2 = fread(buffer2, 1, BUFFER_SIZE, fp2);
        if (bytes_read2 == 0) {
            printf("Files are not synchronized\n");
            exit(0);
        }

        cmp = memcmp(buffer1, buffer2, bytes_read1);
        if (cmp!= 0) {
            printf("Files are not synchronized\n");
            exit(0);
        }
    }

    if (ferror(fp1)!= 0 || ferror(fp2)!= 0) {
        printf("Error reading file\n");
        exit(1);
    }

    fclose(fp1);
    fclose(fp2);

    printf("Files are synchronized\n");

    return 0;
}