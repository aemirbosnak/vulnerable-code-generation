//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 100

// Date structure to hold converted date
typedef struct date {
    int day;
    int month;
    int year; 
} Date;

// Function to convert the given date from string to date format
Date convert_date(char *input) {
    int day, month, year, i, j, index = 0;
    char str_day[3], str_month[3], str_year[5];
    Date date;
    memset(&date, 0, sizeof(Date));
    // Extracting day from string
    for (i = 0; input[i] != '/'; i++) {
        str_day[index++] = input[i];
    }
    str_day[index] = '\0';
    day = atoi(str_day);
    index = 0;
    i++;
    // Extracting month from string
    for (j = i; input[j] != '/'; j++) {
        str_month[index++] = input[j];
    }
    str_month[index] = '\0';
    month = atoi(str_month);
    index = 0;
    j++;
    // Extracting year from string
    for (i = j; input[i] != '\0'; i++) {
        str_year[index++] = input[i];
    }
    str_year[index] = '\0';
    year = atoi(str_year);
    // Storing extracted values to date structure
    date.day = day;
    date.month = month;
    date.year = year;
    return date;
}

// Function to print converted date in desired format
void print_date(Date date) {
    printf("Converted Date: %d-%d-%d\n", date.day, date.month, date.year);
}

// Thread function to get user input for date conversion
void *get_input(void *arg) {
    char input[MAX_INPUT_SIZE];
    Date date;
    while (true) {
        printf("Enter date (dd/mm/yyyy): ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        date = convert_date(input);
        print_date(date);
    }
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, get_input, NULL);
    pthread_join(thread_id, NULL);
    return 0;
}