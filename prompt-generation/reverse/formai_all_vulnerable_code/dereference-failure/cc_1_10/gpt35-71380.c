//FormAI DATASET v1.0 Category: Image Steganography ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void encode(char *hidden_msg, char *image_path, char *output_path)
{
    FILE *image, *output;
    unsigned char header[54], data, bit;
    unsigned int width, height, bytes_per_pixel, padding, i, j, k;
    int hidden_msg_size, bit_count = 0;
    char ch;

    image = fopen(image_path, "rb");
    output = fopen(output_path, "wb");

    if(image == NULL || output == NULL) {
        printf("Cannot open file.\n");
        exit(0);
    }

    // read BMP image header
    for(i=0; i<54; i++) {
        header[i] = fgetc(image);
        fputc(header[i], output);
    }

    // dimensions of image
    width = *(int*)&header[18];
    height = *(int*)&header[22];
    bytes_per_pixel = *(int*)&header[28] / 8;

    // calculate padding
    padding = (4 - (width * bytes_per_pixel) % 4) % 4;

    // size of hidden message
    hidden_msg_size = strlen(hidden_msg);

    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            for(k=0; k<bytes_per_pixel; k++) {
                data = fgetc(image);

                if(bit_count < hidden_msg_size * 8) {
                    bit = (hidden_msg[bit_count/8] >> (7 - bit_count%8)) & 1;
                    data = (data & 0xFE) | bit;
                    bit_count++;
                }

                fputc(data, output);
            }
        }
        for(k=0; k<padding; k++) {
            fputc(0x00, output);
        }
    }

    // write remaining bytes of hidden message
    while(bit_count % 8 != 0) {
        ch = 0x00;
        bit = (hidden_msg[bit_count/8] >> (7 - bit_count%8)) & 1;
        ch = ch | bit;
        fputc(ch, output);
        bit_count++;
    }

    fclose(image);
    fclose(output);
}

void decode(char *image_path)
{
    FILE *image;
    unsigned char header[54], data, bit;
    unsigned int width, height, bytes_per_pixel, padding, i, j, k;
    int bit_count = 0;
    char hidden_msg[1000];

    image = fopen(image_path, "rb");

    if(image == NULL) {
        printf("Cannot open file.\n");
        exit(0);
    }

    // read BMP image header
    for(i=0; i<54; i++) {
        header[i] = fgetc(image);
    }

    // dimensions of image
    width = *(int*)&header[18];
    height = *(int*)&header[22];
    bytes_per_pixel = *(int*)&header[28] / 8;

    // calculate padding
    padding = (4 - (width * bytes_per_pixel) % 4) % 4;

    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            for(k=0; k<bytes_per_pixel; k++) {
                data = fgetc(image);
                bit = data & 1;
                hidden_msg[bit_count/8] = (hidden_msg[bit_count/8] << 1) | bit;
                bit_count++;
                if(bit_count == 8 * 1000) {
                    break;
                }
            }
            if(bit_count == 8 * 1000) {
                break;
            }
        }
        if(bit_count == 8 * 1000) {
            break;
        }
        fseek(image, padding, SEEK_CUR);
    }

    printf("Hidden Message: %s\n", hidden_msg);

    fclose(image);
}

int main()
{
    char input_msg[1000], image_path[100], output_path[100];
    int choice;

    printf("Welcome to Image Steganography!\n");

    while(1) {
        printf("\n1. Encode Message\n2. Decode Message\n3. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the Message to Encode: ");
                scanf(" %[^\n]*c", input_msg);
                printf("Enter the Path of BMP Image: ");
                scanf("%s", image_path);
                printf("Enter the Output Path: ");
                scanf("%s", output_path);

                encode(input_msg, image_path, output_path);

                printf("Message Encoded Successfully!\n");
                break;
            case 2:
                printf("Enter the Path of BMP Image: ");
                scanf("%s", image_path);

                decode(image_path);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}