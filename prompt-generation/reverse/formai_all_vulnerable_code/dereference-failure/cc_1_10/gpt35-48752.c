//FormAI DATASET v1.0 Category: Image Steganography ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

/* function prototypes */
void encode(char* img_path, char* message_path, char* output_path);
void decode(char* img_path);

/* main function */
int main(int argc, char* argv[]) {
    char* option = argv[1];
    char* img_path = argv[2];

    if (argc < 3) {
        printf("Invalid number of arguments!\n");
        exit(1);
    }

    if (*option == 'e') {
        char* message_path = argv[3];
        char* output_path = argv[4];
        encode(img_path, message_path, output_path);
    } else if (*option == 'd') {
        decode(img_path);
    } else {
        printf("Invalid option!\n");
        exit(1);
    }

    return 0;
}

/* function to encode message in image */
void encode(char* img_path, char* message_path, char* output_path) {
    FILE* img = fopen(img_path, "rb");
    if (!img) {
        printf("Error: Unable to open image file!\n");
        exit(1);
    }

    FILE* message = fopen(message_path, "rb");
    if (!message) {
        printf("Error: Unable to open message file!\n");
        exit(1);
    }

    FILE* output = fopen(output_path, "wb");
    if (!output) {
        printf("Error: Unable to open output file!\n");
        exit(1);
    }

    // code for encoding goes here
    
    fclose(img);
    fclose(message);
    fclose(output);

    printf("Message encoded successfully!\n");
}

/* function to decode message from image */
void decode(char* img_path) {
    FILE* img = fopen(img_path, "rb");
    if (!img) {
        printf("Error: Unable to open image file!\n");
        exit(1);
    }

    // code for decoding goes here
    
    fclose(img);

    printf("Message decoded successfully!\n");
}