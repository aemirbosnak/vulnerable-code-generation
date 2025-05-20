//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold data and checksum
typedef struct {
    char *data;
    unsigned int checksum;
} ChecksumData;

// Function to calculate the checksum of the given data
unsigned int calculate_checksum(const char *data) {
    unsigned int checksum = 0;
    while (*data) {
        checksum += (unsigned char)(*data);
        data++;
    }
    return checksum;
}

// Function to allocate memory for ChecksumData and initialize it
ChecksumData* create_checksum_data(const char *data) {
    ChecksumData *cs_data = (ChecksumData *)malloc(sizeof(ChecksumData));
    if (!cs_data) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    cs_data->data = (char *)malloc(strlen(data) + 1);
    if (!cs_data->data) {
        fprintf(stderr, "Memory allocation error!\n");
        free(cs_data);
        exit(EXIT_FAILURE);
    }
    strcpy(cs_data->data, data);
    cs_data->checksum = calculate_checksum(data);
    return cs_data;
}

// Function to print the checksum data
void print_checksum_data(const ChecksumData *cs_data) {
    printf("Data: %s\n", cs_data->data);
    printf("Checksum: %u\n", cs_data->checksum);
}

// Function to free the allocated memory for ChecksumData
void free_checksum_data(ChecksumData *cs_data) {
    if (cs_data) {
        free(cs_data->data);
        free(cs_data);
    }
}

// Function to read input from the user
char* read_input() {
    char *buffer = NULL;
    size_t size = 0;
    printf("Enter data for checksum calculation: ");
    getline(&buffer, &size, stdin);
    // Remove the newline character at the end of the input
    buffer[strcspn(buffer, "\n")] = 0;
    return buffer;
}

// Main function to execute the program
int main() {
    char *input_data = read_input();
    ChecksumData *cs_data = create_checksum_data(input_data);
    print_checksum_data(cs_data);
    free_checksum_data(cs_data);
    free(input_data);
    return EXIT_SUCCESS;
}