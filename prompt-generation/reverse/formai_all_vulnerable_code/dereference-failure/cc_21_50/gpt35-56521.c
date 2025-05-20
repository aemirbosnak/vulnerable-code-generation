//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    FILE *pfile;
    char c;
    int rows=0, cols=0, i, j;
    char *data=NULL, **pixels=NULL, **ascii=NULL;

    // Open the image file in binary mode
    pfile=fopen(argv[1], "rb");

    // Check if the file was opened successfully
    if(pfile==NULL) {
        printf("Error opening file!");
        exit(1);
    }

    // Get the size of the image
    fseek(pfile, 0, SEEK_END);
    int size=ftell(pfile);
    fseek(pfile, 0, SEEK_SET);

    // Allocate memory for the image data
    data=(char*)malloc(size*sizeof(char));

    // Read the image data into the memory
    fread(data, sizeof(char), size, pfile);

    // Close the image file
    fclose(pfile);

    // Get the dimensions of the image
    cols=(int)data[18];
    rows=(int)data[22];

    // Allocate memory for the pixel values
    pixels=(char**)malloc(rows*sizeof(char*));
    for(i=0;i<rows;i++)
        pixels[i]=(char*)malloc(cols*sizeof(char));

    // Get the pixel values from the data array
    int k=54;
    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++) {
            pixels[i][j]=data[k];
            k+=3;
        }
    }

    // Allocate memory for the ASCII art
    ascii=(char**)malloc(rows*sizeof(char*));
    for(i=0;i<rows;i++)
        ascii[i]=(char*)malloc(cols*sizeof(char));

    // Convert the pixel values to ASCII characters
    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++) {
            if(pixels[i][j]>=0 && pixels[i][j]<=31)
                ascii[i][j]='@';
            else if(pixels[i][j]>=32 && pixels[i][j]<=63)
                ascii[i][j]='X';
            else if(pixels[i][j]>=64 && pixels[i][j]<=95)
                ascii[i][j]='W';
            else if(pixels[i][j]>=96 && pixels[i][j]<=127)
                ascii[i][j]='*';
            else if(pixels[i][j]>=128 && pixels[i][j]<=159)
                ascii[i][j]=';';
            else if(pixels[i][j]>=160 && pixels[i][j]<=191)
                ascii[i][j]=':';
            else if(pixels[i][j]>=192 && pixels[i][j]<=223)
                ascii[i][j]='.';
            else if(pixels[i][j]>=224 && pixels[i][j]<=255)
                ascii[i][j]=' ';
        }
    }

    // Print the ASCII art
    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++) {
            printf("%c", ascii[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    free(data);
    for(i=0;i<rows;i++) {
        free(pixels[i]);
        free(ascii[i]);
    }
    free(pixels);
    free(ascii);

    return 0;
}