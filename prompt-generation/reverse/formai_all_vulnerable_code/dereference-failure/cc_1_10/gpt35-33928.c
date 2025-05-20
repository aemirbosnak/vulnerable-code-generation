//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12

char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int is_int(char* str) {
    while(*str != '\0') {
        if(!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

int get_month(char* month_str) {
    for(int i=0;i<12;i++) {
        if(strcmp(month_str, months[i]) == 0) {
            return i+1;
        }
    }
    return -1;
}

int is_leap_year(int year) {
    if(year%4 == 0 && year%100 != 0) {
        return 1;
    }
    if(year%400 == 0) {
        return 1;
    }
    return 0;
}

int days_in_month(int month, int year) {
    switch(month) {
        case JAN:
        case MAR:
        case MAY:
        case JUL:
        case AUG:
        case OCT:
        case DEC:
            return 31;
            break;
        case APR:
        case JUN:
        case SEP:
        case NOV:
            return 30;
            break;
        case FEB:
            if(is_leap_year(year)) {
                return 29;
            } else {
                return 28;
            }
            break;
        default:
            return -1;
            break;
    }
}

void print_date(int day, int month, int year) {
    printf("%d %s %d\n", day, months[month-1], year);
}

int main() {
    char date_str[20];
    printf("Enter date in natural language (e.g. 5th December, 2021): ");
    fgets(date_str, 20, stdin);
    if(date_str[strlen(date_str)-1] == '\n') {
        date_str[strlen(date_str)-1] = '\0';
    }
    char* token;
    token = strtok(date_str, " ");
    int day = atoi(token);
    token = strtok(NULL, " ");
    char month_str[20];
    strcpy(month_str, token);
    token = strtok(NULL, " ");
    int year = atoi(token);
    if(day > 31 || day < 1) {
        printf("Invalid day\n");
        return 0;
    }
    int month = get_month(month_str);
    if(month == -1) {
        printf("Invalid month\n");
        return 0;
    }
    if(year < 1) {
        printf("Invalid year\n");
        return 0;
    }
    int days_in_given_month = days_in_month(month, year);
    if(day > days_in_given_month) {
        printf("Invalid day for given month and year\n");
        return 0;
    }
    if(month == FEB && day == 29 && !is_leap_year(year)) {
        printf("Invalid day for given year (not a leap year)\n");
        return 0;
    }
    print_date(day, month, year);
    return 0;
}