//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* NLtoC(char* nl_date);

int main() {
    printf("Meow! I am a shape-shifting date converter program. Let's convert some dates from natural language to C format!\n");
    
    char nl_date[100];
    char* c_date;
    
    printf("Meow! Please enter a date in natural language (e.g. January 1st, 2022): ");
    fgets(nl_date, 100, stdin);
    
    nl_date[strcspn(nl_date, "\n")] = 0;
    
    c_date = NLtoC(nl_date);
    
    printf("Meow! The date in C format is: %s\n", c_date);
    
    free(c_date);
    
    printf("Meow! Thank you for using my services. Goodbye!\n");
    
    return 0;
}

char* NLtoC(char* nl_date) {
    char* c_date = (char*) malloc(sizeof(char) * 11);
    
    char month[12][3] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
    int day;
    int year;
    int month_num = 0;
    
    sscanf(nl_date, "%*s %d,%*s %d", &day, &year);
    
    char* month_str = strtok(nl_date, " ");
    
    int i = 1;
    
    while (i <= 12) {
        if (strcmp(month_str, month[i]) == 0) {
            month_num = i;
            break;
        }
        i++;
    }
    
    sprintf(c_date, "%04d-%02d-%02d", year, month_num, day);
    
    return c_date;
}