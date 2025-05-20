//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(void) {
    FILE *fp;
    char fileContent[MAX_LINE_LENGTH];
    char reversedContent[MAX_LINE_LENGTH] = {0};
    char *token = NULL;
    size_t len = 0;
    size_t readSize = 0;

    // Open the file with read mode
    fp = fopen("happy.txt", "r");
    if (fp == NULL) {
        printf("Oops! Could not open the file 'happy.txt'.\n");
        return EXIT_FAILURE;
    }

    printf("Reading the content of 'happy.txt'...\n");
    printf("Think positive and let's reverse it together!\n");

    // Read the file line by line
    while (getline(&fileContent, MAX_LINE_LENGTH, fp) > 0) {
        len = strlen(fileContent);

        // Reverse the line content and store it in reversedContent
        for (int i = len - 1; i >= 0; i--) {
            reversedContent[readSize++] = fileContent[i];
        }

        // Add a newline character to the reversedContent
        reversedContent[readSize++] = '\n';
    }

    // Close the file
    fclose(fp);

    // Open the file with write mode
    fp = fopen("happy.txt", "w");
    if (fp == NULL) {
        printf("Oops! Could not open the file 'happy.txt' for writing.\n");
        return EXIT_FAILURE;
    }

    printf("Writing the reversed content to 'happy.txt'...\n");

    // Write the reversed content to the file
    if (fwrite(reversedContent, 1, readSize, fp) != readSize) {
        printf("Error writing to file 'happy.txt'.\n");
        return EXIT_FAILURE;
    }

    printf("Yay! The reversed content has been written to 'happy.txt'.\n");

    // Close the file
    fclose(fp);

    // Free the memory allocated for reversedContent
    free(reversedContent);

    return EXIT_SUCCESS;
}