//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 100

typedef struct {
    char *text;
    int length;
} Line;

void generate_lines(Line lines[], int num_lines) {
    FILE *file = fopen("romeo_and_juliet.txt", "r");
    if (!file) {
        fprintf(stderr, "Error: could not open file.\n");
        exit(1);
    }

    for (int i = 0; i < num_lines; i++) {
        fseek(file, rand() % (int)ftell(file), SEEK_SET);
        char buffer[MAX_LINE_LENGTH];
        fgets(buffer, MAX_LINE_LENGTH, file);
        lines[i].text = strdup(buffer);
        lines[i].length = strlen(buffer);
    }

    fclose(file);
}

void print_lines(Line lines[], int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i].text);
    }
}

void free_lines(Line lines[], int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }
}

int main() {
    srand(time(NULL));

    int num_lines = rand() % MAX_NUM_LINES + 1;
    Line lines[num_lines];

    generate_lines(lines, num_lines);
    print_lines(lines, num_lines);

    free_lines(lines, num_lines);

    return 0;
}