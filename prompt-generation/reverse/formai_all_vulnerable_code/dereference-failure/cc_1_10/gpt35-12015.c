//FormAI DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

/* Removes all occurrences of a given character in a string */
char* remove_char(char* string, char character) {
    int length = strlen(string);
    char* result = calloc(length, sizeof(char));
    int count = 0;

    for(int i = 0; i < length; i++) {
        if(string[i] != character) {
            result[count] = string[i];
            count++;
        }
    }

    return result;
}

/* Reverses the order of words in a string */
char* reverse_words(char* string) {
    int length = strlen(string);
    char* result = calloc(length, sizeof(char));
    char* temp_str = calloc(length, sizeof(char));
    int count = 0;

    for(int i = length - 1; i >= 0; i--) {
        if(string[i] == ' ') {
            strcat(result, temp_str);
            strcat(result, " ");
            memset(temp_str, 0, strlen(temp_str));
            count = 0;
        } else {
            temp_str[count] = string[i];
            count++;
        }
    }

    strcat(result, temp_str);
    free(temp_str);

    return result;
}

int main() {
    char string[MAX_STRING_LENGTH] = "This is a sample string.";
    char* removed_string = remove_char(string, ' ');
    printf("String with spaces removed: %s\n", removed_string);

    char* reversed_string = reverse_words(string);
    printf("String with reversed words: %s\n", reversed_string);

    free(removed_string);
    free(reversed_string);

    return 0;
}