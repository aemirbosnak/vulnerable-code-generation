//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: invasive
#include <stdio.h>

void print_year(int year);
int check_leap_year(int year);
void convert_date(char *date);

int main() {
    char date[11];
    printf("Enter date in format DD/MM/YYYY: ");
    fgets(date, 11, stdin);
    convert_date(date);
    return 0;
}

void print_year(int year) {
    printf("%d", year);
}

int check_leap_year(int year) {
    if(year % 4 == 0)
    {
        if( year % 100 == 0)
        {
            if ( year % 400 == 0)
                return 1;
            else
                return 0;
        }
        else
            return 1;
    }
    else {
        return 0;
    }
}   

void convert_date(char *date) {
    char *day, *month, *year;
    int i = 0;
    day = strtok(date, "/");
    month = strtok(NULL, "/");
    year = strtok(NULL, "/");
    printf("Date in natural language: ");
    switch(month[0]) {
        case '0':
            if(month[1] == '1') {
                printf("January ");
            } else if(month[1] == '2') {
                printf("February ");
            } else {
                printf("Invalid month");
                return;
            }
            break;
        case '1':
            if(month[1] == '0') {
                printf("October ");
            } else if(month[1] == '1') {
                printf("November ");
            } else if(month[1] == '2') {
                printf("December ");
            } else {
                printf("Invalid month");
                return;
            }
            break;
        default:
            printf("Invalid month");
            return;
    }
    switch(day[1]) {
        case '1':
            printf("1st, ");
            break;
        case '2':
            printf("2nd, ");
            break;
        case '3':
            printf("3rd, ");
            break;
        default:
            printf("%c th, ", day[1]);
            break;
    }
    print_year(20);
    for(i = 0; i < 2; i++) {
        printf("%c", year[i]);
    }
    printf(" is ");
    switch(month[0]) {
        case '0':
            if(month[1] == '1') {
                printf("winter");
            } else if(month[1] == '2') {
                printf("winter");
            }
            break;
        case '1':
            if(month[1] == '0') {
                printf("autumn");
            } else if(month[1] == '1') {
                printf("autumn");
            } else if(month[1] == '2') {
                printf("winter");
            }
            break;
    }
    if(check_leap_year(2000 + (year[0] - '0')*10 + (year[1] - '0')))
        printf(" leap year");
    else 
        printf(" non-leap year");
}