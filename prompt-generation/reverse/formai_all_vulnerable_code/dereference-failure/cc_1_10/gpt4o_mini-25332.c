//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function prototypes
void display_menu();
void reverse_string(char *str);
void change_case(char *str);
void rotate_string(char *str, int positions);
void shape_shift(char *str);
void clear_buffer();

int main() {
    char input[MAX_SIZE];
    int choice;
    
    printf("Welcome to the Shape Shifting String Manipulator!\n");
    printf("Enter a string (max %d characters): ", MAX_SIZE - 1);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;  // Remove the newline character from the input

    do {
        display_menu();
        scanf("%d", &choice);
        clear_buffer();  // Clear any extra input in the buffer

        switch (choice) {
            case 1:
                printf("Original String: %s\n", input);
                reverse_string(input);
                break;
            case 2:
                printf("Original String: %s\n", input);
                change_case(input);
                break;
            case 3:
                {
                    int positions;
                    printf("Enter number of positions to rotate: ");
                    scanf("%d", &positions);
                    clear_buffer();
                    printf("Original String: %s\n", input);
                    rotate_string(input, positions);
                }
                break;
            case 4:
                shape_shift(input);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}

// Function to display the menu
void display_menu() {
    printf("Choose a shape shifting operation:\n");
    printf("1. Reverse the string\n");
    printf("2. Change case of the string\n");
    printf("3. Rotate the string\n");
    printf("4. Shape shift the string\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Function to reverse the string
void reverse_string(char *str) {
    int len = strlen(str);
    char temp;
    
    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    printf("Reversed String: %s\n", str);
}

// Function to change the case of the string
void change_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = isupper(str[i]) ? tolower(str[i]) : toupper(str[i]);
    }
    printf("Case Changed String: %s\n", str);
}

// Function to rotate the string
void rotate_string(char *str, int positions) {
    int len = strlen(str);
    positions = positions % len;  // Adjust for positions greater than length
    char temp[MAX_SIZE];
    
    strcpy(temp, str + len - positions);
    str[len - positions] = '\0';
    strcat(temp, str);
    
    strcpy(str, temp);
    printf("Rotated String: %s\n", str);
}

// Function to perform a shape shift to create new variations of the string
void shape_shift(char *str) {
    char shifted[MAX_SIZE];
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            shifted[i] = toupper(str[i]);  // Uppercase for even indices
        } else {
            shifted[i] = tolower(str[i]);  // Lowercase for odd indices
        }
    }
    shifted[len] = '\0';  // Null-terminate the new string
    printf("Shape Shifter String: %s\n", shifted);
}

// Function to clear the input buffer
void clear_buffer() {
    while (getchar() != '\n'); // Clear until newline
}