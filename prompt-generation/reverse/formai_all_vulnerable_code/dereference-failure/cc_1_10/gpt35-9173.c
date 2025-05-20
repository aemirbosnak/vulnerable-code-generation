//FormAI DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void print_words(char* str) {
    int n = strlen(str);
    int i, j;
    int word_start = -1;
    int word_end = -1;

    for (i = 0; i < n; i++) {
        if ((!isalpha(str[i]) || i == n-1) && word_start != -1) {
            word_end = i;
            if (i == n-1) {
                word_end++;
            }

            int word_length = word_end - word_start;
            char* word = malloc((word_length+1) * sizeof(char));
            for (j = word_start; j < word_end; j++) {
                if (!isalpha(str[j])) {
                    continue;
                }

                word[j-word_start] = tolower(str[j]);
            }
            word[word_length] = '\0';

            printf("Word Found: %s\n", word);

            free(word);
            word = NULL;
            word_start = -1;
            word_end = -1;
        } else if (isalpha(str[i]) && word_start == -1) {
            word_start = i;
        }
    }
}

int main(void) {
    char* text = "The quick brown fox jumps over the lazy dog. The dog barked and then ran away.";

    printf("Original Text: %s\n", text);
    printf("Processed Words:\n");
    print_words(text);

    return 0;
}