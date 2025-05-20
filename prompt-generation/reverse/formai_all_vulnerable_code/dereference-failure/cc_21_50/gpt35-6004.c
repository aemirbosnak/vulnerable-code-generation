//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: detailed
/* A Time Travel Simulator program that allows the user to select different dates and travel to a specific time period. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int day, month, year, selection;
    time_t t = time(NULL);
    struct tm *time = localtime(&t);
    int current_year = time->tm_year + 1900;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("What year would you like to travel to? (Enter a year between 0 and %d)\n", current_year);
    scanf("%d", &year);

    // Checking if the user inputs a valid year
    while (year < 0 || year > current_year)
    {
        printf("Invalid year, please enter a year between 0 and %d: ", current_year);
        scanf("%d", &year);
    }

    printf("You have traveled to the year %d\n", year);
    printf("Please select a time period:\n");
    printf("1. Prehistoric Times\n");
    printf("2. Ancient Times\n");
    printf("3. Middle Ages\n");
    printf("4. Renaissance\n");
    printf("5. Modern Times\n");
    printf("Selection: ");
    scanf("%d", &selection);

    // Checking if the user inputs a valid selection
    while (selection < 1 || selection > 5)
    {
        printf("Invalid selection, please enter a number between 1 and 5: ");
        scanf("%d", &selection);
    }

    printf("You have selected: ");

    switch (selection)
    {
        case 1:
            printf("Prehistoric Times\n");
            printf("Please enter a year between 5000 BC and 3000 BC: ");
            scanf("%d", &year);

            while (year < -5000 || year > -3000)
            {
                printf("Invalid year, please enter a year between 5000 BC and 3000 BC: ");
                scanf("%d", &year);
            }
            printf("You have traveled to %d BC\n", abs(year));
            break;

        case 2:
            printf("Ancient Times\n");
            printf("Please select a civilization:\n");
            printf("1. Ancient Egypt\n");
            printf("2. Ancient Greece\n");
            printf("3. Ancient Rome\n");
            printf("Selection: ");
            scanf("%d", &selection);

            while (selection < 1 || selection > 3)
            {
                printf("Invalid selection, please enter a number between 1 and 3: ");
                scanf("%d", &selection);
            }

            switch (selection)
            {
                case 1:
                    printf("You have traveled to Ancient Egypt\n");
                    printf("Please enter a year between 3100 BC and 30 BC: ");
                    scanf("%d", &year);

                    while (year < -3100 || year > -30)
                    {
                        printf("Invalid year, please enter a year between 3100 BC and 30 BC: ");
                        scanf("%d", &year);
                    }
                    printf("You have traveled to %d BC\n", abs(year));
                    break;

                case 2:
                    printf("You have traveled to Ancient Greece\n");
                    printf("Please enter a year between 800 BC and 300 BC: ");
                    scanf("%d", &year);
                    
                    while (year < -800 || year > -300)
                    {
                        printf("Invalid year, please enter a year between 800 BC and 300 BC: ");
                        scanf("%d", &year);
                    }
                    printf("You have traveled to %d BC\n", abs(year));
                    break;

                case 3:
                    printf("You have traveled to Ancient Rome\n");
                    printf("Please enter a year between 753 BC to 476 AD: ");
                    scanf("%d", &year);

                    while (year < -753 || year > 476)
                    {
                        printf("Invalid year, please enter a year between 753 BC and 476 AD: ");
                        scanf("%d", &year);
                    }

                    if (year <= 0)
                        printf("You have traveled to %d BC\n", abs(year));
                    else
                        printf("You have traveled to %d AD\n", year);
                    break;
            }
            break;

        case 3:
            printf("Middle Ages\n");
            printf("Please enter a year between 500 and 1500 AD: ");
            scanf("%d", &year);

            while (year < 500 || year > 1500)
            {
                printf("Invalid year, please enter a year between 500 and 1500 AD: ");
                scanf("%d", &year);
            }
            printf("You have traveled to %d AD\n", year);
            break;

        case 4:
            printf("Renaissance\n");
            printf("Please enter a year between 1300 and 1700 AD: ");
            scanf("%d", &year);

            while (year < 1300 || year > 1700)
            {
                printf("Invalid year, please enter a year between 1300 and 1700 AD: ");
                scanf("%d", &year);
            }
            printf("You have traveled to %d AD\n", year);
            break;

        case 5:
            printf("Modern Times\n");
            printf("Please enter a year between 1800 and %d: ", current_year);
            scanf("%d", &year);

            while (year < 1800 || year > current_year)
            {
                printf("Invalid year, please enter a year between 1800 and %d: ", current_year);
                scanf("%d", &year);
            }
            printf("You have traveled to the year %d\n", year);
            break;
    }

    printf("Thank you for using the Time Travel Simulator. Enjoy your journey!\n");
    return 0;
}