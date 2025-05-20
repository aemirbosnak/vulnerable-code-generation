//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: thoughtful
#include<stdio.h>
#include<string.h>

// Define function to convert month name to integer
int monthConverter(char* month){
    if(strcmp(month,"January")==0){
        return 1;
    }else if(strcmp(month,"February")==0){
        return 2;
    }else if(strcmp(month,"March")==0){
        return 3;
    }else if(strcmp(month,"April")==0){
        return 4;
    }else if(strcmp(month,"May")==0){
        return 5;
    }else if(strcmp(month,"June")==0){
        return 6;
    }else if(strcmp(month,"July")==0){
        return 7;
    }else if(strcmp(month,"August")==0){
        return 8;
    }else if(strcmp(month,"September")==0){
        return 9;
    }else if(strcmp(month,"October")==0){
        return 10;
    }else if(strcmp(month,"November")==0){
        return 11;
    }else if(strcmp(month,"December")==0){
        return 12;
    }
}

int main(){
    char date[20];
    int day, year, month;

    printf("Enter date in natural language (Example: January 1, 2022): ");
    fgets(date, sizeof(date), stdin);

    // Split input string into month, day, year
    char* token = strtok(date, " \n,");
    char* input[3];
    int i=0;
    while(token != NULL){
        input[i] = token;
        i++;
        token = strtok(NULL, " \n,");
    }

    // Convert month name to integer
    month = monthConverter(input[0]);

    // Convert day and year to integer
    day = atoi(input[1]);
    year = atoi(input[2]);

    // Output integer values
    printf("%d-%02d-%02d", year, month, day);
    
    return 0;
}