//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

// Function to create an image filled with nonsense
Image createImage(int width, int height) {
    Image img;
    img.width = width;
    img.height = height;
    img.data = (Pixel *)malloc(width * height * sizeof(Pixel));
    
    // Fill with random colors because why not! 
    for (int i = 0; i < width * height; i++) {
        img.data[i].r = rand() % 256; // A pinch of red!
        img.data[i].g = rand() % 256; // A dab of green!
        img.data[i].b = rand() % 256; // And a splash of blue!
    }
    return img;
}

// Function to flip the image; think of it as a really terrible selfie!
void flipImage(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            // Swapping pixels
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + (img->width - 1 - x)];
            img->data[y * img->width + (img->width - 1 - x)] = temp;
        }
    }
}

// Function to change brightness; because all images need a sun tan!
void adjustBrightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (img->data[i].r + value > 255) ? 255 : (img->data[i].r + value < 0 ? 0 : img->data[i].r + value);
        img->data[i].g = (img->data[i].g + value > 255) ? 255 : (img->data[i].g + value < 0 ? 0 : img->data[i].g + value);
        img->data[i].b = (img->data[i].b + value > 255) ? 255 : (img->data[i].b + value < 0 ? 0 : img->data[i].b + value);
    }
}

// Function to adjust contrast; let's add some drama into the pixels!
void adjustContrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (img->data[i].r - 128) * factor + 128;
        img->data[i].g = (img->data[i].g - 128) * factor + 128;
        img->data[i].b = (img->data[i].b - 128) * factor + 128;

        // Clamp the values
        img->data[i].r = (img->data[i].r < 0) ? 0 : (img->data[i].r > 255) ? 255 : img->data[i].r;
        img->data[i].g = (img->data[i].g < 0) ? 0 : (img->data[i].g > 255) ? 255 : img->data[i].g;
        img->data[i].b = (img->data[i].b < 0) ? 0 : (img->data[i].b > 255) ? 255 : img->data[i].b;
    }
}

// Function to free up the image when it has been disgraced
void freeImage(Image *img) {
    free(img->data);
}

// Main function where the magic happens!
int main() {
    printf("Welcome to the Fantastic Image Manipulator 3000!\n");
    printf("We're about to flip, brighten, and contrast your way to pixel perfect happiness!\n");
    
    Image img = createImage(4, 4); // Let's make a tiny 4x4 pixel image!

    printf("Initial nonsense image created (it looks wild, doesn't it?)!\n");

    // Flip the image
    flipImage(&img);
    printf("Your image has been flipped! It's like a pancake now!\n");

    // Change the brightness (make it shine like a star!)
    adjustBrightness(&img, 50);
    printf("Brightened your image! Now it’s as bright as my future—very promising!\n");

    // Adjust contrast (let's add some spice!)
    adjustContrast(&img, 1.5);
    printf("Contrast adjusted! Now it has more drama than a soap opera!\n");

    // Clean up
    freeImage(&img); 
    printf("All done! The pixels are grateful, and so are we. Have a bright day!\n");

    return 0;
}