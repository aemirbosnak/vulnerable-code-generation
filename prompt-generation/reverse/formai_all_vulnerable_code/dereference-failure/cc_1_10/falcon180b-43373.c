//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 100

char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char *weekdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

struct tm *get_date(char *date_str) {
    struct tm result = {0};
    char *ptr = strptime(date_str, "%A, %B %d, %Y", &result);
    if (ptr == NULL || *ptr!= '\0') {
        return NULL;
    }
    return &result;
}

int main() {
    char input_str[MAX_WORDS];
    char *token;
    struct tm *date;
    time_t now;
    char date_str[100];

    printf("Enter a natural language date: ");
    fgets(input_str, MAX_WORDS, stdin);
    token = strtok(input_str, " ");
    while (token!= NULL) {
        if (strcmp(token, "today") == 0 || strcmp(token, "now") == 0) {
            time(&now);
            date = localtime(&now);
        } else if (strcmp(token, "tomorrow") == 0) {
            time_t tomorrow = time(NULL) + 24 * 60 * 60;
            date = localtime(&tomorrow);
        } else {
            date = get_date(token);
            if (date == NULL) {
                printf("Invalid date format: %s\n", token);
                return 1;
            }
        }
        strftime(date_str, 100, "%A, %B %d, %Y", date);
        printf("Date: %s\n", date_str);
        token = strtok(NULL, " ");
    }
    return 0;
}