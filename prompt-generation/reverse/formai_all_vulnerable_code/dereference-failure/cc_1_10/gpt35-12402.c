//FormAI DATASET v1.0 Category: Image Steganography ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function to hide the message in the image
void hide_message(unsigned char* image_data, char* message, int message_length)
{
    // Get the number of bytes in the image data
    int num_bytes = sizeof(image_data) / sizeof(unsigned char);
    
    // Check if message can be hidden inside image
    if (num_bytes < (message_length * 8))
    {
        printf("Error: Message is too large to be hidden in the image.\n");
        return;
    }
    
    // Loop through the message and hide each bit in the image data
    for (int i = 0; i < message_length; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // Get the bit to hide from the message
            unsigned char bit = (message[i] >> j) & 1;
            
            // Modify the least significant bit of the image data
            if (bit == 0)
            {
                image_data[i*8 + j] &= 0xfe;
            }
            else
            {
                image_data[i*8 + j] |= 0x01;
            }
        }
    }
    
    // Print success message
    printf("Message has been successfully hidden in the image.\n");
}

// Function to reveal the hidden message in the image
void reveal_message(unsigned char* image_data, int message_length)
{
    // Loop through the message and retrieve each hidden bit from the image data
    char message[message_length + 1];
    for (int i = 0; i < message_length; i++)
    {
        message[i] = 0;
        for (int j = 0; j < 8; j++)
        {
            // Get the hidden bit from the image data
            unsigned char bit = image_data[i*8 + j] & 1;
            
            // Store the bit in the message
            message[i] |= (bit << j);
        }
    }
    message[message_length] = '\0'; // Add terminating character to message
    
    // Print the revealed message
    printf("The hidden message is: %s\n", message);
}

int main()
{
    // Read image file into memory
    FILE* image_file = fopen("image.bmp", "rb");
    if (image_file == NULL)
    {
        printf("Error: Unable to open image file.\n");
        return 1;
    }
    fseek(image_file, 0, SEEK_END);
    int image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);
    unsigned char* image_data = malloc(image_size);
    fread(image_data, 1, image_size, image_file);
    fclose(image_file);
    
    // Hide message in image
    char* message = "Hello, World!";
    hide_message(image_data, message, 13);
    
    // Reveal message from image
    reveal_message(image_data, 13);
    
    // Write modified image data to file
    FILE* modified_image_file = fopen("modified_image.bmp", "wb");
    fwrite(image_data, 1, image_size, modified_image_file);
    fclose(modified_image_file);
    
    // Free memory used for image data
    free(image_data);
    
    return 0;
}