//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_LINE_LENGTH 80

typedef struct {
    char input_string[MAX_LINE_LENGTH];
    int is_valid_input;
} Input;

Input read_input(FILE *stream) {
    Input input;
    input.is_valid_input = TRUE;
    fgets(input.input_string, MAX_LINE_LENGTH, stream);
    if (feof(stream)) {
        input.is_valid_input = FALSE;
    }
    return input;
}

int is_numeric(const char *string) {
    for (int i = 0; string[i]!= '\0'; i++) {
        if (!isdigit(string[i])) {
            return FALSE;
        }
    }
    return TRUE;
}

int convert_celsius_to_fahrenheit(double celsius) {
    return (int) ((celsius * 9.0) / 5.0 + 32.0);
}

int convert_fahrenheit_to_celsius(double fahrenheit) {
    return (int) ((fahrenheit - 32.0) * 5.0 / 9.0);
}

int main() {
    FILE *input_file = stdin;
    FILE *output_file = stdout;
    Input input;
    char choice;
    int celsius, fahrenheit;

    do {
        printf("Enter temperature value (C or F): ");
        input = read_input(input_file);
        if (input.is_valid_input) {
            if (is_numeric(input.input_string)) {
                celsius = atoi(input.input_string);
                printf("Enter temperature unit (C or F): ");
                input = read_input(input_file);
                if (input.is_valid_input) {
                    choice = input.input_string[0];
                    if (choice == 'C' || choice == 'c') {
                        fahrenheit = convert_celsius_to_fahrenheit(celsius);
                        printf("%.0f degrees Celsius is %.0f degrees Fahrenheit.\n", celsius, fahrenheit);
                    } else if (choice == 'F' || choice == 'f') {
                        celsius = convert_fahrenheit_to_celsius(celsius);
                        printf("%.0f degrees Fahrenheit is %.0f degrees Celsius.\n", celsius, fahrenheit);
                    } else {
                        printf("Invalid temperature unit.\n");
                    }
                } else {
                    printf("Invalid input.\n");
                }
            } else {
                printf("Invalid input.\n");
            }
        } else {
            printf("End of file reached.\n");
            break;
        }
    } while (TRUE);

    fclose(input_file);
    fclose(output_file);
    return 0;
}