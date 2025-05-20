//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} DateTime;

int main()
{
    // Initialize the random seed
    srand(time(NULL));

    // Get the current date and time
    time_t now = time(NULL);
    struct tm *currentDateTime = localtime(&now);

    // Create a random date and time
    DateTime randomDateTime;
    randomDateTime.year = rand() % 10000 + 1;
    randomDateTime.month = rand() % 12 + 1;
    randomDateTime.day = rand() % 31 + 1;
    randomDateTime.hour = rand() % 24;
    randomDateTime.minute = rand() % 60;
    randomDateTime.second = rand() % 60;

    // Print the current date and time
    printf("Current date and time: %d-%02d-%02d %02d:%02d:%02d\n", currentDateTime->tm_year + 1900, currentDateTime->tm_mon + 1, currentDateTime->tm_mday, currentDateTime->tm_hour, currentDateTime->tm_min, currentDateTime->tm_sec);

    // Print the random date and time
    printf("Random date and time: %d-%02d-%02d %02d:%02d:%02d\n", randomDateTime.year, randomDateTime.month, randomDateTime.day, randomDateTime.hour, randomDateTime.minute, randomDateTime.second);

    // Calculate the time difference between the two dates and times
    time_t timeDifference = mktime(&randomDateTime) - now;

    // Convert the time difference to days, hours, minutes, and seconds
    int days = timeDifference / (60 * 60 * 24);
    int hours = (timeDifference / (60 * 60)) % 24;
    int minutes = (timeDifference / 60) % 60;
    int seconds = timeDifference % 60;

    // Print the time difference
    printf("Time difference: %d days, %d hours, %d minutes, %d seconds\n", days, hours, minutes, seconds);

    return 0;
}