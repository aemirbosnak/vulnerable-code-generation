//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WM_SIZE 100

void embedWatermark(char *data, char *watermark);
char* extractWatermark(char *data);

int main()
{
    char *msg = "This is a secret message";
    char *watermark = "mywatermark001";
    char watermarkedMsg[WM_SIZE];

    // Embedding watermark
    embedWatermark(msg, watermark);

    // Extracting watermark
    char *extractedWatermark = extractWatermark(watermarkedMsg);
    printf("Extracted watermark: %s", extractedWatermark);

    return 0;
}

void embedWatermark(char *data, char *watermark)
{
    int msgLength = strlen(data);
    int wmLength = strlen(watermark);
    int i, j;

    for(i = 0, j = 0; i < msgLength && j < wmLength; i += 2, j++)
    {
        if(data[i] != watermark[j])
        {
            data[i] = watermark[j];
        }
    }
    strcat(data, watermark); // Add watermark to the end of the message string
}

char* extractWatermark(char *data)
{
    int length = strlen(data);
    int i, j;

    char *extractedWatermark = (char*)malloc(WM_SIZE * sizeof(char));

    for(i = 0, j = 0; i < length; i += 2, j++)
    {
        if(data[i] != extractedWatermark[j])
        {
            extractedWatermark[j] = data[i];
        }
    }
    extractedWatermark[strlen(extractedWatermark) - 12] = '\0'; // Remove the watermark from the end of the message string

    return extractedWatermark;
}