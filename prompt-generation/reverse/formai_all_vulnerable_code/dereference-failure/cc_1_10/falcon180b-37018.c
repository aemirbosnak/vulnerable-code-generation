//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to read file and store data in a buffer
void read_file(char* filename, char* buffer) {
    FILE* file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);
    buffer = (char*) malloc(size + 1);
    fread(buffer, size, 1, file);
    fclose(file);
}

// Function to count the number of words in a buffer
int count_words(char* buffer) {
    int count = 0;
    char* token = strtok(buffer, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Recursive function to analyze the Wi-Fi signal strength
void analyze_signal_strength(char* buffer, int level) {
    char* token = strtok(buffer, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            int signal = atoi(token);
            if (signal >= -50 && signal <= -100) {
                printf("Very Low\n");
            } else if (signal > -100 && signal <= -75) {
                printf("Low\n");
            } else if (signal > -75 && signal <= -50) {
                printf("Fair\n");
            } else if (signal > -50 && signal <= 0) {
                printf("Good\n");
            } else {
                printf("Excellent\n");
            }
        } else if (strcmp(token, "Wi-Fi") == 0) {
            printf("Wi-Fi signal strength: ");
        }
        token = strtok(NULL, " ");
    }
}

int main(int argc, char* argv[]) {
    char buffer[MAX_LENGTH];
    read_file("signal_strength.txt", buffer);
    int count = count_words(buffer);
    for (int i = 0; i < count; i++) {
        analyze_signal_strength(buffer, i);
    }
    return 0;
}