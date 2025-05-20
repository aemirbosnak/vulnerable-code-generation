//Falcon-180B DATASET v1.0 Category: Text processing ; Style: genious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove all non-alphanumeric characters from a string
char* remove_non_alphanumeric(char* str) {
    int i = 0;
    int j = 0;
    char* result = (char*) malloc(strlen(str) + 1);

    while (str[i]) {
        if (isalnum(str[i])) {
            result[j++] = tolower(str[i]);
        }
        i++;
    }
    result[j] = '\0';

    return result;
}

// Function to reverse a string
char* reverse_string(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    char* result = (char*) malloc(strlen(str) + 1);

    while (i < j) {
        result[i++] = str[j--];
    }
    result[i] = '\0';

    return result;
}

// Function to count the frequency of each word in a string
void count_words(char* str) {
    int i = 0;
    int j = 0;
    char* token = strtok(str, " ");

    while (token!= NULL) {
        char* word = remove_non_alphanumeric(token);
        int word_length = strlen(word);
        int frequency = 1;

        for (int k = i; k < j; k++) {
            if (strcmp(word, remove_non_alphanumeric(str + k)) == 0) {
                frequency++;
            }
        }

        printf("%s: %d\n", word, frequency);
        free(word);
        i = j;
        j += word_length + 1;
        token = strtok(NULL, " ");
    }
}

// Main function
int main() {
    char input[1000];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    char* cleaned_input = remove_non_alphanumeric(input);
    char* reversed_input = reverse_string(cleaned_input);

    printf("Cleaned input: %s\n", cleaned_input);
    printf("Reversed input: %s\n", reversed_input);
    free(cleaned_input);
    free(reversed_input);

    count_words(input);

    return 0;
}