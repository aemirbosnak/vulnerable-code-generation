//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function to remove whitespace from a string
char* remove_whitespace(char* str) {
    int i, j;
    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!isspace(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    return str;
}

// Function to reverse a string
char* reverse_string(char* str) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return str;
}

// Function to count the number of words in a string
int count_words(char* str) {
    int count = 0;
    char* word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to calculate the average length of words in a string
float avg_word_length(char* str) {
    int word_count = count_words(str);
    if (word_count == 0) {
        return 0;
    }
    int total_length = strlen(str);
    int word_length;
    char* word = strtok(str, " ");
    while (word!= NULL) {
        word_length = strlen(word);
        total_length -= word_length + 1; // +1 for space between words
        word = strtok(NULL, " ");
    }
    return (float)total_length / word_count;
}

// Function to print a string with each word reversed
void print_reversed_string(char* str) {
    char* word = strtok(str, " ");
    while (word!= NULL) {
        printf("%s ", reverse_string(word));
        word = strtok(NULL, " ");
    }
}

// Function to print statistics about a string
void print_stats(char* str) {
    printf("Number of words: %d\n", count_words(str));
    printf("Average word length: %.2f\n", avg_word_length(str));
    printf("Reversed string: ");
    print_reversed_string(str);
    printf("\n");
}

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    printf("Enter a string: ");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);
    input_buffer[strcspn(input_buffer, "\n")] = '\0'; // Remove newline character
    char* str = remove_whitespace(input_buffer);
    print_stats(str);
    free(str);
    return 0;
}