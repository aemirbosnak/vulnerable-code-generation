//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold image data
typedef struct {
    unsigned char *data;
    int width;
    int height;
    int max_color_value;
} Image;

// Function to read a PPM file
Image read_ppm(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Failed to open the file");
        exit(EXIT_FAILURE);
    }

    // Read the PPM header
    char buff[16];
    if (!fgets(buff, sizeof(buff), fp)) {
        perror("Failed to read PPM header");
        exit(EXIT_FAILURE);
    }
    if (buff[0] != 'P' || buff[1] != '6') {
        fprintf(stderr, "Not a valid PPM file\n");
        exit(EXIT_FAILURE);
    }

    Image img;
    fscanf(fp, "%d %d\n%d\n", &img.width, &img.height, &img.max_color_value);
    img.data = (unsigned char *)malloc(img.width * img.height * 3);
    fread(img.data, 3, img.width * img.height, fp);
    fclose(fp);

    return img;
}

// Function to write a PPM file
void write_ppm(const char *filename, const Image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Failed to open the file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "P6\n%d %d\n%d\n", img->width, img->height, img->max_color_value);
    fwrite(img->data, 3, img->width * img->height, fp);
    fclose(fp);
}

// Function to embed a watermark in the image
void embed_watermark(Image *img, const char *watermark) {
    int len = strlen(watermark);
    
    for (int i = 0; i < len; i++) {
        int index = (i * img->width * img->height / len) * 3; // Spread watermark evenly through image
        if (index < img->width * img->height * 3) {
            img->data[index] = (img->data[index] & 0xFE) | ((watermark[i] >> 7) & 0x01); // Embed watermark bit
        }
    }
}

// Function to retrieve the watermark from the image
void retrieve_watermark(const Image *img, char *watermark, int watermark_len) {
    for (int i = 0; i < watermark_len; i++) {
        int index = (i * img->width * img->height / watermark_len) * 3; // Spread watermark evenly through image
        if (index < img->width * img->height * 3) {
            watermark[i] = ((img->data[index] & 0x01) << 7); // Retrieve watermark bit
        }
    }
    watermark[watermark_len] = '\0'; // Null-terminate the string
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <watermark>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    const char *watermark = argv[3];

    Image img = read_ppm(input_filename);

    // Embed the watermark
    embed_watermark(&img, watermark);

    // Write the new image with the embedded watermark
    write_ppm(output_filename, &img);

    // Retrieve the watermark for verification
    char retrieved_watermark[100] = { 0 }; // Assume watermark is less than 100 chars
    retrieve_watermark(&img, retrieved_watermark, strlen(watermark));

    printf("Original Watermark: %s\n", watermark);
    printf("Retrieved Watermark: %s\n", retrieved_watermark);

    // Clean up
    free(img.data);

    return EXIT_SUCCESS;
}