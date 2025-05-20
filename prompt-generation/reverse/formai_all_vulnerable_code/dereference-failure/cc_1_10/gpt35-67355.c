//FormAI DATASET v1.0 Category: Date and time ; Style: imaginative
// Welcome to our virtual world clock!

#include <stdio.h>
#include <time.h>

int main() {
    //we declare some variables and print out descriptions to give the program some structure and context

    time_t now;
    struct tm* local;
    struct tm* london;
    struct tm* tokyo;
    char nowString[25];

    printf("Welcome to our virtual world clock.\n");
    printf("This program shows you the current time in three different cities around the world.\n");
    printf("For reference, the time zone this program runs in is UTC.\n");
    printf("Press any key to continue...\n");
    getchar();
    
    printf("Getting current time...\n");

    // We'll use the time() function to get the current timestamp,
    // then use localtime() to create a struct of type tm that breaks it down into year, month, day, hour,
    // minute, and second components. We'll store that struct in the local variable.
    // We'll also convert the timestamp to a human-readable string and store it in the nowString variable.
    now = time(NULL);
    local = localtime(&now);
    strftime(nowString, sizeof(nowString), "%c", local);

    printf("The current time in this location is: %s\n", nowString);

    // Now we want to calculate the time in two other time zones.
    // We'll create two more structs of type tm, but instead of using localtime(),
    // which takes the local time zone into account, we'll set the tm_gmtoff field of each one to the desired
    // offset from UTC. In this case, London is five hours ahead of us, while Tokyo is nine hours ahead.
    printf("Calculating time in London and Tokyo...\n");

    london = localtime(&now);
    london->tm_gmtoff = 60 * 60 * 5;
    strftime(nowString, sizeof(nowString), "%c", london);
    printf("The current time in London is: %s\n", nowString);

    tokyo = localtime(&now);
    tokyo->tm_gmtoff = 60 * 60 * 9;
    strftime(nowString, sizeof(nowString), "%c", tokyo);
    printf("The current time in Tokyo is: %s\n", nowString);

    printf("Press any key to exit...\n");
    getchar();

    return 0;
}