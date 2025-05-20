//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Virus signature database
const char *signatures[] = {
    "4D 5A 90 00 03 00 00 00", // MZ header
    "E9 [0-9A-F]{4}",          // JMP instruction
    "40 E8 [0-9A-F]{4}",          // CALL instruction
    "8D 4C 24 [0-9A-F]{2}",          // LEA instruction
    "FF D0",                   // CALL instruction
    "55 8B EC",                   // PUSH EBP, MOV EBP, ESP
    "8B 45 08",                   // MOV EAX, [EBP+8]
    "8B 48 04",                   // MOV ECX, [EAX+4]
    "33 C9",                   // XOR ECX, ECX
    "89 C8",                   // MOV EAX, ECX
    "89 E3",                   // MOV EBX, EAX
    "89 C1",                   // MOV ECX, EAX
    "89 C3",                   // MOV EBX, EAX
    "89 C7",                   // MOV EDI, EAX
    "89 C6",                   // MOV ESI, EAX
    "89 C5",                   // MOV EBP, EAX
};

// Scan a file for virus signatures
int scan_file(const char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return -1;
    }

    // Read the file into a buffer
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buffer = malloc(file_size);
    if (!buffer) {
        perror("malloc");
        return -1;
    }
    fread(buffer, file_size, 1, fp);
    fclose(fp);

    // Scan the buffer for virus signatures
    int found = 0;
    for (int i = 0; i < sizeof(signatures) / sizeof(char *); i++) {
        const char *signature = signatures[i];
        char *match = strstr(buffer, signature);
        if (match) {
            found = 1;
            printf("Virus signature found: %s\n", signature);
        }
    }

    // Free the buffer
    free(buffer);

    return found;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    // Scan the file
    int found = scan_file(argv[1]);

    // Print the results
    if (found) {
        printf("File is infected!\n");
    } else {
        printf("File is clean.\n");
    }

    return 0;
}