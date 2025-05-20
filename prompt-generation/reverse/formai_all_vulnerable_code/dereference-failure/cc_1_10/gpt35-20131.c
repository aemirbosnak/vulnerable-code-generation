//FormAI DATASET v1.0 Category: Image Steganography ; Style: puzzling
#include<stdio.h>
#include<math.h>

char* binary(char ch) //function to convert character to binary
{
    static char bin[9]; //array to store binary value
    for(int i=7; i>=0; i--) //loop to convert to binary
    {
        bin[i] = (ch % 2) + '0'; //converting remainder to character and storing
        ch = ch / 2; //dividing by 2
    }
    bin[8] = '\0'; //adding null character at end
    return bin; //returning binary value as string
}

int main()
{
    FILE *f1, *f2; //file pointers to read and write image files
    f1 = fopen("image.bmp", "rb"); //opening image file in read mode
    f2 = fopen("stego.bmp", "wb"); //creating new image file in write mode
    if(f1 == NULL || f2 == NULL) //checking if file opening was successful
    {
        printf("Error opening file!"); //displaying error message
        return 0; //exiting program
    }
    int offset = 54; //offset from start of file where pixel data starts
    int width, height; //variables to store width and height of image
    fseek(f1, 18, SEEK_SET); //moving file pointer to width and height information in header
    fread(&width, sizeof(int), 1, f1); //reading width
    fread(&height, sizeof(int), 1, f1); //reading height
    int size = width * height * 3; //size of pixel data
    fseek(f1, 0, SEEK_SET); //moving file pointer back to start of file
    char header[offset]; //array to store header information
    fread(header, sizeof(char), offset, f1); //reading header into array
    fwrite(header, sizeof(char), offset, f2); //writing header to new file
    char pixel[size]; //array to store pixel data
    fread(pixel, sizeof(char), size, f1); //reading pixel data into array
    int index = 0; //variable to keep track of index in array
    char message[] = "This is a secret message!"; //secret message to be encoded
    int msg_len = strlen(message); //length of secret message
    int binary_index = 0; //variable to keep track of index in binary string
    char binary_msg[msg_len * 8]; //array to store binary string of secret message
    for(int i=0; i<msg_len; i++) //loop to convert secret message to binary string
    {
        char *bin = binary(message[i]); //converting character to binary string
        for(int j=0; j<8; j++) //loop to add binary string to binary_msg array
        {
            binary_msg[binary_index] = bin[j];
            binary_index++;
        }
    }
    for(int i=0; i<size; i+=3) //loop to encode secret message in pixel data
    {
        for(int j=0; j<3; j++) //loop to encode message in each color channel
        {
            if(index >= binary_index) //breaking out of loop if message has been completely encoded
            {
                break;
            }
            int bit = binary_msg[index] - '0'; //converting binary value to integer
            int pixel_bit = pixel[i+j] & 0xFE; //clearing least significant bit of pixel byte
            pixel_bit += bit; //adding bit to least significant bit of pixel byte
            pixel[i+j] = pixel_bit; //updating pixel value in array
            index++; //incrementing index
        }
        if(index >= binary_index) //breaking out of loop if message has been completely encoded
        {
            break;
        }
    }
    fwrite(pixel, sizeof(char), size, f2); //writing encoded pixel data to new file
    printf("Message encoded successfully!"); //displaying success message
    fclose(f1); //closing input file
    fclose(f2); //closing output file
    return 0;
}