//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of days in each month
int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Define the names of the months
char *months[] = {"January", "February", "March", "April", "May", "June",
                   "July", "August", "September", "October", "November", "December"};

// Define the names of the days of the week
char *days_of_week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define the leap year function
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

// Define the date converter function
void date_converter(int year, int month, int day) {
    // Check if the date is valid
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > days_in_month[month - 1]) {
        printf("Invalid date.\n");
        return;
    }

    // Calculate the day of the year
    int day_of_year = 0;
    for (int i = 0; i < month - 1; i++) {
        day_of_year += days_in_month[i];
    }
    day_of_year += day;

    // Calculate the day of the week
    int day_of_week = (day_of_year + 3) % 7;

    // Print the date in the desired format
    printf("%s, %s %d, %d\n", days_of_week[day_of_week], months[month - 1], day, year);
}

int main() {
    // Get the current date and time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Print the current date in the desired format
    date_converter(tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday);

    return 0;
}