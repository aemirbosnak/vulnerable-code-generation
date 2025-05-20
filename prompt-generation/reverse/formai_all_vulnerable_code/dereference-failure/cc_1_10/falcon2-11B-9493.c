//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a random string
char* generateRandomString(int length) {
    char* str = (char*)malloc(length + 1);
    str[length] = '\0'; // Add null terminator

    for (int i = 0; i < length; i++) {
        int randomNumber = rand() % 26 + 'A'; // Generate a random ASCII character
        str[i] = randomNumber;
    }

    return str;
}

int main() {
    // Prompt the user for their name
    printf("Enter your name: ");
    char name[100];
    scanf("%s", name);

    // Generate a random string for the user's weapon
    int weaponLength = rand() % 10 + 10;
    char* weapon = generateRandomString(weaponLength);

    // Print the user's name and weapon
    printf("Welcome to the Post-Apocalyptic C Rogue-like Game!\n\nYour name is %s and your weapon is %s.\n", name, weapon);

    // Prompt the user for their choice of action
    printf("What would you like to do?\n");
    printf("1. Explore the wasteland\n");
    printf("2. Fight a mutant\n");
    printf("3. Rest\n");
    printf("4. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You have explored the wasteland. You found a rusty can.\n");
            break;
        case 2:
            printf("You have fought a mutant. You have won!\n");
            break;
        case 3:
            printf("You have rested. Your HP has been restored to 100.\n");
            break;
        case 4:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}