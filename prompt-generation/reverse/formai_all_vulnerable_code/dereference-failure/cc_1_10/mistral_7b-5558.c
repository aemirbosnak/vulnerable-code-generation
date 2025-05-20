//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char unit[10];
    double conversion_factor;
} UnitConversion;

UnitConversion units[] = {
    {"Miles", 0.000621371},
    {"Kilometers", 1.60934},
    {"Pounds", 0.453592},
    {"Kilograms", 2.20462},
    {"Gallons", 3.78541},
    {"Liters", 0.264172},
    {"Fahrenheit", 0.555556},
    {"Celsius", 1.8},
    {"Inches", 0.0254},
    {"Centimeters", 0.01}
};

void print_usage() {
    printf("\nUSAGE:\n");
    printf("Converter <source-unit> <amount> <destination-unit>\n");
    printf("Example: Converter Miles 10 Kilometers\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int i;
    int num_arguments = argc;

    if (num_arguments != 4) {
        print_usage();
    }

    for (i = 0; i < 10; i++) {
        if (strcmp(argv[1], units[i].unit) == 0) {
            double source_amount = atof(argv[2]);
            double conversion_factor = source_amount * units[i].conversion_factor;

            for (int j = 0; j < 10; j++) {
                if (strcmp(argv[3], units[j].unit) == 0) {
                    double destination_amount = conversion_factor * units[j].conversion_factor;
                    printf("%.16f %s is equal to %.16f %s\n", source_amount, argv[1], destination_amount, argv[3]);
                    return 0;
                }
            }

            print_usage();
        }
    }

    print_usage();
}