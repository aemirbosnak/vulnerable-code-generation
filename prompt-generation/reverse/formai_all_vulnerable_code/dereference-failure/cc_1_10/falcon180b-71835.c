//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_LENGTH 1024
#define VIRUS_LENGTH 4

typedef struct virus {
    char virus[VIRUS_LENGTH];
    int count;
} Virus;

int is_virus(char *input, Virus *virus) {
    int i, j;
    for (i = 0; i < strlen(input) - VIRUS_LENGTH + 1; i++) {
        for (j = 0; j < VIRUS_LENGTH; j++) {
            if (toupper(input[i + j])!= toupper(virus->virus[j])) {
                break;
            }
        }
        if (j == VIRUS_LENGTH) {
            virus->count++;
        }
    }
    return virus->count;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    Virus virus = { "VIRUS", 0 };

    if (argc < 2) {
        printf("Usage: %s file\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((getline(&line, &len, file))!= -1) {
        int count = is_virus(line, &virus);
        if (count > 0) {
            printf("%s: %s found %d times\n", argv[1], virus.virus, count);
        }
    }

    free(line);
    fclose(file);

    return 0;
}