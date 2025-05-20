//FormAI DATASET v1.0 Category: Image Steganography ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 100
#define MAX_MESSAGE_SIZE 1000

// function to get the length of a file
int get_file_size(FILE *file) {
    fseek(file, 0L, SEEK_END);
    int size = ftell(file);
    rewind(file);
    return size;
}

// function to hide the message in the image
void hide_message(char *filename, char *message) {
    // open the file in binary mode
    FILE *file = fopen(filename, "rb+");
    if (file) {
        // get the size of the image file and the message
        int image_size = get_file_size(file);
        int message_size = strlen(message) + 1;
        
        // calculate the maximum message size that can be hidden in the image
        int max_message_size = (image_size * 3) / 8;
        if (message_size > max_message_size) {
            printf("Error: Message is too long to hide in the image.\n");
            return;
        }
        
        // read the image data into a buffer
        unsigned char *buffer = (unsigned char*) malloc(image_size);
        fread(buffer, 1, image_size, file);
        
        // hide the message in the least significant bits of the image data
        unsigned char *data = buffer;
        char *message_ptr = message;
        int bit_count = 0;
        
        while (*message_ptr) {
            // get the next bit from the message
            char bit = (*message_ptr >> bit_count) & 1;
            
            // set the least significant bit of the current byte to the message bit
            *data = (*data & ~1) | bit;
            
            // move to the next bit of the message
            bit_count++;
            if (bit_count == 8) {
                bit_count = 0;
                message_ptr++;
            }
            
            // move to the next byte of the image data
            data++;
        }
        
        // write the updated image data to the file
        fseek(file, 0L, SEEK_SET);
        fwrite(buffer, 1, image_size, file);
        
        // cleanup
        free(buffer);
        fclose(file);
        
    } else {
        printf("Error: Unable to open file.\n");
    }
}

// function to reveal the message in the image
void reveal_message(char *filename) {
    // open the file in binary mode
    FILE *file = fopen(filename, "rb");
    if (file) {
        // get the size of the image file
        int image_size = get_file_size(file);
        
        // read the image data into a buffer
        unsigned char *buffer = (unsigned char*) malloc(image_size);
        fread(buffer, 1, image_size, file);
        
        // reveal the message from the least significant bits of the image data
        unsigned char *data = buffer;
        char message[MAX_MESSAGE_SIZE];
        char *message_ptr = message;
        int bit_count = 0;
        
        while (*data && message_ptr - message < MAX_MESSAGE_SIZE) {
            // get the least significant bit of the current byte
            char bit = *data & 1;
            
            // set the current bit of the message to the least significant bit of the current byte
            *message_ptr |= bit << bit_count;
            
            // move to the next bit of the message
            bit_count++;
            if (bit_count == 8) {
                bit_count = 0;
                message_ptr++;
            }
            
            // move to the next byte of the image data
            data++;
        }
        
        // print the revealed message
        printf("Revealed Message: %s\n", message);
        
        // cleanup
        free(buffer);
        fclose(file);
        
    } else {
        printf("Error: Unable to open file.\n");
    }
}

int main() {
    char filename[MAX_FILENAME_SIZE];
    char message[MAX_MESSAGE_SIZE];
    
    // prompt the user for the image filename and message to hide
    printf("Enter the filename of the image: ");
    scanf("%s", filename);
    printf("Enter the message to hide in the image: ");
    scanf("%s", message);
    
    // hide the message in the image
    hide_message(filename, message);
    
    // reveal the message from the image
    reveal_message(filename);
    
    return 0;
}