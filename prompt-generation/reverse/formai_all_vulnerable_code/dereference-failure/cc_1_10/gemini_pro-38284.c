//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the struct for storing the date and time
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} DateAndTime;

// Define the function to convert a date and time to a string
char *dateAndTimeToStr(DateAndTime *dateAndTime) {
    // Allocate memory for the string
    char *str = malloc(sizeof(char) * 26);

    // Convert the date and time to a string
    sprintf(str, "%04d-%02d-%02d %02d:%02d:%02d",
            dateAndTime->year, dateAndTime->month, dateAndTime->day,
            dateAndTime->hour, dateAndTime->minute, dateAndTime->second);

    // Return the string
    return str;
}

// Define the function to convert a string to a date and time
DateAndTime *strToDateAndTime(char *str) {
    // Allocate memory for the date and time
    DateAndTime *dateAndTime = malloc(sizeof(DateAndTime));

    // Convert the string to a date and time
    sscanf(str, "%04d-%02d-%02d %02d:%02d:%02d",
            &dateAndTime->year, &dateAndTime->month, &dateAndTime->day,
            &dateAndTime->hour, &dateAndTime->minute, &dateAndTime->second);

    // Return the date and time
    return dateAndTime;
}

// Define the function to print the date and time
void printDateAndTime(DateAndTime *dateAndTime) {
    // Print the date and time
    printf("Date and Time: %s\n", dateAndTimeToStr(dateAndTime));
}

// Define the main function
int main() {
    // Create a date and time
    DateAndTime dateAndTime = {
        .year = 2023,
        .month = 3,
        .day = 8,
        .hour = 13,
        .minute = 37,
        .second = 0
    };

    // Print the date and time
    printDateAndTime(&dateAndTime);

    // Convert the date and time to a string
    char *str = dateAndTimeToStr(&dateAndTime);

    // Print the string
    printf("String: %s\n", str);

    // Convert the string to a date and time
    DateAndTime *dateAndTime2 = strToDateAndTime(str);

    // Print the date and time
    printDateAndTime(dateAndTime2);

    // Free the memory allocated for the string
    free(str);

    // Free the memory allocated for the date and time
    free(dateAndTime2);

    return 0;
}