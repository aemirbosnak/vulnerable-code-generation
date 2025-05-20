//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the months of the year
char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Define the days of the week
char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define the number of days in each month
int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Define the leap year rule
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

// Convert a date string to a date struct
struct date {
    int year;
    int month;
    int day;
} convert_date(char *date_string) {
    struct date date;

    // Parse the year
    date.year = atoi(strtok(date_string, "-"));

    // Parse the month
    char *month_name = strtok(NULL, "-");
    for (int i = 0; i < 12; i++) {
        if (strcmp(month_name, months[i]) == 0) {
            date.month = i + 1;
            break;
        }
    }

    // Parse the day
    date.day = atoi(strtok(NULL, "-"));

    return date;
}

// Convert a date struct to a date string
char *convert_date_string(struct date date) {
    char *date_string = malloc(11);

    // Format the date string
    sprintf(date_string, "%04d-%02d-%02d", date.year, date.month, date.day);

    return date_string;
}

// Get the day of the week for a given date
char *get_day_of_week(struct date date) {
    // Calculate the day of the week
    int day_of_week = (date.year + date.year / 4 - date.year / 100 + date.year / 400 + date.month + days_in_month[date.month - 1] + date.day) % 7;

    // Return the day of the week
    return days[day_of_week];
}

// Print the date in a human-readable format
void print_date(struct date date) {
    // Print the date
    printf("%s, %s %d, %d\n", get_day_of_week(date), months[date.month - 1], date.day, date.year);
}

// Main function
int main() {
    // Get the date from the user
    char date_string[11];
    printf("Enter a date (YYYY-MM-DD): ");
    scanf("%s", date_string);

    // Convert the date string to a date struct
    struct date date = convert_date(date_string);

    // Print the date in a human-readable format
    print_date(date);

    return 0;
}