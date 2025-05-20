//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>

#define BUF_SIZE 1024

// Function to convert hexadecimal number to decimal
int hex_to_dec(char* hex, int len) {
    int dec = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(hex[i])) {
            dec = dec * 10 + hex[i] - '0';
        } else {
            if (hex[i] == 'A') dec = dec * 16 + 10;
            else if (hex[i] == 'B') dec = dec * 16 + 11;
            else if (hex[i] == 'C') dec = dec * 16 + 12;
            else if (hex[i] == 'D') dec = dec * 16 + 13;
            else if (hex[i] == 'E') dec = dec * 16 + 14;
            else if (hex[i] == 'F') dec = dec * 16 + 15;
        }
    }
    return dec;
}

// Function to convert decimal number to hexadecimal
char* dec_to_hex(int dec) {
    char* hex = (char*)malloc(sizeof(char) * 3);
    hex[0] = dec / 16 + '0';
    hex[1] = (dec / 4 % 16) + '0';
    hex[2] = dec % 4 + '0';
    return hex;
}

// Function to get time in seconds
double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec + (tv.tv_usec / 1000000.0));
}

// Function to get input
char* get_input(char* prompt) {
    char* input = (char*)malloc(sizeof(char) * BUF_SIZE);
    printf("%s", prompt);
    fgets(input, BUF_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';
    return input;
}

// Function to convert hexadecimal number to decimal
int main() {
    char* input;
    double start_time, end_time;
    double total_time;
    int hex_value;

    printf("Enter hexadecimal number: ");
    input = get_input("> ");

    start_time = get_time();
    hex_value = hex_to_dec(input, strlen(input));
    end_time = get_time();

    printf("Hexadecimal number %s is equal to %d\n", input, hex_value);
    total_time = end_time - start_time;
    printf("Time taken: %.2f seconds\n", total_time);

    printf("Enter decimal number: ");
    input = get_input("> ");

    start_time = get_time();
    char* hex_str = dec_to_hex(hex_value);
    end_time = get_time();

    printf("Decimal number %d is equal to %s\n", hex_value, hex_str);
    total_time = end_time - start_time;
    printf("Time taken: %.2f seconds\n", total_time);

    free(hex_str);
    return 0;
}