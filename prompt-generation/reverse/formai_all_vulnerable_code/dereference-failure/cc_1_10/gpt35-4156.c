//FormAI DATASET v1.0 Category: Image Steganography ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void encode(char image[], char message[]){
    FILE *fptr1, *fptr2;
    unsigned char byte, bit;
    int i, j=0;

    fptr1 = fopen(image, "rb");
    if(fptr1==NULL){
        printf("Error opening image file.");
        exit(1);
    }

    fptr2 = fopen("encoded_image.bmp", "wb");
    if(fptr2==NULL){
        printf("Error generating encoded image file.");
        exit(1);
    }


    fseek(fptr1, 0, SEEK_SET);
    while(!feof(fptr1)){
        byte = getc(fptr1);
        for(i=0; i<8; i++){
            if(j<strlen(message)){
                bit = (message[j] >> i) & 1;
            }
            else{
                bit = 0;
            }
            byte = (byte & 0xFE) | bit;
            fwrite(&byte,1,1,fptr2);
            j++;
        }
    }
    fclose(fptr1);
    fclose(fptr2);

    printf("Message encoded successfully!\n");
}

void decode(char image[], int message_length){
    FILE *fptr;
    unsigned char byte;
    int i, j=0;

    fptr = fopen(image, "rb");
    if(fptr==NULL){
        printf("Error opening image file.");
        exit(1);
    }

    fseek(fptr, 0, SEEK_SET);
    for(i=0; i<message_length; i++){
        byte = 0;
        for(j=0; j<8; j++){
            byte = byte | ((getc(fptr) & 1) << j);
        }
        putchar(byte);
    }
    fclose(fptr);

    printf("Decoded successfully!\n");
}

int main(){
    char image[50];
    char message[150];
    int option, message_length;

    printf("Welcome to Retro Style Image Steganography Program\n");
    while(1){
        printf("1. Encode message in an image\n");
        printf("2. Decode message from an image\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter name of image file: ");
                scanf("%s", image);
                printf("Enter message to be encoded (max 150 characters): ");
                getchar(); //clean input buffer
                fgets(message, 150, stdin);
                message_length = strlen(message);
                encode(image, message);
                break;
            case 2:
                printf("Enter name of image file: ");
                scanf("%s", image);
                printf("Enter length of message to be decoded: ");
                scanf("%d", &message_length);
                decode(image, message_length);
                break;
            case 3:
                printf("Exiting Retro Style Image Steganography Program. Goodbye!");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}