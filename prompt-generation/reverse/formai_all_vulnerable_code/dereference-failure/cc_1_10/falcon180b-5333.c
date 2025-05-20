//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 100

typedef struct {
    char *str;
    int len;
} String;

String *newString(char *str) {
    String *s = malloc(sizeof(String));
    s->str = str;
    s->len = strlen(str);
    return s;
}

void deleteString(String *s) {
    free(s->str);
    free(s);
}

int main() {
    char input[MAX_LINE_SIZE];
    String *tempString = NULL;
    int choice;

    printf("Welcome to the Temperature Converter!\n\n");
    printf("Please enter a temperature in either Celsius or Fahrenheit: ");
    fgets(input, MAX_LINE_SIZE, stdin);

    tempString = newString(input);

    if (tempString->len == 0) {
        printf("Error: Empty input.\n");
        return 1;
    }

    if (strstr(tempString->str, "C")) {
        printf("You entered a temperature in Celsius.\n");
        printf("Please enter the temperature in Fahrenheit: ");
        fgets(input, MAX_LINE_SIZE, stdin);

        tempString = newString(input);

        if (tempString->len == 0) {
            printf("Error: Empty input.\n");
            return 1;
        }

        double celsius = atof(tempString->str);
        double fahrenheit = (celsius * 9/5) + 32;

        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
    } else if (strstr(tempString->str, "F")) {
        printf("You entered a temperature in Fahrenheit.\n");
        printf("Please enter the temperature in Celsius: ");
        fgets(input, MAX_LINE_SIZE, stdin);

        tempString = newString(input);

        if (tempString->len == 0) {
            printf("Error: Empty input.\n");
            return 1;
        }

        double fahrenheit = atof(tempString->str);
        double celsius = (fahrenheit - 32) * 5/9;

        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
    } else {
        printf("Error: Invalid temperature unit.\n");
        return 1;
    }

    deleteString(tempString);
    return 0;
}