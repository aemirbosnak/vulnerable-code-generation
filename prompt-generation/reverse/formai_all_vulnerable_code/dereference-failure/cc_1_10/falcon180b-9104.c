//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DATE_LENGTH 64
#define DATE_FORMAT "dd/mm/yyyy"
#define DELIMITER '/'
#define MONTH_DELIMITER '.'

int main() {
    char input_date[MAX_DATE_LENGTH];
    char *token = NULL;
    int day, month, year;
    struct tm date_struct;
    time_t date_time;
    char output_date[MAX_DATE_LENGTH];

    printf("Enter a date in the format 'dd/mm/yyyy': ");
    fgets(input_date, MAX_DATE_LENGTH, stdin);

    // Parse the input date
    token = strtok(input_date, DELIMITER);
    day = atoi(token);
    token = strtok(NULL, DELIMITER);
    month = atoi(token);
    token = strtok(NULL, DELIMITER);
    year = atoi(token);

    // Check if the date is valid
    if (month < 1 || month > 12) {
        printf("Invalid month!\n");
        return 1;
    }

    if (day < 1 || day > 31) {
        printf("Invalid day!\n");
        return 1;
    }

    if (year < 1000 || year > 9999) {
        printf("Invalid year!\n");
        return 1;
    }

    // Convert the input date to a struct tm
    date_struct.tm_year = year - 1900;
    date_struct.tm_mon = month - 1;
    date_struct.tm_mday = day;

    // Get the current timezone
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);

    // Set the timezone of the input date
    date_struct.tm_isdst = local_time->tm_isdst;
    date_struct.tm_gmtoff = local_time->tm_gmtoff;

    // Convert the input date to a time_t
    date_time = mktime(&date_struct);

    // Convert the time_t to a string in the format 'dd/mm/yyyy'
    strftime(output_date, MAX_DATE_LENGTH, DATE_FORMAT, localtime(&date_time));

    printf("The input date is: %s\n", input_date);
    printf("The output date is: %s\n", output_date);

    return 0;
}