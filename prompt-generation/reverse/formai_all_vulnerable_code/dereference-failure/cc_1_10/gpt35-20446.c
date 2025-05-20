//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to convert date
void convert_date(int day, int month, int year) {
    char *months[] = {"January", "February", "March", "April", "May", "June", "July",
                        "August", "September", "October", "November", "December"};
                        
    //check if date is valid
    if (day < 1 || day > 31) {
        printf("Invalid day!");
        exit(0);
    }
    if (month < 1 || month > 12) {
        printf("Invalid month!");
        exit(0);
    }
    if (year < 1900 || year > 2100) {
        printf("Invalid year!");
        exit(0);
    }
    
    //get month name
    char *month_name = months[month-1];
    
    //get date string
    char date_string[20];
    sprintf(date_string, "%s %d, %d", month_name, day, year);
    
    //print date string
    printf("Converted date: %s", date_string);
}

//main function
int main() {
    //get current time
    time_t t = time(NULL);
    struct tm cur_time = *localtime(&t);
    
    //get current date
    int cur_day = cur_time.tm_mday;
    int cur_month = cur_time.tm_mon + 1;
    int cur_year = cur_time.tm_year + 1900;

    //print current date
    printf("Current date: %d/%d/%d\n", cur_day, cur_month, cur_year);
    
    //get user input
    int day, month, year;
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);
    
    //convert date
    convert_date(day, month, year);

    return 0;
}