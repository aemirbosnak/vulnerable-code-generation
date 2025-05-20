//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Function to implement digital watermarking in C

void digitalWatermark(char *imagePath, char *message, char *outPath){
    
    // Opening the input image file
    FILE *imgFile = fopen(imagePath, "rb");
    if(imgFile == NULL){
        printf("Error: Could not open input image file.\n");
        return;
    }

    // Creating an output file with watermark
    FILE *outFile = fopen(outPath, "wb");
    if(outFile == NULL){
        printf("Error: Could not create output image file.\n");
        return;
    }

    // Finding the size of the input image
    fseek(imgFile, 0L, SEEK_END);
    long int size = ftell(imgFile);
    fseek(imgFile, 0L, SEEK_SET);

    // Reading the input image into a buffer
    unsigned char *imgData = (unsigned char *) malloc(size * sizeof(unsigned char));
    fread(imgData, size, 1, imgFile);

    // Watermarking the image with the message
    int messageLen = strlen(message);
    int byteIndex = 0;
    for(int i=0; i<size; i++){
        if(byteIndex < messageLen){
            imgData[i] |= (1 << 0);
            imgData[i] &= ~(1 << 1);
            imgData[i] |= ((message[byteIndex] >> 6) << 2);
            byteIndex++;
            continue;
        }
        break;
    }
    
    // Writing the watermarked image to the output file
    fwrite(imgData, size, 1, outFile);

    // Closing the files
    fclose(imgFile);
    fclose(outFile);

    printf("Digital watermarking complete.\n");
}

int main(){
    char *imagePath = "input.png"; // Path to the input image file
    char *message = "This is a digital watermarking example."; // Message to be watermarked into image
    char *outPath = "output.png"; // Path to the output image file with watermark

    digitalWatermark(imagePath, message, outPath);

    return 0;
}