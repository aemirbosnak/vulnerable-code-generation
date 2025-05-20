//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define max_buf 1000

int convert_month(char*);
void format_date(int, int, int);

int main() {
    char input[max_buf];
    int day, year, month;
    
    printf("Enter the date in natural language (Example: January 1, 2022): ");
    fgets(input, max_buf, stdin);

    char *ptr;
    ptr = strtok(input, " ");
    
    // Extract month from the input
    month = convert_month(ptr);
    
    // Extract day and year from the input
    ptr = strtok(NULL, ", ");
    day = atoi(ptr);
    ptr = strtok(NULL, ", ");
    year = atoi(ptr);
    
    format_date(month, day, year);    
    
    return 0;
}

// Convert month from string to integer
int convert_month(char* input) {
    int month;
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    for(int i=0; i<12; i++) {
        if(strcasecmp(input, months[i])==0) {
            month = i+1;
            break;
        }
    }
    
    return month;
}

// Format date as dd/mm/yyyy
void format_date(int month, int day, int year) {
    printf("Formatted date: %02d/%02d/%04d\n", day, month, year);
}