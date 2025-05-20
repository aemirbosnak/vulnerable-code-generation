//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Function prototypes */
unsigned long calculate_checksum(const char *data, size_t length);
void print_usage(const char *program_name);
void introspect_input_data(const char *data);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_data = argv[1];
    size_t length = strlen(input_data);
    
    printf("Received input data: \"%s\"\n", input_data);
    printf("Length of input data: %zu characters\n", length);

    introspect_input_data(input_data);

    unsigned long checksum = calculate_checksum(input_data, length);
    printf("Calculated checksum: %lu\n", checksum);
    
    return EXIT_SUCCESS;
}

/* Function to calculate checksum */
unsigned long calculate_checksum(const char *data, size_t length) {
    unsigned long checksum = 0;
    for (size_t i = 0; i < length; i++) {
        checksum += (unsigned char)data[i];
        checksum ^= (unsigned long)data[i] << (i % 8);
    }
    return checksum;
}

/* Function to print program usage */
void print_usage(const char *program_name) {
    printf("Usage: %s <string>\n", program_name);
    printf("Calculates the checksum of the given string input.\n");
}

/* Function to introspect the input data */
void introspect_input_data(const char *data) {
    printf("Introspecting input data...\n");
    printf("Analyzing data character by character:\n");
    
    for (size_t i = 0; i < strlen(data); i++) {
        printf("Char %zu: '%c' (ASCII: %d)\n", i, data[i], (int)data[i]);
        
        // Additional analysis - check if character is alphanumeric
        if ((data[i] >= 'A' && data[i] <= 'Z') || (data[i] >= 'a' && data[i] <= 'z')) {
            printf(" - Alphabetic character\n");
        } else if (data[i] >= '0' && data[i] <= '9') {
            printf(" - Numeric character\n");
        } else {
            printf(" - Special character\n");
        }
    }
    
    printf("End of introspection.\n");
}