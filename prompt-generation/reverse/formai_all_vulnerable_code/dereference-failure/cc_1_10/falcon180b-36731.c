//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 100

// Define the structure for each fortune
typedef struct {
    char *text; // The text of the fortune
    int length; // The length of the fortune
} Fortune;

// Function to generate a random fortune
Fortune generateFortune() {
    Fortune fortune;
    char *fortunes[] = {
        "You will find happiness in unexpected places.",
        "A pleasant surprise awaits you today.",
        "Your hard work will pay off soon.",
        "You are destined for greatness.",
        "Success is within your reach.",
        "A new opportunity will present itself to you.",
        "Believe in yourself and all that you are.",
        "You are capable of achieving great things.",
        "Your future is bright and full of possibilities.",
        "You have the power to create your own destiny."
    };

    int numFortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    int randIndex = rand() % numFortunes;

    strncpy(fortune.text, fortunes[randIndex], MAX_FORTUNES - 1);
    fortune.length = strlen(fortune.text);

    return fortune;
}

// Function to print a fortune
void printFortune(Fortune fortune) {
    printf("Your fortune: %s\n", fortune.text);
}

// Main function
int main() {
    srand(time(NULL));

    Fortune fortune;
    char choice;

    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Would you like to hear your fortune? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            fortune = generateFortune();
            printFortune(fortune);
        } else {
            printf("Thank you for visiting. Come back soon!\n");
        }

        printf("Would you like to hear another fortune? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}