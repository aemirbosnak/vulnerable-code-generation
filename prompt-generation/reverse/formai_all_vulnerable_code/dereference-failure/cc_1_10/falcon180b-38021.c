//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[MAX_SIZE];
    strcpy(filename, argv[1]);

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    char *buffer = (char *) malloc(filesize);
    if (buffer == NULL) {
        printf("Error: Could not allocate memory for file buffer.\n");
        fclose(fp);
        return 1;
    }

    fread(buffer, 1, filesize, fp);
    fclose(fp);

    unsigned int checksum = 0;
    for (int i = 0; i < filesize; i++) {
        char c = tolower(buffer[i]);
        if (isalpha(c)) {
            checksum += (c - 'a' + 1) * i;
        }
    }

    printf("Checksum: %d\n", checksum);

    free(buffer);
    return 0;
}