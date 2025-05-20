//FormAI DATASET v1.0 Category: Image Steganography ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

void encode(char* image_path, char* message_path, char* output_path) {
    FILE *image,*message,*output;
    int image_data, message_data, len, msg_index = 0, bit_index = 7;

    // Open files
    image = fopen(image_path,"rb");
    if(image == NULL) {
        printf("Error: Unable to open image file\n");
        return;
    }
    message = fopen(message_path,"r");
    if(message == NULL) {
        printf("Error: Unable to open message file\n");
        return;
    }
    output = fopen(output_path,"wb");
    if(output == NULL) {
        printf("Error: Unable to create output file\n");
        return;
    }

    // Read the image data and get the length of the message
    fseek(image,0,SEEK_END);
    len = ftell(image);
    fseek(image,0,SEEK_SET);

    // Write the length of the message as the first 4 bytes of the output file
    fwrite(&len,sizeof(len),1,output);

    // Encode the message into the image data
    while((image_data = fgetc(image)) != EOF) {
        if(msg_index < len) {
            message_data = fgetc(message);
            if(message_data == EOF) {
                printf("Error: Message file is too small\n");
                return;
            }
            for(int i=0;i<8;i++) {
                int bit = ((message_data >> i) & 1) << bit_index--;
                image_data = (image_data & ~(1<<bit_index)) | bit;
                if(bit_index < 0) {
                    bit_index = 7;
                    msg_index++;
                    if(msg_index == len) break;
                }
            }
        }
        fputc(image_data,output);
        if(msg_index == len) break;
    }

    fclose(image);
    fclose(message);
    fclose(output);
}

void decode(char* input_path, char* output_path) {
    FILE *input,*output;
    int len, index = 0, bit_index = 7, data = 0, bit;

    // Open files
    input = fopen(input_path,"rb");
    if(input == NULL) {
        printf("Error: Unable to open input file\n");
        return;
    }
    output = fopen(output_path,"w");
    if(output == NULL) {
        printf("Error: Unable to create output file\n");
        return;
    }

    // Read the length of the message from the first 4 bytes of the input file
    fread(&len, sizeof(len), 1, input);

    // Decode the message from the input data
    while((data = fgetc(input)) != EOF) {
        for(int i=0;i<8;i++) {
            bit = (data >> bit_index--) & 1;
            index = (index << 1) | bit;
            if(bit_index < 0) {
                bit_index = 7;
                if(index > 0 && index <= len) fputc(index,output);
                if(ftell(output) == len) break;
                index = 0;
            }
        }
        if(ftell(output) == len) break;
    }

    fclose(input);
    fclose(output);
}

int main() {
    int choice;
    char image_path[MAX], message_path[MAX], output_path[MAX];

    printf("Welcome to Image Steganography Program\n");
    printf("-------------------------------------\n");

    printf("Choose an option:\n");
    printf("1. Encode message\n2. Decode message\n");
    scanf("%d",&choice);

    switch(choice) {
        case 1:
            printf("\nEnter the path to the image file: ");
            scanf("%s",image_path);
            printf("Enter the path to the message file: ");
            scanf("%s",message_path);
            printf("Enter the path to the output file: ");
            scanf("%s",output_path);
            encode(image_path,message_path,output_path);
            printf("\nMessage encoded successfully!\n");
            break;
        case 2:
            printf("\nEnter the path to the input file: ");
            scanf("%s",image_path);
            printf("Enter the path to the output file: ");
            scanf("%s",output_path);
            decode(image_path,output_path);
            printf("\nMessage decoded successfully!\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }

    return 0;
}