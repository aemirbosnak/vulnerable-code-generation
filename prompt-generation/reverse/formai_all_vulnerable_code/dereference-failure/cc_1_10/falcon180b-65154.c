//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_WORD_COUNT 1000

// Romeo and Juliet word count
int romeo_count = 0;
int juliet_count = 0;

char *words[MAX_WORD_COUNT];
int word_count = 0;

void process_word(char *word) {
    if (strcmp(word, "Romeo") == 0) {
        romeo_count++;
    } else if (strcmp(word, "Juliet") == 0) {
        juliet_count++;
    } else {
        int i;
        for (i = 0; i < word_count; i++) {
            if (strcmp(words[i], word) == 0) {
                break;
            }
        }
        if (i == word_count) {
            words[word_count++] = strdup(word);
        }
    }
}

int main(int argc, char **argv) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *word;
    int in_word = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int line_length = strlen(line);
        char *p = line;
        while ((word = strtok_r(p, " \t\r\n\f", &p))!= NULL) {
            int word_length = strlen(word);
            if (word_length > MAX_WORD_LENGTH) {
                printf("Warning: Word '%s' is too long, truncating\n", word);
                word[MAX_WORD_LENGTH - 1] = '\0';
                word_length = MAX_WORD_LENGTH;
            }
            process_word(word);
        }
    }

    fclose(file);

    printf("Total words: %d\n", word_count);
    printf("Occurrences of 'Romeo': %d\n", romeo_count);
    printf("Occurrences of 'Juliet': %d\n", juliet_count);

    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i], i + 1);
    }

    for (int i = 0; i < word_count; i++) {
        free(words[i]);
    }

    return 0;
}