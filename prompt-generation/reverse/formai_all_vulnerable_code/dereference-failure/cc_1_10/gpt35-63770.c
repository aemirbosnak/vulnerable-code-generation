//FormAI DATASET v1.0 Category: String manipulation ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100 // maximum length of input string

char *append_string(const char *original_string, const char *string_to_append) { // function to append one string to another
    int original_len = strlen(original_string);
    int to_append_len = strlen(string_to_append);
    char *new_string = (char*)malloc(original_len + to_append_len + 1); // allocating memory for the new string
    strcpy(new_string, original_string); // copying the original string to the new string
    strcat(new_string, string_to_append); // appending string_to_append to the new string
    return new_string; // returning the new string
}

char *remove_char(const char *input_string, const char *char_to_remove) { // function to remove a character from a string
    int input_len = strlen(input_string);
    int char_to_remove_len = strlen(char_to_remove);
    char *new_string = (char*)malloc(input_len + 1); // allocating memory for the new string
    int j = 0;
    for(int i = 0; i < input_len; i++) { // iterating over the input string and copying only the characters which are not equal to the character to remove
        if(input_string[i] != char_to_remove[0]) {
            new_string[j] = input_string[i];
            j++;
        }
    }
    new_string[j] = '\0'; // adding null character at the end of the new string
    return new_string; // returning the new string
}

void reverse_string(char *input_string) { // function to reverse a string
    int len = strlen(input_string);
    for(int i = 0; i < len/2; i++) {  // iterating over the half of the length of the string and swapping the characters
        char temp = input_string[i];
        input_string[i] = input_string[len-i-1];
        input_string[len-i-1] = temp;
    }
}

int main() {
    char input[MAX_LEN]; // declaring input string of maximum length MAX_LEN
    printf("Enter a string: ");
    fgets(input, MAX_LEN, stdin); // reading input string from the user

    printf("\n\nOriginal string: %s", input);

    char *appended_string = append_string(input, " is awesome!"); // appending " is awesome!" to the input string
    printf("After appending (original string unchanged): %s\n\n", appended_string);
    free(appended_string); // freeing the memory allocated for the appended string

    char *removed_char_string = remove_char(input, "a"); // removing all "a"s from the input string
    printf("After removing 'a's (original string unchanged): %s\n\n", removed_char_string);
    free(removed_char_string); // freeing the memory allocated for the string without 'a's

    reverse_string(input); // reversing the input string
    printf("After reversing: %s\n\n", input);
    
    return 0; // returning from main
}