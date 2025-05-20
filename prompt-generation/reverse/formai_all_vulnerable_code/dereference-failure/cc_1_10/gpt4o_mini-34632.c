//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_SIZE 100000
#define MAGIC_NUMBER "STEG"

// Laughter is the best medicine, let's inject some fun! 

typedef struct {
    char magic[4];  // For a little magic in our life!
    int width;
    int height;
    unsigned char *data;
} Image;

void print_heading() {
    printf("==================================\n");
    printf("       Funny Image Steganography  \n");
    printf("==================================\n");
    printf("A top-secret recipe for hiding stuff!\n");
}

Image* load_image(const char *filename) {
    Image *img = malloc(sizeof(Image));
    if (!img) {
        printf("Oops! Not enough memory for a magic potion!\n");
        return NULL;
    }

    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Hmm... Can't find that image! It must be playing hide and seek!\n");
        free(img);
        return NULL;
    }

    // Read magic number
    fread(img->magic, sizeof(char), 4, file);
    if (strncmp(img->magic, MAGIC_NUMBER, 4) != 0) {
        printf("Not a magical stego image! Is it a potion instead?\n");
        fclose(file);
        free(img);
        return NULL;
    }

    // Read image dimensions
    fread(&img->width, sizeof(int), 1, file);
    fread(&img->height, sizeof(int), 1, file);

    // Allocate memory for pixel data
    img->data = (unsigned char*)malloc(img->width * img->height * 3);
    fread(img->data, sizeof(unsigned char), img->width * img->height * 3, file);
    fclose(file);

    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Unable to send the image to the storage dimension! \n");
        return;
    }

    fwrite(img->magic, sizeof(char), 4, file);
    fwrite(&img->width, sizeof(int), 1, file);
    fwrite(&img->height, sizeof(int), 1, file);
    fwrite(img->data, sizeof(unsigned char), img->width * img->height * 3, file);
    fclose(file);
    
    printf("Image has been saved! It should stop hiding now.\n");
}

void hide_message(Image *img, const char *message) {
    int msg_len = strlen(message);
    if (msg_len > img->width * img->height * 3 / 8) {
        printf("Oops! The message is too long for this tiny image! It's like trying to fit an elephant in a bathtub!\n");
        return;
    }
    
    // Hide the message length in the first byte of pixel data
    img->data[0] = (unsigned char)msg_len;
    for (int i = 0; i < msg_len; i++) {
        // Hide each character in the least significant bit of the pixel channels
        img->data[i + 1] = (unsigned char)message[i];
    }
    
    printf("The message has successfully slipped into the image like a ninja!\n");
}

char* extract_message(Image *img) {
    int msg_len = img->data[0];
    char *message = malloc(msg_len + 1);
    if (!message) {
        printf("Memory error while extracting the hidden message!\n");
        return NULL;
    }

    for (int i = 0; i < msg_len; i++) {
        message[i] = img->data[i + 1];
    }
    message[msg_len] = '\0';  // Null-terminate the string

    return message;
}

void free_image(Image *img) {
    free(img->data);
    free(img);
    printf("The magical image is now free from our grasp, like a bird!\n");
}

int main() {
    print_heading();
    
    Image *img = load_image("magic_image.bin");
    if (!img) {
        return EXIT_FAILURE;
    }

    char *message_to_hide = "I love coding! Can't hide this! 🤫";
    hide_message(img, message_to_hide);
    save_image("stealthy_image.bin", img);

    char *extracted_msg = extract_message(img);
    printf("Here’s the hidden message extracted from the image: %s\n", extracted_msg);
    
    free(extracted_msg);
    free_image(img);
    
    printf("The magic is complete! Thanks for joining this hilarious ride!\n");

    return EXIT_SUCCESS;
}