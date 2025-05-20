//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VIRUS_SIGNATURE_LENGTH 8
#define FILE_BUFFER_SIZE 1024

typedef struct {
    char *name;
    FILE *file;
    unsigned char signature[VIRUS_SIGNATURE_LENGTH];
} FileInfo;

int is_infected(unsigned char *buffer, unsigned char *signature) {
    int i;
    for (i = 0; i < VIRUS_SIGNATURE_LENGTH; i++) {
        if (buffer[i]!= signature[i]) {
            return 0;
        }
    }
    return 1;
}

void scan_file(char *filename, unsigned char *signature) {
    FILE *file;
    char buffer[FILE_BUFFER_SIZE];
    int bytes_read;
    int infected = 0;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    while ((bytes_read = fread(buffer, 1, FILE_BUFFER_SIZE, file)) > 0) {
        infected = is_infected(buffer, signature);
        if (infected) {
            printf("Virus detected in file: %s\n", filename);
            break;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <virus_signature>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    unsigned char signature[VIRUS_SIGNATURE_LENGTH];
    int i;

    for (i = 0; i < strlen(argv[2]); i++) {
        signature[i] = argv[2][i];
    }

    scan_file(filename, signature);

    return 0;
}