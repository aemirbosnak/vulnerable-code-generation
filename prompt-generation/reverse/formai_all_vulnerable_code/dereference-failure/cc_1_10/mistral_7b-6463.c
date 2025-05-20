//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

void strShocker(char *str) {
    int i, len = 0, counter = 0, tempCounter = 0;
    char *newStr, *tempStr, *shockedWord;

    if (!str) {
        printf("Error: Null string input!\n");
        return;
    }

    len = strlen(str);

    newStr = (char *)malloc((len + 2) * sizeof(char)); // Allocate memory for the new string

    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) { // Check if character is alphabet
            newStr[counter++] = toupper(str[i]); // Convert to uppercase
            tempCounter = 0;
        } else if (isdigit(str[i])) { // Check if character is digit
            if (tempCounter > 0) { // If digit is not first in the sequence
                newStr[counter++] = '0' + (tempCounter * 10 + str[i] - '0'); // Concatenate digits
                tempCounter = 0;
            } else {
                newStr[counter++] = str[i]; // Add digit as is
            }
        } else { // Check for other characters
            if (tempCounter > 0) { // If non-alphanumeric character is not first in the sequence
                shockedWord = (char *)malloc((counter + 1) * sizeof(char)); // Allocate memory for the shocked word
                strncpy(shockedWord, newStr, counter); // Copy the new string to shockedWord
                printf("\n%s %c %s", shockedWord, str[i], "is trying to shock us with this character!");
                free(shockedWord); // Free memory allocated for shockedWord
                counter = 0; // Reset counter for newString
            }
            newStr[counter++] = str[i]; // Add non-alphanumeric character as is
            tempCounter++; // Increment tempCounter for next alphanumeric character
        }
    }

    // Add the last alphanumeric character or sequence to newString
    if (counter > 0) {
        newStr[counter] = '\0';
        shockedWord = (char *)malloc((counter + 1) * sizeof(char)); // Allocate memory for the shocked word
        strncpy(shockedWord, newStr, counter); // Copy the new string to shockedWord
        printf("\n%s %c ", shockedWord, str[i]);
        free(shockedWord); // Free memory allocated for shockedWord
    }

    free(newStr); // Free memory allocated for newString
}

int main() {
    char str[SIZE];

    printf("Enter a string: ");
    fgets(str, SIZE, stdin);

    str[strcspn(str, "\n")] = '\0'; // Remove newline character from string

    printf("\nBefore shocking: %s", str);
    strShocker(str); // Call the function to shock the string

    return 0;
}