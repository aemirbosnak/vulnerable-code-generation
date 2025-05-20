//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

// Function to reverse a string
char *reverse_string(char *str) {
    char *reversed_str = malloc(strlen(str) + 1);
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < strlen(str); i++, j--) {
        reversed_str[i] = str[j];
    }
    reversed_str[strlen(str)] = '\0';
    return reversed_str;
}

// Function to convert a string to uppercase
char *to_uppercase(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

// Function to convert a string to lowercase
char *to_lowercase(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

// Function to remove all spaces from a string
char *remove_spaces(char *str) {
    int i, j;
    char *new_str = malloc(strlen(str) + 1);
    for (i = 0, j = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';
    return new_str;
}

// Function to count the number of words in a string
int count_words(char *str) {
    int i, count = 0;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    return count + 1;
}

// Function to find the longest word in a string
char *longest_word(char *str) {
    int i, j, max_length = 0, start = 0, end = 0;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            if (i - start > max_length) {
                max_length = i - start;
                end = i - 1;
            }
            start = i + 1;
        }
    }
    if (strlen(str) - start > max_length) {
        max_length = strlen(str) - start;
        end = strlen(str) - 1;
    }
    char *longest_word = malloc(max_length + 1);
    for (i = start, j = 0; i <= end; i++, j++) {
        longest_word[j] = str[i];
    }
    longest_word[j] = '\0';
    return longest_word;
}

// Function to print a menu of options
void print_menu() {
    printf("\nString Manipulation Options:\n");
    printf("1. Reverse a string\n");
    printf("2. Convert a string to uppercase\n");
    printf("3. Convert a string to lowercase\n");
    printf("4. Remove all spaces from a string\n");
    printf("5. Count the number of words in a string\n");
    printf("6. Find the longest word in a string\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

// Main function
int main() {
    char str[BUF_SIZE];
    int choice;
    char *result;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                scanf(" %[^\n]%*c", str);
                result = reverse_string(str);
                printf("Reversed string: %s\n", result);
                free(result);
                break;
            case 2:
                printf("Enter a string: ");
                scanf(" %[^\n]%*c", str);
                result = to_uppercase(str);
                printf("Uppercase string: %s\n", result);
                free(result);
                break;
            case 3:
                printf("Enter a string: ");
                scanf(" %[^\n]%*c", str);
                result = to_lowercase(str);
                printf("Lowercase string: %s\n", result);
                free(result);
                break;
            case 4:
                printf("Enter a string: ");
                scanf(" %[^\n]%*c", str);
                result = remove_spaces(str);
                printf("String with spaces removed: %s\n", result);
                free(result);
                break;
            case 5:
                printf("Enter a string: ");
                scanf(" %[^\n]%*c", str);
                int count = count_words(str);
                printf("Number of words in the string: %d\n", count);
                break;
            case 6:
                printf("Enter a string: ");
                scanf(" %[^\n]%*c", str);
                result = longest_word(str);
                printf("Longest word in the string: %s\n", result);
                free(result);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}