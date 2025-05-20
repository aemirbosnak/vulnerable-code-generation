//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* month_names[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date{
    int year;
    int month;
    int day;
};

int is_leap_year(int year){
    if (year % 4 != 0) return 0;
    if (year % 100 != 0) return 1;
    if (year % 400 != 0) return 0;
    return 1;
}

int get_days_in_month(int month, int year){
    if (month == 1 && is_leap_year(year)) return 29;
    return days_in_month[month];
}

struct date convert_date(char* date_str){
    struct date new_date;
    char* token;
    token = strtok(date_str, "/");
    new_date.day = atoi(token);
    token = strtok(NULL, "/");
    new_date.month = atoi(token);
    token = strtok(NULL, "/");
    new_date.year = atoi(token);
    return new_date;
}

char* convert_to_string(struct date d){
    char* date_str = malloc(sizeof(char) * 20);
    sprintf(date_str, "%d %s %d", d.day, month_names[d.month - 1], d.year);
    return date_str;
}

struct date add_days(struct date d, int num_days){
    int days_left = num_days;
    while (days_left > 0){
        int days_in_month = get_days_in_month(d.month - 1, d.year);
        int days_to_end_of_month = days_in_month - d.day;
        if (days_to_end_of_month >= days_left){
            d.day += days_left;
            days_left = 0;
        } else {
            d.day = 1;
            if (d.month == 12){
                d.year++;
                d.month = 1;
            } else {
                d.month++;
            }
            days_left -= days_to_end_of_month;
        }
    }
    return d;
}

int main(){
    struct date d;
    char date_str[20];
    int num_days;
    printf("Enter a date (e.g. 20/12/2022): ");
    scanf("%s", date_str);
    d = convert_date(date_str);
    printf("Enter number of days to add: ");
    scanf("%d", &num_days);
    struct date new_date = add_days(d, num_days);
    char* new_date_str = convert_to_string(new_date);
    printf("New date: %s\n", new_date_str);
    free(new_date_str);
    return 0;
}