//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: brave
#include <stdio.h>
#include <time.h>

int main(){
    // welcome the user
    printf("Welcome to the Time Travel Simulator!\n");
    
    // get the current time
    time_t currentTime;
    time(&currentTime);

    // store the current time in a struct
    struct tm *localTime = localtime(&currentTime);

    // display the current time
    printf("The current time is: %d-%02d-%02d %02d:%02d:%02d\n", 
        localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
        localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

    // get the user's desired year to travel to
    int desiredYear;
    printf("Enter the year you would like to travel to: ");
    scanf("%d", &desiredYear);

    // calculate the number of years to travel
    int yearsToTravel = desiredYear - (localTime->tm_year + 1900);

    // display the number of years to travel
    printf("You will travel %d years into the %s.\n", 
        abs(yearsToTravel), yearsToTravel > 0 ? "future" : "past");

    // pause for dramatic effect
    printf("Press enter to begin your journey...\n");
    char ch = getchar();

    // simulate traveling through time
    for (int i = 0; i < abs(yearsToTravel); i++){
        // increment or decrement the current year
        if (yearsToTravel > 0){
            localTime->tm_year++;
        }
        else {
            localTime->tm_year--;
        }

        // update the time struct and display the current time
        currentTime = mktime(localTime);
        localTime = localtime(&currentTime);

        printf("Year %d: %d-%02d-%02d %02d:%02d:%02d\n",
            i + 1, localTime->tm_year + 1900, localTime->tm_mon + 1, 
            localTime->tm_mday, localTime->tm_hour, localTime->tm_min, 
            localTime->tm_sec);
    }

    // bid farewell to the user
    printf("You have arrived in the year %d! Enjoy your stay!\n", 
        localTime->tm_year + 1900);

    // close the program
    return 0;
}