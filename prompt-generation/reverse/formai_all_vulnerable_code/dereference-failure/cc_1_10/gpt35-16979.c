//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void embed_watermark(int *, int *, char *);
void extract_watermark(int *, int *, char *);
void print_image(int *);
void print_watermark(char *);

int main(){
    int image[25] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125};
    int watermark[4] = { 1, 2, 3, 4};
    char message[] = "Hello, World!";
    
    printf("Original Image:\n");
    print_image(image);
    
    embed_watermark(image, watermark, message);
    printf("\nImage with Embedded Watermark:\n");
    print_image(image);
    
    char extracted_message[15];
    extract_watermark(image, watermark, extracted_message);
    printf("\nWatermark Extracted from Image:\n");
    print_watermark(extracted_message);

    return 0;
}

void embed_watermark(int *image, int *watermark, char *message){
    int i, j=0, k, l, m;
    for(i=0; i<4; i++){
        m = watermark[i];
        for(j=0; j<25; j++){
            if(*(image+j) > (m*10-1) && *(image+j) < (m*10+9)){
                k = *(image+j);
                l = k%10;
                k = k/10;
                k = k*10 + m;
                k = k*10 + l;
                *(image+j) = k;
                if(strlen(message) <= i*3)
                    break;
                *(image+j) += message[i*3]*1000;
                if(strlen(message) <= i*3+1)
                    break;
                *(image+j) += message[i*3+1]*1000000;
                if(strlen(message) <= i*3+2)
                    break;
                *(image+j) += message[i*3+2]*1000000000;
            }
        }
    }
}

void extract_watermark(int *image, int *watermark, char *extracted_message){
    int i, j=0, k, l;
    for(i=0; i<4; i++){
        k=0;
        l=0;
        j=0;
        while(j<25){
            if(*(image+j)/10%10==watermark[i]){
                k = *(image+j)%10;
                l = *(image+j)/1000;
                extracted_message[i*3] = k;
                extracted_message[i*3+1] = l;
                if(strlen(extracted_message) <= i*3+2)
                    break;
                extracted_message[i*3+2] = *(image+j)/1000000;
            }
            j++;
        }
    }
}

void print_image(int *image){
    int i;
    for(i=0; i<25; i++){
        printf("%d ", *(image+i));
        if(i%5==4)
            printf("\n");
    }
}

void print_watermark(char *message){
    printf("%s\n", message);
}