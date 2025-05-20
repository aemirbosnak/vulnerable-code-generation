//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char date[40];
    int day, month, year;
    printf("Enter the date (in natural language): ");
    fgets(date, 40, stdin);
    printf("\n");

    //Splitting the string into separate words
    char *token;
    token = strtok(date, " ");
    while(token != NULL){
        if(strcmp(token, "January") == 0 || strcmp(token, "Jan") == 0)
            month = 1;
        else if(strcmp(token, "February") == 0 || strcmp(token, "Feb") == 0)
            month = 2;
        else if(strcmp(token, "March") == 0 || strcmp(token, "Mar") == 0)
            month = 3;
        else if(strcmp(token, "April") == 0 || strcmp(token, "Apr") == 0)
            month = 4;
        else if(strcmp(token, "May") == 0)
            month = 5;
        else if(strcmp(token, "June") == 0 || strcmp(token, "Jun") == 0)
            month = 6;
        else if(strcmp(token, "July") == 0 || strcmp(token, "Jul") == 0)
            month = 7;
        else if(strcmp(token, "August") == 0 || strcmp(token, "Aug") == 0)
            month = 8;
        else if(strcmp(token, "September") == 0 || strcmp(token, "Sept") == 0)
            month = 9;
        else if(strcmp(token, "October") == 0 || strcmp(token, "Oct") == 0)
            month = 10;
        else if(strcmp(token, "November") == 0 || strcmp(token, "Nov") == 0)
            month = 11;
        else if(strcmp(token, "December") == 0 || strcmp(token, "Dec") == 0)
            month = 12;
        else{
            if(isdigit(token[0]))
                day = atoi(token);
            else if(isdigit(token[strlen(token)-2]))
                year = atoi(token);
        }
        token = strtok(NULL, " ");
    }

    printf("The date in numeric format is: %d/%d/%d", day, month, year);
    return 0;
}