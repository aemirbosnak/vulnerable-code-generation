//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB

// Function to read the file into memory
void read_file(FILE *file, char *buffer) {
    int bytes_read = 0;
    int buffer_index = 0;

    while ((bytes_read = fread(buffer + buffer_index, 1, MAX_FILE_SIZE - buffer_index, file)) > 0) {
        buffer_index += bytes_read;
    }

    buffer[buffer_index] = '\0';
}

// Function to count the frequency of each character in the buffer
void count_frequency(char *buffer, int freq_table[256]) {
    int i;

    for (i = 0; i < strlen(buffer); i++) {
        freq_table[buffer[i]]++;
    }
}

// Function to print the frequency table
void print_frequency_table(int freq_table[256]) {
    int i;

    for (i = 0; i < 256; i++) {
        if (freq_table[i] > 0) {
            printf("%c: %d\n", i, freq_table[i]);
        }
    }
}

int main() {
    FILE *file;
    char buffer[MAX_FILE_SIZE];
    int freq_table[256] = {0};

    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(file, buffer);
    count_frequency(buffer, freq_table);
    print_frequency_table(freq_table);

    fclose(file);

    return 0;
}