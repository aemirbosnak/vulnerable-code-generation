//FormAI DATASET v1.0 Category: Image Steganography ; Style: cheerful
#include<stdio.h>

int main(){
    printf("Welcome to C Image Steganography program!\n");
    printf("This program allows you to hide a secret message inside an image.\nLet's get started!\n");

    // Ask user for image name/path
    char image_path[100];
    printf("Enter the name/path of the image you would like to use: ");
    scanf("%s", image_path);

    // Open image file
    FILE *image = fopen(image_path, "rb");

    // Check if file exists
    if(image == NULL){
        printf("Error: File not found.\n");
        return 0;
    }

    // Read image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image);

    // Check if image is valid
    if(header[0] != 'B' || header[1] != 'M'){
        printf("Error: Invalid image format.\n");
        fclose(image);
        return 0;
    }

    // Calculate image size
    int image_size = *(int*)&header[2];

    // Allocate memory for image data
    unsigned char *image_data = (unsigned char*)malloc(image_size);

    // Read image data
    fread(image_data, sizeof(unsigned char), image_size, image);

    // Ask user for secret message
    char message[100];
    printf("Enter the message you would like to hide in the image: ");
    scanf("%s", message);

    // Loop through pixels and hide message
    int i,j,k=0;
    for(i=54;i<image_size;i+=3){
        if(k>=strlen(message)){
            break;
        }
        image_data[i] = message[k++];
    }

    // Save new image with hidden message
    FILE *new_image = fopen("new_image.bmp", "wb");
    fwrite(header, sizeof(unsigned char), 54, new_image);
    fwrite(image_data, sizeof(unsigned char), image_size, new_image);

    // Close files and free memory
    fclose(image);
    fclose(new_image);
    free(image_data);

    printf("Success! Your message has been hidden in the image. Check out the new_image.bmp file.\n");
    return 0;
}