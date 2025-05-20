//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

char sep[2] = "/";

int isLeap(int year){
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        return 1;
    else
        return 0;
}

int isDateValid(int day, int month, int year){
    if (month < 1 || month > 12)
        return 0;
    if (day < 1 || day > 31)
        return 0;
    if (month == 2){
        if (isLeap(year))
            return (day <= 29);
        else
            return (day <= 28);
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return (day <= 30);
    else
        return 1;
}

int getMonthFromName(char* monthName){
    for (int i = 0; i < 12; i++){
        if (strcmp(monthName, months[i]) == 0){
            return i + 1;
        }
    }
    return -1;
}

int main(){
    printf("Enter a date in the format of Month Day, Year (e.g. January 15, 2022): ");
    char date[20];
    fgets(date, 20, stdin);
    date[strcspn(date, "\n")] = 0;
    char* monthName = strtok(date, sep);
    char* day = strtok(NULL, ",");
    char* year = strtok(NULL, " ");
    printf("\nYou entered: %s %s, %s\n", monthName, day, year);
    int month = getMonthFromName(monthName);
    if (month == -1 || !isdigit(*day) || !isdigit(*year)){
        printf("\nInvalid date format.\n");
        return 0;
    }
    int dayNum = atoi(day);
    int yearNum = atoi(year);
    if (!isDateValid(dayNum, month, yearNum)){
        printf("\nInvalid date.\n");
        return 0;
    }
    printf("\nThe date in YYYY/MM/DD format is: %d/%02d/%02d\n", yearNum, month, dayNum);
    return 0;
}