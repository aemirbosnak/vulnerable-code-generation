//FormAI DATASET v1.0 Category: Image Steganography ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* int2bin(int a);
int bin2dec(char* arr);
void encode(char* img_path, char* txt_path, char* out_path);
void decode(char* img_path, char* out_path);

int main() {
    int choice;
    char img_path[50], txt_path[50], out_path[50];
    
    do {
        printf("===== MENU =====\n");
        printf("[1] Encode\n");
        printf("[2] Decode\n");
        printf("[3] Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter image file name: ");
                scanf("%s", img_path);
                printf("Enter text file name: ");
                scanf("%s", txt_path);
                printf("Enter output file name: ");
                scanf("%s", out_path);

                encode(img_path, txt_path, out_path);
                printf("Encoding done!\n");
                break;
            case 2:
                printf("Enter image file name: ");
                scanf("%s", img_path);
                printf("Enter output file name: ");
                scanf("%s", out_path);

                decode(img_path, out_path);
                printf("Decoding done!\n");
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(1);

    return 0;
}

char* int2bin(int a) {
    char* arr = malloc(sizeof(char) * 9);
    int i;

    for(i = 0; i < 8; ++i) {
        arr[i] = (a & (1 << i)) ? '1' : '0';
    }
    arr[8] = '\0';

    return arr;
}

int bin2dec(char* arr) {
    int num = 0, i;

    for(i = 0; i < 8; ++i) {
        num += (arr[i] - '0') * (1 << i);
    }

    return num; 
}

void encode(char* img_path, char* txt_path, char* out_path) {
    FILE *img, *txt, *out;
    int i, j, k, len, pixel, bit, r, g, b;
    char c, *cbin;

    img = fopen(img_path, "rb");
    txt = fopen(txt_path, "r");
    out = fopen(out_path, "wb");

    if(img == NULL || txt == NULL || out == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fseek(txt, 0, SEEK_END);
    len = ftell(txt);
    fseek(txt, 0, SEEK_SET);

    fwrite(&len, sizeof(int), 1, out);

    for(i = 0; i < len; ++i) {
        fread(&pixel, sizeof(int), 1, img);
        c = fgetc(txt);

        cbin = int2bin(c);

        for(j = 0; j < 8; ++j) {

            bit = cbin[j] - '0';

            r = (pixel >> 16) & 0xff;
            g = (pixel >> 8) & 0xff;
            b = pixel & 0xff;

            if(j % 3 == 0) {
                r = (r & 0xfe) | bit;
            }
            else if(j % 3 == 1) {
                g = (g & 0xfe) | bit;
            }
            else {
                b = (b & 0xfe) | bit;
            }

            pixel = (r << 16) | (g << 8) | b;
        }
        
        fwrite(&pixel, sizeof(int), 1, out);
        free(cbin);

    }
    while(fread(&pixel, sizeof(int), 1, img)) {
        fwrite(&pixel, sizeof(int), 1, out);
    }

    fclose(img);
    fclose(txt);
    fclose(out);
}

void decode(char* img_path, char* out_path) {
    FILE *img, *out;
    int i, j, k, len, pixel, bit, r, g, b;
    char c = 0;
    char *cbin, *msgbin;

    img = fopen(img_path, "rb");
    out = fopen(out_path, "w");

    if(img == NULL || out == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }   

    fread(&len, sizeof(int), 1, img);

    for(i = 0; i < len; ++i) {
        fread(&pixel, sizeof(int), 1, img);

        cbin = malloc(sizeof(char) * 25);

        for(j = 0; j < 8; ++j) {
            r = (pixel >> 16) & 0xff;
            g = (pixel >> 8) & 0xff;
            b = pixel & 0xff;

            if(j % 3 == 0) {
                bit = r & 0x01;
            }
            else if(j % 3 == 1) {
                bit = g & 0x01;
            }
            else {
                bit = b & 0x01;
            }

            cbin[j] = bit + '0';
        }
        cbin[8] = '\0';

        c = bin2dec(cbin);

        fwrite(&c, sizeof(char), 1, out);

        free(cbin);
    }

    fclose(img);
    fclose(out);
}