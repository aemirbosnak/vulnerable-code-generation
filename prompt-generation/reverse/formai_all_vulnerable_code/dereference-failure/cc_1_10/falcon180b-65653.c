//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    char* month;
    int day;
    int year;
} Date;

Date parse_date(char* date_string) {
    Date date;
    char* month_str;
    int day, year;

    month_str = strtok(date_string, " ");
    day = atoi(strtok(NULL, " "));
    year = atoi(strtok(NULL, "\n"));

    date.month = month_str;
    date.day = day;
    date.year = year;

    return date;
}

char* format_date(Date date) {
    char* formatted_date;
    time_t timestamp;
    struct tm* tm_struct;

    tm_struct = malloc(sizeof(struct tm));
    strptime(date.month, "%B", tm_struct);
    tm_struct->tm_mday = date.day;
    tm_struct->tm_year = date.year - 1900;
    timestamp = mktime(tm_struct);

    formatted_date = asctime(tm_struct);

    free(tm_struct);
    return formatted_date;
}

int main() {
    char input_date[MAX_STRING_LENGTH];

    printf("Enter a date in the format 'Month Day, Year': ");
    scanf("%s", input_date);

    Date date = parse_date(input_date);
    char* formatted_date = format_date(date);

    printf("Formatted date: %s\n", formatted_date);

    return 0;
}