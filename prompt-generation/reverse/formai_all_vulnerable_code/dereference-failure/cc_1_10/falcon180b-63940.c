//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_VIRUS_LENGTH 100
#define MAX_FILE_NAME_LENGTH 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    FILE *file;
} File;

bool is_virus(char *virus) {
    char *needle = "virus";
    return strstr(virus, needle)!= NULL;
}

bool is_infected(File *file) {
    char buffer[MAX_VIRUS_LENGTH];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file->file))!= -1) {
        if (is_virus(line)) {
            printf("Virus found in file: %s\n", file->name);
            return true;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    File file = {0};

    file.name[0] = '\0';
    strncat(file.name, file_name, strlen(file_name) - 1);

    file.file = fopen(file.name, "r");

    if (file.file == NULL) {
        printf("Error opening file: %s\n", file.name);
        return 1;
    }

    if (is_infected(&file)) {
        fclose(file.file);
        return 1;
    }

    fclose(file.file);
    return 0;
}