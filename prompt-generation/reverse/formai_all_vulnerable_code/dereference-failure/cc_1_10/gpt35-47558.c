//FormAI DATASET v1.0 Category: Image Steganography ; Style: complex
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define FILE_SIZE 100000
#define WIDTH 32
#define HEIGHT 32

void hide(char* data, char* message){
    int len = strlen(message);
    int i, j, k, ch, bit;

    for(i = 0, j = 0, k = 0; i < len; i++, k++){
        if(k%8 == 0){
            ch = message[j++];
            k = 0;
        }
        bit = (ch >> k) & 1;
        data[i] = (data[i] & 0xFE) | bit; 
        //setting the last bit to 0 or 1 based on the message bit
    }
    data[i] = '\0';
}

void unhide(char* data, char* message){
    int i, j, k, bit = 0, len = 0;

    for(i = 0; data[i] != '\0'; i++){
        bit = data[i] & 1;
        len++;
        if(len%8 == 0){
            message[j++] = (char)k;
            k = 0;
        }
        k = (k << 1) | bit; //appending the message bit
    }
    message[j] = '\0';
}

void encode(char* source, char* dest, char* message){
    FILE* fp1;
    FILE* fp2;
    char data[FILE_SIZE];
    int i, j;

    fp1 = fopen(source, "rb");
    if(fp1 == NULL){
        printf("Error in opening file %s", source);
        exit(0);
    }

    fp2 = fopen(dest, "wb");
    if(fp2 == NULL){
        printf("Error in opening file %s", dest);
        exit(0);
    }

    fseek(fp1, 0, SEEK_END);
    long int size = ftell(fp1);
    fseek(fp1, 0, SEEK_SET);

    int height = HEIGHT, width = WIDTH, n = height * width;
    int row = size/(3*width);
    if(row > height){
        printf("Image size is larger than capacity of %dx%d image\n", width, height);
        exit(0);
    }

    fread(data, sizeof(char), size, fp1);
    fclose(fp1);

    hide(data, message);

    i = 0; j = 0;
    while(i < size){
        fwrite(&data[i], sizeof(char), 3, fp2);
        if(j == n-1){
            for(int k = 0; k < width; k++){
                fwrite(data, sizeof(char), 3, fp2);
            }
            j = -1;
        }
        i += 3;
        j++;
    }

    if(j > 0 && j < n){
        for(int k = 0; k < (n-j); k++){
            fwrite(data, sizeof(char), 3, fp2);
        }
    }

    fclose(fp2);
}

void decode(char* source, char* message){
    FILE* fp;
    char data[FILE_SIZE];

    fp = fopen(source, "rb");
    if(fp == NULL){
        printf("Error in opening file %s", source);
        exit(0);
    }

    fseek(fp, 0, SEEK_END);
    long int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    int height = HEIGHT, width = WIDTH, n = height * width;
    int row = size/(3*width);
    if(row > height){
        printf("Image size is larger than capacity of %dx%d image\n", width, height);
        exit(0);
    }

    fread(data, sizeof(char), size, fp);
    fclose(fp);

    unhide(data, message);
}

int main(){
    char source[100], dest[100], message[1000], msg[1000], ch;
    int choice;

    printf("\n**********************************************************");
    printf("\n                  WELCOME TO STEGANOGRAPHY                 ");
    printf("\n**********************************************************");
    printf("\n\nWhat do you want to do?\n1. Encode a message into an image\n2. Decode a message from an image\nChoice: ");
    scanf("%d", &choice);
    if(choice == 1){
        printf("\nEnter the source image file name (with extension): ");
        scanf("%s", source);
        printf("\nEnter the destination image file name (with extension): ");
        scanf("%s", dest);
        printf("\nEnter the message to hide: ");
        scanf(" ");
        fgets(message, sizeof(message), stdin);
        message[strlen(message)-1] = '\0'; //removing the newline character at the end of the message
        encode(source, dest, message);
        printf("\nMessage successfully hidden in the image!\n");
    }
    else if(choice == 2){
        printf("\nEnter the source image file name (with extension): ");
        scanf("%s", source);
        printf("\nDecoding message from the image...\n");
        decode(source, msg);
        printf("\nMessage extracted from the image: %s\n", msg);
    }
    else{
        printf("\nInvalid choice!\n");
    }

    return 0;
}