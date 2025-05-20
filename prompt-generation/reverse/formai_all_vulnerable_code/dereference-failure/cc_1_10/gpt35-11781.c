//FormAI DATASET v1.0 Category: Image compression ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_PIXEL 3

typedef struct Image{
    unsigned char *data;
    int width;
    int height;
} Image;

void freeImage(Image *img){
    if(img){
        if(img->data){
            free(img->data);
        }
        free(img);
    }
}

Image *readBMP(char *filename){
    FILE *file = fopen(filename, "rb");
    if(!file){
        printf("Error: failed to open %s\n", filename);
        return NULL;
    }
    
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, file);
    
    // extract image dimensions from BMP header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];
    
    // extract image size and offset from BMP header
    int size = *(int*)&info[34];
    int offset = *(int*)&info[10];
    
    if(offset == 0){
        offset = 54;
    }
    
    // calculate padding
    int padding = 0;
    while((width * BYTES_PER_PIXEL + padding) % 4 != 0){
        padding++;
    }
    
    // allocate memory for image data
    unsigned char *data = (unsigned char*)malloc((size - offset) * sizeof(unsigned char));
    if(!data){
        printf("Error: failed to allocate memory for image data\n");
        fclose(file);
        return NULL;
    }
    
    // read image data from file
    fseek(file, offset, SEEK_SET);
    fread(data, sizeof(unsigned char), size - offset, file);
    
    // reverse row order for BMP files
    for(int i = 0; i < height / 2; i++){
        for(int j = 0; j < width * BYTES_PER_PIXEL; j++){
            int k = (height - i - 1) * width * BYTES_PER_PIXEL + j;
            unsigned char temp = data[i * width * BYTES_PER_PIXEL + j];
            data[i * width * BYTES_PER_PIXEL + j] = data[k];
            data[k] = temp;
        }
    }
    
    fclose(file);
    
    // create image struct
    Image *img = (Image*)malloc(sizeof(Image));
    if(!img){
        printf("Error: failed to allocate memory for Image struct\n");
        free(data);
        return NULL;
    }
    img->data = data;
    img->width = width;
    img->height = height;
    
    return img;
}

int writeBMP(char *filename, Image *img){
    if(!img){
        printf("Error: no image input provided\n");
        return -1;
    }
    
    FILE *file = fopen(filename, "wb");
    if(!file){
        printf("Error: failed to open %s for writing\n", filename);
        return -1;
    }
    
    // calculate padding
    int padding = 0;
    while((img->width * BYTES_PER_PIXEL + padding) % 4 != 0){
        padding++;
    }
    
    // create BMP header
    unsigned char header[54];
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = 54 + (img->width * BYTES_PER_PIXEL + padding) * img->height;
    *(int*)&header[10] = 54;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = img->width;
    *(int*)&header[22] = img->height;
    header[26] = 1;
    header[28] = BYTES_PER_PIXEL * 8;
    *(int*)&header[34] = (img->width * BYTES_PER_PIXEL + padding) * img->height;
    
    // write header to file
    fwrite(header, sizeof(unsigned char), 54, file);
    
    // write image data to file
    for(int i = 0; i < img->height; i++){
        for(int j = 0; j < img->width * BYTES_PER_PIXEL; j++){
            fwrite(&img->data[i * img->width * BYTES_PER_PIXEL + j], sizeof(unsigned char), 1, file);
        }
        for(int k = 0; k < padding; k++){
            fwrite("\x00", sizeof(unsigned char), 1, file);
        }
    }
    
    fclose(file);
    
    return 0;
}

Image *compressImage(Image *img, int factor){
    if(!img || factor <= 0){
        printf("Error: invalid input provided\n");
        return NULL;
    }
    
    // allocate memory for compressed image data
    int newWidth = img->width / factor;
    int newHeight = img->height / factor;
    unsigned char *newData = (unsigned char*)malloc(newWidth * newHeight * BYTES_PER_PIXEL * sizeof(unsigned char));
    if(!newData){
        printf("Error: failed to allocate memory for compressed image data\n");
        return NULL;
    }
    
    // compress image data by averaging pixels
    for(int i = 0; i < newHeight; i++){
        for(int j = 0; j < newWidth; j++){
            int sumR = 0;
            int sumG = 0;
            int sumB = 0;
            for(int x = 0; x < factor; x++){
                for(int y = 0; y < factor; y++){
                    int indexR = (i * factor + x) * img->width * BYTES_PER_PIXEL + (j * factor + y) * BYTES_PER_PIXEL;
                    int indexG = indexR + 1;
                    int indexB = indexG + 1;
                    sumR += img->data[indexR];
                    sumG += img->data[indexG];
                    sumB += img->data[indexB];
                }
            }
            int indexR = i * newWidth * BYTES_PER_PIXEL + j * BYTES_PER_PIXEL;
            int indexG = indexR + 1;
            int indexB = indexG + 1;
            newData[indexR] = sumR / (factor * factor);
            newData[indexG] = sumG / (factor * factor);
            newData[indexB] = sumB / (factor * factor);
        }
    }
    
    // create new image struct
    Image *newImg = (Image*)malloc(sizeof(Image));
    if(!newImg){
        printf("Error: failed to allocate memory for new Image struct\n");
        free(newData);
        return NULL;
    }
    newImg->data = newData;
    newImg->width = newWidth;
    newImg->height = newHeight;
    
    return newImg;
}

int main(){
    // read input image
    Image *img = readBMP("input.bmp");
    if(!img){
        return -1;
    }
    
    // compress input image by a factor of 4
    Image *compressedImg = compressImage(img, 4);
    if(!compressedImg){
        freeImage(img);
        return -1;
    }
    
    // write compressed image to file
    int result = writeBMP("output.bmp", compressedImg);
    
    freeImage(img);
    freeImage(compressedImg);
    
    return result;
}