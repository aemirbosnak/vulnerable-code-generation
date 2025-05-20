//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function to perform division and handle errors
double safe_divide(double numerator, double denominator) {
    if (denominator == 0) {
        errno = EDOM; // Domain error (divide by zero)
        return 0.0;
    }
    return numerator / denominator;
}

// Function to handle error messages
void handle_error(const char* msg) {
    fprintf(stderr, "Error: %s. ", msg);
    
    if (errno) {
        // Print system error message
        fprintf(stderr, "Details: %s\n", strerror(errno));
        errno = 0; // Reset errno after handling it
    } else {
        fprintf(stderr, "No further details available.\n");
    }
}

// Main function where the user interaction takes place
int main() {
    double num1, num2, result;
    char buffer[256];
    char choice;

    printf("Welcome to the Safe Division Program!\n");
    
    while (1) {
        // Prompt user for input
        printf("Enter the numerator: ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            handle_error("Failed to read numerator.");
            continue;
        }
        num1 = atof(buffer); // Convert string to double
        
        printf("Enter the denominator: ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            handle_error("Failed to read denominator.");
            continue;
        }
        num2 = atof(buffer); // Convert string to double

        // Attempt to perform division
        result = safe_divide(num1, num2);
        
        if (errno == EDOM) {
            handle_error("Division by zero detected.");
        } else {
            printf("Result of %.2f / %.2f = %.2f\n", num1, num2, result);
        }

        // Check if user wants to perform another calculation
        printf("Would you like to perform another calculation? (y/n): ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            handle_error("Failed to read choice.");
            continue;
        }
        
        // Handling user choice
        choice = buffer[0];
        if (choice == 'n' || choice == 'N') {
            printf("Thank you for using the Safe Division Program. Goodbye!\n");
            break;
        } else if (choice != 'y' && choice != 'Y') {
            fprintf(stderr, "Invalid choice! Exiting program.\n");
            break;
        }
    }

    return 0;
}