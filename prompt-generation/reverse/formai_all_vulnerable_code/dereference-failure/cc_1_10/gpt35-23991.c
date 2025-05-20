//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_LENGTH 100000
#define MAX_WATERMARK_LENGTH 100

/* Function Declarations */
void embedWatermark(char *original_string, char *watermark_string);
void extractWatermark(char *original_string);

/* Main Function */
int main()
{
    char original_string[MAX_STRING_LENGTH], watermark_string[MAX_WATERMARK_LENGTH];
    
    /* Accepting user input */
    printf("Enter the original string to be watermarked: \n");
    fgets(original_string, MAX_STRING_LENGTH, stdin);
    
    printf("Enter the watermark string: \n");
    fgets(watermark_string, MAX_WATERMARK_LENGTH, stdin);
    
    /* Embedding watermark into original string */
    embedWatermark(original_string, watermark_string);
    
    /* Extracting watermark from the watermarked string */
    extractWatermark(original_string);
    
    return 0;
}

/* Function to Embed Watermark into Original String */
void embedWatermark(char *original_string, char *watermark_string)
{
    int string_length = strlen(original_string);
    int watermark_length = strlen(watermark_string);
    int index = (string_length - watermark_length) / 2;
    
    /* Embed watermark into original string */
    for(int i=0; i<watermark_length; i++)
    {
        original_string[index+i] = watermark_string[i];
    }
    
    printf("\nWatermark Successfully Embedded!\n\n");
}

/* Function to Extract Watermark from the Watermarked String */
void extractWatermark(char *original_string)
{
    int string_length = strlen(original_string);
    int watermark_length = 10; // Assuming watermark length to be 10.
    int index = (string_length - watermark_length) / 2;
    
    char *extracted_watermark = malloc(watermark_length+1);
    
    /* Extract watermark from the watermarked string */
    for(int i=0; i<watermark_length; i++)
    {
        extracted_watermark[i] = original_string[index+i];
    }
    extracted_watermark[watermark_length] = '\0';
    
    printf("Extracted Watermark: %s\n", extracted_watermark);
    
    free(extracted_watermark);
}