//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

/*Function to simulate time travel*/
void timeTravel(int year, int month, int day, int hour, int minute, int second){
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    t->tm_year = year - 1900;
    t->tm_mon = month - 1;
    t->tm_mday = day;
    t->tm_hour = hour;
    t->tm_min = minute;
    t->tm_sec = second;
    mktime(t);

    /*Printing the date and time of time travel*/
    printf("You have traveled back in time to %d-%02d-%02d %02d:%02d:%02d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);

    /*Simulating a Romeo and Juliet scenario*/
    if(year == 1597 && month == 2 && day == 14){
        printf("\n\nWelcome to Verona, Italy in the year 1597!\n");
        printf("You have arrived in time to witness the tragic love story of Romeo and Juliet.\n");
        printf("As you walk through the bustling streets of Verona, you see two young lovers gazing at each other across a crowded square.\n");
        printf("Their names are Romeo and Juliet, and they are deeply in love despite being from rival families.\n");
        printf("Their families have been feuding for generations, making their love impossible.\n");
        printf("You watch as they sneak away to a secret meeting place, hoping to find a way to be together forever.\n");
        printf("But their love is not meant to be, and tragedy strikes when they both meet their untimely end.\n");
        printf("As you travel back to the present day, you can't help but think about the power of love and the tragedy it can bring.\n");
    }else{
        printf("\n\nWelcome to the year %d-%02d-%02d %02d:%02d:%02d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
        printf("It seems like you have traveled to a random time and place.\n");
        printf("Perhaps there is a lesson to be learned in the events that unfold during your journey.\n");
    }
}

int main(){
    int year, month, day, hour, minute, second;
    char choice;

    printf("Welcome to the time travel simulator!\n");
    printf("Enter the date and time you wish to travel to:\n");
    
    /*Taking input from user*/
    printf("Year (in YYYY format): ");
    scanf("%d", &year);
    printf("Month (in MM format): ");
    scanf("%d", &month);
    printf("Day (in DD format): ");
    scanf("%d", &day);
    printf("Hour (in 24-hour format): ");
    scanf("%d", &hour);
    printf("Minute: ");
    scanf("%d", &minute);
    printf("Second: ");
    scanf("%d", &second);
    
    /*Checking for valid input*/
    if(year>1970 && month>=1 && month<=12 && day>=1 && day <= 31 && hour>=0 && hour<=23 && minute>=0 && minute<=59 && second>=0 && second<=59){
        timeTravel(year, month, day, hour, minute, second);
    }else{
        printf("Invalid date and/or time entered. Please try again.\n");
        return 0;
    }
    
    /*Asking if the user wants to travel again*/
    printf("\n\nDo you want to travel again? (Y/N): ");
    scanf(" %c", &choice);
    if(choice == 'Y' || choice == 'y') main();
    else printf("Thank you for using the time travel simulator!\n");
    
    return 0;
}