//FormAI DATASET v1.0 Category: Image Steganography ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

//function to perform steganography
void steganography(char *message, char *image, char *output){
    FILE *msg, *img, *out;
    msg = fopen(message, "r");
    img = fopen(image, "rb");
    out = fopen(output, "wb");

    if(msg == NULL || img == NULL || out == NULL){
        printf("Error opening file!");
        exit(1);
    }

    //copy header of image file
    unsigned char header[54];
    for(int i=0;i<54;i++){
        header[i] = fgetc(img);
    }
    fwrite(header, sizeof(unsigned char), 54, out);

    //copy message byte by byte into the least significant bit of image pixel
    unsigned char pixel_val;
    int bit_pos = 0;
    char msg_char;
    while((msg_char = fgetc(msg)) != EOF){

        fseek(img, bit_pos*3+54, SEEK_SET);

        for(int i=0;i<8;i++){
            if((msg_char>>i)&1){
                pixel_val = fgetc(img)|1;
            }
            else{
                pixel_val = fgetc(img)&0xFE;
            }
            fseek(img, -1, SEEK_CUR);
            fputc(pixel_val, out);
            bit_pos++;
        }
    }

    //copy rest of image file
    fseek(img, bit_pos*3+54, SEEK_SET);
    while((pixel_val = fgetc(img)) != EOF){
        fputc(pixel_val, out);
    }

    printf("Message successfully hidden!\n");

    fclose(msg);
    fclose(img);
    fclose(out);
}

int main(){
    char message_file[] = "secret_message.txt"; //message file containing the secret message
    char image_file[] = "input_image.bmp"; //image file in which the message will be hidden
    char output_file[] = "output_image.bmp"; //output file with the hidden message

    steganography(message_file, image_file, output_file);

    return 0;
}