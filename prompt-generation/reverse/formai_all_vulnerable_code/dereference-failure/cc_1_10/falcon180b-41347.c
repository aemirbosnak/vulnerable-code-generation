//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define FILE_NAME "romantic_poem.txt"
#define VIRUS_NAME "unromantic_word"
#define MAX_LINE_LENGTH 1000
#define MAX_VIRUS_LENGTH 20

typedef struct {
    char *name;
    size_t length;
} Virus;

Virus *new_virus(const char *name) {
    Virus *virus = malloc(sizeof(Virus));
    virus->name = strdup(name);
    virus->length = strlen(name);
    return virus;
}

bool is_virus(const char *line, Virus *virus) {
    size_t i;
    for (i = 0; i < strlen(line) && i < virus->length; i++) {
        if (tolower(line[i])!= tolower(virus->name[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    Virus *virus = new_virus(VIRUS_NAME);

    file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", FILE_NAME);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (is_virus(line, virus)) {
            printf("Virus found on line %zu: %s\n", ftell(file) - strlen(line) + 1, line);
        }
    }

    fclose(file);
    free(virus->name);
    free(virus);
    return 0;
}