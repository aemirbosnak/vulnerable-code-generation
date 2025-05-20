//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Let's play a game of bitwise operations!

    // First, let's define some happy numbers.
    unsigned int num1 = 0xCAFEF00D;  // Looks like a happy face :)
    unsigned int num2 = 0xDEADBEEF;  // And this one looks like a skull and crossbones :P

    // Now, let's perform some bitwise operations on them.
    unsigned int result = num1 & num2;  // Bitwise AND
    printf("num1 & num2 = 0x%08X\n", result);  // Should be 0xDEADF00D

    result = num1 | num2;  // Bitwise OR
    printf("num1 | num2 = 0x%08X\n", result);  // Should be 0xCAFEFFFF

    result = num1 ^ num2;  // Bitwise XOR
    printf("num1 ^ num2 = 0x%08X\n", result);  // Should be 0x22620F02

    result = ~num1;  // Bitwise NOT
    printf("~num1 = 0x%08X\n", result);  // Should be 0x35310FF2

    result = num1 << 2;  // Bitwise left shift
    printf("num1 << 2 = 0x%08X\n", result);  // Should be 0x95FC001A

    result = num1 >> 2;  // Bitwise right shift
    printf("num1 >> 2 = 0x%08X\n", result);  // Should be 0x15FBF7E6

    // Now, let's try some more complex operations.
    result = (num1 & num2) | (~num1 & num2);  // Bitwise AND followed by bitwise OR
    printf("(num1 & num2) | (~num1 & num2) = 0x%08X\n", result);  // Should be 0xCAFEFFFF

    result = (num1 | num2) & (~num1 | num2);  // Bitwise OR followed by bitwise AND
    printf("(num1 | num2) & (~num1 | num2) = 0x%08X\n", result);  // Should be 0xDEADBEEF

    // And finally, let's perform some bitwise operations on a string.
    char *str = "Hello, world!";
    unsigned int str_len = strlen(str);

    for (unsigned int i = 0; i < str_len; i++) {
        str[i] ^= 0x55;  // Bitwise XOR with 0x55 to encrypt the string
    }

    printf("Encrypted string: %s\n", str);  // Should be "Wkh\v|riiwv;"

    for (unsigned int i = 0; i < str_len; i++) {
        str[i] ^= 0x55;  // Bitwise XOR with 0x55 again to decrypt the string
    }

    printf("Decrypted string: %s\n", str);  // Should be "Hello, world!"

    // Hope you enjoyed this happy bitwise operations adventure!
    return 0;
}