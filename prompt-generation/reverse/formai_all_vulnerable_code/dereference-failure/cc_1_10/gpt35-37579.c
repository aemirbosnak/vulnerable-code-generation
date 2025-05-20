//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * Function to check if the year is a leap year 
**/
int isLeapYear(int year){
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Function to get the number of days in a given month 
**/
int daysInMonth(int month, int year){
    int days;

    switch (month){
        case 2:
            if(isLeapYear(year)){
                days = 29;
            }else{
                days = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = 31;
    }

    return days;
}

/**
 * Function to convert the month from string to int 
**/
int convertMonthToInt(char* month){
    char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for(int i=0; i<12; i++){
        if(strcmp(month, months[i]) == 0){
            return i+1;
        }
    }
    return 0;
}

/**
 * Main function to take input and convert date 
**/
int main(){
    char date[20];
    printf("Enter date in natural language format (ie. January 1, 2022): ");
    fgets(date, 20, stdin);

    // Tokenize the input string 
    char* month = strtok(date, " ,\n");
    char* day = strtok(NULL, " ,\n");
    char* year = strtok(NULL, " ,\n");

    // Convert month and year from string to int 
    int monthInt = convertMonthToInt(month);
    int yearInt = atoi(year);

    // Convert day from string to int and check that it is valid for given month and year
    int dayInt = atoi(day);
    int maxDay = daysInMonth(monthInt, yearInt);
    if(dayInt < 1 || dayInt > maxDay){
        printf("Invalid day for given month and year");
        exit(1);
    }

    // Print the converted date in YYYY-MM-DD format 
    printf("%d-%02d-%02d", yearInt, monthInt, dayInt);
    
    return 0;
}