//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_LINE_LENGTH 100

typedef struct {
    char input[MAX_LINE_LENGTH];
    char output[MAX_LINE_LENGTH];
} Conversion;

void get_input(Conversion* conversion) {
    printf("Enter the temperature to convert: ");
    fgets(conversion->input, MAX_LINE_LENGTH, stdin);
    conversion->input[strcspn(conversion->input, "\n")] = '\0';
}

int is_valid_input(Conversion* conversion) {
    char* endptr;
    strtol(conversion->input, &endptr, 10);
    if (endptr!= conversion->input + strlen(conversion->input)) {
        return FALSE;
    }
    return TRUE;
}

void convert_temperature(Conversion* conversion) {
    double temp, converted_temp;
    char unit[3];
    strcpy(unit, conversion->input + strlen(conversion->input) - 2);
    conversion->input[strlen(conversion->input) - 2] = '\0';
    temp = strtod(conversion->input, NULL);
    if (strcmp(unit, "F") == 0) {
        converted_temp = (temp - 32) * 5 / 9;
        sprintf(conversion->output, "%.2fC", converted_temp);
    } else if (strcmp(unit, "C") == 0) {
        converted_temp = temp * 9 / 5 + 32;
        sprintf(conversion->output, "%.2fF", converted_temp);
    } else {
        strcpy(conversion->output, "Invalid unit");
    }
}

void print_result(Conversion* conversion) {
    printf("%.2f %s = %.2f %s\n", strtod(conversion->input, NULL), conversion->input + strlen(conversion->input) - 2, strtod(conversion->output, NULL), conversion->output + strlen(conversion->output) - 2);
}

int main() {
    Conversion conversion;
    char choice;
    do {
        printf("Enter temperature to convert (e.g. 25C or 77F): ");
        get_input(&conversion);
        if (!is_valid_input(&conversion)) {
            printf("Invalid input\n");
        } else {
            convert_temperature(&conversion);
            print_result(&conversion);
        }
        printf("Do you want to convert another temperature? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    return 0;
}