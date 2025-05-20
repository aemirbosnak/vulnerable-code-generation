//Falcon-180B DATASET v1.0 Category: Educational ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a random number
void print_num(int num) {
    printf("Random number: %d\n", num);
}

// Function to generate a random string of given length
char* rand_str(int length) {
    char* str = (char*) malloc(length + 1);
    for(int i=0; i<length; i++) {
        str[i] = rand() % 26 + 'a'; // Generating lowercase letter
    }
    str[length] = '\0';
    return str;
}

// Function to print a random string
void print_str(char* str) {
    printf("Random string: %s\n", str);
}

int main() {
    srand(time(NULL)); // Initialize random seed based on current time

    int num1 = rand_num(1, 100);
    int num2 = rand_num(1, 100);
    int num3 = rand_num(1, 100);

    printf("Three random numbers between 1 and 100:\n");
    print_num(num1);
    print_num(num2);
    print_num(num3);

    char* str1 = rand_str(10);
    char* str2 = rand_str(10);
    char* str3 = rand_str(10);

    printf("\nThree random strings of length 10:\n");
    print_str(str1);
    print_str(str2);
    print_str(str3);

    return 0;
}