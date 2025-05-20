//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

//function for file input/output error
void error(char *msg){
    printf("Error: %s", msg);
    exit(1);
}

//function to flip image horizontally
void horizontal_flip(unsigned char *input_buffer, unsigned char *output_buffer, int width, int height, int bpp){
    int i, j, k, offset, temp;
    offset = 0;

    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            for(k=0; k<bpp; k++){
                temp = input_buffer[offset + j*bpp + k];
                output_buffer[offset + (width-1-j)*bpp + k] = temp;
            }
        }
        offset += width * bpp;
    }
}

//function to change brightness
void change_brightness(unsigned char *input_buffer, unsigned char *output_buffer, int width, int height, int bpp, int brightness){
    int i, j, k, offset, temp;
    offset = 0;

    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            for(k=0; k<bpp; k++){
                temp = input_buffer[offset + j*bpp + k] + brightness;
                if(temp < 0){
                    temp = 0;
                }
                else if(temp > 255){
                    temp = 255;
                }
                output_buffer[offset + j*bpp + k] = temp;
            }
        }
        offset += width * bpp;
    }
}

//function to change contrast
void change_contrast(unsigned char *input_buffer, unsigned char *output_buffer, int width, int height, int bpp, float contrast){
    int i, j, k, offset, temp;
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    offset = 0;

    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            for(k=0; k<bpp; k++){
                temp = (int) (factor * (input_buffer[offset + j*bpp + k] - 128) + 128);
                if(temp < 0){
                    temp = 0;
                }
                else if(temp > 255){
                    temp = 255;
                }
                output_buffer[offset + j*bpp + k] = temp;
            }
        }
        offset += width * bpp;
    }
}

int main(){
    FILE *input_file, *output_file;
    char input_filename[] = "input_image.raw";
    char output_filename[] = "output_image.raw";
    unsigned char *input_buffer, *output_buffer;
    int width = 512;
    int height = 512;
    int bpp = 1; //grayscale image
    int filesize = width * height * bpp;

    //open input file
    input_file = fopen(input_filename, "rb");
    if(input_file == NULL){
        error("Error opening input file");
    }

    //open output file
    output_file = fopen(output_filename, "wb");
    if(output_file == NULL){
        error("Error creating output file");
    }

    //allocate memory for input and output buffer
    input_buffer = (unsigned char*) malloc(filesize);
    output_buffer = (unsigned char*) malloc(filesize);

    //read input file into buffer
    fread(input_buffer, sizeof(unsigned char), filesize, input_file);

    //flip image horizontally
    horizontal_flip(input_buffer, output_buffer, width, height, bpp);

    //change brightness (increase by 50)
    change_brightness(output_buffer, output_buffer, width, height, bpp, 50);

    //change contrast (increase by 50%)
    change_contrast(output_buffer, output_buffer, width, height, bpp, 50.0);

    //write output buffer to output file
    fwrite(output_buffer, sizeof(unsigned char), filesize, output_file);

    //free memory allocation
    free(input_buffer);
    free(output_buffer);

    //close input and output file
    fclose(input_file);
    fclose(output_file);

    printf("Image processing complete");
    return 0;
}