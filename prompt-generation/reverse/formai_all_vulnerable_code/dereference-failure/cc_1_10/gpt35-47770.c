//FormAI DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main() {
    char* message = "secret message"; // define the secret message
    char* image_path = "image_path.bmp"; // define the image file path
    char* output_path = "output.bmp"; // define the output file path

    FILE* image = fopen(image_path, "rb"); // open the image in read mode
    FILE* output = fopen(output_path, "wb"); // open the output file in write mode

    if (image == NULL || output == NULL) { // check if there was an error opening files
        printf("File error occurred!");
        exit(1);
    }

    //read the image header data
    //write the image header data to the output file

    int byte_counter = 0, bit_counter = 0;
    char byte = fgetc(image); // read the first byte of the image

    while (byte != EOF) { // loop through all the bytes in the image
        if (byte_counter < strlen(message)) { // if the message is not fully encoded yet
            char msg_byte = message[byte_counter]; // get the next byte of the message

            for (int i = 0; i < 8; i++) { // loop through all the bits in the message byte
                char bit = (msg_byte >> i) & 1; // get the i-th bit of the message byte
                byte &= ~(1 << bit_counter); // clear the i-th least significant bit of the image byte
                byte |= bit << bit_counter; // set the i-th least significant bit of the image byte to the message bit
                bit_counter++;

                if (bit_counter == 8) { // if all the 8 bits of the byte have been overwritten
                    bit_counter = 0;
                    byte_counter++;

                    fwrite(&byte, sizeof(char), 1, output); // write the byte to the output file
                    byte = fgetc(image); // read the next image byte
                }
            }
        } else { // if the message has been fully encoded, just write the remaining image bytes to the output file
            fwrite(&byte, sizeof(char), 1, output); // write the byte to the output file
            byte = fgetc(image); // read the next image byte
        }
    }

    fclose(image); // close the image file
    fclose(output); // close the output file

    return 0;
}