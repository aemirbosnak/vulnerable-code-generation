//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB
#define VIRUS_SIGNATURE "This is a virus!"

int is_infected(FILE *file) {
    char buffer[MAX_FILE_SIZE];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file))!= -1) {
        if (strstr(line, VIRUS_SIGNATURE)!= NULL) {
            free(line);
            return 1;
        }
        free(line);
        line = NULL;
        len = 0;
    }

    if (line!= NULL) {
        free(line);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int is_infected_result = is_infected(file);

    if (is_infected_result == 0) {
        printf("The file is not infected.\n");
    } else {
        printf("The file is infected with a virus.\n");
    }

    fclose(file);
    return 0;
}