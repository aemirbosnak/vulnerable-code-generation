//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEYWORD_COUNT 4
const char *keywords[KEYWORD_COUNT] = {"love", "heart", "passion", "romance"};

int main(int argc, char **argv) {
    FILE *file;
    char filename[100];
    int keyword_count[KEYWORD_COUNT] = {0};
    int ch;

    if (argc != 2) {
        printf("Usage: %s <love.txt>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        int i;
        for (i = 0; i < KEYWORD_COUNT; i++) {
            int len = strlen(keywords[i]);
            if (strncasecmp(keywords[i], &ch, len) == 0) {
                keyword_count[i]++;
                break;
            }
        }

        // Convert lowercase characters for better matching
        if (isalpha(ch)) {
            putchar(tolower(ch));
        } else {
            putchar(ch);
        }
    }

    fclose(file);

    printf("\nThe text file '%s' contains the following romantic keyword occurrences:\n", filename);
    for (int i = 0; i < KEYWORD_COUNT; i++) {
        printf("%s: %d\n", keywords[i], keyword_count[i]);
    }

    int total_romantic_words = 0;
    for (int i = 0; i < KEYWORD_COUNT; i++) {
        total_romantic_words += keyword_count[i];
    }

    if (total_romantic_words > 5) {
        printf("\nYour text is filled with %d romantic words! Here's a little something extra for you:\n", total_romantic_words);
        printf("'%s'\n", "May your love be like a rose, ever gentle, ever strong.");
    }

    return 0;
}