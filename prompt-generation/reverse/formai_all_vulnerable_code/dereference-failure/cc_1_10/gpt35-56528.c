//FormAI DATASET v1.0 Category: File handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {

    char file_name[MAX_SIZE], message[MAX_SIZE], choice;
    FILE *file;

    printf("Hello there! I'm a program that can create, write, and read files!\n");
    printf("Please enter the name of the file that you want to create or open: ");
    scanf("%s", file_name);

    // Check if file exists
    if ((file = fopen(file_name, "r"))) {
        printf("This file already exists! Do you want to overwrite it? Y/N: ");
        scanf(" %c", &choice);
        if (choice == 'Y' || choice == 'y') {
            // Overwrite the file
            printf("Warning: This will overwrite the existing file!\n");
            file = fopen(file_name, "w");
        } else {
            // Exit the program
            printf("No changes have been made to the file. Goodbye!\n");
            exit(0);
        }
    } else {
        // If file doesn't exist, create a new file
        file = fopen(file_name, "w");
    }

    // Write to file
    printf("Please type a message to write to the file: ");
    scanf(" %[^\n]", message);
    fprintf(file, "%s", message);
    printf("The message has been successfully written to the file!\n\n");

    // Read from file
    printf("Would you like to read the contents of the file? Y/N: ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        file = fopen(file_name, "r");
        char content[MAX_SIZE];
        while (fgets(content, MAX_SIZE, file)) {
            printf("%s", content);
        }
        printf("\n");
    } else {
        printf("Okay, goodbye!\n");
        exit(0);
    }

    // Close the file
    fclose(file);

    return 0;
}