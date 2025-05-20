//FormAI DATASET v1.0 Category: Word Count Tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

int main() {
    char input[MAX_WORDS];
    char *words[MAX_WORDS];
    int freq[MAX_WORDS];
    int count = 0;

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    /* Tokenize input */
    char *ptr = strtok(input, " ");
    while (ptr != NULL) {
        /* Convert word to lowercase */
        for (int i = 0; i < strlen(ptr); i++) {
            ptr[i] = tolower(ptr[i]);
        }

        /* Count word frequency, or add to list of distinct words */
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(ptr, words[i]) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            words[count] = malloc((strlen(ptr) + 1) * sizeof(char));
            strcpy(words[count], ptr);
            freq[count] = 1;
            count++;
        }

        /* Get next token */
        ptr = strtok(NULL, " ");
    }

    /* Print word count */
    printf("\nWord Count:\n");
    for (int i = 0; i < count; i++) {
        printf("\"%s\" - %d\n", words[i], freq[i]);
    }

    /* Free allocated memory */
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }

    return 0;
}