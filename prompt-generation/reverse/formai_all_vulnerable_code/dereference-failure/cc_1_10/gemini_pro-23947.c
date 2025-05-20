//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

Date parseDate(char *dateStr) {
    Date date;
    char *ptr;

    ptr = strtok(dateStr, "/");
    date.day = atoi(ptr);

    ptr = strtok(NULL, "/");
    date.month = atoi(ptr);

    ptr = strtok(NULL, "/");
    date.year = atoi(ptr);

    return date;
}

char *formatDate(Date date) {
    char *dateStr;
    
    dateStr = malloc(11);
    sprintf(dateStr, "%02d/%02d/%04d", date.day, date.month, date.year);

    return dateStr;
}

int main() {
    char *dateStr = "2023/03/08";
    Date date;
    char *formattedDate;

    date = parseDate(dateStr);
    formattedDate = formatDate(date);

    printf("Original date: %s\n", dateStr);
    printf("Parsed date: %02d/%02d/%04d\n", date.day, date.month, date.year);
    printf("Formatted date: %s\n", formattedDate);

    free(formattedDate);
    return 0;
}