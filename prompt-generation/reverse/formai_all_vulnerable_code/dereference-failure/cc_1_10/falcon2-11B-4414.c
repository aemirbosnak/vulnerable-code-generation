//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char sentence[1000];
    char *words[100];
    int n = 0, i = 0, j = 0;

    // Get the user input
    printf("Enter a sentence to summarize: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Split the sentence into individual words
    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        words[i] = strdup(word);
        i++;
        word = strtok(NULL, " ");
    }

    // Sort the words in descending order of frequency
    for (j = 0; j < i; j++) {
        for (n = 0; n < i - 1; n++) {
            if (strcmp(words[n], words[n + 1]) > 0) {
                char *temp = words[n];
                words[n] = words[n + 1];
                words[n + 1] = temp;
            }
        }
    }

    // Generate the summary
    int k = 0;
    for (j = 0; j < i; j++) {
        if (k < 10) {
            printf("%s", words[j]);
            k++;
        } else if (k < 100) {
            printf("%s, ", words[j]);
            k++;
        } else {
            printf("%s", words[j]);
            k = 0;
        }
    }

    // Free the allocated memory
    for (n = 0; n < i; n++) {
        free(words[n]);
    }

    return 0;
}