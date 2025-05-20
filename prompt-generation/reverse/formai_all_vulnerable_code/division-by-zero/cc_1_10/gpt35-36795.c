//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LEN 1024

// Function to encode message with the key
void encode_message(char *message, char *key)
{
    int msg_len = strlen(message);
    int key_len = strlen(key);

    // Apply the XOR operation with the key to each character in the message
    for (int i = 0; i < msg_len; i++)
    {
        message[i] ^= key[i % key_len];
    }
}

// Function to decode message with the key
void decode_message(char *message, char *key)
{
	encode_message(message, key); 
}

int main()
{
    char message[MAX_MESSAGE_LEN];
    char key[MAX_MESSAGE_LEN];

    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_LEN, stdin);

    printf("Enter watermark key: ");
    fgets(key, MAX_MESSAGE_LEN, stdin);

    // Remove newline characters from message and key
    message[strcspn(message, "\n")] = 0; 
    key[strcspn(key, "\n")] = 0; 

    // Encode message with the key
    encode_message(message, key);

    printf("\nEncoded Message: %s\n", message);

    // Decode message with the key
    decode_message(message, key);

    printf("\nDecoded Message: %s\n", message);

    return 0;
}