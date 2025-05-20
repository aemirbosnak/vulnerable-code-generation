//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an image to ASCII art
void convertImageToAscii(const char *filename, const char *output)
{
    // Open the image file
    FILE *imageFile = fopen(filename, "r");
    if (imageFile == NULL)
    {
        printf("Error opening image file: %s\n", filename);
        return;
    }
    
    // Read the image data
    char buffer[100];
    fread(buffer, sizeof(char), 100, imageFile);
    
    // Convert the image data to ASCII art
    printf("Converting image to ASCII art...\n");
    printf("---------------------------------\n");
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (buffer[i] >= 'A' && buffer[i] <= 'Z')
            printf("%c", buffer[i] - 'A' + '0');
        else if (buffer[i] >= 'a' && buffer[i] <= 'z')
            printf("%c", buffer[i] - 'a' + '0');
        else
            printf("%c", buffer[i]);
        if ((i + 1) % 80 == 0)
            printf("\n");
    }
    printf("---------------------------------\n");
    
    // Write the ASCII art to a file
    FILE *asciiFile = fopen(output, "w");
    if (asciiFile == NULL)
    {
        printf("Error opening ASCII art file: %s\n", output);
        return;
    }
    fwrite(buffer, sizeof(char), strlen(buffer), asciiFile);
    fclose(asciiFile);
    
    printf("Image converted to ASCII art!\n");
    printf("---------------------------------\n");
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <image file> <ASCII art file>\n", argv[0]);
        return 1;
    }
    
    const char *imageFile = argv[1];
    const char *outputFile = argv[2];
    
    convertImageToAscii(imageFile, outputFile);
    
    return 0;
}