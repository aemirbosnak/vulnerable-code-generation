//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define EBOOK_TITLE "Ada Lovelace: The First Programmer"

typedef struct {
    char *text;
    int size;
} Ebook;

void read_ebook(Ebook *ebook) {
    FILE *file = fopen("ebook.txt", "r");
    if (file == NULL) {
        printf("Error: could not open ebook file.\n");
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    int line_count = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        ebook->text = realloc(ebook->text, ebook->size + strlen(line) + 1);
        strcat(ebook->text, line);
        ebook->size += strlen(line);
        line_count++;
    }

    fclose(file);
    printf("Read %d lines from ebook.\n", line_count);
}

void print_ebook(Ebook *ebook) {
    printf("Ebook Title: %s\n", EBOOK_TITLE);
    printf("Number of Lines: %d\n", ebook->size / 2); // assuming each line has 2 characters on average
    printf("Ebook Text:\n%s", ebook->text);
}

int main() {
    Ebook ebook;
    ebook.text = NULL;
    ebook.size = 0;

    read_ebook(&ebook);
    print_ebook(&ebook);

    free(ebook.text);
    return 0;
}