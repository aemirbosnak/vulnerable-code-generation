//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global array of fortunes
char fortunes[5][100] = {
    "You will meet someone special today.",
    "An unexpected event will bring you good fortune.",
    "You will find success in your career.",
    "Unexpected financial gains are coming your way.",
    "A long lost friend will re-enter your life."
};

// Function to generate a random fortune
char *get_fortune() {
    srand(time(NULL));
    int i = rand() % 5;
    return fortunes[i];
}

int main() {
    char day[10], month[10];
    int year, age;

    // Get user's birth date
    printf("Enter your birth date (dd/mm/yyyy): ");
    scanf("%s/%s/%d", day, month, &year);

    // Calculate user's age
    time_t now = time(NULL);
    struct tm *time_now = localtime(&now);
    int current_year = time_now->tm_year + 1900;
    age = current_year - year;

    // Ask user if they want their fortune
    char response[10];
    printf("Hello! Would you like to know your fortune for today? (Yes or No): ");
    scanf("%s", response);

    if (strcmp(response, "Yes") == 0) {
        // Generate and display fortune
        char *fortune = get_fortune();
        printf("Your fortune for today is: %s\n", fortune);
    } else {
        printf("Okay, have a great day!\n");
    }

    printf("Thank you for using the Automated Fortune Teller.\n");
    return 0;
}