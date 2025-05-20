//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Function to convert string month to integer value */
int convertMonthToInteger(char* month) {
    if (strcmp(month, "January") == 0) return 1;
    if (strcmp(month, "February") == 0) return 2;
    if (strcmp(month, "March") == 0) return 3;
    if (strcmp(month, "April") == 0) return 4;
    if (strcmp(month, "May") == 0) return 5;
    if (strcmp(month, "June") == 0) return 6;
    if (strcmp(month, "July") == 0) return 7;
    if (strcmp(month, "August") == 0) return 8;
    if (strcmp(month, "September") == 0) return 9;
    if (strcmp(month, "October") == 0) return 10;
    if (strcmp(month, "November") == 0) return 11;
    if (strcmp(month, "December") == 0) return 12;
    return 0; // Invalid month value
}

/* Function to convert integer month to string value */
char* convertMonthToString(int month) {
    switch (month) {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "Invalid month value";
    }
}

/* Function to convert date to Unix time format */
time_t convertDateToUnix(int year, int month, int day) {
    struct tm timeinfo = {0};
    timeinfo.tm_year = year - 1900; // Years since 1900
    timeinfo.tm_mon = month - 1; // Months since January
    timeinfo.tm_mday = day; // Day of the month
    return mktime(&timeinfo);
}

/* Function to convert Unix time format to date string */
char* convertUnixToDate(time_t unixtime) {
    struct tm* timeinfo = localtime(&unixtime);
    char* date = (char*) malloc(12*sizeof(char)); // Date format: DD/MM/YYYY + null terminator
    sprintf(date, "%d/%d/%d", timeinfo->tm_mday, timeinfo->tm_mon+1, timeinfo->tm_year+1900);
    return date;
}

/* Main function */
int main() {
    char dateStr[20]; // Date input string format: DD MMMM YYYY
    int day, month, year;
    printf("Enter a date in DD MMMM YYYY format: ");
    fgets(dateStr, 20, stdin);

    // Parse day, month and year values from input string
    day = atoi(strtok(dateStr, " "));
    month = convertMonthToInteger(strtok(NULL, " "));
    year = atoi(strtok(NULL, " "));

    // Convert date to Unix time format and then back to string
    time_t unixtime = convertDateToUnix(year, month, day);
    char* date = convertUnixToDate(unixtime);

    // Print out converted date string
    printf("The date in DD/MM/YYYY format is: %s\n", date);

    // Free dynamically allocated memory
    free(date);

    return 0;
}