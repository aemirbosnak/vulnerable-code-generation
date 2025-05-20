//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert natural language date to numerical format
void convertToDate(char *str) {
    char *months[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

    char *tokens[4];
    tokens[0] = strtok(str, " ");
    tokens[1] = strtok(NULL, " ");
    tokens[2] = strtok(NULL, " ");
    tokens[3] = strtok(NULL, " ");
    
    int month = -1, day = -1, year = -1;
    for(int i=0; i<12; i++) {
        if(strcmp(months[i], tokens[0]) == 0) {
            month = i + 1;
            break;
        }
    }
    
    if(month == -1) {
        printf("Invalid Month! Please enter valid month name.\n");
        return;
    }
    
    if(strlen(tokens[1]) > 2 || strlen(tokens[2]) > 4) {
        printf("Invalid date format! Please enter in specified format.\n");
        return;
    }
    
    day = atoi(tokens[1]);
    year = atoi(tokens[2]);
    
    if(day < 1 || day > 31) {
        printf("Invalid day! Please enter valid day between 1 and 31.\n");
        return;
    }
    
    if(year < 0) {
        printf("Invalid year! Please enter valid year.\n");
        return;
    }
    
    printf("Converted Date: %02d/%02d/%04d\n", month, day, year);
}

int main() {
    char input[50];
    printf("Please enter date in natural language format (e.g. September 22 2021): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // removes \n character from input
    
    convertToDate(input);
    
    return 0;
}