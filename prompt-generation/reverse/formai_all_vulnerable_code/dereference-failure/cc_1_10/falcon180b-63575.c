//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_DATE_LENGTH 50
#define MAX_MONTH_NAME_LENGTH 15
#define MAX_WEEKDAY_NAME_LENGTH 15
#define MAX_TIME_LENGTH 20
#define MAX_TIMEZONE_LENGTH 50

typedef struct {
    char date[MAX_DATE_LENGTH];
    char month_name[MAX_MONTH_NAME_LENGTH];
    char weekday_name[MAX_WEEKDAY_NAME_LENGTH];
    char time[MAX_TIME_LENGTH];
    char timezone[MAX_TIMEZONE_LENGTH];
} Date;

void initialize_date(Date* date) {
    strcpy(date->date, "");
    strcpy(date->month_name, "");
    strcpy(date->weekday_name, "");
    strcpy(date->time, "");
    strcpy(date->timezone, "");
}

void parse_date(const char* input_date, Date* date) {
    char* date_str = strdup(input_date);
    char* token = strtok(date_str, " ");
    strcpy(date->date, token);

    token = strtok(NULL, " ");
    strcpy(date->month_name, token);

    token = strtok(NULL, " ");
    strcpy(date->weekday_name, token);

    token = strtok(NULL, " ");
    strcpy(date->time, token);

    token = strtok(NULL, " ");
    strcpy(date->timezone, token);

    free(date_str);
}

void format_date(const Date* date, char* output) {
    strcat(output, date->month_name);
    strcat(output, " ");
    strcat(output, date->weekday_name);
    strcat(output, ", ");
    strcat(output, date->date);
    strcat(output, " ");
    strcat(output, date->time);
    strcat(output, " ");
    strcat(output, date->timezone);
}

int main() {
    Date input_date;
    initialize_date(&input_date);

    printf("Enter a date in the format 'Month Day, Year Time Timezone': ");
    scanf("%s", input_date.date);

    parse_date(input_date.date, &input_date);

    char output[MAX_DATE_LENGTH + MAX_MONTH_NAME_LENGTH + MAX_WEEKDAY_NAME_LENGTH + MAX_TIME_LENGTH + MAX_TIMEZONE_LENGTH + 1];
    format_date(&input_date, output);

    printf("Formatted date: %s\n", output);

    return 0;
}