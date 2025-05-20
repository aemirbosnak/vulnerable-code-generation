//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100

// Sherlock Holmes' Ebook Reader

typedef struct {
    char *title;
    char *author;
    char *text;
    int length;
} Ebook;

void load_ebook(Ebook *ebook, FILE *file) {
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    ebook->title = NULL;
    ebook->author = NULL;
    ebook->text = NULL;
    ebook->length = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (line[0] == '*') {
            if (ebook->title == NULL) {
                ebook->title = strdup(line + 1);
            } else if (ebook->author == NULL) {
                ebook->author = strdup(line + 1);
            }
        } else {
            strcat(ebook->text, line);
            ebook->length += strlen(line);
        }
    }
}

void display_ebook(Ebook *ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Length: %d words\n\n", ebook->length);
    printf("%s", ebook->text);
}

int main() {
    Ebook ebook;
    FILE *file;

    file = fopen("sherlock_holmes.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    load_ebook(&ebook, file);
    fclose(file);

    display_ebook(&ebook);

    free(ebook.title);
    free(ebook.author);
    free(ebook.text);

    return 0;
}