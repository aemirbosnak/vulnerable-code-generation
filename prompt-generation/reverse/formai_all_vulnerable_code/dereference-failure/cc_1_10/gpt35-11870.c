//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to convert the character to binary form
void char2bin(char ch, char *str)
{
    for(int i=0; i<8; i++)
    {
        if(ch & (1 << i))
            str[7-i] = '1';
        else
            str[7-i] = '0';
    }
    str[8] = '\0';
}

// Function to convert the binary string to character
char bin2char(char *str)
{
    char ch = 0;

    for(int i=0; i<8; i++)
    {
        if(str[i] == '1')
            ch = ch | (1 << (7-i));
    }

    return ch;
}

// Function to embed the watermark text in the original image
void embedWatermark(FILE *fpIn, FILE *fpOut, char *watermarkText)
{
    char inBuffer[1024], outBuffer[1024], binWatermark[65];
    int idx = 0;
    int len = strlen(watermarkText);

    // Convert the watermark text to binary string
    for(int i=0; i<len; i++)
    {
        char2bin(watermarkText[i], &binWatermark[idx]);
        idx += 8;
    }

    // Read the contents of input file and embed the binary watermark text inside it
    while(!feof(fpIn))
    {
        size_t bytesRead = fread(inBuffer, 1, 1024, fpIn);

        for(int i=0; i<bytesRead && idx<64; i++)
        {
            char2bin(inBuffer[i], &outBuffer[i*8]);

            if(idx < 64)
            {
                outBuffer[i*8+6] = binWatermark[idx++];
            }
        }

        fwrite(outBuffer, 1, bytesRead*8, fpOut);
    }

    fprintf(stderr, "Watermark Embedded successfully!\n");
}

// Function to extract the watermark text from the watermarked image
void extractWatermark(FILE *fpIn, char *watermarkText)
{
    char inBuffer[1024], binWatermark[65];
    int idx = 0, len = 0;

    // Read the contents of watermarked file and extract the binary watermark text from it
    while(!feof(fpIn))
    {
        size_t bytesRead = fread(inBuffer, 1, 1024, fpIn);

        for(int i=0; i<bytesRead; i++)
        {
            binWatermark[idx++] = inBuffer[i*8+6];

            if(idx == 64)
            {
                watermarkText[len++] = bin2char(binWatermark);
                idx = 0;
            }
        }
    }

    fprintf(stderr, "Watermark Extracted successfully!\n");
}

int main(int argc, char *argv[])
{
    if(argc < 4)
    {
        printf("Usage: %s <input_file> <output_file> <\"watermark_text\">\n", argv[0]);
        return -1;
    }

    char *inFile = argv[1];
    char *outFile = argv[2];
    char *watermarkText = argv[3];

    FILE *fpIn = fopen(inFile, "rb");
    FILE *fpOut = fopen(outFile, "wb");

    if(fpIn == NULL || fpOut == NULL)
    {
        perror("Error");
        return -1;
    }

    embedWatermark(fpIn, fpOut, watermarkText);

    fclose(fpIn);
    fclose(fpOut);

    fpIn = fopen(outFile, "rb");

    if(fpIn == NULL)
    {
        perror("Error");
        return -1;
    }

    char extractedWatermarkText[65];
    memset(extractedWatermarkText, 0, 65);

    extractWatermark(fpIn, extractedWatermarkText);

    printf("Watermark Text: %s\n", extractedWatermarkText);

    fclose(fpIn);

    return 0;
}