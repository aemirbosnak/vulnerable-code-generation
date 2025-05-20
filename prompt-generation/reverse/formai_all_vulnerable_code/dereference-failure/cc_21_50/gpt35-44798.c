//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char date_input[50];
    printf("Enter a date (DD/MM/YYYY format): ");
    fgets(date_input, sizeof(date_input), stdin);
    strtok(date_input, "\n");

    // Separating the input date into day, month and year variables
    char *day_str = strtok(date_input, "/");
    char *month_str = strtok(NULL, "/");
    char *year_str = strtok(NULL, "/");
    int day = atoi(day_str);
    int month = atoi(month_str);
    int year = atoi(year_str);

    // Checking for valid date
    if ((day <= 0 || day > 31) || (month <= 0 || month > 12) || (year <= 0)) {
        printf("Invalid date entered\n");
        return 1;
    }

    // Checking for leap year
    int is_leap_year = 0;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        is_leap_year = 1;
    }

    // Determining the number of days passed since 1st January of the input year
    int days_passed = 0;
    int month_days[12] = {31, 28 + is_leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < month - 1; i++) {
        days_passed += month_days[i];
    }
    days_passed += day - 1;

    // Converting the number of days to the date in Natural Language
    int year_days = is_leap_year ? 366 : 365;
    if ((days_passed >= 0) && (days_passed <= 31)) {
        printf("January %d, %d", days_passed + 1, year);
    } else if ((days_passed > 31) && (days_passed <= 59 + is_leap_year)) {
        printf("February %d, %d", days_passed - 31, year);
    } else if ((days_passed > 59 + is_leap_year) && (days_passed <= 90 + is_leap_year)) {
        printf("March %d, %d", days_passed - (59 + is_leap_year), year);
    } else if ((days_passed > 90 + is_leap_year) && (days_passed <= 120 + is_leap_year)) {
        printf("April %d, %d", days_passed - (90 + is_leap_year), year);
    } else if ((days_passed > 120 + is_leap_year) && (days_passed <= 151 + is_leap_year)) {
        printf("May %d, %d", days_passed - (120 + is_leap_year), year);
    } else if ((days_passed > 151 + is_leap_year) && (days_passed <= 181 + is_leap_year)) {
        printf("June %d, %d", days_passed - (151 + is_leap_year), year);
    } else if ((days_passed > 181 + is_leap_year) && (days_passed <= 212 + is_leap_year)) {
        printf("July %d, %d", days_passed - (181 + is_leap_year), year);
    } else if ((days_passed > 212 + is_leap_year) && (days_passed <= 243 + is_leap_year)) {
        printf("August %d, %d", days_passed - (212 + is_leap_year), year);
    } else if ((days_passed > 243 + is_leap_year) && (days_passed <= 273 + is_leap_year)) {
        printf("September %d, %d", days_passed - (243 + is_leap_year), year);
    } else if ((days_passed > 273 + is_leap_year) && (days_passed <= 304 + is_leap_year)) {
        printf("October %d, %d", days_passed - (273 + is_leap_year), year);
    } else if ((days_passed > 304 + is_leap_year) && (days_passed <= 334 + is_leap_year)) {
        printf("November %d, %d", days_passed - (304 + is_leap_year), year);
    } else if ((days_passed > 334 + is_leap_year) && (days_passed <= year_days)) {
        printf("December %d, %d", days_passed - (334 + is_leap_year), year);
    } else {
        printf("Invalid date entered\n");
        return 1;
    }

    return 0;
}