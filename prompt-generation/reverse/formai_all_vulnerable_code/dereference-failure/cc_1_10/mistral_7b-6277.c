//MISTRAL-7B DATASET v1.0 Category: Antivirus scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 101

typedef struct {
    char signature[32];
    char *description;
} VirusSignature;

VirusSignature signatures[TABLE_SIZE];

unsigned long hashFunction(char *str, int size) {
    unsigned long hash = 5381;
    int i;

    for (i = 0; i < size; i++)
        hash = ((hash << 5) + hash) + str[i];

    return hash % TABLE_SIZE;
}

void readSignatures() {
    FILE *file;
    char line[256];
    char signature[32];
    char *description;
    int i;

    file = fopen("signatures.txt", "r");

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%31s %s", signature, description);

        VirusSignature vs;
        strcpy(vs.signature, signature);
        vs.description = malloc(strlen(description) + 1);
        strcpy(vs.description, description);

        i = hashFunction(signature, strlen(signature));
        signatures[i] = vs;
    }

    fclose(file);
}

void scanFile(FILE *file) {
    char buffer[256];
    unsigned char byte;
    int i, j;

    while (fgets(buffer, sizeof(buffer), file)) {} // consume newline after last line

    rewind(file);

    while ((fread(&byte, sizeof(byte), 1, file)) > 0) {
        for (i = 0; i < TABLE_SIZE; i++) {
            if (signatures[i].description) continue; // skip occupied slots

            for (j = 0; j < strlen(signatures[i].signature); j++)
                if (signatures[i].signature[j] != byte) break;

            if (j == strlen(signatures[i].signature)) {
                printf("\nVirus '%s' detected in file '%s'.\n", signatures[i].description, "input.txt");
                free(signatures[i].description);
                signatures[i].description = NULL;
                goto end_scan;
            }
        }
    }

end_scan: {};
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    readSignatures();

    FILE *file = fopen(argv[1], "rb");

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    scanFile(file);

    fclose(file);

    return 0;
}