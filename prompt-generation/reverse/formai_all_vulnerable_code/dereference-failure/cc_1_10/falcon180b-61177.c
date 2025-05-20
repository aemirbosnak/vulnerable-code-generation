//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VIRUS_LENGTH 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char *name;
    char *signature;
    int length;
} Virus;

Virus viruses[] = {
    {"Dummy Virus", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26},
    {"Trojan Horse", "DEFGHIJKLMNOPQRSTUVWXYZABC", 26},
    {"Worm", "BCDFGHJKLMNPQRSTVWXYZ", 21}
};

int num_viruses = sizeof(viruses) / sizeof(Virus);

int is_virus(FILE *file, Virus *virus) {
    char buffer[MAX_VIRUS_LENGTH];
    int i, j;

    rewind(file);
    fseek(file, 0, SEEK_SET);

    while (fgets(buffer, MAX_VIRUS_LENGTH, file)!= NULL) {
        for (i = 0; i < virus->length; i++) {
            if (tolower(buffer[i])!= tolower(virus->signature[i])) {
                break;
            }
        }

        if (i == virus->length) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int file_size = 0;
    char *buffer = NULL;
    int virus_found = 0;

    while ((fread(&buffer[file_size], 1, 1, file))!= 0) {
        file_size++;
    }

    if (file_size > MAX_FILE_SIZE) {
        printf("File is too large.\n");
        fclose(file);
        return 1;
    }

    buffer = malloc(file_size + 1);

    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    rewind(file);
    fread(buffer, file_size, 1, file);
    buffer[file_size] = '\0';

    for (int i = 0; i < num_viruses; i++) {
        if (is_virus(file, &viruses[i])) {
            printf("Virus found: %s\n", viruses[i].name);
            virus_found = 1;
        }
    }

    if (!virus_found) {
        printf("No viruses found.\n");
    }

    fclose(file);
    free(buffer);

    return 0;
}