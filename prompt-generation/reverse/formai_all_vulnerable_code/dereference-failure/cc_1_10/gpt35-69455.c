//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MESSAGE_SIZE 100  //Maximum size for the message
#define KEY_SIZE 16       //Size of the key used for encryption
#define BLOCK_SIZE 16     //Size of the block used for encryption

//function to perform the XOR operation
void get_xor(unsigned char *message_block, unsigned char *key_block, unsigned char *result_block) {
    for(int i=0;i<BLOCK_SIZE;i++) {
        result_block[i] = message_block[i] ^ key_block[i];  //XOR operation on each byte
    }
}

int main() {
    unsigned char message[MESSAGE_SIZE], key[KEY_SIZE], encrypted_message[MESSAGE_SIZE], decrypted_message[MESSAGE_SIZE];
    unsigned char message_block[BLOCK_SIZE], key_block[BLOCK_SIZE], encrypted_block[BLOCK_SIZE], decrypted_block[BLOCK_SIZE];
    int message_length, num_blocks, num_padding_bytes, i, j;

    //Getting the message from the user
    printf("Enter the message: ");
    fgets(message, MESSAGE_SIZE, stdin);
    message_length = strlen(message);

    //Getting the key from the user
    printf("Enter the key: ");
    fgets(key, KEY_SIZE, stdin);

    //Padding the message to be a multiple of BLOCK_SIZE bytes
    num_padding_bytes = BLOCK_SIZE - (message_length % BLOCK_SIZE);
    for(i=0;i<num_padding_bytes;i++) {
        message[message_length+i] = num_padding_bytes;
    }
    message_length += num_padding_bytes;

    //Encrypting the message
    num_blocks = message_length / BLOCK_SIZE;
    for(i=0;i<num_blocks;i++) {
        memcpy(message_block, message+i*BLOCK_SIZE, BLOCK_SIZE);  //Copying a block of size BLOCK_SIZE to message_block
        memcpy(key_block, key+(i%KEY_SIZE)*BLOCK_SIZE, BLOCK_SIZE);  //Repeating the key to make it a suitable size for encryption
        get_xor(message_block, key_block, encrypted_block);  //Performing the XOR operation to get encrypted block
        memcpy(encrypted_message+i*BLOCK_SIZE, encrypted_block, BLOCK_SIZE);  //Copying the encrypted block to encrypted_message
    }
    encrypted_message[message_length] = 0; //Null terminating the encrypted message

    //Decrypting the message
    for(i=0;i<num_blocks;i++) {
        memcpy(encrypted_block, encrypted_message+i*BLOCK_SIZE, BLOCK_SIZE);  //Copying a block of size BLOCK_SIZE to encrypted_block
        memcpy(key_block, key+(i%KEY_SIZE)*BLOCK_SIZE, BLOCK_SIZE); //Repeating the key to make it a suitable size for decryption
        get_xor(encrypted_block, key_block, decrypted_block); //Performing the XOR operation to get decrypted block
        memcpy(decrypted_message+i*BLOCK_SIZE, decrypted_block, BLOCK_SIZE);  //Copying the decrypted block to decrypted_message
    }
    for(i=num_padding_bytes;i>0;i--) {
        if(decrypted_message[message_length-i]!=i) {
            printf("Incorrect padding\n");  //Checking for correct padding
            return 0;
        }
    }
    decrypted_message[message_length-num_padding_bytes] = 0; //Null terminating the decrypted message

    //Printing the encrypted and decrypted messages
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}