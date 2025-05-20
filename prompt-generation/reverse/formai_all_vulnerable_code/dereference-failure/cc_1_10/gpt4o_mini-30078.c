//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to reverse a string
void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Function to convert a string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to count vowels in a string
int countVowels(const char *str) {
    int count = 0;
    const char *vowels = "aeiouAEIOU";
    while (*str) {
        if (strchr(vowels, *str)) {
            count++;
        }
        str++;
    }
    return count;
}

// Function to generate a substring
void substring(const char *source, int start, int length, char *dest) {
    if (start < 0 || start + length > strlen(source)) {
        snprintf(dest, MAX_LENGTH, "Invalid range");
        return;
    }
    strncpy(dest, source + start, length);
    dest[length] = '\0'; // Null-terminate the substring
}

// Function to print the menu
void printMenu() {
    printf("\nString Manipulation Menu:\n");
    printf("1. Reverse the string\n");
    printf("2. Convert to uppercase\n");
    printf("3. Count vowels\n");
    printf("4. Generate a substring\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char str[MAX_LENGTH];
    char sub[MAX_LENGTH];
    int option, start, length;

    printf("Enter a string (max %d characters): ", MAX_LENGTH - 1);
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove the newline character

    while (1) {
        printMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                reverseString(str);
                printf("Reversed string: %s\n", str);
                break;

            case 2:
                toUpperCase(str);
                printf("Uppercase string: %s\n", str);
                break;

            case 3:
                printf("Number of vowels: %d\n", countVowels(str));
                break;

            case 4:
                printf("Enter starting index for substring: ");
                scanf("%d", &start);
                printf("Enter length of substring: ");
                scanf("%d", &length);
                substring(str, start, length, sub);
                printf("Generated substring: %s\n", sub);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}