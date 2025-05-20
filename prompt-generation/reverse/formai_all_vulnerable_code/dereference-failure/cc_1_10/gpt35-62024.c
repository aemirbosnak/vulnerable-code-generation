//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024       // Maximum length of the input string
#define MAX_WATERMARK_LEN 256  // Maximum length of the watermark string

// Function to convert an integer to binary in string format
char* int_to_binary_string(int num)
{
    char *str = (char *)malloc(sizeof(char) * 33);
    int i = 0;
    for(i = 31; i >= 0; --i)
    {
        str[31-i] = ((num >> i) & 1) ? '1' : '0';
    }
    str[32] = '\0';
    return str;
}

// Function to convert a binary string to an integer
int binary_string_to_int(char *str)
{
    int num = 0;
    int len = strlen(str);
    int i = 0;
    for(i = 0; str[i] != '\0'; ++i)
    {
        num += ((str[len - i - 1] - '0') << i);
    }
    return num;
}

// Function to add the watermark to the input string
char* add_watermark(char *input, char *watermark)
{
    int input_len = strlen(input);
    int watermark_len = strlen(watermark);

    char *bin_input = (char *)malloc(sizeof(char) * (input_len * 8 + 1));
    bin_input[0] = '\0';
    int i = 0;
    for(i = 0; i < input_len; ++i)
    {
        char *bin_str = int_to_binary_string(input[i]);
        strcat(bin_input, bin_str);
        free(bin_str);
    }

    char *bin_watermark = (char *)malloc(sizeof(char) * (watermark_len * 8 + 1));
    bin_watermark[0] = '\0';
    for(i = 0; i < watermark_len; ++i)
    {
        char *bin_str = int_to_binary_string(watermark[i]);
        strcat(bin_watermark, bin_str);
        free(bin_str);
    }

    char *result = (char *)malloc(sizeof(char) * (input_len + watermark_len + 1));
    result[0] = '\0';

    i = 0;
    int j = 0;
    for(i = 0; i < input_len * 8; i += watermark_len * 8)
    {
        for(j = 0; j < watermark_len * 8 && i + j < input_len * 8; ++j)
        {
            bin_input[i + j] = bin_watermark[j];
        }
    }

    i = 0;
    for(j = 0; j < input_len * 8; j += 8)
    {
        char *bin_str = (char *)malloc(sizeof(char) * 9);
        bin_str[0] = '\0';
        strncpy(bin_str, bin_input + j, 8);
        bin_str[8] = '\0';
        int num = binary_string_to_int(bin_str);
        result[i] = num;
        ++i;
    }

    result[i] = '\0';
    free(bin_input);
    free(bin_watermark);

    return result;
}

// Function to extract the watermark from the watermarked string
char* extract_watermark(char *input, int watermark_len)
{
    int input_len = strlen(input);

    char *bin_input = (char *)malloc(sizeof(char) * (input_len * 8 + 1));
    bin_input[0] = '\0';
    int i = 0;
    for(i = 0; i < input_len; ++i)
    {
        char *bin_str = int_to_binary_string(input[i]);
        strcat(bin_input, bin_str);
        free(bin_str);
    }

    char *bin_watermark = (char *)malloc(sizeof(char) * (watermark_len * 8 + 1));
    bin_watermark[0] = '\0';
    for(i = 0; i < watermark_len; ++i)
    {
        char *bin_str = int_to_binary_string('\0');
        strcat(bin_watermark, bin_str);
        free(bin_str);
    }

    i = 0;
    int j = 0;
    for(i = 0; i < input_len * 8; i += watermark_len * 8)
    {
        for(j = 0; j < watermark_len * 8 && i + j < input_len * 8; ++j)
        {
            bin_watermark[j] = bin_input[i + j];
        }
    }

    char *result = (char *)malloc(sizeof(char) * (watermark_len + 1));
    result[0] = '\0';

    i = 0;
    for(j = 0; j < watermark_len * 8; j += 8)
    {
        char *bin_str = (char *)malloc(sizeof(char) * 9);
        bin_str[0] = '\0';
        strncpy(bin_str, bin_watermark + j, 8);
        bin_str[8] = '\0';
        int num = binary_string_to_int(bin_str);
        result[i] = num;
        ++i;
    }

    result[i] = '\0';
    free(bin_input);
    free(bin_watermark);

    return result;
}

int main()
{
    char input[MAX_STR_LEN] = "This is a test message.";
    char watermark[MAX_WATERMARK_LEN] = "confidential";
    printf("Input string: %s\n", input);
    printf("Watermark: %s\n", watermark);

    char *watermarked = add_watermark(input, watermark);
    printf("Watermarked string: %s\n", watermarked);

    char *extracted = extract_watermark(watermarked, strlen(watermark));
    printf("Extracted watermark: %s\n", extracted);

    free(watermarked);
    free(extracted);

    return 0;
}