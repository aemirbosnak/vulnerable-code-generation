//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LENGTH 50
#define MONTHS_NUM 12

struct Date {
    int day;
    int month;
    int year;
};

typedef struct Date Date;

void convert_date(const char* input_date, Date* output_date) {
    char input_str[MAX_DATE_LENGTH];
    strcpy(input_str, input_date);

    int day = 0;
    int month = 0;
    int year = 0;

    int pos = 0;
    while (input_str[pos] != ' ') {
        if (isdigit(input_str[pos])) {
            day = day * 10 + (input_str[pos] - '0');
        } else if (input_str[pos] == '/') {
            month++;
        }
        pos++;
    }
    month *= 30;
    day += ((input_str[pos + 1] - '0') * 30) + ((input_str[pos + 2] - '0') / 12);
    year = (input_str[pos + 3] - '0') * 100 + (input_str[pos + 4] - '0') + ((input_str[pos + 5] - '0') / 100);

    output_date->day = day;
    output_date->month = month + (input_str[pos] - '0');
    output_date->year = year;
}

void print_date(const Date* date) {
    char* month_names[] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

    printf("%s %d, %d", month_names[date->month - 1], date->day, date->year);
}

int main(int argc, char** argv) {
    char input_date[MAX_DATE_LENGTH];
    if (argc != 2) {
        printf("Usage: %s date_string\n", argv[0]);
        return 1;
    }

    strcpy(input_date, argv[1]);

    Date output_date;
    convert_date(input_date, &output_date);

    printf("Converted date: ");
    print_date(&output_date);
    printf("\n");

    return 0;
}