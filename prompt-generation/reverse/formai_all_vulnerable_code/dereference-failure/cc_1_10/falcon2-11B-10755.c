//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100];
    char* word;

    printf("Welcome to the Text-Based Adventure Game!\n");

    while (1) {
        printf("Please enter your choice:\n");
        printf("1. Go North\n");
        printf("2. Go South\n");
        printf("3. Go East\n");
        printf("4. Go West\n");
        printf("5. Take item\n");
        printf("6. Use item\n");
        printf("7. Inventory\n");
        printf("8. Quit\n");
        printf("Enter your choice: ");
        fgets(input, 100, stdin);

        word = strtok(input, " ");
        word = strtok(NULL, " ");

        if (strcmp(word, "1") == 0) {
            printf("You have gone north.\n");
        } else if (strcmp(word, "2") == 0) {
            printf("You have gone south.\n");
        } else if (strcmp(word, "3") == 0) {
            printf("You have gone east.\n");
        } else if (strcmp(word, "4") == 0) {
            printf("You have gone west.\n");
        } else if (strcmp(word, "5") == 0) {
            printf("You have taken the item.\n");
        } else if (strcmp(word, "6") == 0) {
            printf("You have used the item.\n");
        } else if (strcmp(word, "7") == 0) {
            printf("Here is your inventory:\n");
            // Display inventory here
        } else if (strcmp(word, "8") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}