//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert natural language date to numerical date
void convertDate(char *input_date) {

    // array of month names to match with input string
    char *month_names[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    int day, month, year;
    char *token = strtok(input_date, " ");

    // check if input date is in correct format
    if (token != NULL && token[0] >= '0' && token[0] <= '9') {
        // numerical date format
        sscanf(token, "%d", &month);

        token = strtok(NULL, " ");
        sscanf(token, "%d", &day);

        token = strtok(NULL, " ");
        sscanf(token, "%d", &year);
    } else {
        // natural language date format
        int i = 0;
        for (; i < 12; i++) {
            if (strcmp(token, month_names[i]) == 0) break;
        }
        month = i + 1;

        token = strtok(NULL, " ");
        sscanf(token, "%d,", &day);

        token = strtok(NULL, " ");
        sscanf(token, "%d", &year);
    }

    // print the converted numerical date
    printf("%d-%02d-%02d", year, month, day);
}

int main() {
    char input_date[50];

    printf("Enter a date in natural language or numerical format: ");
    fgets(input_date, sizeof input_date, stdin);

    // remove newline character
    input_date[strcspn(input_date, "\n")] = 0;

    convertDate(input_date);

    return 0;
}