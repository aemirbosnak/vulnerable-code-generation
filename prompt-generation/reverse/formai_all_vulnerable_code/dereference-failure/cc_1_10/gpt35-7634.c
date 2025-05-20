//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_RDM_MASK 4
#define MAX_RDM_VALUE 256
#define MAX_MESSAGE_LEN 1000

// function to generate random masks
void generate_masks(int num_masks, int masks[num_masks][num_masks], int max_value) {
    for(int i=0; i<num_masks; i++) {
        for(int j=0; j<num_masks; j++) {
            masks[i][j] = rand() % max_value;
        }
    }
}

// function to get the binary representation of a char
char* get_binary(char c) {
    char* binary = (char*) malloc(sizeof(char) * 8);
    for(int i=7; i>=0; i--) {
        binary[i] = (c & 1) ? '1' : '0';
        c >>= 1;
    }
    return binary;
}

// function to encrypt the message with the random masks
char* encrypt_message(char* message, int masks[MAX_RDM_MASK][MAX_RDM_MASK], int num_masks) {
    int message_len = strlen(message);
    char* encrypted_message = (char*) malloc(sizeof(char) * (message_len * 8 * num_masks + 1));

    int index = 0;
    for(int i=0; i<message_len; i++) {
        char* binary = get_binary(message[i]);

        for(int j=0; j<8; j++) {
            for(int k=0; k<num_masks; k++) {
                int sum = 0;
                for(int l=0; l<num_masks; l++) {
                    sum += masks[k][l] * binary[l];
                }
                encrypted_message[index++] = ((sum % 2) + '0');
            }
        }
    }

    encrypted_message[index] = '\0';
    return encrypted_message;
}

// function to decrypt the encrypted message with the random masks
char* decrypt_message(char* encrypted_message, int masks[MAX_RDM_MASK][MAX_RDM_MASK], int num_masks) {
    int message_len = strlen(encrypted_message) / (8 * num_masks);
    char* decrypted_message = (char*) malloc(sizeof(char) * (message_len + 1));

    int index = 0;
    for(int i=0; i<message_len; i++) {
        char message_char = 0;
        for(int j=0; j<8; j++) {
            int sum = 0;
            for(int k=0; k<num_masks; k++) {
                sum += masks[k][j] * (encrypted_message[index++] - '0');
            }
            message_char |= ((sum % 2) << (7-j));
        }
        decrypted_message[i] = message_char;
    }

    decrypted_message[message_len] = '\0';
    return decrypted_message;
}

// function to print a mask
void print_mask(int mask[MAX_RDM_MASK][MAX_RDM_MASK], int num_masks) {
    for(int i=0; i<num_masks; i++) {
        for(int j=0; j<num_masks; j++) {
            printf("%d ", mask[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));

    char message[MAX_MESSAGE_LEN];
    int num_masks;

    printf("Enter the message you want to encrypt: ");
    fgets(message, MAX_MESSAGE_LEN, stdin);
    message[strlen(message)-1] = '\0';

    printf("Enter the number of random masks to generate (max %d): ", MAX_RDM_MASK);
    scanf("%d", &num_masks);

    int masks[MAX_RDM_MASK][MAX_RDM_MASK];
    generate_masks(num_masks, masks, MAX_RDM_VALUE);

    char* encrypted_message = encrypt_message(message, masks, num_masks);
    printf("Encrypted message: %s\n", encrypted_message);

    char* decrypted_message = decrypt_message(encrypted_message, masks, num_masks);
    printf("Decrypted message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}