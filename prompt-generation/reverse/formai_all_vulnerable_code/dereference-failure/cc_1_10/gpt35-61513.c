//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* function prototypes */
bool is_leap_year(int year);
int month_to_number(char *month_name);
int parse_day(char *str);
int parse_year(char *str);
void convert_date(char *user_input, char *output);
bool is_digit(char *str);

/* main function */
int main(void) {
    char input[100];
    char output[100];

    /* get user input */
    printf("Enter a date in natural language: ");
    fgets(input, 100, stdin);

    /* remove trailing newline */
    input[strcspn(input, "\n")] = 0;

    /* convert date */
    convert_date(input, output);

    /* print output */
    printf("Converted date: %s\n", output);

    /* return success */
    return 0;
}

/* check if given year is a leap year */
bool is_leap_year(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

/* convert month name to number */
int month_to_number(char *month_name) {
    int i;
    char *months[] = {"january", "february", "march",
                      "april", "may", "june",
                      "july", "august", "september",
                      "october", "november", "december"};

    for (i = 0; i < 12; i++) {
        if (strcmp(month_name, months[i]) == 0) {
            return i + 1;
        }
    }

    /* default case */
    return 0;
}

/* parse day from user input */
int parse_day(char *str) {
    int i;
    char *day_str;
    int day;

    /* find day substring */
    day_str = strtok(str, " ");

    /* check that day string contains a digit */
    if (!is_digit(day_str)) {
        return 0;
    }

    /* convert day string to integer */
    day = atoi(day_str);

    /* validate day */
    if (day < 1 || day > 31) {
        return 0;
    }

    /* return day */
    return day;
}

/* parse year from user input */
int parse_year(char *str) {
    int i;
    char *year_str;
    int year;

    /* find year substring */
    year_str = strtok(NULL, " ");

    /* check that year string contains a digit */
    if (!is_digit(year_str)) {
        return 0;
    }

    /* convert year string to integer */
    year = atoi(year_str);

    /* validate year */
    if (year < 0 || year > 9999) {
        return 0;
    }

    /* return year */
    return year;
}

/* convert natural language date to standard format */
void convert_date(char *user_input, char *output) {
    int day, month, year;
    char *token;
    char copy[100];

    /* make copy of input string */
    strcpy(copy, user_input);

    /* obtain month name */
    token = strtok(copy, " ");

    if (token == NULL) {
        strcpy(output, "Invalid input");
        return;
    }

    /* convert month name to number */
    month = month_to_number(token);

    if (month == 0) {
        strcpy(output, "Invalid input");
        return;
    }

    /* parse day and year from user input */
    day = parse_day(user_input);
    year = parse_year(user_input);

    if (day == 0 || year == 0) {
        strcpy(output, "Invalid input");
        return;
    }

    /* check for leap year and adjust february values */
    if (month == 2) {
        if (is_leap_year(year)) {
            if (day > 29) {
                strcpy(output, "Invalid input");
                return;
            }
        } else {
            if (day > 28) {
                strcpy(output, "Invalid input");
                return;
            }
        }
    }

    /* format output string */
    sprintf(output, "%02d/%02d/%04d", month, day, year);
}

/* check if given string represents a digit */
bool is_digit(char *str) {
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}