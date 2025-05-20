//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sherlock's magnifying glass - a file scanner
void scanFile(char *filename, char *signature) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return;
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        if (strstr(buffer, signature)) {
            printf("Found %s in %s\n", signature, filename);
        }
    }

    fclose(file);
}

// Watson's assistant - a file recoverer
void recoverFile(char *filename, char *signature, char *recoveredFile) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return;
    }

    FILE *recovered = fopen(recoveredFile, "wb");
    if (!recovered) {
        printf("Could not open file %s\n", recoveredFile);
        return;
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        if (strstr(buffer, signature)) {
            fwrite(buffer, 1, bytesRead, recovered);
        }
    }

    fclose(file);
    fclose(recovered);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <filename> <signature> <recoveredFile>\n", argv[0]);
        return 1;
    }

    scanFile(argv[1], argv[2]);
    recoverFile(argv[1], argv[2], argv[3]);

    printf("Elementary, my dear Watson!\n");
    return 0;
}