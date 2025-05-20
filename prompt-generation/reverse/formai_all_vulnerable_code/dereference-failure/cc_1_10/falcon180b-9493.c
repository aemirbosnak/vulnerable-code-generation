//Falcon-180B DATASET v1.0 Category: Text processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char *text;
    int length;
} Text;

void initialize_text(Text *text) {
    text->text = NULL;
    text->length = 0;
}

void append_to_text(Text *text, char *new_text) {
    int new_length = strlen(new_text);
    int old_length = text->length;
    char *new_buffer = (char*) malloc(old_length + new_length + 1);

    if (new_buffer == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    strcpy(new_buffer, text->text);
    strcat(new_buffer, new_text);

    free(text->text);
    text->text = new_buffer;
    text->length += new_length;
}

void print_text(Text *text) {
    printf("%s", text->text);
}

int main() {
    FILE *input_file;
    Text input_text;

    initialize_text(&input_text);

    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        append_to_text(&input_text, line);
    }

    fclose(input_file);

    print_text(&input_text);

    return 0;
}