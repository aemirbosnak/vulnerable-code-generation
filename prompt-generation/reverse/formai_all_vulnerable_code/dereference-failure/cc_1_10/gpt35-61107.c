//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Function to convert month string to corresponding numerical value
int getMonth(char* monthString) {
    if (strcmp(monthString, "January") == 0)
        return 1;
    else if (strcmp(monthString, "February") == 0)
        return 2;
    else if (strcmp(monthString, "March") == 0)
        return 3;
    else if (strcmp(monthString, "April") == 0)
        return 4;
    else if (strcmp(monthString, "May") == 0)
        return 5;
    else if (strcmp(monthString, "June") == 0)
        return 6;
    else if (strcmp(monthString, "July") == 0)
        return 7;
    else if (strcmp(monthString, "August") == 0)
        return 8;
    else if (strcmp(monthString, "September") == 0)
        return 9;
    else if (strcmp(monthString, "October") == 0)
        return 10;
    else if (strcmp(monthString, "November") == 0)
        return 11;
    else
        return 12;
}

// Function to convert string date to numerical date format
void* convertDate(void* date) {
    char* stringDate = (char*) date;
    char* token = strtok(stringDate, " ");
    int day = atoi(token);
    token = strtok(NULL, " ");
    int month = getMonth(token);
    token = strtok(NULL, " ");
    int year = atoi(token);

    printf("%d/%d/%d\n", day, month, year);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    char stringDate[20];

    printf("Enter date in natural language (e.g. 25 October 2022): ");
    fgets(stringDate, 20, stdin);

    pthread_create(&thread, NULL, convertDate, (void*) stringDate);
    pthread_join(thread, NULL);

    return 0;
}