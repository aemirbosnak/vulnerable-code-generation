//FormAI DATASET v1.0 Category: Image Steganography ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to convert character to binary
void char_to_bin(char c, char* bin) {
    int i;
    for(i = 7; i >= 0; i--) {
        if(c & (1 << i)) {
            bin[7-i] = '1';
        } else {
            bin[7-i] = '0';
        }
    }
    bin[8] = '\0';
}

//function to convert binary to character
char bin_to_char(char* bin) {
    int i;
    char c = 0;
    for(i = 7; i >= 0; i--) {
        if(bin[7-i] == '1') {
            c = c + (1 << i);
        }
    }
    return c;
}

//function to hide message in image
void hide_message(char* image_filename, char* message) {
    FILE* image_file = fopen(image_filename, "rb");
    if(image_file == NULL) {
        printf("Error: Could not open image file!\n");
        return;
    }

    //get image size
    fseek(image_file, 0L, SEEK_END);
    int image_size = ftell(image_file);
    fseek(image_file, 0L, SEEK_SET);

    //allocate memory for image data
    char* image_data = (char*) malloc(image_size*sizeof(char));
    if(image_data == NULL) {
        printf("Error: Could not allocate memory for image data!\n");
        return;
    }

    //read image data
    int read_size = fread(image_data, sizeof(char), image_size, image_file);
    if(read_size != image_size) {
        printf("Error: Could not read image data!\n");
        return;
    }

    fclose(image_file);

    printf("Image size: %d bytes\n", image_size);

    //get message length and convert to binary
    int message_length = strlen(message);
    char message_length_bin[33];
    char_to_bin(message_length, message_length_bin);
    printf("Message length: %d bits\n", message_length*8);

    //check if message can fit into image
    if((8*message_length) > (image_size - 54)) {
        printf("Error: The message cannot fit into the image!\n");
        return;
    }

    //hide message length in image header
    int i;
    int header_size = 54;
    char temp[9];
    for(i = 0; i < 32; i++) {
        char_to_bin(image_data[header_size + i], temp);
        temp[7] = message_length_bin[i];
        image_data[header_size + i] = bin_to_char(temp);
    }

    //hide message in image data
    int j = 0;
    char curr_char;
    char curr_bin[9];
    for(i = header_size + 32; i < image_size; i++) {
        curr_char = image_data[i];
        char_to_bin(curr_char, curr_bin);
        curr_bin[7] = message[j];
        image_data[i] = bin_to_char(curr_bin);
        j++;
        if(j == message_length) {
            break;
        }
    }

    //write modified image data to file
    char* output_filename = "output.bmp";
    FILE* output_file = fopen(output_filename, "wb");
    if(output_file == NULL) {
        printf("Error: Could not create output file!\n");
        return;
    }
    fwrite(image_data, sizeof(char), image_size, output_file);
    fclose(output_file);

    printf("Message hidden successfully in image file '%s'!\n", output_filename);

    free(image_data);
}

//function to extract message from image
void extract_message(char* image_filename) {
    FILE* image_file = fopen(image_filename, "rb");
    if(image_file == NULL) {
        printf("Error: Could not open image file!\n");
        return;
    }

    //get image size
    fseek(image_file, 0L, SEEK_END);
    int image_size = ftell(image_file);
    fseek(image_file, 0L, SEEK_SET);

    //allocate memory for image data
    char* image_data = (char*) malloc(image_size*sizeof(char));
    if(image_data == NULL) {
        printf("Error: Could not allocate memory for image data!\n");
        return;
    }

    //read image data
    int read_size = fread(image_data, sizeof(char), image_size, image_file);
    if(read_size != image_size) {
        printf("Error: Could not read image data!\n");
        return;
    }

    fclose(image_file);

    printf("Image size: %d bytes\n", image_size);

    //extract message length from image header
    int i;
    int header_size = 54;
    char temp[9];
    char message_length_bin[33];
    for(i = 0; i < 32; i++) {
        char_to_bin(image_data[header_size + i], temp);
        message_length_bin[i] = temp[7];
    }
    message_length_bin[32] = '\0';
    int message_length = strtol(message_length_bin, NULL, 2);
    printf("Message length: %d bits\n", message_length*8);

    //extract message from image data
    char curr_char;
    char curr_bin[9];
    char* message = (char*) malloc((message_length + 1)*sizeof(char));
    int j = 0;
    for(i = header_size + 32; i < image_size; i++) {
        curr_char = image_data[i];
        char_to_bin(curr_char, curr_bin);
        message[j] = curr_bin[7];
        j++;
        if(j == message_length) {
            break;
        }
    }
    message[message_length] = '\0';

    printf("Message extracted successfully: %s\n", message);

    free(image_data);
}

int main() {
    char* image_filename = "image.bmp";
    char* message = "This is a test message! This message will be hidden in the image using steganography.";
    hide_message(image_filename, message);
    extract_message("output.bmp");
    return 0;
}