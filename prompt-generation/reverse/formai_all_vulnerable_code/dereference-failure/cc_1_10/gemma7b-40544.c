//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct TextBlob
{
    char *text;
    int length;
} TextBlob;

TextBlob *text_blob_new(int length)
{
    TextBlob *blob = malloc(sizeof(TextBlob));
    blob->text = malloc(length * MAX_BUFFER_SIZE);
    blob->length = length;

    return blob;
}

void text_blob_free(TextBlob *blob)
{
    free(blob->text);
    free(blob);
}

int text_blob_append(TextBlob *blob, char *text, int length)
{
    int i = 0;

    if (blob->length * MAX_BUFFER_SIZE < length)
    {
        return -1;
    }

    for (i = 0; i < length; i++)
    {
        blob->text[blob->length++] = text[i];
    }

    return 0;
}

char *text_blob_get(TextBlob *blob)
{
    return blob->text;
}

int main()
{
    TextBlob *blob = text_blob_new(100);

    text_blob_append(blob, "This is a sample text.", 20);
    text_blob_append(blob, "It has been modified.", 15);

    char *text = text_blob_get(blob);

    printf("%s", text);

    text_blob_free(blob);

    return 0;
}