//FormAI DATASET v1.0 Category: Image Steganography ; Style: active
#include <stdio.h>
#include <stdlib.h>

//Function to get the bit value at the given index
int get_bit_value(int pixel_value, int index) {
    return (pixel_value >> index) & 1;
}

//Function to set bit value at the given index
void set_bit_value(int *pixel_value, int index, int value) {
    *pixel_value ^= (-value ^ *pixel_value) & (1 << index);
}

//Function to hide message in the image
void hide_message(FILE *in_img, FILE *out_img, char *message) {
    //Variables to hold image data
    unsigned char image_header[54], pixel_data[3];
    int image_width, image_height, image_bit_depth, pixel_count = 0;
    
    //Read image header
    fread(image_header, 1, 54, in_img);
    
    //Get image dimensions and bit depth
    image_width = *(int*)&image_header[18];
    image_height = *(int*)&image_header[22];
    image_bit_depth = *(int*)&image_header[28];
    
    //Check if image is 24-bit
    if(image_bit_depth != 24) {
        printf("Only 24-bit images are supported!\n");
        return;
    }
    
    //Calculate maximum message length based on image size
    int max_message_length = (image_width * image_height * 3) / 8;
    
    //Check if message length is within limit
    int message_length = strlen(message);
    if(message_length > max_message_length) {
        printf("Message is too long to be hidden in the image!\n");
        return;
    }
    
    //Hide message length in the first 32 pixels
    int i, bit_value;
    for(i = 0; i < 32 && i < message_length; i++) {
        fread(pixel_data, 1, 3, in_img);
        bit_value = get_bit_value(pixel_data[0], 0);
        set_bit_value(&pixel_data[0], 0, ((int)message_length >> i) & 1);
        fwrite(pixel_data, 1, 3, out_img);
        pixel_count++;
    }
    
    //Hide message in remaining pixels
    for(i = 0; i < message_length; i++) {
        fread(pixel_data, 1, 3, in_img);
        bit_value = get_bit_value(pixel_data[0], 0);
        set_bit_value(&pixel_data[0], 0, ((int)message[i] >> 0) & 1);
        set_bit_value(&pixel_data[1], 0, ((int)message[i] >> 1) & 1);
        set_bit_value(&pixel_data[2], 0, ((int)message[i] >> 2) & 1);
        fwrite(pixel_data, 1, 3, out_img);
        pixel_count++;
    }
    
    //Copy remaining pixels from input to output
    while(fread(pixel_data, 1, 3, in_img)) {
        fwrite(pixel_data, 1, 3, out_img);
        pixel_count++;
    }
    
    printf("Message was hidden in %d pixels of the image!\n", pixel_count);
}

//Function to extract message from the image
void extract_message(FILE *in_img, char **message) {
    //Variables to hold image data
    unsigned char image_header[54], pixel_data[3];
    int image_width, image_height, image_bit_depth, pixel_count = 0;
    
    //Read image header
    fread(image_header, 1, 54, in_img);
    
    //Get image dimensions and bit depth
    image_width = *(int*)&image_header[18];
    image_height = *(int*)&image_header[22];
    image_bit_depth = *(int*)&image_header[28];
    
    //Check if image is 24-bit
    if(image_bit_depth != 24) {
        printf("Only 24-bit images are supported!\n");
        return;
    }
    
    //Extract message length from first 32 pixels
    int i, message_length = 0;
    for(i = 0; i < 32; i++) {
        fread(pixel_data, 1, 3, in_img);
        message_length |= get_bit_value(pixel_data[0], 0) << i;
        pixel_count++;
    }
    
    //Allocate memory for message
    *message = (char*)malloc((message_length + 1) * sizeof(char));
    
    //Extract message from remaining pixels
    for(i = 0; i < message_length; i++) {
        fread(pixel_data, 1, 3, in_img);
        int value = get_bit_value(pixel_data[0], 0) |
                    (get_bit_value(pixel_data[1], 0) << 1) |
                    (get_bit_value(pixel_data[2], 0) << 2);
        (*message)[i] = (char)value;
        pixel_count++;
    }
    
    (*message)[message_length] = '\0';
    
    printf("Message was extracted from %d pixels of the image!\n", pixel_count);
}

int main(int argc, char **argv) {
    //Check command line arguments
    if(argc != 4) {
        printf("Usage: %s <input_image> <output_image> <message>\n", argv[0]);
        return 1;
    }
    
    //Open input and output images
    FILE *in_img = fopen(argv[1], "rb");
    FILE *out_img = fopen(argv[2], "wb");
    
    //Check if files were opened successfully
    if(in_img == NULL || out_img == NULL) {
        printf("Failed to open input or output image file!\n");
        return 1;
    }
    
    //Check if operation is hide or extract
    if(strcmp(argv[3], "hide") == 0) {
        //Ask user for message to hide
        char message[1024];
        printf("Enter message to hide in the image (up to 1024 characters):\n");
        fgets(message, 1024, stdin);
        message[strlen(message)-1] = '\0';
        
        //Hide message in the image
        hide_message(in_img, out_img, message);
    }
    else if(strcmp(argv[3], "extract") == 0) {
        //Extract message from the image
        char *message = NULL;
        extract_message(in_img, &message);
        printf("Extracted message: %s\n", message);
        free(message);
    }
    else {
        //Invalid operation
        printf("Invalid operation specified (must be 'hide' or 'extract')!\n");
        return 1;
    }
    
    //Close files
    fclose(in_img);
    fclose(out_img);
    
    return 0;
}