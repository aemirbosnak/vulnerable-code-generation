//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to hexadecimal.
char *dec_to_hex(int dec_num) {
    char hex_digits[] = "0123456789ABCDEF";
    char *hex_num = malloc(sizeof(char) * 20);
    int hex_num_index = 0;
    
    // Keep dividing by 16 until the number becomes zero.
    while (dec_num > 0) {
        int remainder = dec_num % 16;
        hex_num[hex_num_index] = hex_digits[remainder];
        hex_num_index++;
        dec_num /= 16;
    }
    
    // Reverse the order of the characters in the hex number.
    int i, j;
    for (i = 0, j = strlen(hex_num) - 1; i < j; i++, j--) {
        char temp = hex_num[i];
        hex_num[i] = hex_num[j];
        hex_num[j] = temp;
    }
    
    return hex_num;
}

int main() {
    int num1, num2, num3, hex_sum;
    char *hex_sum_str;
    
    printf("Enter three decimal numbers:\n");
    scanf("%d%d%d", &num1, &num2, &num3);
    
    // Convert each decimal number to hexadecimal.
    char *hex_num1 = dec_to_hex(num1);
    char *hex_num2 = dec_to_hex(num2);
    char *hex_num3 = dec_to_hex(num3);
    
    // Compute the sum of the three hexadecimal numbers.
    hex_sum_str = malloc(sizeof(char) * 20);
    strcpy(hex_sum_str, hex_num1);
    strcat(hex_sum_str, hex_num2);
    strcat(hex_sum_str, hex_num3);
    hex_sum = (int) strtol(hex_sum_str, NULL, 16);
    
    // Output the results.
    printf("\nHexadecimal values:\n");
    printf("%d = %s\n", num1, hex_num1);
    printf("%d = %s\n", num2, hex_num2);
    printf("%d = %s\n", num3, hex_num3);
    printf("\nSum of hexadecimal values:\n");
    printf("%s + %s + %s = %s\n", hex_num1, hex_num2, hex_num3, dec_to_hex(hex_sum));
    
    free(hex_num1);
    free(hex_num2);
    free(hex_num3);
    free(hex_sum_str);
    
    return 0;
}