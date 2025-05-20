//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_SIGNATURES 100
#define MAX_FILE_SIZE 1000000 // 1 MB

typedef struct {
    char *signature;
    int signature_length;
} VirusSignature;

VirusSignature virus_signatures[MAX_VIRUS_SIGNATURES] = {
    {"EICAR-Test-File", 64},
    {"Win32.Worm.Zhelatin", 32},
    {"Win32.Sality", 32},
    {"Win32.Nimda", 32},
    {"Win32.Mydoom", 32},
    {"Win32.Sasser", 32},
    {"Win32.Stration", 32},
    {"Win32.Virut", 32},
    {"Win32.Brontok", 32},
    {"Win32.Rbot", 32}
};

int num_virus_signatures = sizeof(virus_signatures) / sizeof(VirusSignature);

void scan_file(const char *filename) {
    FILE *file;
    char buffer[MAX_FILE_SIZE];
    int file_size;
    int i;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File %s is too large (%d bytes)\n", filename, file_size);
        fclose(file);
        return;
    }

    rewind(file);
    while (fread(buffer, 1, MAX_FILE_SIZE, file) > 0) {
        for (i = 0; i < num_virus_signatures; i++) {
            if (memmem(buffer, file_size, virus_signatures[i].signature, virus_signatures[i].signature_length)!= NULL) {
                printf("Virus found: %s\n", virus_signatures[i].signature);
                return;
            }
        }
    }

    fclose(file);
    printf("File %s is clean\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    scan_file(argv[1]);
    return 0;
}