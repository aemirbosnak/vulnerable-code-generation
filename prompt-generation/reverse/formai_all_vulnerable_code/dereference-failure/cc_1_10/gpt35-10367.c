//FormAI DATASET v1.0 Category: File Synchronizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void syncFiles(char* file1, char* file2);

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: sync <file1> <file2>\n");
        return 0;
    }

    syncFiles(argv[1], argv[2]);

    return 0;
}

void syncFiles(char* file1, char* file2) {
    FILE *f1, *f2;
    long f1Size, f2Size;

    // Open file1 for reading and file2 for writing or create if it doesn't exist
    f1 = fopen(file1,"r");
    f2 = fopen(file2,"w+");
    
    // Get file1 size
    fseek(f1, 0, SEEK_END);
    f1Size = ftell(f1);
    rewind(f1);

    // Get file2 size
    fseek(f2, 0, SEEK_END); 
    f2Size = ftell(f2);
    rewind(f2);

    // If file1 is bigger write to file2
    if (f1Size > f2Size) {
        char* buffer = malloc(f1Size);
        fread(buffer, f1Size, 1, f1);
        fwrite(buffer, f1Size, 1, f2);
        free(buffer);
    }
    
    // If file2 is bigger write to file1
    if (f2Size > f1Size) {
        char* buffer = malloc(f2Size);
        fread(buffer, f2Size, 1, f2);
        fwrite(buffer, f2Size, 1, f1);
        free(buffer);
    }

    // Loop through files byte by byte and sync
    while (!feof(f1) && !feof(f2)) {
        char f1Byte = fgetc(f1);
        char f2Byte = fgetc(f2);

        if (f1Byte != f2Byte) {
            fseek(f1, ftell(f1)-1, SEEK_SET);
            fseek(f2, ftell(f2)-1, SEEK_SET);

            fputc(f1Byte, f2);
            fputc(f2Byte, f1);
        }
    }

    // Close files
    fclose(f1);
    fclose(f2);

    printf("Files synchronized.\n");
}