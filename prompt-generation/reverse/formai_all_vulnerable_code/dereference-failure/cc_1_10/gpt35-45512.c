//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: decentralized
#include <stdio.h>
#include <string.h>

// Function to convert month to number
int month_to_number(char *month)
{
    int number = -1; // Default value
    
    // Check if month is valid
    if(strcmp(month, "January") == 0)
        number = 1;
    else if(strcmp(month, "February") == 0)
        number = 2;
    else if(strcmp(month, "March") == 0)
        number = 3;
    else if(strcmp(month, "April") == 0)
        number = 4;
    else if(strcmp(month, "May") == 0)
        number = 5;
    else if(strcmp(month, "June") == 0)
        number = 6;
    else if(strcmp(month, "July") == 0)
        number = 7;
    else if(strcmp(month, "August") == 0)
        number = 8;
    else if(strcmp(month, "September") == 0)
        number = 9;
    else if(strcmp(month, "October") == 0)
        number = 10;
    else if(strcmp(month, "November") == 0)
        number = 11;
    else if(strcmp(month, "December") == 0)
        number = 12;
    
    return number;
}

// Function to convert number to month
char* number_to_month(int number)
{
    char *month;
    
    switch(number)
    {
        case 1:
            month = "January";
            break;
        case 2:
            month = "February";
            break;
        case 3:
            month = "March";
            break;
        case 4:
            month = "April";
            break;
        case 5:
            month = "May";
            break;
        case 6:
            month = "June";
            break;
        case 7:
            month = "July";
            break;
        case 8:
            month = "August";
            break;
        case 9:
            month = "September";
            break;
        case 10:
            month = "October";
            break;
        case 11:
            month = "November";
            break;
        case 12:
            month = "December";
            break;
        default:
            month = "Invalid";
    }
    
    return month;
}

// Function to calculate number of days in a month
int days_in_month(int month, int year)
{
    int days;
    
    if(month == 2)
    {
        if(year%4 == 0 && (year%100!=0 || year%400==0))
            days = 29;
        else
            days = 28;
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    else
        days = 31;
    
    return days;
}

// Function to convert natural language date to standard format
void convert_date(char *date)
{
    char *day_str, *month_str, *year_str;
    int day, month, year;
    
    day_str = strtok(date, " ");
    month_str = strtok(NULL, " ");
    year_str = strtok(NULL, " ");
    
    day = atoi(day_str);
    month = month_to_number(month_str);
    year = atoi(year_str);
    
    if(day < 1 || day > days_in_month(month, year) || month == -1)
        printf("Invalid date!\n");
    else
        printf("%02d-%02d-%04d\n", day, month, year);
}

int main()
{
    char date[30];
    
    printf("Enter a natural language date (Example: 1st January 2022): ");
    fgets(date, sizeof(date), stdin);
    
    convert_date(date);
    
    return 0;   
}