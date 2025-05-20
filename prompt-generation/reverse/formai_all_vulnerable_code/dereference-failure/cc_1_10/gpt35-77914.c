//FormAI DATASET v1.0 Category: Spam Detection System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1000

int main() {

    FILE *input_file, *output_file;
    char file_name[50], line[MAX_LINE_LENGTH];
    int i, is_spam;

    printf("Enter the file name: ");
    scanf("%s", file_name);

    input_file = fopen(file_name, "r");
    output_file = fopen("output.txt", "w");

    if (input_file == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

    if (output_file == NULL) {
        printf("Error creating the output file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        is_spam = 0;

        // Check for spam words
        char spam_words[][20] = {"free", "buy now", "limited time offer", "click here"};
        int num_spam_words = sizeof(spam_words) / sizeof(spam_words[0]);

        for (i = 0; i < num_spam_words; i++) {
            if (strstr(line, spam_words[i]) != NULL) {
                is_spam = 1;
                break;
            }
        }

        // Check for spam phrases
        char spam_phrases[][50] = {"earn money fast", "lose weight now", "get rid of debt", "increase your sales"};
        int num_spam_phrases = sizeof(spam_phrases) / sizeof(spam_phrases[0]);

        for (i = 0; i < num_spam_phrases; i++) {
            if (strstr(line, spam_phrases[i]) != NULL) {
                is_spam = 1;
                break;
            }
        }

        // If line is not spam, write it to output file
        if (!is_spam) {
            fprintf(output_file, "%s", line);
        }
    }

    printf("Spam detection completed. Output written to output.txt\n");

    fclose(input_file);
    fclose(output_file);

    return 0;
}