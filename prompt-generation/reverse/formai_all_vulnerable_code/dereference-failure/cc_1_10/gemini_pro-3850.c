//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Retro-style virus signature database
char *virus_signatures[] = {
    "0x55, 0x68, 0x72, 0x65, 0x61, 0x00",
    "0x69, 0x72, 0x75, 0x73, 0x00",
    "0x49, 0x20, 0x61, 0x6d, 0x20",
    "0x72, 0x65, 0x74, 0x72, 0x6f, 0x00",
    "0x49, 0x20, 0x61, 0x6d, 0x20",
    "0x73, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x00"
};

// Retro-style memory scanner
int scan_memory(unsigned char *memory, size_t size) {
    int i, j;

    for (i = 0; i < size - 5; i++) {
        for (j = 0; j < sizeof(virus_signatures) / sizeof(char *); j++) {
            if (memcmp(&memory[i], virus_signatures[j], strlen(virus_signatures[j])) == 0) {
                return i;
            }
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL) {
        printf("Error: Could not open file \"%s\".\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    unsigned char *memory = malloc(size);

    if (memory == NULL) {
        printf("Error: Could not allocate memory for file.\n");
        fclose(file);
        return 1;
    }

    fread(memory, size, 1, file);
    fclose(file);

    int offset = scan_memory(memory, size);

    free(memory);

    if (offset == -1) {
        printf("No viruses found in file \"%s\".\n", argv[1]);
    } else {
        printf("Virus found in file \"%s\" at offset 0x%08X.\n", argv[1], offset);
    }

    return 0;
}