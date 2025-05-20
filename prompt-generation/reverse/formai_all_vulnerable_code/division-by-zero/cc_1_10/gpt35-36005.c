//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set the seed for the random number generator
    srand(time(0));

    // Welcome message
    printf("Welcome to the Time Travel Simulator!\n\n");

    // Ask the user for their birth year
    int birthYear;
    printf("What year were you born? ");
    scanf("%d", &birthYear);

    // Get the current year
    time_t now = time(0);
    struct tm* current = localtime(&now);
    int currentYear = current->tm_year + 1900;

    // Calculate the user's age
    int age = currentYear - birthYear;

    // Display the user's age
    printf("You are currently %d years old.\n\n", age);

    // Ask the user if they want to time travel
    char choice;
    printf("Do you want to time travel? (Y/N) ");
    scanf(" %c", &choice);

    // If the user wants to time travel
    if (choice == 'Y' || choice == 'y')
    {
        // Generate a random year to time travel to
        int randomYear = rand() % currentYear;

        // Display the year the user will travel to
        printf("\nYou will time travel to the year %d.\n\n", randomYear);

        // Calculate how many years into the future or past the user will go
        int years = abs(randomYear - birthYear);

        // Display how many years they will go
        printf("You will travel %d years into the ", years);
        if (randomYear > currentYear)
        {
            printf("future.\n\n");
        }
        else
        {
            printf("past.\n\n");
        }

        // Ask the user if they want to continue
        char cont;
        printf("Press any key to continue...\n");
        scanf(" %c", &cont);

        // Display the countdown to time travel
        printf("3...\n");
        sleep(1);
        printf("2...\n");
        sleep(1);
        printf("1...\n");
        sleep(1);
        printf("Time travel initiated!\n\n");
        
        // Display the result of time traveling
        if (randomYear > currentYear)
        {
            printf("You have traveled to the future.\n\n");
        }
        else
        {
            printf("You have traveled to the past.\n\n");
        }

        printf("You are now %d years old.\n\n", age + years);

        // Ask the user if they want to time travel again
        char again;
        printf("Do you want to time travel again? (Y/N) ");
        scanf(" %c", &again);

        // If the user wants to time travel again, restart the program
        if (again == 'Y' || again == 'y')
        {
            main();
        }
        else
        {
            printf("\nThank you for using the Time Travel Simulator!\n");
        }
    }
    else
    {
        printf("\nThank you for using the Time Travel Simulator!\n");
    }

    return 0;
}