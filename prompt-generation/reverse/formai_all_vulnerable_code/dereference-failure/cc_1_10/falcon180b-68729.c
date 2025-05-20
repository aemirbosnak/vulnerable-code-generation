//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024

typedef struct {
    char* data;
    int size;
} Message;

void generate_random_message(Message* message) {
    message->data = malloc(MAX_SIZE);
    message->size = rand() % MAX_SIZE;
    for (int i = 0; i < message->size; i++) {
        message->data[i] = rand() % 26 + 'a';
    }
    message->data[message->size] = '\0';
}

int main() {
    Message hidden_message, cover_image;
    char* hidden_data = NULL;
    int hidden_size = 0;

    // Generate random message to hide
    generate_random_message(&hidden_message);
    hidden_data = hidden_message.data;
    hidden_size = hidden_message.size;

    // Read cover image
    FILE* fp = fopen("cover.bmp", "rb");
    if (fp == NULL) {
        printf("Error: Could not open cover image.\n");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);
    cover_image.data = malloc(file_size);
    cover_image.size = file_size;
    fread(cover_image.data, 1, file_size, fp);
    fclose(fp);

    // Hide message in cover image
    int index = 0;
    for (int i = 0; i < file_size; i++) {
        if (isalpha(cover_image.data[i])) {
            cover_image.data[i] = hidden_data[index];
            index++;
            if (index == hidden_size) {
                index = 0;
            }
        }
    }

    // Save steganographic image
    fp = fopen("stego.bmp", "wb");
    if (fp == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }
    fwrite(cover_image.data, 1, file_size, fp);
    fclose(fp);

    printf("Message hidden successfully!\n");

    return 0;
}