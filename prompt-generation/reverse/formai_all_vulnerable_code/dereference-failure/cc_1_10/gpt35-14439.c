//FormAI DATASET v1.0 Category: Image Steganography ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define our image pixel structure
typedef struct pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

// define our steganography message structure
typedef struct message {
    char* text;
    int length;
} message;

// define our image dimensions
#define WIDTH 400
#define HEIGHT 300

// define our steganography key
const char* STEG_KEY = "s3cr3tkey";

// function to encrypt our steganography message
void encrypt(message* m) {
    for(int i=0; i<m->length; i++) {
        m->text[i] = m->text[i] ^ STEG_KEY[i % strlen(STEG_KEY)];
    }
}

int main() {
    // load our image into memory
    pixel* image = (pixel*) malloc(sizeof(pixel) * WIDTH * HEIGHT);
    FILE* fp = fopen("image.bmp", "rb");
    fseek(fp, 54, SEEK_SET);
    fread(image, sizeof(pixel), WIDTH * HEIGHT, fp);
    fclose(fp);

    // create our steganography message
    message m;
    m.text = "This is a secret message.";
    m.length = strlen(m.text);

    // encrypt our steganography message
    encrypt(&m);

    // hide the message in the image
    int idx = 0;
    int b = 0;
    for(int i=0; i<WIDTH*HEIGHT; i++) {
        // if we've reached the end of the message, break out of the loop
        if(idx >= m.length) break;

        // get the current pixel
        pixel* p = image + i;

        // check if we've reached the end of a color channel
        if(b == 8) {
            // move to the next pixel
            i++;
            p = image + i;

            // reset our channel counter
            b = 0;
        }

        // set the least significant bit of the color channel to the message bit
        if((m.text[idx] >> b) & 1) {
            p->r |= 1;
        } else {
            p->r &= ~1;
        }

        // increment our channel counter
        b++;

        // move to the next bit in the message
        idx++;
    }

    // save our modified image to disk
    fp = fopen("image_steg.bmp", "wb");
    fseek(fp, 0, SEEK_SET);
    fwrite(image, sizeof(pixel), WIDTH * HEIGHT, fp);
    fclose(fp);

    // free our allocated memory
    free(image);

    return 0;
}