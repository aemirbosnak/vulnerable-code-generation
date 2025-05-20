//FormAI DATASET v1.0 Category: Image Steganography ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    unsigned char r, g, b;
}pixel;

int hideData(const char* host_image_name, const char* secret_image_name, const char* output_image_name) {
    FILE *fp1 = fopen(host_image_name, "rb");
    FILE *fp2 = fopen(secret_image_name, "rb");
    FILE *fp3 = fopen(output_image_name, "wb");

    if (fp1 == NULL || fp2 == NULL || fp3 == NULL) {
        perror("Error in opening file");
        return -1;
    }

    // read the headers of input image files
    unsigned char header1[54], header2[54];
    fread(header1, sizeof(unsigned char), 54, fp1);
    fread(header2, sizeof(unsigned char), 54, fp2);

    // write the headers to the output image file
    fwrite(header1, sizeof(unsigned char), 54, fp3);

    // extract the dimensions of the input image files
    int width1 = *((int*)&header1[18]), height1 = *((int*)&header1[22]);
    int width2 = *((int*)&header2[18]), height2 = *((int*)&header2[22]);

    // check if the two images have the same dimensions
    if (width1 != width2 || height1 != height2) {
        printf("\nError: sizes of the two images are different");
        return -1;
    }

    // allocate memory to host the pixels of the input and output images and the encrypted data
    int size = width1 * height1;
    pixel *img1 = (pixel*)malloc(size * sizeof(pixel)), *img2 = (pixel*)malloc(size * sizeof(pixel));
    unsigned char *encrypted_data = (unsigned char*)malloc((size / 8) * sizeof(unsigned char));

    // read the pixels of the input images
    fread(img1, sizeof(pixel), size, fp1);
    fread(img2, sizeof(pixel), size, fp2);

    // process the pixels by encrypting the data
    int i, j = 0;
    char ch;
    for (i = 0; i < size; i++) {
        ch = fgetc(fp2);
        while(j < 8) {
            // hide one bit of the encrypted data in each pixel
            encrypted_data[i] = (encrypted_data[i] << 1) | ((ch >> (7-j)) & 1);
            // move to the next bit of the encrypted data
            j++;
        }
        if (j == 8) {
            j = 0;
            // read the next character from the input file
            ch = fgetc(fp2);
        }
        // set the last bit of the blue channel of each pixel to the corresponding bit of the encrypted data
        img1[i].b = (img1[i].b & 0xFE) | (encrypted_data[i] & 1);
    }

    // write the pixels of the output image file
    fwrite(img1, sizeof(pixel), size, fp3);

    // close all the files and release the memory allocated
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    free(img1);
    free(img2);
    free(encrypted_data);

    return 0;
}

int extractData(const char* input_image_name, const char* output_image_name) {
    FILE *fp1 = fopen(input_image_name, "rb");
    FILE *fp2 = fopen(output_image_name, "wb");

    if (fp1 == NULL || fp2 == NULL) {
        perror("Error in opening file");
        return -1;
    }

    // read the headers of the input image file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp1);

    // write the headers to the output image file
    fwrite(header, sizeof(unsigned char), 54, fp2);

    // extract the dimensions of the input image file
    int width = *((int*)&header[18]), height = *((int*)&header[22]);

    // allocate memory to host the pixels of the input and output images and the decrypted data
    int size = width * height;
    pixel *img = (pixel*)malloc(size * sizeof(pixel));
    unsigned char *decrypted_data = (unsigned char*)malloc((size / 8) * sizeof(unsigned char));

    // read the pixels of the input image
    fread(img, sizeof(pixel), size, fp1);

    // process the pixels by decrypting the data
    int i;
    for (i = 0; i < size; i++) {
        // extract the last bit of the blue channel of each pixel and combine them to form the decrypted data
        decrypted_data[i] = (img[i].b & 1) | (decrypted_data[i] << 1);
    }

    // write the decrypted data to the output file
    fwrite(decrypted_data, sizeof(unsigned char), size / 8, fp2);

    // close all the files and release the memory allocated
    fclose(fp1);
    fclose(fp2);
    free(img);
    free(decrypted_data);

    return 0;
}

int main() {
    const char* host_image_name = "sample.bmp", *secret_image_name = "secret.bmp", *output_image_name = "output.bmp";
    const char* input_image_name = "output.bmp", *output_file_name = "secret.txt";

    // hide data inside the image file
    int ret = hideData(host_image_name, secret_image_name, output_image_name);
    if (ret == 0) {
        printf("\nData hidden successfully inside the input image file.");
    }
    else {
        printf("\nError in hiding data inside the input image file.");
        return -1;
    }

    // extract data from the image file
    ret = extractData(input_image_name, output_file_name);
    if (ret == 0) {
        printf("\nData extracted successfully from the input image file.");
    }
    else {
        printf("\nError in extracting data from the input image file.");
        return -1;
    }

    return 0;
}