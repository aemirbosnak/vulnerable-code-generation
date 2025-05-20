//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_AGE_LENGTH 3

// Function to sanitize name input to allow only alphabetic characters
void sanitize_name(char *name) {
    int len = strlen(name);
    for (int i = 0; i < len; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            printf("Invalid character '%c' found in name. It will be replaced.\n", name[i]);
            name[i] = ' '; // replace invalid character with space
        }
    }
}

// Function to sanitize age input to ensure it's a valid number
int sanitize_age(char *age) {
    for (int i = 0; age[i] != '\0'; i++) {
        if (!isdigit(age[i])) {
            printf("Invalid character '%c' found in age. Please enter a valid number.\n", age[i]);
            return -1; // return -1 to indicate invalid input
        }
    }
    return atoi(age); // return sanitized age
}

// Function to trim spaces from start and end of the string
char* trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after the last character
    end[1] = '\0';

    return str;
}

int main() {
    char name[MAX_NAME_LENGTH];
    char age_input[MAX_AGE_LENGTH];

    printf("Welcome! Please enter your name (only alphabetic characters are allowed):\n");
    fgets(name, sizeof(name), stdin); // get user input for name
    name[strcspn(name, "\n")] = 0; // remove the newline character if present

    printf("Thank you for your input! Now, we will sanitize your name:\n");
    sanitize_name(name);
    char *trimmed_name = trim_whitespace(name); // trim any residual spaces
    printf("Sanitized Name: '%s'\n", trimmed_name);

    printf("\nNow, could you please tell us your age (only numbers are accepted):\n");
    fgets(age_input, sizeof(age_input), stdin); // get user input for age
    age_input[strcspn(age_input, "\n")] = 0; // remove the newline character if present

    int age = sanitize_age(age_input);
    if (age == -1) {
        printf("Please try running the program again with valid input.\n");
        return 1; // exit if age is invalid
    }

    printf("\nThank you for providing your information!\n");
    printf("Your sanitized name is: '%s' and your age is: %d\n", trimmed_name, age);

    printf("\nWe appreciate your cooperation in keeping data clean and safe!\n");
    return 0; // indicate successful completion
}