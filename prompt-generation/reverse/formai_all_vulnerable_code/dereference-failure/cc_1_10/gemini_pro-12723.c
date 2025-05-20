//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: visionary
// Embark on a celestial sojourn of hidden messages with this ethereal image steganography canvas.

#include <stdio.h>
#include <stdlib.h>

// Define the celestial paintbrush for encrypting and decrypting secrets.
typedef struct {
    int width, height;
    unsigned char *data;
} Image;

// Open an image from the ethereal realms, revealing its hidden depths.
Image *open_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return NULL;
    Image *img = malloc(sizeof(Image));
    fscanf(fp, "%d %d\n", &img->width, &img->height);
    img->data = malloc(img->width * img->height * 4);
    fread(img->data, sizeof(char), img->width * img->height * 4, fp);
    fclose(fp);
    return img;
}

// Stealthily weave a secret message into the image's ethereal fabric.
void encode_message(Image *img, const char *message) {
    int pos = 0;
    for (int i = 0; i < img->width * img->height * 4; i += 4) {
        if (message[pos] == '\0') break;
        img->data[i] &= 0xFE;
        img->data[i] |= (message[pos] & 1);
        pos++;
    }
}

// Decipher the hidden message from the image's enigmatic whispers.
char *decode_message(Image *img) {
    int pos = 0;
    char *message = malloc(1024);
    for (int i = 0; i < img->width * img->height * 4; i += 4) {
        message[pos++] = img->data[i] & 1;
    }
    message[pos] = '\0';
    return message;
}

// Save the enchanted image, preserving its secret payload.
void save_image(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) return;
    fprintf(fp, "%d %d\n", img->width, img->height);
    fwrite(img->data, sizeof(char), img->width * img->height * 4, fp);
    fclose(fp);
}

// Witness the celestial tapestry of image steganography in action.
int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_image> <output_image> <message>\n", argv[0]);
        return 1;
    }

    Image *img = open_image(argv[1]);
    if (!img) {
        printf("Error opening input image.\n");
        return 1;
    }

    if (strlen(argv[3]) > img->width * img->height * 4 / 2) {
        printf("Message too long for the image.\n");
        return 1;
    }

    if (strcmp(argv[2], argv[1]) == 0) {
        printf("Input and output images cannot be the same.\n");
        return 1;
    }
    
    encode_message(img, argv[3]);
    save_image(img, argv[2]);
    printf("Message successfully hidden in output image.\n");

    char *decoded_message = decode_message(img);
    printf("Decoded message: %s\n", decoded_message);

    free(img->data);
    free(img);
    free(decoded_message);
    return 0;
}