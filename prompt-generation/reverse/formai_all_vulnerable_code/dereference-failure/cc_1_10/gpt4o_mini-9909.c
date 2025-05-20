//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum for the input data
unsigned int calculate_checksum(const char *data) {
    unsigned int checksum = 0;
    unsigned int length = strlen(data);

    for (unsigned int i = 0; i < length; i++) {
        checksum += data[i];
    }

    return checksum;
}

// Function to read data from a file
char* read_data_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *data = (char *)malloc(file_size + 1);
    if (data == NULL) {
        perror("Unable to allocate memory for file data");
        fclose(file);
        return NULL;
    }

    fread(data, 1, file_size, file);
    data[file_size] = '\0'; // Null-terminate the string

    fclose(file);
    return data;
}

// Function to write the checksum to a file
int write_checksum_to_file(const char *filename, unsigned int checksum) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file to write checksum");
        return -1;
    }

    fprintf(file, "Checksum: %u\n", checksum);
    fclose(file);

    return 0;
}

// Function to display the help information
void display_help() {
    printf("Checksum Calculator\n");
    printf("Usage: checksum_calculator <input_file> <output_file>\n");
    printf("Calculates the checksum of the data from <input_file> and writes\n");
    printf("the checksum to <output_file>.\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_help();
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    char *data = read_data_from_file(input_file);
    if (data == NULL) {
        return EXIT_FAILURE;
    }

    unsigned int checksum = calculate_checksum(data);
    free(data);

    if (write_checksum_to_file(output_file, checksum) != 0) {
        return EXIT_FAILURE;
    }

    printf("Checksum calculated successfully: %u\n", checksum);
    printf("Checksum written to: %s\n", output_file);

    return EXIT_SUCCESS;
}