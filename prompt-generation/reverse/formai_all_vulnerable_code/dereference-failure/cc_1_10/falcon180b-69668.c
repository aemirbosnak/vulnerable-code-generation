//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int num_lines;
} Ebook;

void read_ebook(Ebook *ebook, FILE *fp) {
    char line[MAX_LINE_SIZE];
    ebook->num_lines = 0;
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        ebook->line = realloc(ebook->line, ebook->num_lines * sizeof(char *));
        ebook->line[ebook->num_lines - 1] = strdup(line);
        ebook->num_lines++;
    }
}

void print_ebook(Ebook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        printf("%s\n", ebook->line[i]);
    }
}

void free_ebook(Ebook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        free(ebook->line[i]);
    }
    free(ebook->line);
    ebook->num_lines = 0;
}

int main() {
    Ebook ebook;
    FILE *fp;

    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    read_ebook(&ebook, fp);
    print_ebook(&ebook);

    free_ebook(&ebook);
    fclose(fp);

    return 0;
}