//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: surrealist
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Function to convert date to natural language
void convertDate(struct tm *time) {
    int month = time->tm_mon + 1;
    int day = time->tm_mday;
    int year = time->tm_year - 1900;

    // Convert month to natural language
    switch (month) {
        case 1:
            printf("January");
            break;
        case 2:
            printf("February");
            break;
        case 3:
            printf("March");
            break;
        case 4:
            printf("April");
            break;
        case 5:
            printf("May");
            break;
        case 6:
            printf("June");
            break;
        case 7:
            printf("July");
            break;
        case 8:
            printf("August");
            break;
        case 9:
            printf("September");
            break;
        case 10:
            printf("October");
            break;
        case 11:
            printf("November");
            break;
        case 12:
            printf("December");
            break;
    }

    // Convert day to natural language
    if (day < 10) {
        printf("0");
    }
    printf("%d", day);

    // Convert year to natural language
    if (year % 100 == 0) {
        printf("th");
    } else if (year % 10 == 0) {
        printf("th");
    } else if (year % 4 == 0) {
        printf("th");
    } else if (year % 2 == 0) {
        printf("nd");
    } else if (year % 3 == 0) {
        printf("rd");
    } else {
        printf("th");
    }
    printf(" century");
}

// Function to get current time
void getTime() {
    struct tm *currentTime;
    time_t now = time(NULL);
    currentTime = localtime(&now);

    // Print converted date
    convertDate(currentTime);
}

int main() {
    getTime();
    return 0;
}