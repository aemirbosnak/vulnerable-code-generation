//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <string.h>

char* monthConverter(int month){
    switch(month){
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "Invalid month";
    }
}

void dateConverter(char* date){
    char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int day, year, month;
    char delimiter[] = " ";
    char* token = strtok(date,delimiter);

    month = atoi(token);
    token = strtok(NULL,delimiter);
    day = atoi(token);
    token = strtok(NULL,delimiter);
    year = atoi(token);
    printf("%s %d, %d\n", monthConverter(month), day, year);
}

int main(){
    char* date1 = "01 12 2022";
    char* date2 = "03 17 2023";
    char* date3 = "12 25 2024";

    printf("Dates in Natural Language:\n");
    dateConverter(date1);
    dateConverter(date2);
    dateConverter(date3);

    return 0;
}