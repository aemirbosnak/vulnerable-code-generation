//FormAI DATASET v1.0 Category: Data recovery tool ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *infile, *outfile;
    char buffer[BLOCK_SIZE];
    char filename[256];
    int count = 0, size = 0, blocks = 0;
    int i, j;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    infile = fopen(argv[1], "rb");
    if (infile == NULL) {
        printf("Error: Cannot open file '%s'\n", argv[1]);
        return 1;
    }

    while (fread(buffer, BLOCK_SIZE, 1, infile) == 1) {
        if (memcmp(buffer, "DATA", 4) == 0) {
            count++;
            memset(filename, 0, 256);
            memcpy(filename, &buffer[4], strlen((char*)&buffer[4]));
            outfile = fopen(filename, "wb");
            if (outfile == NULL) {
                printf("Error: Cannot create file '%s'\n", filename);
                return 1;
            }
            printf("Recovering file: %s\n", filename);
        } else if (count > 0) {
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
            size += BLOCK_SIZE;
            blocks++;
        }
    }

    printf("Total blocks recovered: %d\n", blocks);
    printf("Total size recovered: %d bytes\n", size);

    fclose(infile);
    fclose(outfile);

    return 0;
}