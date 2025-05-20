//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Function to convert a month number to a string
char* month_to_string(int month) {
    static char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month];
}

// Function to convert a day of the week number to a string
char* day_of_week_to_string(int day_of_week) {
    static char days[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days[day_of_week];
}

// Function to convert a date string to a struct tm
struct tm* string_to_tm(char* date_string) {
    struct tm tm;
    strptime(date_string, "%A, %B %d, %Y", &tm);
    return &tm;
}

// Function to convert a struct tm to a date string
char* tm_to_string(struct tm* tm) {
    char date_string[MAX_STRING_LENGTH];
    strftime(date_string, MAX_STRING_LENGTH, "%A, %B %d, %Y", tm);
    return strdup(date_string);
}

// Function to get the user's date input
char* get_date_input() {
    char input[MAX_STRING_LENGTH];
    printf("Enter a date in the format 'Day of the week, Month day, Year' (e.g. 'Monday, January 1, 2022'): ");
    fgets(input, MAX_STRING_LENGTH, stdin);
    return strtok(input, "\n");
}

int main() {
    char* date_string = get_date_input();
    struct tm* tm = string_to_tm(date_string);
    char* day_of_week_string = day_of_week_to_string(tm->tm_wday);
    char* month_string = month_to_string(tm->tm_mon + 1);
    char* formatted_date_string = tm_to_string(tm);

    printf("Today is %s, %s %d, %s.\n", day_of_week_string, month_string, tm->tm_mday, formatted_date_string);

    free(formatted_date_string);
    free(day_of_week_string);
    free(month_string);
    free(date_string);

    return 0;
}