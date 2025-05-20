//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024
#define MAX_LINE_LENGTH 1024

// Generate a random file name
char *generate_random_file_name() {
    char name[50];
    srand(time(NULL));
    int i;

    for (i = 0; i < 50; i++) {
        name[i] = 'a' + (rand() % 26);
    }

    return name;
}

// Read a random line from a file
char *read_random_line(char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file);
    fclose(file);

    return line;
}

int main() {
    char *file_name = generate_random_file_name();
    char *line = read_random_line(file_name);

    if (line == NULL) {
        printf("Failed to read line from %s\n", file_name);
        return 1;
    }

    printf("Random line from %s: %s\n", file_name, line);

    free(line);
    free(file_name);

    return 0;
}