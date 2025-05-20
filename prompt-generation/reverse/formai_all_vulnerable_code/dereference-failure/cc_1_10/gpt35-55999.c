//FormAI DATASET v1.0 Category: Image Steganography ; Style: high level of detail
/*
* Program Name: Image Steganography
* Author: [Your Name]
* Description: This program hides a message within an image using Least Significant Bit (LSB) substitution.
* The message will be hidden in the red component of each pixel in the image.
*/

#include<stdio.h>
#include<stdlib.h>

/*
* Function Name: check_size
* Description: checks if the size of message to be hidden can fit in the image
*/
int check_size(int img_size, int msg_size){
    if(img_size >= msg_size){
        return 1;
    }
    else{
        return 0;
    }
}

/*
* Function Name: hide_message
* Description: hides the message inside image
*/
void hide_message(char* img_file, char* msg_file){
    // Open image file
    FILE* img = fopen(img_file, "rb");
    fseek(img, 0, SEEK_END);
    int img_size = ftell(img);
    rewind(img);

    // Open message file
    FILE* msg = fopen(msg_file, "rb");
    fseek(msg, 0, SEEK_END);
    int msg_size = ftell(msg);
    rewind(msg);

    // check if message can be hidden in image
    if(!check_size(img_size, msg_size)){
        printf("\nError: Message size too large to fit in image!\n");
        exit(1);
    }

    // Create output file
    FILE* out = fopen("output.bmp", "wb");

    // copy header from input file to output file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, img);
    fwrite(header, sizeof(unsigned char), 54, out);

    // hide message in red component
    unsigned char data;
    unsigned char red;
    int count = 0;
    while(fread(&data, sizeof(unsigned char), 1, img) == 1){
        // handle the red component 
        if(count % 3 == 0){
            fseek(msg, count/3, SEEK_SET);
            fread(&red, sizeof(unsigned char), 1, msg);
            // hide the bit
            data = (data & 0xfe) | ((red >> 7) & 0x01);
        }
        fwrite(&data, sizeof(unsigned char), 1, out);
        count++;
    }

    fclose(img);
    fclose(msg);
    fclose(out);
    printf("\nMessage hidden successfully!\n");
}

/*
* Function Name: extract_message
* Description: extracts the message hidden in the image
*/
void extract_message(char* img_file, char* out_file){
    // Open image file
    FILE* img = fopen(img_file, "rb");
    fseek(img, 0, SEEK_END);
    int img_size = ftell(img);
    rewind(img);

    // Create output file
    FILE* out = fopen(out_file, "wb");

    // skip header
    fseek(img, 54, SEEK_SET);

    // extract message from red component
    unsigned char data;
    unsigned char red;
    int count = 0;
    while(fread(&data, sizeof(unsigned char), 1, img) == 1){
        // handle the red component
        if(count % 3 == 0){
            red = (red << 1) | (data & 0x01);
            if(count % 8 == 0){
                fwrite(&red, sizeof(unsigned char), 1, out);
            }
        }
        count++;
    }

    fclose(img);
    fclose(out);
    printf("\nMessage extracted successfully!\n");
}

int main(){
    char* img_file = "input.bmp";
    char* msg_file = "message.txt";
    char* out_file = "extracted_msg.txt";

    // hide message in image
    hide_message(img_file, msg_file);

    // extract message from image
    extract_message("output.bmp", out_file);

    return 0;
}