//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_IMAGE_SIZE 500000
#define MAX_MESSAGE_SIZE 100

typedef unsigned char BYTE;

struct image_info {
    int width;
    int height;
    int max_color;
    BYTE* image_data;
};

int main() {
    srand(time(NULL));

    int width, height, max_color;
    char* message = "This is a secret message";
    BYTE* image_data;

    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the maximum number of colors: ");
    scanf("%d", &max_color);

    image_data = malloc(MAX_IMAGE_SIZE);
    if (image_data == NULL) {
        printf("Failed to allocate memory for image data.\n");
        return 1;
    }

    struct image_info info = {
        width,
        height,
        max_color,
        image_data
    };

    // Generate random image data
    for (int i = 0; i < width * height; i++) {
        image_data[i] = rand() % max_color;
    }

    // Generate random positions to hide the message
    int message_length = strlen(message);
    int* message_positions = (int*) malloc(sizeof(int) * message_length);
    if (message_positions == NULL) {
        printf("Failed to allocate memory for message positions.\n");
        return 1;
    }

    for (int i = 0; i < message_length; i++) {
        int position = rand() % width * height;
        while (image_data[position] == 0) {
            position = rand() % width * height;
        }
        message_positions[i] = position;
    }

    // Hide the message in the image
    char* buffer = (char*) malloc(sizeof(char) * (MAX_MESSAGE_SIZE + 1));
    if (buffer == NULL) {
        printf("Failed to allocate memory for buffer.\n");
        return 1;
    }
    for (int i = 0; i < message_length; i++) {
        sprintf(buffer, "%d ", message_positions[i]);
    }
    buffer[message_length] = '\0';

    int message_length_encoded = 0;
    int message_position = 0;
    while (message_position < MAX_MESSAGE_SIZE) {
        if (message_position + 1 + strlen(buffer) <= MAX_MESSAGE_SIZE) {
            memcpy(image_data + message_positions[message_length_encoded], buffer, strlen(buffer));
            message_position += strlen(buffer);
            message_length_encoded++;
        } else {
            break;
        }
    }

    // Write the modified image to a file
    char filename[50];
    printf("Enter the filename for the output image: ");
    scanf("%s", filename);

    FILE* output = fopen(filename, "wb");
    if (output == NULL) {
        printf("Failed to open file for writing.\n");
        return 1;
    }

    fwrite(info.image_data, info.width * info.height, 1, output);
    fclose(output);

    free(message_positions);
    free(buffer);
    free(image_data);

    return 0;
}