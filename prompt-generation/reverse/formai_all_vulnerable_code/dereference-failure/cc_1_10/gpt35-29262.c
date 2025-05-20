//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("*** WELCOME TO THE TIME TRAVEL SIMULATOR! ***\n\n");

    // get current time
    time_t now;
    time(&now);

    struct tm *local = localtime(&now);

    int current_year = local->tm_year + 1900;


    printf("The current year is %d. Where would you like to go?\n", current_year);
    printf("Enter the year you would like to travel to: ");

    int target_year;
    scanf("%d", &target_year);

    if(target_year < current_year)
    {
        printf("Sorry, time travel to the past is not yet possible. Please enter a year in the future.\n");
        return 1;
    }

    printf("\n\nPreparing for time travel... Initiating launch sequence...\n\n");

    printf("3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    printf("BLAST OFF!!\n\n");

    printf("*** BOOM! You have arrived in the year %d! ***\n\n", target_year);

    printf("What would you like to do?\n");
    printf("[1] Explore the city\n");
    printf("[2] Meet historical figures\n");
    printf("[3] Investigate the future\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\n\nYou explore the city of the year %d and find it is completely different from what you know.\n", target_year);
            printf("The architecture is futuristic and there are flying cars everywhere.\n\n");
            break;

        case 2:
            printf("\n\nYou meet famous historical figures from the year %d.\n", target_year);
            printf("You have tea with Albert Einstein, drink wine with Leonardo da Vinci, and dance with Marie Curie!\n\n");
            break;

        case 3:
            printf("\n\nYou investigate the future of the year %d.\n", target_year);
            printf("You find that things are not as you expected.\n");
            printf("There are robots and AI everywhere, and humans have colonized Mars and other planets.\n\n");
            break;

        default:
            printf("\n\nInvalid choice. Returning to present day...\n");
            break;
    }

    printf("*** RETURNING TO PRESENT DAY ***\n");
    printf("Initiating return sequence...\n");

    printf("3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    printf("ARRIVING IN 3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    printf("WELCOME BACK TO PRESENT DAY!\n");

    return 0;
}