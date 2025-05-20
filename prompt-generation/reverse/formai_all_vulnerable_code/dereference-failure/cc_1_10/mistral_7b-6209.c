//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define BUFFER_SIZE 1024

void reverse_string(char *str) {
    int i = 0, j = strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int is_palindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    FILE *input_file = fopen("input.txt", "r"), *output_file = fopen("output.txt", "w");
    char buffer[BUFFER_SIZE], word[MAX_WORD_LEN];
    int palindrome_count = 0;

    if (input_file == NULL || output_file == NULL) {
        perror("Error opening files.");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE, input_file)) {
        char *token = strtok(buffer, " \t\n\r.,;:!");
        while (token != NULL) {
            strcpy(word, token);
            int len = strlen(word);
            if (len > 0 && len <= MAX_WORD_LEN) {
                reverse_string(word);
                if (is_palindrome(word)) {
                    palindrome_count++;
                    fprintf(output_file, "%s\n", word);
                }
            }
            token = strtok(NULL, " \t\n\r.,;:!");
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("Number of palindromic words found: %d\n", palindrome_count);

    return EXIT_SUCCESS;
}