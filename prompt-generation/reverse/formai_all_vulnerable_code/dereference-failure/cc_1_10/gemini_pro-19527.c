//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove all occurrences of a character from a string
char *remove_char(char *str, char c) {
    char *newstr = (char *)malloc(strlen(str) + 1);  // Allocate memory for the new string
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != c) {
            newstr[j++] = str[i];
        }
    }
    newstr[j] = '\0';  // Null-terminate the new string
    return newstr;
}

// Function to count the number of words in a string
int count_words(char *str) {
    int count = 0;
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            count++;
        }
    }
    return count + 1;  // Add 1 to the count for the last word
}

// Function to reverse a string
char *reverse_string(char *str) {
    int length = strlen(str);
    char *newstr = (char *)malloc(length + 1);  // Allocate memory for the new string
    int i;
    for (i = 0; i < length; i++) {
        newstr[i] = str[length - i - 1];
    }
    newstr[length] = '\0';  // Null-terminate the new string
    return newstr;
}

// Function to print a string in a box
void print_in_box(char *str) {
    int length = strlen(str);
    printf("+");
    for (int i = 0; i < length + 2; i++) {
        printf("-");
    }
    printf("+\n");
    printf("| %s |\n", str);
    printf("+");
    for (int i = 0; i < length + 2; i++) {
        printf("-");
    }
    printf("+\n");
}

// Main function
int main() {
    // Get a string from the user
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Remove all occurrences of the character 'a' from the string
    char *newstr = remove_char(str, 'a');
    printf("String with all occurrences of 'a' removed: %s\n", newstr);

    // Count the number of words in the string
    int word_count = count_words(str);
    printf("Number of words in the string: %d\n", word_count);

    // Reverse the string
    char *reversed_str = reverse_string(str);
    printf("Reversed string: %s\n", reversed_str);

    // Print the string in a box
    print_in_box(str);

    // Free the allocated memory
    free(newstr);
    free(reversed_str);
    return 0;
}