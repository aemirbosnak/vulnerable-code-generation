//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int intInput(char prompt[]);
void timeTravel(void);

int main(void)
{
    int choice;
    do
    {
        // Main menu
        printf("\nTime Travel Simulator\n"
                "---------------------\n"
                "1. Travel through time\n"
                "2. Exit\n");

        choice = intInput("Enter choice: ");

        switch (choice)
        {
            case 1:
                timeTravel();
                break;
            case 2:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }  
    } while (choice != 2);

    return 0;
}

// Function to get integer input from user
int intInput(char prompt[])
{
    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;
}

// Function to simulate time travel
void timeTravel(void)
{
    int year, month, day, hour, minute, second;
    printf("\nEnter date and time to travel to (YYYY/MM/DD HH:MM:SS):\n");
    scanf("%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

    // Calculate current time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Adjust current time to time travel destination
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = minute;
    tm.tm_sec = second;

    // Get adjusted time in seconds
    time_t destination = mktime(&tm);

    // Calculate time difference in seconds
    time_t diff = difftime(destination, t);

    // Randomly shift shape of user
    srand(time(NULL));
    int shape = rand() % 3;
    switch (shape)
    {
        case 0:
            printf("\nYou have transformed into a bird!\n");
            break;
        case 1:
            printf("\nYou have transformed into a fish!\n");
            break;
        case 2:
            printf("\nYou have transformed into a wolf!\n");
            break;
    }

    // Active time travel simulation
    printf("\nInitiating time travel sequence...\n");
    for (int i = 3; i > 0; i--)
    {
        printf("%d...\n", i);
        sleep(1);
    }

    // Arrival at destination time
    printf("\nYou have arrived at your destination time!\n");

    // Display final date and time
    struct tm *finalTime = localtime(&destination);
    printf("Date: %04d/%02d/%02d\nTime: %02d:%02d:%02d\n",
            finalTime->tm_year + 1900, finalTime->tm_mon + 1, finalTime->tm_mday,
            finalTime->tm_hour, finalTime->tm_min, finalTime->tm_sec);

    // Return to present time
    printf("\nReturning to present time...\n");
    for (int i = 3; i > 0; i--)
    {
        printf("%d...\n", i);
        sleep(1);
    }

    // Display current date and time
    t = time(NULL);
    struct tm *currentTime = localtime(&t);
    printf("\nYou are now back in the present time.\n"
            "Date: %04d/%02d/%02d\nTime: %02d:%02d:%02d\n",
            currentTime->tm_year + 1900, currentTime->tm_mon + 1, currentTime->tm_mday,
            currentTime->tm_hour, currentTime->tm_min, currentTime->tm_sec);

    // Display shape shifted form
    switch (shape)
    {
        case 0:
            printf("You have returned to human form from a bird.\n");
            break;
        case 1:
            printf("You have returned to human form from a fish.\n");
            break;
        case 2:
            printf("You have returned to human form from a wolf.\n");
            break;
    }
    printf("\nTime travel sequence complete.\n");
}