//FormAI DATASET v1.0 Category: Image Steganography ; Style: genious
#include <stdio.h>

#define BITS_PER_PIXEL 24
#define MAX_PIXEL_VALUE 255

void hide_message(unsigned char* image_data, char* message){
    int message_index = 0;
    int bit_index = 0;
    char current_char = message[message_index];

    for(int i = 0; message[i] != '\0'; i++) {
        for(int j = 0; j < BITS_PER_PIXEL; j++) {
            if(bit_index % 8 == 0) {
                current_char = message[message_index];
                message_index++;
            }
            
            unsigned char bit = (current_char >> (bit_index % 8)) & 1;
            unsigned char* pixel = &image_data[i * BITS_PER_PIXEL / 8 + j / 8];
            *pixel = (*pixel & ~(1 << (j % 8))) | (bit << (j % 8));

            bit_index++;
        }
    }
}

char* retrieve_message(unsigned char* image_data, int max_message_length){
    char* message = (char*) malloc(max_message_length * sizeof(char));
    int message_index = 0;
    char current_char = 0;

    for(int i = 0; i < max_message_length * BITS_PER_PIXEL; i++) {
        if(i % 8 == 0) {
            message[message_index] = current_char;
            message_index++;
            current_char = 0;
        }

        unsigned char* pixel = &image_data[i / 8];
        unsigned char bit = (*pixel >> (i % 8)) & 1;
        current_char |= bit << (i % 8);
    }

    message[message_index] = '\0';
    return message;
}

int main() {
    FILE* file = fopen("image.bmp", "rb");
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char* image_data = (unsigned char*) malloc(file_size);
    fread(image_data, 1, file_size, file);
    fclose(file);

    char* message = "Hello, world!";
    hide_message(image_data + 54, message); // Skip BMP header

    FILE* output_file = fopen("output.bmp", "wb");
    fwrite(image_data, 1, file_size, output_file);
    fclose(output_file);

    char* retrieved_message = retrieve_message(image_data + 54, strlen(message));
    printf("%s\n", retrieved_message);

    free(image_data);
    free(retrieved_message);

    return 0;
}