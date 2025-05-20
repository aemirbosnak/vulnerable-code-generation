//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_WORDS 1000
#define MAX_CHARS 500

typedef struct {
    char *word;
    int length;
} Word;

int main() {
    FILE *file;
    char ch;
    Word words[MAX_WORDS];
    int num_words = 0;
    int i;

    // Open the file
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the file
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[num_words].word = (char *) malloc(MAX_CHARS);
            words[num_words].length = 0;
            while (isalpha(ch)) {
                words[num_words].word[words[num_words].length++] = tolower(ch);
                ch = fgetc(file);
            }
            words[num_words].word[words[num_words].length] = '\0';
            num_words++;
        }
    }

    // Close the file
    fclose(file);

    // Print the words
    for (i = 0; i < num_words; i++) {
        printf("%s\n", words[i].word);
    }

    // Free the memory
    for (i = 0; i < num_words; i++) {
        free(words[i].word);
    }

    return 0;
}