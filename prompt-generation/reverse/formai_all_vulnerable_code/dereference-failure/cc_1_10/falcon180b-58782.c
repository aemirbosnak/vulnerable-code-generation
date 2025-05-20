//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

char *month_name(int month) {
    static char *months[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    return months[month];
}

int main() {
    char input[256];
    int day, month, year;
    char *token;
    struct tm date;

    printf("Enter a date in the format MM/DD/YYYY: ");
    fgets(input, sizeof(input), stdin);

    // Parse input
    token = strtok(input, "/");
    month = atoi(token);
    token = strtok(NULL, "/");
    day = atoi(token);
    token = strtok(NULL, "/");
    year = atoi(token);

    // Validate input
    if (month < 1 || month > 12) {
        printf("Invalid month.\n");
        return 1;
    }
    if (day < 1 || day > 31) {
        printf("Invalid day.\n");
        return 1;
    }

    // Convert to struct tm
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    date.tm_hour = 0;
    date.tm_min = 0;
    date.tm_sec = 0;

    // Print formatted date
    printf("The date is: %s, %d %s %d\n", month_name(date.tm_mon + 1), day, month_name(date.tm_mon + 1), year + 1900);

    return 0;
}