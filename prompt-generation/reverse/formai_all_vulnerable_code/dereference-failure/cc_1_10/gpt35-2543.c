//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 20
#define FILENAME_SIZE 50

char* generateWatermark()
{
    char* watermark = (char*) malloc(WATERMARK_SIZE * sizeof(char));

    // Generate a random string of lowercase letters
    for (int i = 0; i < WATERMARK_SIZE - 1; i++)
    {
        watermark[i] = 'a' + rand() % 26;
    }

    // Add null terminator to the end of the string
    watermark[WATERMARK_SIZE - 1] = '\0';

    return watermark;
}

void embedWatermark(char* filename, char* watermark)
{
    FILE* fp = fopen(filename, "r+");

    if (fp == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    // Skip the watermark size bytes (to keep the original file size)
    fseek(fp, WATERMARK_SIZE, SEEK_SET);

    // Embed the watermark in the file
    for (int i = 0; i < WATERMARK_SIZE - 1; i++)
    {
        fputc(watermark[i], fp);
    }

    fclose(fp);

    printf("Watermark '%s' embedded in file %s\n", watermark, filename);
}

char* extractWatermark(char* filename)
{
    char* watermark = (char*) malloc(WATERMARK_SIZE * sizeof(char));
    
    FILE* fp = fopen(filename, "r");
    
    if (fp == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }
    
    // Read the watermark from the file
    fseek(fp, WATERMARK_SIZE, SEEK_SET);
    
    for (int i = 0; i < WATERMARK_SIZE - 1; i++)
    {
        watermark[i] = fgetc(fp);
    }
    
    watermark[WATERMARK_SIZE - 1] = '\0';

    fclose(fp);

    return watermark;
}

int main()
{
    char filename[FILENAME_SIZE];

    printf("Enter filename to embed watermark: ");
    scanf("%s", filename);

    char* watermark = generateWatermark();

    embedWatermark(filename, watermark);

    free(watermark);

    printf("Enter filename to extract watermark: ");
    scanf("%s", filename);

    char* extractedWatermark = extractWatermark(filename);

    if (extractedWatermark != NULL)
    {
        printf("Extracted watermark: '%s'\n", extractedWatermark);
        free(extractedWatermark);
    }

    return 0;
}