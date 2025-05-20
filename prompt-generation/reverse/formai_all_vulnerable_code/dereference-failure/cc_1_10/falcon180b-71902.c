//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_PARAGRAPH_LENGTH 5000

typedef struct {
    char *text;
    int length;
} Paragraph;

Paragraph *read_paragraph(FILE *file) {
    char buffer[MAX_SENTENCE_LENGTH];
    Paragraph *paragraph = malloc(sizeof(Paragraph));
    paragraph->text = malloc(MAX_PARAGRAPH_LENGTH * sizeof(char));
    paragraph->length = 0;

    while(fgets(buffer, MAX_SENTENCE_LENGTH, file)!= NULL) {
        int sentence_length = strlen(buffer);
        if(sentence_length > 0 && buffer[sentence_length - 1] == '\n') {
            buffer[sentence_length - 1] = '\0';
            sentence_length--;
        }
        strcat(paragraph->text, buffer);
        paragraph->length += sentence_length;

        if(paragraph->length >= MAX_PARAGRAPH_LENGTH) {
            break;
        }
    }

    return paragraph;
}

void print_paragraph(Paragraph *paragraph) {
    printf("%s", paragraph->text);
}

int main() {
    FILE *file;
    file = fopen("example.txt", "r");
    if(file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    Paragraph *paragraph;
    while((paragraph = read_paragraph(file))!= NULL) {
        print_paragraph(paragraph);
        printf("\n");
    }

    fclose(file);
    return 0;
}