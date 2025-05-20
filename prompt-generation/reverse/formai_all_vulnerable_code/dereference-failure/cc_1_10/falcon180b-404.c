//Falcon-180B DATASET v1.0 Category: Text processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main(int argc, char *argv[]) {
    FILE *input_file;
    char filename[100];
    char buffer[1000];
    struct word_count *word_counts = malloc(MAX_WORDS * sizeof(struct word_count));
    int num_words = 0;

    // prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // open input file
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // read in file contents
    while (fgets(buffer, sizeof(buffer), input_file)!= NULL) {
        // remove newline character from end of buffer
        buffer[strcspn(buffer, "\n")] = '\0';

        // convert all characters to lowercase
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] = tolower(buffer[i]);
        }

        // split buffer into words
        char *token = strtok(buffer, " ");
        while (token!= NULL) {
            // check if word is already in word_count array
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word_counts[i].word, token) == 0) {
                    // word already exists, increment count
                    word_counts[i].count++;
                    break;
                }
            }
            // word does not exist, add to word_count array
            if (i == num_words) {
                strcpy(word_counts[num_words].word, token);
                word_counts[num_words].count = 1;
                num_words++;
            }
            token = strtok(NULL, " ");
        }
    }

    // close input file
    fclose(input_file);

    // print word counts
    printf("Word counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    // free memory
    free(word_counts);

    return 0;
}