//FormAI DATASET v1.0 Category: Image Steganography ; Style: Cryptic
#include<stdio.h> 
#include<stdlib.h>
#include<math.h>

//define our secret message here
const char* secretMsg = "CRYPTIC"; 

//function to get binary representation of a decimal number
char* decToBin(int num){
    int i;
    char *bin = calloc(sizeof(char),8);
    for(i=7;i>=0;i--){
        if(num >= pow(2,i)){
            bin[i] = '1';
            num -= pow(2,i);
        }
        else{
            bin[i] = '0';
        }
    }
    return bin;
}

//main function
int main(){
    //open the image file in binary read mode
    FILE *fp = fopen("image.bmp","rb");
    if(fp == NULL){
        printf("Image file not found! Exiting.\n");
        exit(1);
    }

    //get size of image file
    fseek(fp,0,SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    //read contents of image file into buffer
    unsigned char *buffer = calloc(sizeof(unsigned char),size);
    fread(buffer,sizeof(unsigned char),size,fp);

    //get position of the start of the pixel data
    int pixelPos = *(int*)&buffer[10];

    //get width and height of image
    int width = *(int*)&buffer[18];
    int height = *(int*)&buffer[22];

    //hide our secret message in the least significant bit of the least significant byte of each pixel
    int i, j, k=0;
    char *bin;
    for(i=pixelPos;i<size;i+=3){
        if(k==7){
            break; //stop once the whole secret message has been hidden
        }
        for(j=0;j<8;j++){
            if(k==7){
                break; //stop once the whole secret message has been hidden
            }

            //get binary representation of the pixel value
            bin = decToBin(buffer[i+j]);

            //replace the least significant bit with the corresponding bit from our secret message
            bin[7] = secretMsg[k] & 1 ? '1' : '0';
            k++;

            //convert binary representation back to decimal and write to buffer
            buffer[i+j] = (unsigned char)strtol(bin,NULL,2);
            
            free(bin);
        }
    }

    //write the modified image data to a new file
    FILE *out = fopen("hidden.bmp","wb");
    fwrite(buffer,sizeof(unsigned char),size,out);

    //cleanup
    fclose(fp);
    fclose(out);
    free(buffer);

    printf("Secret message hidden in image!\n");

    return 0;
}