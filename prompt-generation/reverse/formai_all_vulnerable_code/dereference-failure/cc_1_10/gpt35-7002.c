//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT 100
#define ERROR_MSG "Sorry, invalid input. Please enter a valid date in natural language." 
#define PARANOID_MSG "We take security very seriously. Therefore, please enter the date in the format: DD/MM/YYYY."

int is_valid_month(char *month) {
    char *valid_months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for(int i = 0; i < 12; i++) {
        if(strcasecmp(month, valid_months[i]) == 0) {
            return i+1;
        }
    }
    return 0;
}

int is_leap_year(int year) {
    if(year % 400 == 0) {
        return 1;
    } else if(year % 100 == 0) {
        return 0;
    } else if(year % 4 == 0) {
        return 1;
    }
    return 0;
}

int is_valid_date(int day, int month, int year) {
    if(month < 1 || month > 12) {
        return 0;
    }
    int days_in_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(is_leap_year(year)) {
        days_in_month[1] = 29;
    }
    if(day < 1 || day > days_in_month[month-1]) {
        return 0;
    }
    return 1;
}

void convert_date(char *input) {
    int day, month, year;
    char *token;
    char *delimiter = " -,/";
    token = strtok(input, delimiter);
    if(!isdigit(token[0])) {
        month = is_valid_month(token);
        if(!month) {
            printf(ERROR_MSG);
            return;
        }
        token = strtok(NULL, delimiter);
        if(!isdigit(token[0])) {
            printf(ERROR_MSG);
            return;
        }
    }
    day = atoi(token);
    if(day < 1 || day > 31) {
        printf(ERROR_MSG);
        return;
    }
    token = strtok(NULL, delimiter);
    if(!token) {
        printf(ERROR_MSG);
        return;
    }
    month = is_valid_month(token);
    if(!month) {
        printf(ERROR_MSG);
        return;
    }
    token = strtok(NULL, delimiter);
    if(!token) {
        printf(ERROR_MSG);
        return;
    }
    year = atoi(token);
    if(year < 1) {
        printf(ERROR_MSG);
        return;
    } else if(year > 9999) {
        printf(PARANOID_MSG);
        return;
    }
    if(!is_valid_date(day, month, year)) {
        printf(ERROR_MSG);
        return;
    }
    printf("%02d/%02d/%04d", day, month, year);
}

int main() {
    char input[MAX_INPUT];
    printf("Please enter a date in natural language (e.g. January 1, 2022): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = '\0';
    convert_date(input);
    return 0;
}