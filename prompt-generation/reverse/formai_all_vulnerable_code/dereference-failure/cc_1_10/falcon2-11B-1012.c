//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to convert natural language date to a standard date format
int convertDate(char* dateString) {
    // Split the date string into day, month, and year components
    char* day = strtok(dateString, " ");
    char* month = strtok(NULL, " ");
    char* year = strtok(NULL, " ");

    // Convert the day component to a numeric value
    int dayNum = atoi(day);

    // Convert the month component to a numeric value
    int monthNum = atoi(month);

    // Check if the month is valid
    if (monthNum > 12 || monthNum < 1) {
        printf("Invalid month!\n");
        return -1;
    }

    // Convert the year component to a numeric value
    int yearNum = atoi(year);

    // Check if the year is valid
    if (yearNum > 9999 || yearNum < 1000) {
        printf("Invalid year!\n");
        return -1;
    }

    // Calculate the standard date format
    char standardDate[11];
    sprintf(standardDate, "%d-%02d-%04d", dayNum, monthNum, yearNum);

    // Print the standard date format
    printf("Standard date format: %s\n", standardDate);

    return 0;
}

// Main function
int main() {
    char dateString[50];
    printf("Enter a natural language date (e.g. 'March 5, 2022'): ");
    scanf("%s", dateString);

    int result = convertDate(dateString);
    if (result == -1) {
        printf("Invalid date!\n");
    }

    return 0;
}