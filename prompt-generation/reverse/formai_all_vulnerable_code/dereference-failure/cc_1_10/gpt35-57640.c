//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to time travel
void timeTravel()
{
    //Get current time
    time_t t = time(NULL);
    struct tm currentTime = *localtime(&t);
    
    //Generate random year
    srand(time(NULL));
    int randomYear = rand() % 10000 + currentTime.tm_year - 5000; //Years between (current year - 5000) and (current year + 4999)
    
    //Generate random month and day
    int randomMonth = rand() % 12 + 1; //1 to 12
    int randomDay = 0;
    switch(randomMonth)
    {
        case 2: //February
            if(randomYear % 400 == 0 || (randomYear % 4 == 0 && randomYear % 100 != 0)) //Leap year
                randomDay = rand() % 29 + 1; //1 to 29
            else
                randomDay = rand() % 28 + 1; //1 to 28
            break;
        case 4: //April
        case 6: //June
        case 9: //September
        case 11: //November
            randomDay = rand() % 30 + 1; //1 to 30
            break;
        default: //January, March, May, July, August, October, December 
            randomDay = rand() % 31 + 1; //1 to 31
    }
    
    //Generate random hour, minute, and second
    int randomHour = rand() % 24; //0 to 23
    int randomMinute = rand() % 60; //0 to 59
    int randomSecond = rand() % 60; //0 to 59
    
    //Set new time
    struct tm newTime = {0};
    newTime.tm_year = randomYear - 1900; //Year since 1900
    newTime.tm_mon = randomMonth - 1; //0 to 11
    newTime.tm_mday = randomDay; //1 to 31
    newTime.tm_hour = randomHour; //0 to 23
    newTime.tm_min = randomMinute; //0 to 59
    newTime.tm_sec = randomSecond; //0 to 59
    time_t newT = mktime(&newTime);
    struct tm newCurrentTime = *localtime(&newT);
    
    //Display the time travel
    printf("You have successfully time traveled to %02d/%02d/%04d %02d:%02d:%02d!\n", newCurrentTime.tm_mon + 1, newCurrentTime.tm_mday, newCurrentTime.tm_year + 1900, newCurrentTime.tm_hour, newCurrentTime.tm_min, newCurrentTime.tm_sec);
}

int main()
{
    int choice;
    
    printf("Welcome to the Time Travel Simulator!\n");
    do
    {
        printf("\nWhat would you like to do?\n");
        printf("1. Time Travel\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                timeTravel();
                break;
            case 2:
                printf("Thanks for using the Time Travel Simulator!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }while(choice != 2);
    
    return 0;
}