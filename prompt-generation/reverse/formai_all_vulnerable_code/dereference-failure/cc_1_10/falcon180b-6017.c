//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_WORDS 100

int count_words(char* str);
void reverse_string(char* str);
void convert_to_title_case(char* str);

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove the newline character from the end of the input string
    input[strcspn(input, "\n")] = '\0';

    // Reverse the input string
    reverse_string(input);

    // Convert the input string to title case
    convert_to_title_case(input);

    // Count the number of words in the input string
    int num_words = count_words(input);

    // Reverse the input string again
    reverse_string(input);

    // Generate the output string
    sprintf(output, "The input string contains %d words and is %d characters long.", num_words, strlen(input));

    printf("Output: %s\n", output);

    return 0;
}

int count_words(char* str) {
    int count = 0;
    char* word = strtok(str, " ");

    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

void reverse_string(char* str) {
    int length = strlen(str);
    char* start = str;
    char* end = str + length - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void convert_to_title_case(char* str) {
    int length = strlen(str);
    char* start = str;

    while (start < str + length) {
        if (isalpha(*start)) {
            *start = toupper(*start);
        }
        start++;
    }
}