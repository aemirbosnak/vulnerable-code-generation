//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
unsigned long calculate_checksum(const char *data);
void report_checksum(const char *data, unsigned long checksum);
void investigate_case(const char *filename);

int main() {
    // Ah, the lights dim down, and the skies loom overhead. It was not a case for mere mortals.
    printf("Greetings, dear reader. Welcome to the Sherlock Holmes Checksum Calculator.\n");
    
    // Let's inspect a file to unravel the mystery of the missing checksum.
    const char *filename = "case_file.txt";
    printf("Commencing investigation on the file: %s\n", filename);
    investigate_case(filename);
    
    return 0;
}

void investigate_case(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Ah, the file cannot be found!");
        return;
    }
    
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *data = malloc(length + 1);
    if (!data) {
        perror("Unable to allocate memory for investigation...");
        fclose(file);
        return;
    }
    
    fread(data, 1, length, file);
    data[length] = '\0'; // Null-terminate the string

    fclose(file);
    printf("The contents of the file have been gathered, let's proceed!\n");

    unsigned long checksum = calculate_checksum(data);
    report_checksum(data, checksum);

    free(data);
}

unsigned long calculate_checksum(const char *data) {
    unsigned long checksum = 0;
    while (*data) {
        checksum += (unsigned char)(*data++);
    }
    // The calculated checksum is now concealed, awaiting discovery.
    return checksum;
}

void report_checksum(const char *data, unsigned long checksum) {
    printf("The data retrieved from the inscribed pages:\n");
    printf("--------------------------------------------------\n");
    printf("%s\n", data);
    printf("--------------------------------------------------\n");
    printf("Aha! The checksum, a number both grand and grotesque, is: %lu\n", checksum);
    printf("As we bid farewell, remember: some secrets are best left uncovered...\n");
}