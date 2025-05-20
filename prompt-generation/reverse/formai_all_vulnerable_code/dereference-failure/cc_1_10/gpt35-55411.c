//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Helper function to check if the entered year is a leap year
int is_leap_year(int year){
    if(year%4 == 0 && year%100 != 0 || year%400 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to convert date to number of days passed from start of the year
int date_to_days(int day, int month, int year){
    int days_in_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int days = day;

    for(int i=1;i<month;i++){
        days += days_in_month[i];
    }

    if(month>2 && is_leap_year(year)){
        days += 1;
    }

    return days;
}

// Function to convert number of days passed from start of the year to date
void days_to_date(int days, int year, int *month, int *day){
    int days_in_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    *month = 1;
    *day = days;

    if(is_leap_year(year)){
        days_in_month[2] = 29;
    }

    while(*day > days_in_month[*month]){
        *day -= days_in_month[*month];
        *month += 1;
    }
}

int main(){
    int day, month, year;
    char date[11];

    // Taking user input
    printf("Enter date (dd-mm-yyyy): ");
    scanf("%s", date);

    // Parsing input string to integers
    day = atoi(strtok(date,"-"));
    month = atoi(strtok(NULL,"-"));
    year = atoi(strtok(NULL,"-"));

    // Converting date to number of days passed from start of the year
    int days = date_to_days(day, month, year);
    printf("Days passed from start of the year: %d\n", days);

    // Converting number of days passed from start of the year to date
    int converted_month, converted_day;
    days_to_date(days, year, &converted_month, &converted_day);
    printf("Converted date: %02d-%02d-%04d\n", converted_day, converted_month, year);

    return 0;
}