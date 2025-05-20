//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if (year % 400 == 0) {
        return 1;
    } else if (year % 100 == 0) {
        return 0;
    } else if (year % 4 == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to get the number of days in a certain month and year
int getDaysInMonth(int month, int year) {
    switch(month) {
        case 1:
            return 31;
        case 2:
            if (isLeapYear(year)) {
                return 29;
            } else {
                return 28;
            }
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            printf("Invalid month.\n");
            exit(1);
    }
}

// Function to convert a date in string format to integer format
void convertDate(char *str_date, int *d, int *m, int *y) {
    char *token = strtok(str_date, "/");
    *d = atoi(token);
    
    token = strtok(NULL, "/");
    *m = atoi(token);
    
    token = strtok(NULL, "/");
    *y = atoi(token);
}

// Function to convert an integer date to string format
void convertToStr(int dd, int mm, int yyyy) {
    char month[12];
    switch(mm) {
        case 1:
            strcpy(month, "January");
            break;
        case 2:
            strcpy(month, "February");
            break;
        case 3:
            strcpy(month, "March");
            break;
        case 4:
            strcpy(month, "April");
            break;
        case 5:
            strcpy(month, "May");
            break;
        case 6:
            strcpy(month, "June");
            break;
        case 7:
            strcpy(month, "July");
            break;
        case 8:
            strcpy(month, "August");
            break;
        case 9:
            strcpy(month, "September");
            break;
        case 10:
            strcpy(month, "October");
            break;
        case 11:
            strcpy(month, "November");
            break;
        case 12:
            strcpy(month, "December");
            break;
    }
    printf("%d %s %d\n", dd, month, yyyy);
}

// Function to add days to a given date
void addDays(int d, int m, int y, int days_to_add) {
    int days_in_month;
    while(days_to_add > 0) {
        days_in_month = getDaysInMonth(m, y);
        if (d + days_to_add > days_in_month) {
            days_to_add -= (days_in_month - d + 1);
            d = 1;
            if (m == 12) {
                m = 1;
                y++;
            } else {
                m++;
            }
        } else {
            d += days_to_add;
            days_to_add = 0;
        }
    }
    convertToStr(d, m, y);
}

// Main function
int main() {
    char date[12];
    int days_to_add;
    int dd, mm, yyyy;

    printf("Enter a date in dd/mm/yyyy format: ");
    fgets(date, 12, stdin);
    convertDate(date, &dd, &mm, &yyyy);

    printf("Enter the number of days to add: ");
    scanf("%d", &days_to_add);

    addDays(dd, mm, yyyy, days_to_add);

    return 0;
}