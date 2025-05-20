//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_SIZE (1024*1024*10) // 10 MB

typedef struct {
    char *name;
    char *signature;
    int length;
} virus_t;

virus_t viruses[] = {
    {"W32.SillyFDC", "FDCCBFCD", 0},
    {"W32.Stration", "E8FBC9F057", 0},
    {"W32.Sality.OG", "9D2C1B0C3D5", 0},
    {"W32.Virut.CF", "CDB6B398", 0},
    {"W32.Zbot", "E9D71A3D", 0}
};

int num_viruses = sizeof(viruses) / sizeof(virus_t);

bool is_virus(char *data, int size, virus_t *virus) {
    if (size < virus->length) {
        return false;
    }

    char *signature = malloc(virus->length);
    memset(signature, 0, virus->length);

    for (int i = 0; i < virus->length; i++) {
        signature[i] = tolower(data[i]);
    }

    if (strcmp(signature, virus->signature) == 0) {
        printf("Found virus: %s\n", virus->name);
        return true;
    }

    free(signature);
    return false;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    if (size > MAX_FILE_SIZE) {
        printf("File is too large.\n");
        fclose(file);
        return 1;
    }

    rewind(file);
    char *data = malloc(size);
    fread(data, size, 1, file);
    fclose(file);

    for (int i = 0; i < num_viruses; i++) {
        if (is_virus(data, size, &viruses[i])) {
            return 1;
        }
    }

    printf("No viruses found.\n");
    free(data);
    return 0;
}