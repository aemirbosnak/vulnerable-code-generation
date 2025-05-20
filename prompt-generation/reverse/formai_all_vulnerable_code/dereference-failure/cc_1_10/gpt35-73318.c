//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int year, month, day, hour, minute, second;
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);
    printf("The current time is: %s \n", asctime(currentTime));
    printf("Enter a date and time in the past to time travel: \n");

    printf("Year (1900 - %d): ", currentTime->tm_year + 1900);
    scanf("%d", &year);

    printf("Month (1 - 12): ");
    scanf("%d", &month);

    printf("Day (1 - 31): ");
    scanf("%d", &day);

    printf("Hour (0 - 23): ");
    scanf("%d", &hour);

    printf("Minute (0 - 59): ");
    scanf("%d", &minute);

    printf("Second (0 - 59): ");
    scanf("%d", &second);

    // create a tm struct to hold the desired time
    struct tm desiredTime = {0};
    desiredTime.tm_year = year - 1900;
    desiredTime.tm_mon = month - 1;
    desiredTime.tm_mday = day;
    desiredTime.tm_hour = hour;
    desiredTime.tm_min = minute;
    desiredTime.tm_sec = second;

    // convert the desired time to UNIX time
    time_t desiredUnixTime = mktime(&desiredTime);

    // check if the desired time is in the past
    if (difftime(t, desiredUnixTime) < 0)
    {
        printf("You cannot time travel to the future!\n");
        return -1;
    }

    // set the system time to the desired time
    int result = system("date -u ");
    char unixTimeStr[20];
    sprintf(unixTimeStr, "%ld", desiredUnixTime);
    result += system(unixTimeStr);

    // check if the system time was set successfully
    if (result != 0)
    {
        printf("Time travel unsuccessful.\n");
        return -1;
    }

    printf("\nYou have successfully time traveled to %s \n", asctime(localtime(&desiredUnixTime)));

    return 0;
}