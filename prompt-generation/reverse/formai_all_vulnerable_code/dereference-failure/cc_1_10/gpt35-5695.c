//FormAI DATASET v1.0 Category: Image Steganography ; Style: energetic
#include<stdio.h>
#include<string.h>

int main(){
    char image_path[50];
    printf("Enter the image file path: ");
    scanf("%s", &image_path); //Input image file path
    FILE* fptr_img = fopen(image_path, "rb"); 
    if(fptr_img == NULL){ //Check if image file exists
        printf("Error opening file!");
        return 1;
    }
    char message[500];
    printf("Enter the message you want to hide: ");
    scanf("%s", &message); //Input message to be hidden
    char stego_image_path[50];
    printf("Enter the file path for the stego image: ");
    scanf("%s", &stego_image_path); //Input file path to save stego image
    FILE* fptr_stego = fopen(stego_image_path, "wb");
    int image_size = 0, image_width = 0, image_height = 0;
    fseek(fptr_img, 18, SEEK_SET); //Set the file pointer to point to image size information
    fread(&image_width, sizeof(int), 1, fptr_img); //Read the image width information from file
    fread(&image_height, sizeof(int), 1, fptr_img); //Read the image height information from file
    image_size = 3 * image_width * image_height; //Calculate the image size in bytes
    fseek(fptr_img, 0, SEEK_SET); //Set the file pointer back to the beginning of the file
    char* image_data = (char*)malloc(image_size); //Allocate memory to store image data
    fread(image_data, sizeof(char), image_size, fptr_img); //Read image data from file
    fclose(fptr_img); //Close the image file
    int message_size = strlen(message); //Calculate message size in bytes
    int stego_byte = 0;
    for(int i = 0; i < message_size; i++){
        char current_char = message[i];
        for(int j = 0; j < 8; j++){ //Loop through bits in character
            if((current_char >> j) & 1){ //If bit is 1
                if(image_data[stego_byte] % 2 == 0){ //If current pixel value is even
                    image_data[stego_byte] += 1; //Change pixel value to odd
                }
            }else{ //If bit is 0
                if(image_data[stego_byte] % 2 != 0){ //If current pixel value is odd
                    image_data[stego_byte] -= 1; //Change pixel value to even
                }
            }
            stego_byte += 1; //Move to next pixel
        }
    }
    fwrite(image_data, sizeof(char), image_size, fptr_stego); //Write stego image data to file
    fclose(fptr_stego); //Close the stego image file
    printf("Stegonographic hide image created successfully!\n");
    return 0;
}