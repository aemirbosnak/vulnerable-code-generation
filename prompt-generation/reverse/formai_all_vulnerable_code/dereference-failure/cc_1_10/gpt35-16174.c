//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 8192
#define MAX_BRIGHTNESS 255
#define MAX_CONTRAST 100

unsigned char Image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
unsigned char NewImage[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];

int Width, Height;
int Brightness = MAX_BRIGHTNESS / 2;
int Contrast = MAX_CONTRAST / 2;

void ReadImage(char* FileName){
    FILE* fp;
    int i, j, k, w, h, d;

    fp = fopen(FileName, "rb");
    if (!fp){
        printf("Error: Unable to open image file %s\n", FileName);
        exit(EXIT_FAILURE);
    }

    if (fscanf(fp, "P%d\n%d %d\n%d\n", &d, &w, &h, &k) != 4){
        printf("Error: Invalid image format\n");
        exit(EXIT_FAILURE);
    }

    if ((w > MAX_IMAGE_SIZE) || (h > MAX_IMAGE_SIZE)){
        printf("Error: Image size exceeds maximum\n");
        exit(EXIT_FAILURE);
    }

    Width = w;
    Height = h;

    switch (d){
        case 5:
            for (j = 0; j < Height; j++){
                for (i = 0; i < Width; i++){
                    if (fread(&Image[i][j], sizeof(unsigned char), 1, fp) != 1){
                        printf("Error: Unable to read from image file\n");
                        exit(EXIT_FAILURE);
                    }
                }
            }
            break;

        case 6:
            for (j = 0; j < Height; j++){
                for (i = 0; i < Width; i++){
                    for (k = 0; k < 3; k++){
                        if (fread(&Image[i][j], sizeof(unsigned char), 1, fp) != 1){
                            printf("Error: Unable to read from image file\n");
                            exit(EXIT_FAILURE);
                        }
                    }
                }
            }
            break;

        default:
            printf("Error: Invalid image format\n");
            exit(EXIT_FAILURE);
    }

    fclose(fp);
}

void WriteImage(char* FileName){
    FILE* fp;
    int i, j;

    fp = fopen(FileName, "wb");
    if (!fp){
        printf("Error: Unable to write to image file %s\n", FileName);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "P5\n%d %d\n%d\n", Width, Height, MAX_BRIGHTNESS);

    for (j = 0; j < Height; j++){
        for (i = 0; i < Width; i++){
            if (fwrite(&NewImage[i][j], sizeof(unsigned char), 1, fp) != 1){
                printf("Error: Unable to write to image file\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(fp);
}

void FlipImage(){
    int i, j;

    for (j = 0; j < Height; j++){
        for (i = 0; i < Width; i++){
            NewImage[i][j] = Image[(Width-1)-i][j];
        }
    }
}

void AdjustBrightness(){
    int i, j;

    for (j = 0; j < Height; j++){
        for (i = 0; i < Width; i++){
            int b = (int)Image[i][j] + Brightness;

            if (b < 0){
                NewImage[i][j] = 0;
            } else if (b > MAX_BRIGHTNESS){
                NewImage[i][j] = MAX_BRIGHTNESS;
            } else {
                NewImage[i][j] = b;
            }
        }
    }
}

void AdjustContrast(){
    int i, j;
    double factor = (259 * (Contrast + 255)) / (255 * (259 - Contrast));

    for (j = 0; j < Height; j++){
        for (i = 0; i < Width; i++){
            int p = Image[i][j];

            int q = (int)(factor * (p - 128) + 128);

            if (q < 0){
                NewImage[i][j] = 0;
            } else if (q > MAX_BRIGHTNESS){
                NewImage[i][j] = MAX_BRIGHTNESS;
            } else {
                NewImage[i][j] = q;
            }
        }
    }
}

int main(int argc, char* argv[]){
    if (argc != 5){
        printf("Usage: %s input_file output_file task value\n", argv[0]);
        printf("task can be 'flip', 'brightness' or 'contrast'\n");
        printf("value should be between 0 and 100\n");
        exit(EXIT_FAILURE);
    }

    ReadImage(argv[1]);

    char* task = argv[3];
    int value = atoi(argv[4]);

    if (strcmp(task, "flip") == 0){
        FlipImage();
    } else if (strcmp(task, "brightness") == 0){
        Brightness = (int)((double)value / 100.0 * MAX_BRIGHTNESS);
        AdjustBrightness();
    } else if (strcmp(task, "contrast") == 0){
        Contrast = value;
        AdjustContrast();
    } else {
        printf("Error: Invalid task\n");
        exit(EXIT_FAILURE);
    }

    WriteImage(argv[2]);

    return 0;
}