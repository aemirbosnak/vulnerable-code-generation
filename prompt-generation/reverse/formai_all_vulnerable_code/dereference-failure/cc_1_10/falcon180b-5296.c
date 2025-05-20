//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 80

typedef struct {
    char *month;
    int day;
} Date;

Date *parse_date(char *date_str) {
    char *month_str;
    int day;
    Date *date = malloc(sizeof(Date));

    month_str = strtok(date_str, " ");
    if (month_str == NULL) {
        free(date);
        return NULL;
    }

    if (strcmp(month_str, "January") == 0) {
        date->month = "January";
    } else if (strcmp(month_str, "February") == 0) {
        date->month = "February";
    } else if (strcmp(month_str, "March") == 0) {
        date->month = "March";
    } else if (strcmp(month_str, "April") == 0) {
        date->month = "April";
    } else if (strcmp(month_str, "May") == 0) {
        date->month = "May";
    } else if (strcmp(month_str, "June") == 0) {
        date->month = "June";
    } else if (strcmp(month_str, "July") == 0) {
        date->month = "July";
    } else if (strcmp(month_str, "August") == 0) {
        date->month = "August";
    } else if (strcmp(month_str, "September") == 0) {
        date->month = "September";
    } else if (strcmp(month_str, "October") == 0) {
        date->month = "October";
    } else if (strcmp(month_str, "November") == 0) {
        date->month = "November";
    } else if (strcmp(month_str, "December") == 0) {
        date->month = "December";
    } else {
        free(date);
        return NULL;
    }

    day = atoi(strtok(NULL, " "));
    if (day < 1 || day > 31) {
        free(date);
        return NULL;
    }

    date->day = day;
    return date;
}

void print_date(Date *date) {
    printf("%s %d, %d\n", date->month, date->day, 2021);
}

int main() {
    char date_str[MAX_LEN];
    Date *date;

    printf("Enter a date in the format 'Month Day, Year': ");
    fgets(date_str, MAX_LEN, stdin);

    date = parse_date(date_str);
    if (date!= NULL) {
        print_date(date);
    }

    return 0;
}