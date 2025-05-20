//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

// Function to check if a word is a valid date
int is_valid_date(char* word) {
    int day, month, year;
    char* date_format = "dd/mm/yyyy";

    // Check if the word matches the date format
    if (strlen(word)!= strlen(date_format)) {
        return 0;
    }

    // Extract day, month and year from the word
    sscanf(word, date_format, &day, &month, &year);

    // Check if the extracted values are valid
    if (day < 1 || day > 31 || month < 1 || month > 12) {
        return 0;
    }

    // Check if the year is valid
    if (year < 1000 || year > 9999) {
        return 0;
    }

    return 1;
}

// Function to convert a date from natural language to date format
char* convert_date(char* word) {
    char* date_format = "dd/mm/yyyy";
    char* result = malloc(MAX_WORD_LENGTH * sizeof(char));

    // Check if the word is a valid date
    if (!is_valid_date(word)) {
        strcpy(result, "Invalid date");
        return result;
    }

    // Convert the word to date format
    sscanf(word, "%s %s %s", date_format, result, result + strlen(date_format));

    return result;
}

int main() {
    char* input_string = "Today is 15th July, 2021. I was born on 25th December, 1990.";
    char* word;

    // Extract words from the input string
    word = strtok(input_string, " ");
    while (word!= NULL) {
        // Check if the word is a date
        if (isdigit(word[0]) && isdigit(word[1]) && isdigit(word[3])) {
            char* converted_date = convert_date(word);
            printf("%s\n", converted_date);
            free(converted_date);
        }
        word = strtok(NULL, " ");
    }

    return 0;
}