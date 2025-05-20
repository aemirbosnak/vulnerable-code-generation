//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the binary representation of a decimal number
char* decimal_to_binary(int decimal_num){
    int binary_arr[100], i=0;
    while(decimal_num > 0){
        binary_arr[i] = decimal_num % 2;
        decimal_num /= 2;
        i++;
    }
    char* binary_str = (char*)malloc(sizeof(char)*(i+1));
    for(int j=0; j<i; j++){
        binary_str[j] = binary_arr[i-j-1] + '0';
    }
    binary_str[i] = '\0';
    return binary_str;
}

// Function to embed a watermark in a string using bitwise operations
void embed_watermark(char* in_str, char* watermark, char* out_str){
    int n = strlen(watermark);
    int cnt = 0;
    // Iterate over each character of the string
    for(int i=0; i<strlen(in_str); i++){
        // Convert the character to binary string
        char* binary_str = decimal_to_binary(in_str[i]);
        int j=0;
        // Iterate over each bit of the binary string
        while(j<8){
            if(cnt >= n){
                break;
            }
            // If the bit of the watermark is 1, we set the least significant bit of the current binary digit to 1
            if(watermark[cnt] == '1'){
                binary_str[j] = '1';
            }
            j++;
            cnt++;
        }
        // Convert the modified binary string back to decimal and save it in the output string
        int decimal_val = strtol(binary_str, NULL, 2);
        out_str[i] = (char)decimal_val;
        free(binary_str);
    }
    out_str[strlen(in_str)] = '\0';
}

// Function to extract the watermark from a string using bitwise operations
char* extract_watermark(char* in_str, int watermark_len){
    char* watermark = (char*)malloc(sizeof(char)*(watermark_len+1));
    int cnt = 0;
    // Iterate over each character of the string
    for(int i=0; i<strlen(in_str); i++){
        // Convert the character to binary string
        char* binary_str = decimal_to_binary(in_str[i]);
        int j=0;
        // Iterate over each bit of the binary string
        while(j<8){
            if(cnt >= watermark_len){
                break;
            }
            // Extract the least significant bit of the current binary digit and save it in the watermark
            watermark[cnt] = binary_str[j];
            j++;
            cnt++;
        }
        free(binary_str);
        if(cnt >= watermark_len){
            break;
        }
    }
    watermark[watermark_len] = '\0';
    return watermark;
}

int main(){
    char in_str[100];
    char watermark[100];
    // Input the string and the watermark
    printf("Enter the string: ");
    scanf("%[^\n]%*c", in_str);
    printf("Enter the watermark: ");
    scanf("%[^\n]%*c", watermark);
    // Find the length of the watermark and the length of the string
    int watermark_len = strlen(watermark);
    int str_len = strlen(in_str);
    // Embed the watermark in the string
    char out_str[100];
    embed_watermark(in_str, watermark, out_str);
    // Print the modified string
    printf("Embedded String: %s\n", out_str);
    // Extract the watermark from the modified string and print it
    char* extracted_watermark = extract_watermark(out_str, watermark_len);
    printf("Extracted Watermark: %s\n", extracted_watermark);
    return 0;
}