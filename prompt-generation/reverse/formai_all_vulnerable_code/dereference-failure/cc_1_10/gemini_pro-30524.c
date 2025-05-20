//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void print_usage(const char *progname) {
    fprintf(stderr, "Usage: %s [options] <temperature> <unit>\n", progname);
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "  -h, --help     Print this help message and exit\n");
    fprintf(stderr, "  -v, --verbose  Print additional information\n");
}

int main(int argc, char *argv[]) {
    // Parse command line arguments
    const char *progname = argv[0];
    int verbose = 0;
    for (int i = 1; i < argc; i++) {
        const char *arg = argv[i];
        if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
            print_usage(progname);
            return EXIT_SUCCESS;
        } else if (strcmp(arg, "-v") == 0 || strcmp(arg, "--verbose") == 0) {
            verbose = 1;
        } else {
            // The first non-option argument is the temperature
            const char *temperature_str = arg;

            // The second non-option argument is the unit
            const char *unit_str = argv[++i];

            // Convert the temperature to a double
            double temperature = atof(temperature_str);

            // Convert the unit to a character
            char unit = unit_str[0];

            // Convert the temperature to the other unit
            double converted_temperature;
            if (unit == 'C' || unit == 'c') {
                converted_temperature = temperature * 9 / 5 + 32;
                if (verbose) {
                    printf("Converting from Celsius to Fahrenheit: %.2f C -> %.2f F\n", temperature, converted_temperature);
                }
            } else if (unit == 'F' || unit == 'f') {
                converted_temperature = (temperature - 32) * 5 / 9;
                if (verbose) {
                    printf("Converting from Fahrenheit to Celsius: %.2f F -> %.2f C\n", temperature, converted_temperature);
                }
            } else {
                fprintf(stderr, "Invalid unit: %s\n", unit_str);
                return EXIT_FAILURE;
            }

            // Print the converted temperature
            printf("%.2f\n", converted_temperature);
        }
    }

    return EXIT_SUCCESS;
}