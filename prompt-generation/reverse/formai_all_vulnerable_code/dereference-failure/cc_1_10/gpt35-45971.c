//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARS 100

// Function to perform Digital Watermarking on a string
void digital_watermarking(char *string_to_mark, char *watermark) {

    // Calculate the length of both the string and watermark
    int string_len = strlen(string_to_mark), watermark_len = strlen(watermark);

    // Check if the length of watermark is greater than the string. If yes, then generate an error and return.
    if(watermark_len > string_len) {
        printf("Watermark length is greater than string length. Digital Watermarking failed.\n");
        return;
    }

    // Get the ASCII sum of the characters in the watermark
    int watermark_sum = 0;
    for(int i=0; i<watermark_len; i++) {
        watermark_sum += watermark[i];
    }

    // Insert the watermark at the middle of the string
    int insert_index = string_len/2 - watermark_len/2;
    for(int i=string_len-1; i>=insert_index; i--) {
        string_to_mark[i+watermark_len] = string_to_mark[i];
    }
    for(int i=0; i<watermark_len; i++) {
        string_to_mark[insert_index+i] = watermark[i];
    }

    // Modify the string to include the watermark sum at the end
    string_to_mark[string_len+watermark_len] = '\0';
    sprintf(string_to_mark+string_len, "%d", watermark_sum);

    printf("\nDigital Watermarking Successful.\n");
}

// Function to extract watermarked text and watermark sum from a given watermarked string
void extract_watermark(char *watermarked_text, char *extracted_text, int *watermark_sum) {

    // Get the length of watermarked text
    int watermarked_text_len = strlen(watermarked_text);

    // Get the watermark sum from the end of the watermarked text
    char watermark_sum_str[MAX_CHARS];
    int i = watermarked_text_len - 1;
    while(watermarked_text[i] >= '0' && watermarked_text[i] <= '9') {
        watermark_sum_str[i-(watermarked_text_len-1)] = watermarked_text[i];
        i--;
    }
    *watermark_sum = atoi(watermark_sum_str);

    // Extract the original text from the watermarked text
    int extracted_len = watermarked_text_len - strlen(watermark_sum_str);
    strncpy(extracted_text, watermarked_text, extracted_len);
    extracted_text[extracted_len] = '\0';
}

int main() {

    // Take the input string and watermark from the user
    char input_string[MAX_CHARS];
    printf("Enter the input string:\n");
    fgets(input_string, MAX_CHARS, stdin);

    char watermark[MAX_CHARS];
    printf("Enter the watermark:\n");
    fgets(watermark, MAX_CHARS, stdin);

    // Perform Digital Watermarking
    digital_watermarking(input_string, watermark);

    // Extract the watermark and original text from the watermarked result
    char extracted_text[MAX_CHARS];
    int watermark_sum;

    extract_watermark(input_string, extracted_text, &watermark_sum);

    printf("\nExtracted Text: %s\n", extracted_text);
    printf("Extracted Watermark Sum: %d\n", watermark_sum);

    return 0;
}