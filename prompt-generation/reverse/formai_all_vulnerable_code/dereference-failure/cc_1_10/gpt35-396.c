//FormAI DATASET v1.0 Category: Image Steganography ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

//function for converting a decimal number to binary
void decimalToBinary(int n,int binary[]){
    int i = 0;
    while(n > 0){
        binary[i] = n % 2;
        n /= 2;
        i++;
    }
}

//function for converting a binary number to decimal
int binaryToDecimal(int binary[]){
    int decimal = 0;
    int base = 1;
    for(int i=0;i<8;i++){
        decimal += binary[i] * base;
        base *= 2;
    }
    return decimal;
}

//function for steganography
void imageStegano(char source_image[],char secret_message[]){
    FILE *source_fp, *stegano_fp;
    source_fp = fopen(source_image, "rb");
    stegano_fp = fopen("stegano_image.bmp", "wb");

    if(source_fp == NULL){
        printf("Error opening source image file\n");
        exit(0);
    }
    if(stegano_fp == NULL){
        printf("Error opening stegano image file\n");
        exit(0);
    }

    //skip header for source image file
    int byte;
    for(int i=0;i<54;i++){
        byte = getc(source_fp);
        putc(byte,stegano_fp);
    }

    //read secret message from file
    FILE *secret_fp;
    secret_fp = fopen(secret_message,"r");
    if(secret_fp == NULL){
        printf("Error opening secret message file\n");
        exit(0);
    }
    char secret_message_text[1000];
    fgets(secret_message_text,1000,secret_fp);

    int len_secret_text = strlen(secret_message_text);
    printf("Length of secret message: %d\n",len_secret_text);

    //convert each character of secret message to its binary equivalent and store in an array
    int secret_binary[len_secret_text*8];
    for(int i=0;i<len_secret_text;i++){
        decimalToBinary(secret_message_text[i],&(secret_binary[i*8]));
    }

    //embed the binary bits into the blue component of each pixel
    int pixel[3];
    int i = 0;
    while((byte = getc(source_fp)) != EOF){
        pixel[i%3] = byte;
        if(i%3 == 2){
            int binary[8] = {0,0,0,0,0,0,0,0};
            decimalToBinary(pixel[2],binary);
            for(int j=0;j<8;j++){
                binary[7-j] = secret_binary[i-2+j];
            }
            pixel[2] = binaryToDecimal(binary);
            putc(pixel[0],stegano_fp);
            putc(pixel[1],stegano_fp);
            putc(pixel[2],stegano_fp);
        }
        i++;
    }
    printf("Steganography completed successfully!!!\n");
}

int main(){
    imageStegano("source.bmp","secret.txt");
    return 0;
}