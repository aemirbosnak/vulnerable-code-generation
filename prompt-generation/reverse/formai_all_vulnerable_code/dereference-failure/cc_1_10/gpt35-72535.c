//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Donald Knuth
#include<stdio.h>
#include<string.h>

//Function to convert the image to ASCII art
void convertToAscii(char* fileName) {
    FILE* imgFile = fopen(fileName, "rb"); //Opening the file in binary mode
    if(imgFile != NULL) {
        fseek(imgFile, 0, SEEK_END);
        long fileSize = ftell(imgFile);
        fseek(imgFile, 0, SEEK_SET);
        unsigned char* buffer = (unsigned char*)malloc(sizeof(unsigned char)*fileSize);
        fread(buffer, fileSize, 1, imgFile); //Reading the file into the buffer
        fclose(imgFile);

        int width = 100; //Setting width of the output ASCII art
        int height = fileSize/(3*width); //Calculating height of the output ASCII art
        unsigned char* outputArray = (unsigned char*)malloc(sizeof(unsigned char)*width*height);
        int i = 0, j = 0, k = 0;
        for(i=0; i<height; i++) {
            for(j=0; j<width; j++) {
                k = (i*width*3) + (j*3); //Calculating the index in the buffer for each pixel
                unsigned char r = buffer[k]; //Getting the red value of the pixel
                unsigned char g = buffer[k+1]; //Getting the green value of the pixel
                unsigned char b = buffer[k+2]; //Getting the blue value of the pixel
                if((r+g+b)/3 < 50) {
                    outputArray[i*width+j] = '@'; //Assigning the ASCII character for dark pixel
                }
                else if((r+g+b)/3 < 100) {
                    outputArray[i*width+j] = '%'; //Assigning the ASCII character for medium-dark pixel
                }
                else if((r+g+b)/3 < 150) {
                    outputArray[i*width+j] = '#'; //Assigning the ASCII character for medium-bright pixel
                }
                else {
                    outputArray[i*width+j] = '.'; //Assigning the ASCII character for bright pixel
                }
            }
        }

        //Printing the output ASCII art to the console
        for(i=0; i<height; i++) {
            for(j=0; j<width; j++) {
                printf("%c", outputArray[i*width+j]);
            }
            printf("\n");
        }

        free(buffer);
        free(outputArray);
    }
}

int main() {
    char fileName[100];
    printf("Enter the name of the image file: ");
    scanf("%s", fileName);
    convertToAscii(fileName);
    return 0;
}