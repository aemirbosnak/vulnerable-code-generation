//Falcon-180B DATASET v1.0 Category: Error handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function declarations
void initialize_array(char *arr, int size);
int is_valid_ip_address(char *ip_address);

int main(int argc, char *argv[]) {
    char ip_address[MAX_SIZE];

    // Check if the correct number of arguments are provided
    if (argc!= 2) {
        printf("Error: Invalid number of arguments.\n");
        return 1;
    }

    // Copy the argument to the ip_address array
    strcpy(ip_address, argv[1]);

    // Initialize the ip_address array
    initialize_array(ip_address, strlen(ip_address));

    // Check if the ip_address is valid
    if (is_valid_ip_address(ip_address)) {
        printf("The IP address is valid.\n");
    } else {
        printf("The IP address is invalid.\n");
    }

    return 0;
}

// Initializes the ip_address array with '.' characters
void initialize_array(char *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = '.';
    }
}

// Checks if the ip_address is valid
int is_valid_ip_address(char *ip_address) {
    int i, j, num_parts = 0;
    char *part;

    // Split the ip_address into parts
    part = strtok(ip_address, ".");
    while (part!= NULL) {
        num_parts++;
        part = strtok(NULL, ".");
    }

    // Check if there are exactly 4 parts
    if (num_parts!= 4) {
        return 0;
    }

    // Check each part for validity
    for (i = 0; i < num_parts; i++) {
        part = strtok(ip_address, ".");
        for (j = 0; j < strlen(part); j++) {
            if (!isdigit(part[j])) {
                return 0;
            }
        }
        if (atoi(part) < 0 || atoi(part) > 255) {
            return 0;
        }
    }

    return 1;
}