//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    printf("-----------------------------\n");
    printf("Welcome to Time Travel Simulator!\n");
    printf("-----------------------------\n\n");

    //enter birth year
    int birth_year;
    printf("What year were you born in? ");
    scanf("%d", &birth_year);

    //calculate age
    int current_year;
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    current_year = t->tm_year + 1900;
    int age = current_year - birth_year;

    printf("\n\n");

    //show user options
    char choice;
    printf("Select an option:\n");
    printf("1 - Travel back in time\n");
    printf("2 - Travel to the future\n");
    printf("3 - Exit\n\n");


    while(1)
    {
        printf("What would you like to do?: ");
        scanf(" %c",&choice);

        if(choice == '1')
        {
            int year;
            printf("Enter the year you want to travel to (yyyy): ");
            scanf("%d", &year);

            //check if year entered is valid
            if(year >= current_year)
            {
                printf("You can't travel to the future (yet)!\n");
            }
            else if(year < birth_year)
            {
                printf("You weren't born yet!\n");
            }
            else
            {
                printf("Woohoo! Enjoy your trip back in time to %d!\n", year);
                break;
            }
        }
        else if(choice == '2')
        {
            int year;
            printf("Enter the year you want to travel to (yyyy): ");
            scanf("%d", &year);

            //check if year entered is valid
            if(year < current_year)
            {
                printf("You can't travel back in time (yet)!\n");
            }
            else if(year - birth_year > 120)
            {
                printf("You probably won't be around in %d...\n", year);
            }
            else
            {
                printf("Woohoo! Enjoy your trip to the future in %d!\n", year);
                break;
            }
        }
        else if(choice == '3')
        {
            printf("Goodbye! Thanks for using our Time Travel Simulator!\n");
            exit(0);
        }
        else
        {
            printf("Sorry, invalid option. Please select 1, 2, or 3.\n");
        }
    }
    return 0;
}