//Falcon-180B DATASET v1.0 Category: Text processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

// Function to remove leading and trailing whitespace from a string
char* trim(char* str) {
    char* end = str + strlen(str) - 1;
    while (isspace(*end)) {
        end--;
        *end = '\0';
    }
    while (*str && isspace(*str)) {
        str++;
    }
    return str;
}

// Function to count the number of words in a string
int count_words(char* str) {
    int count = 0;
    char* word_start = str;
    while (*str) {
        if (isspace(*str)) {
            count++;
            word_start = str + 1;
        }
        str++;
    }
    return count;
}

// Function to read a line of text from the user
char* read_line() {
    char* line = malloc(MAX_LINE_LENGTH);
    fgets(line, MAX_LINE_LENGTH, stdin);
    return trim(line);
}

// Function to process a line of text
void process_line(char* line) {
    int word_count = count_words(line);
    printf("Line contains %d words.\n", word_count);
}

int main() {
    char* line;
    while ((line = read_line())!= NULL) {
        process_line(line);
        free(line);
    }
    return 0;
}