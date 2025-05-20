//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: distributed
#include <stdio.h>
#include <string.h>

// Function to sanitize user input
char* sanitize_input(char* input) {
    // Allocate memory for the sanitized string
    char* sanitized = (char*) malloc(sizeof(char) * strlen(input));
    int j=0;
    for(int i=0;i<strlen(input);i++){
        // Ensure only alphanumeric and space characters are allowed
        if((input[i]>='A' && input[i]<='Z') ||
           (input[i]>='a' && input[i]<='z') ||
           (input[i]>='0' && input[i]<='9') ||
           (input[i] == ' ')) {
            sanitized[j] = input[i];
            j++;
        }
    }

    // Null terminate the sanitized string
    sanitized[j] = '\0';

    // Return the sanitized string
    return sanitized;
}

// Main function
int main() {
    // Declare variables for user input
    char name[100], address[100], phone[15];

    // Get user input
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter your address: ");
    fgets(address, sizeof(address), stdin);

    printf("Enter your phone number: ");
    fgets(phone, sizeof(phone), stdin);

    // Sanitize user inputs
    char* sanitized_name = sanitize_input(name);
    char* sanitized_address = sanitize_input(address);
    char* sanitized_phone = sanitize_input(phone);

    // Display sanitized inputs
    printf("\nSanitized Inputs:\n");
    printf("Name: %s\n", sanitized_name);
    printf("Address: %s\n", sanitized_address);
    printf("Phone: %s\n", sanitized_phone);

    // Free memory of sanitized strings
    free(sanitized_name);
    free(sanitized_address);
    free(sanitized_phone);

    // Exit program
    return 0;
}