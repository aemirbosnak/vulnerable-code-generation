//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: modular
#include<stdio.h>
#include<string.h>

// function to convert month to number
int monthToNumber(char *month){
    char *months[] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
    for(int i = 0; i < 12; i++){
        if(strcmp(months[i], month) == 0){
            return i+1;
        }
    }
    return -1;
}

// function to convert number to month
char* numberToMonth(int month){
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month-1];
}

// function to check for leap year
int isLeapYear(int year){
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        return 1;
    }
    return 0;
}

// function to get number of days in a month for a given year
int getDaysInMonth(int month, int year){
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month == 2 && isLeapYear(year)){
        return 29;
    }
    return days[month-1];
}

// function to check if date is valid
int isValidDate(int day, int month, int year){
    if(year > 0 && month >= 1 && month <= 12){
        int daysInMonth = getDaysInMonth(month, year);
        if(day >= 1 && day <= daysInMonth){
            return 1;
        }
    }
    return 0;
}

// function to convert date from natural language to number
void convertToDate(char *input, int *day, int *month, int *year){
    char *token = strtok(input, " ");

    // get day
    *day = atoi(token);

    // get month
    token = strtok(NULL, " ");
    *month = monthToNumber(token);

    // get year
    token = strtok(NULL, " ");
    *year = atoi(token);
}

int main(){
    char input[50];
    int day, month, year;

    // get input from user
    printf("Enter date in natural language (e.g. \"28th February 2022\"):\n");
    fgets(input, 50, stdin);

    // convert input to date
    convertToDate(input, &day, &month, &year);

    // check if date is valid
    if(isValidDate(day, month, year)){
        // print date in different formats
        printf("Date in natural language:\t%s", input);
        printf("Date in number format:\t%d/%d/%d\n", day, month, year);
        printf("Date in month/year format:\t%s %d\n", numberToMonth(month), year);
    }
    else{
        printf("Invalid date!\n");
    }

    return 0;
}