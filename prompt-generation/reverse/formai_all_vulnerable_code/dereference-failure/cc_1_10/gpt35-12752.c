//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

typedef enum {
    FLIP_HORIZONTAL,
    FLIP_VERTICAL
} FlipDirection;

void flipImage(Image *img, FlipDirection direction){
    int x, y;
    unsigned char temp;

    for(y = 0; y < img->height; y++){
        for(x = 0; x < img->width / 2; x++){
            int other_x = img->width - x - 1;
            int idx_a = y * img->width + x;
            int idx_b = y * img->width + other_x;

            if(direction == FLIP_HORIZONTAL){
                idx_a = y * img->width + other_x;
                idx_b = y * img->width + x;
            }

            //swap
            temp = img->data[idx_a];
            img->data[idx_a] = img->data[idx_b];
            img->data[idx_b] = temp;
        }
    }
}

void changeBrightness(Image *img, int value){
    int i;
    int new_value;
    for(i = 0; i < img->width * img->height; i++){
        new_value = img->data[i] + value;
        if(new_value < 0){
            new_value = 0;
        }else if(new_value > 255){
            new_value = 255;
        }
        img->data[i] = new_value;
    }
}

void changeContrast(Image *img, float value){
    int i;
    float avg_value = 0;
    for(i = 0; i < img->width * img->height; i++){
        avg_value += img->data[i];
    }
    avg_value /= img->width * img->height;

    for(i = 0; i < img->width * img->height; i++){
        img->data[i] = (img->data[i] - avg_value) * value + avg_value;
    }
}

int main(){
    Image img;
    int i, j, value;
    FILE *fp = fopen("sample.pgm", "rb");

    if(fp == NULL){
        printf("Error: file not found!\n");
        return -1;
    }

    char magic_number[3];
    fscanf(fp, "%s", magic_number);

    if(magic_number[0] != 'P' || magic_number[1] != '5'){
        printf("Error: file format not recognized!\n");
        return -1;
    }

    fscanf(fp, "%d %d", &img.width, &img.height);
    img.data = (unsigned char*) malloc(img.width * img.height * sizeof(unsigned char));

    for(i = 0; i < img.height; i++){
        for(j = 0; j < img.width; j++){
            fread(&img.data[i*img.width+j], sizeof(unsigned char), 1, fp); 
        }
    }

    fclose(fp);

    //flip horizontally
    flipImage(&img, FLIP_HORIZONTAL);

    //change brightness
    printf("Enter brightness value: ");
    scanf("%d", &value);
    changeBrightness(&img, value);

    //change contrast
    printf("Enter contrast value: ");
    scanf("%f", &value);
    changeContrast(&img, value);

    //flip vertically
    flipImage(&img, FLIP_VERTICAL);

    //write output
    fp = fopen("output.pgm", "wb");

    fprintf(fp, "P5\n%d %d\n255\n", img.width, img.height);
    for(i = 0; i < img.height; i++){
        fwrite(&img.data[i*img.width], sizeof(unsigned char), img.width, fp);
    }

    fclose(fp);

    free(img.data);

    printf("Processing complete. Check output.pgm.\n");

    return 0;
}