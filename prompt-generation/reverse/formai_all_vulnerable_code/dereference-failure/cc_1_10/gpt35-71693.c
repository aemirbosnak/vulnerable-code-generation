//FormAI DATASET v1.0 Category: Image Steganography ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

// Structure to store RGB values of image pixels
typedef struct RGB{
    unsigned int red : 8;
    unsigned int green : 8;
    unsigned int blue : 8;
}RGB;

// Function to get the binary equivalent of a decimal number
void decToBinary(int num, int binary[], int size){
    int mask = 1;
    for(int i=size-1;i>=0;i--){
        if(num & mask)
            binary[i] = 1;
        else
            binary[i] = 0;
        mask = mask << 1;
    }
}

// Function to get the decimal equivalent of a binary number
int binaryToDec(int binary[], int size){
    int res = 0, base = 1;
    for(int i=size-1;i>=0;i--){
        res += (binary[i] * base);
        base *= 2;
    }
    return res;
}

// Function to hide the message in the image
void hideMessage(RGB *image, char message[]){
    int message_len = strlen(message);
    int binary_message[8*message_len];
    for(int i=0;i<message_len;i++){
        decToBinary(message[i], binary_message+(i*8), 8);
    }
    for(int i=0;i<8*message_len;i+=2){
        image[i/2].red &= 0xFE;
        image[i/2].red |= binary_message[i];
        image[i/2].green &= 0xFE;
        image[i/2].green |= binary_message[i+1];
    }
}

// Function to retrieve the hidden message from the image
char *retrieveMessage(RGB *image, int num_pixels){
    int binary_message[8*num_pixels];
    for(int i=0;i<8*num_pixels;i+=2){
        binary_message[i] = image[i/2].red & 1;
        binary_message[i+1] = image[i/2].green & 1;
    }
    char *message = (char*)malloc(num_pixels);
    for(int i=0;i<num_pixels;i++){
        message[i] = binaryToDec(binary_message+(i*8), 8);
    }
    return message;
}

int main(){
    // Image size is assumed to be 256x256 pixels
    int num_pixels = 256 * 256;
    RGB *image = (RGB*)malloc(num_pixels*sizeof(RGB));
    
    // Initialize image with some random RGB values
    for(int i=0;i<num_pixels;i++){
        image[i].red = rand()%256;
        image[i].green = rand()%256;
        image[i].blue = rand()%256;
    }
    
    // Hide a message in the image
    char message[] = "Hello, this is a secret message!";
    hideMessage(image, message);
    
    // Retrieve the hidden message from the image
    char *retrieved_message = retrieveMessage(image, num_pixels);
    printf("Retrieved Message: %s", retrieved_message);
    
    // Free memory
    free(image);
    free(retrieved_message);
    
    return 0;
}