//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STRING_SIZE 100

// This function takes in a string as an input and returns its length
int string_length(char* string){
    int length = 0; // initialize the length to be zero
    while(string[length]) length++; // increment the length till the end of the string
    return length;
}

// This function takes in a string as an input and returns its ASCII sum
int calculate_ascii_sum(char* string){
    int length = string_length(string);
    int ascii_sum = 0; // initialize the ascii_sum to be zero
    for(int i=0; i<length; i++) ascii_sum += (int)string[i]; // add the ASCII value of each character to the sum
    return ascii_sum;
}

// This function takes in a string as an input and returns its binary representation
char* calculate_binary(char* string){
    int length = string_length(string);
    int ascii_sum = calculate_ascii_sum(string);
    int binary_length = (int)(log2(ascii_sum))+1; // calculate the length of the binary representation required
    char* binary = (char*)malloc(binary_length*sizeof(char));

    // Convert the decimal value to binary
    int i=0;
    while (ascii_sum > 0) {
        binary[i++] = ascii_sum%2 + '0'; // get the last bit of the number and add it to the binary string
        ascii_sum /= 2; // shift the number one bit to the right
    }
    binary[i] = '\0'; // end the binary string with null terminator

    return binary;
}

int main(){
    char input[MAX_STRING_SIZE];
    printf("Enter a string: ");
    fgets(input, MAX_STRING_SIZE, stdin); // read the input string from the user

    char* binary = calculate_binary(input);
    printf("Binary representation: %s\n", binary);

    free(binary); // free the dynamically allocated memory for the binary string

    return 0;
}