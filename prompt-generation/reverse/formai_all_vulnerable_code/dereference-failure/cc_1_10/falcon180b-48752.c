//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000 // 1 MB
#define VIRUS_SIGNATURES_NUM 3

typedef struct {
    char *filename;
    char *signature;
} virus_signature;

void scan_file(FILE *file, virus_signature signatures[]) {
    char buffer[MAX_FILE_SIZE];
    int buffer_index = 0;

    while (fread(buffer + buffer_index, sizeof(char), 1, file)!= 0) {
        buffer_index++;

        if (buffer_index == MAX_FILE_SIZE) {
            printf("File too large to scan.\n");
            exit(1);
        }
    }

    buffer[buffer_index] = '\0';

    for (int i = 0; i < VIRUS_SIGNATURES_NUM; i++) {
        char *substring = strstr(buffer, signatures[i].signature);

        while (substring!= NULL) {
            printf("Virus found in file %s: %s\n", signatures[i].filename, buffer);
            exit(1);
        }
    }

    printf("File %s is clean.\n", file);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    virus_signature signatures[] = {
        {"eicar.com", "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"},
        {"test.txt", "This is a test file."},
        {"example.exe", "MZ"}
    };

    scan_file(file, signatures);

    fclose(file);

    return 0;
}