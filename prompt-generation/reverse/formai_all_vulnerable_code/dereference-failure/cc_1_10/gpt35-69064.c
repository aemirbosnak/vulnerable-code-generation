//FormAI DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000

char* read_file(const char* file_name) {
    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char* content = malloc(MAX_CHARS + 1);
    int index = 0;
    char c;

    while ((c = fgetc(file)) != EOF && index < MAX_CHARS) {
        content[index++] = c;
    }

    content[index] = '\0';
    fclose(file);
    return content;
}

int count_words(const char* text) {
    int count = 0;
    int in_word = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] != ' ' && text[i] != '\t' && text[i] != '\n') {
            if (!in_word) {
                in_word = 1;
                count++;
            }
        } else {
            in_word = 0;
        }
    }

    return count;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./program [file_path]\n");
        return 1;
    }

    char* content = read_file(argv[1]);

    if (content == NULL) {
        return 1;
    }

    int count = count_words(content);
    printf("The text has %d words\n", count);
    free(content);
    return 0;
}