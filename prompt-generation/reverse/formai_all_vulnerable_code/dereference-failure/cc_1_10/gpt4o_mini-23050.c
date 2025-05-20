//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 256

/* 
 * Function to calculate the checksum of a string 
 * using a simple algorithm (summing the ASCII values).
 */
unsigned short calculate_checksum(const char *data) {
    unsigned short checksum = 0;
    while (*data) {
        checksum += (unsigned char)(*data);
        data++;
    }
    return checksum;
}

/* 
 * Function to read data from a file and calculate its checksum 
 */
unsigned short calculate_file_checksum(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    unsigned short checksum = 0;
    char buffer[MAX_LEN];
    
    while (fgets(buffer, MAX_LEN, file)) {
        checksum += calculate_checksum(buffer);
    }
    
    fclose(file);
    return checksum;
}

/* 
 * Function to print the checksum in hexadecimal format 
 */
void print_checksum(const char *filename, unsigned short checksum) {
    printf("Checksum for file '%s': 0x%04X\n", filename, checksum);
}

/*
 * Function to interactively prompt user for a string input 
 */
void interactive_input() {
    char input[MAX_LEN];
    printf("Enter a string to calculate its checksum: ");
    fgets(input, MAX_LEN, stdin);
    
    // Remove newline character if it exists 
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    
    unsigned short checksum = calculate_checksum(input);
    printf("Checksum for input string: 0x%04X\n", checksum);
}

/*
 * Main function to execute the program logic 
 */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename|interactive>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    if (strcmp(argv[1], "interactive") == 0) {
        interactive_input();
    } else {
        unsigned short checksum = calculate_file_checksum(argv[1]);
        if (checksum != 0) {
            print_checksum(argv[1], checksum);
        }
    }
    
    return EXIT_SUCCESS;
}