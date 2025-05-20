//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

int get_month_days(int month, int year) {
    int days;
    
    if (month == 2) { // February
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
            days = 29;
        } else {
            days = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) { // Months with 30 days
        days = 30;
    } else { // Months with 31 days
        days = 31;
    }
    
    return days;
}

int is_valid_date(Date d) {
    if (d.year < 1 || d.month < 1 || d.month > 12 || d.day < 1 || d.day > get_month_days(d.month, d.year)) {
        return 0;
    }
    
    return 1;
}

void print_date(Date d) {
    printf("%02d/%02d/%d", d.day, d.month, d.year);
}

Date* convert_date(char* input) {
    Date* date = malloc(sizeof(Date));
    char* token;
    
    // Get year
    token = strtok(input, "/");
    if (token == NULL) {
        printf("Invalid date format\n");
        return NULL;
    }
    date->year = atoi(token);
    
    // Get month
    token = strtok(NULL, "/");
    if (token == NULL) {
        printf("Invalid date format\n");
        return NULL;
    }
    date->month = atoi(token);
    
    // Get day
    token = strtok(NULL, "/");
    if (token == NULL) {
        printf("Invalid date format\n");
        return NULL;
    }
    date->day = atoi(token);
    
    if (!is_valid_date(*date)) {
        printf("Invalid date\n");
        return NULL;
    }
    
    return date;
}

char* convert_month(int month) {
    char* month_name;
    
    switch (month) {
        case 1:
            month_name = "January";
            break;
        case 2:
            month_name = "February";
            break;
        case 3:
            month_name = "March";
            break;
        case 4:
            month_name = "April";
            break;
        case 5:
            month_name = "May";
            break;
        case 6:
            month_name = "June";
            break;
        case 7:
            month_name = "July";
            break;
        case 8:
            month_name = "August";
            break;
        case 9:
            month_name = "September";
            break;
        case 10:
            month_name = "October";
            break;
        case 11:
            month_name = "November";
            break;
        case 12:
            month_name = "December";
            break;
        default:
            month_name = "";
    }
    
    return month_name;
}

void print_date_long(Date d) {
    char* month_name = convert_month(d.month);
    
    printf("%s %d, %d", month_name, d.day, d.year);
}

int main() {
    char input[20];
    
    printf("Enter date in format dd/mm/yyyy: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline character
    
    Date* date = convert_date(input);
    
    if (date != NULL) {
        printf("Short format: ");
        print_date(*date);
        printf("\n");
        
        printf("Long format: ");
        print_date_long(*date);
        printf("\n");
    }
    
    free(date);
    
    return 0;
}