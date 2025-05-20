//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert month from natural language to numerical format
int getMonth(char* month){
    if(strcmp(month, "January") == 0){
        return 1;
    }
    else if(strcmp(month, "February") == 0){
        return 2;
    }
    else if(strcmp(month, "March") == 0){
        return 3;
    }
    else if(strcmp(month, "April") == 0){
        return 4;
    }
    else if(strcmp(month, "May") == 0){
        return 5;
    }
    else if(strcmp(month, "June") == 0){
        return 6;
    }
    else if(strcmp(month, "July") == 0){
        return 7;
    }
    else if(strcmp(month, "August") == 0){
        return 8;
    }
    else if(strcmp(month, "September") == 0){
        return 9;
    }
    else if(strcmp(month, "October") == 0){
        return 10;
    }
    else if(strcmp(month, "November") == 0){
        return 11;
    }
    else if(strcmp(month, "December") == 0){
        return 12;
    }
    else{
        return -1; // Invalid month name
    }
}

int main(){
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date (example format: January 1st, 2022): ");
    
    char input[50];
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
    
    char* month = strtok(input, " ");
    char* day = strtok(NULL, ",");
    char* year = strtok(NULL, "");
    
    int numericalMonth = getMonth(month);
    
    if(numericalMonth == -1){
        printf("Invalid month name. Please try again.\n");
        return 0;
    }
    
    int numericalDay = atoi(day);
    
    if(numericalDay < 1 || numericalDay > 31){
        printf("Invalid day. Please try again.\n");
        return 0;
    }
    
    int numericalYear = atoi(year);
    
    if(numericalYear < 0){
        printf("Negative year value not allowed. Please try again.\n");
        return 0;
    }
    
    printf("The date you entered is: %02d/%02d/%d\n", numericalMonth, numericalDay, numericalYear);

    return 0;
}