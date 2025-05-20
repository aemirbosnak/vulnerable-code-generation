//FormAI DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A macro to calculate the array length
#define ARRAY_LENGTH(arr) sizeof(arr)/sizeof(arr[0])

// A function to split a string into an array of substrings based on a delimiter
char **split_string(char *str, char *delimiter, int *length) {
    int count = 0;
    char **result = NULL;
    char *token = strtok(str, delimiter);
    while(token != NULL) {
        result = (char **)realloc(result, (count + 1) * sizeof(char *));
        result[count++] = token;
        token = strtok(NULL, delimiter);
    }
    *length = count;
    return result;
}

// A function to join an array of substrings into a single string based on a delimiter
char *join_string(char **str_array, int length, char *delimiter) {
    int i;
    char *result = NULL;
    for(i = 0; i < length; i++) {
        result = (char *)realloc(result, strlen(result) + strlen(str_array[i]) + strlen(delimiter) + 1);
        strcat(result, str_array[i]);
        if(i < length - 1) strcat(result, delimiter);
    }
    return result;
}

int main() {
    char *string = "Hello, World! How are you doing today?";
    char *delimiter = " ";
    int length = 0;
    printf("Original string: %s\n", string);
    char **string_array = split_string(string, delimiter, &length);
    printf("Number of substrings: %d\n", length);
    printf("Substrings:\n");
    int i;
    for(i = 0; i < length; i++) {
        printf("%d: %s\n", i, string_array[i]);
    }
    char *new_delimiter = "-";
    char *new_string = join_string(string_array, length, new_delimiter);
    printf("New string: %s\n", new_string);
    free(string_array);
    free(new_string);
    return 0;
}