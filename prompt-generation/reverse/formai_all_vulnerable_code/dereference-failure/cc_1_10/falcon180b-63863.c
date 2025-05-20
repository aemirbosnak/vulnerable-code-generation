//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

char *search_word;
int search_word_length;
int search_word_found = 0;

void read_file(FILE *file) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            search_word[i++] = tolower(ch);
            if (i >= MAX_WORD_LENGTH) {
                search_word[i] = '\0';
                search_word_length = i;
                search_word_found = 1;
                break;
            }
        } else {
            i = 0;
        }
    }
}

void search_file(FILE *file) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (tolower(ch) == search_word[i]) {
                i++;
            } else {
                i = 0;
            }
            if (i == search_word_length) {
                printf("Found the word '%s' in the file.\n", search_word);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file_name> <word>\n", argv[0]);
        exit(1);
    }

    search_word = argv[2];
    search_word_length = strlen(search_word);

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", argv[1]);
        exit(1);
    }

    read_file(file);

    if (!search_word_found) {
        printf("The word '%s' was not found in the file.\n", search_word);
    } else {
        search_file(file);
    }

    fclose(file);
    return 0;
}