//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1024
#define MAX_VIRUS_NAMES 10
#define MAX_VIRUS_LENGTH 50

char *virus_names[MAX_VIRUS_NAMES] = {"MyDoom", "Sasser", "Conficker", "Stuxnet", "WannaCry", "Petya", "NotPetya", "Locky", "Cryptolocker", "Emotet"};
int num_viruses = sizeof(virus_names) / sizeof(virus_names[0]);

char *scan_file(FILE *file, char *buffer, int *buffer_size) {
    int c;
    int i = 0;

    while ((c = fgetc(file))!= EOF) {
        if (i >= *buffer_size - 1) {
            *buffer_size += MAX_STRING_LENGTH;
            buffer = realloc(buffer, *buffer_size);
        }

        if (isprint(c)) {
            buffer[i++] = tolower(c);
        }
    }

    buffer[i] = '\0';

    return buffer;
}

int is_virus(char *buffer, int buffer_size) {
    int i;

    for (i = 0; i < num_viruses; i++) {
        if (strstr(buffer, virus_names[i])!= NULL) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *buffer = NULL;
    int buffer_size = 0;

    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    buffer = scan_file(file, buffer, &buffer_size);

    if (is_virus(buffer, buffer_size)) {
        printf("Virus detected: %s\n", argv[1]);
    } else {
        printf("No virus detected in %s\n", argv[1]);
    }

    free(buffer);
    fclose(file);

    return 0;
}