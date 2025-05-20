//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024
#define MAX_PASS 100

int main() {
    char message[MAX_SIZE];
    char password[MAX_PASS];
    int message_size, password_size;
    FILE *input_file, *output_file;
    int i, j;
    char *image_data;
    int image_size;
    int bytes_to_hide, bytes_hidden;

    printf("Enter message: ");
    fgets(message, MAX_SIZE, stdin);
    message_size = strlen(message);

    printf("Enter password: ");
    fgets(password, MAX_PASS, stdin);
    password_size = strlen(password);

    input_file = fopen("input.png", "rb");
    if (!input_file) {
        printf("Error opening input file.\n");
        exit(1);
    }

    fseek(input_file, 0, SEEK_END);
    image_size = ftell(input_file);
    rewind(input_file);

    image_data = (char *)malloc(image_size);
    if (!image_data) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    fread(image_data, image_size, 1, input_file);
    fclose(input_file);

    bytes_to_hide = message_size + 1;
    bytes_hidden = 0;

    for (i = 0; i < image_size; i++) {
        if (bytes_hidden >= bytes_to_hide) {
            break;
        }

        if (image_data[i] == 0x00) {
            image_data[i] = message[bytes_hidden];
            bytes_hidden++;
        }
    }

    output_file = fopen("output.png", "wb");
    if (!output_file) {
        printf("Error opening output file.\n");
        exit(1);
    }

    fwrite(image_data, image_size, 1, output_file);
    fclose(output_file);

    printf("Message hidden successfully.\n");

    return 0;
}