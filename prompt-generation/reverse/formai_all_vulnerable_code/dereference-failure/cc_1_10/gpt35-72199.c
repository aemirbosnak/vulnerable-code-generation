//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MESSAGE_SIZE 100
#define SEED_TIME 1234

// Function to generate a random sequence of bytes based on the seed
unsigned char* generateRandomSequence(int size, long int seed) {
    srand(seed);

    unsigned char* sequence = (unsigned char*) malloc(sizeof(unsigned char) * size);
    for(int i = 0; i < size; i++) {
        sequence[i] = (unsigned char) (rand() % 256);
    }

    return sequence;
}

// Function to mix two sequences randomly
unsigned char* mixSequences(unsigned char* sequence1, unsigned char* sequence2, int size, long int seed) {
    srand(seed);

    unsigned char* mixed_sequence = (unsigned char*) malloc(sizeof(unsigned char) * size);
    for(int i = 0; i < size; i++) {
        if(rand() % 2 == 0) {
            mixed_sequence[i] = sequence1[i];
        } else {
            mixed_sequence[i] = sequence2[i];
        }
    }

    return mixed_sequence;
}

// Function to create a digital watermark for a given message
unsigned char* createWatermark(char* message, unsigned char* secret_key, long int seed) {
    int message_length = strlen(message);
    int key_length = SEED_TIME % message_length + MESSAGE_SIZE;
    int sequence_size = message_length * key_length;

    unsigned char* message_sequence = (unsigned char*) malloc(sizeof(unsigned char) * message_length);
    for(int i = 0; i < message_length; i++) {
        message_sequence[i] = (unsigned char) message[i];
    }

    unsigned char* key_sequence = generateRandomSequence(key_length, SEED_TIME);
    unsigned char* mixed_sequence = mixSequences(message_sequence, key_sequence, sequence_size, seed);

    unsigned char* watermark = (unsigned char*) malloc(sizeof(unsigned char) * sequence_size);
    for(int i = 0; i < sequence_size; i++) {
        watermark[i] = mixed_sequence[i] ^ secret_key[i % MESSAGE_SIZE];
    }

    free(message_sequence);
    free(key_sequence);
    free(mixed_sequence);

    return watermark;
}

// Function to extract a message from a digital watermark
char* extractMessage(unsigned char* watermark, unsigned char* secret_key, long int seed) {
    int key_length = SEED_TIME % MESSAGE_SIZE + MESSAGE_SIZE;
    int watermark_length = strlen((char*) watermark);
    int sequence_size = watermark_length * key_length;

    unsigned char* mixed_sequence = (unsigned char*) malloc(sizeof(unsigned char) * sequence_size);
    for(int i = 0; i < sequence_size; i++) {
        mixed_sequence[i] = watermark[i] ^ secret_key[i % MESSAGE_SIZE];
    }

    unsigned char* key_sequence = generateRandomSequence(key_length, SEED_TIME);
    unsigned char* message_sequence = mixSequences(mixed_sequence, key_sequence, watermark_length, seed);

    char* message = (char*) malloc(sizeof(char) * (watermark_length + 1));
    for(int i = 0; i < watermark_length; i++) {
        message[i] = (char) message_sequence[i];
    }
    message[watermark_length] = '\0';

    free(key_sequence);
    free(mixed_sequence);
    free(message_sequence);

    return message;
}

// Sample usage of the digital watermarking functions
int main() {
    char message[] = "The future belongs to those who prepare for it today. - Malcolm X";
    unsigned char secret_key[] = "t#&5K9@!";

    unsigned char* watermark = createWatermark(message, secret_key, 5678);
    printf("Watermark: %s\n", watermark);

    char* extracted_message = extractMessage(watermark, secret_key, 5678);
    printf("Extracted message: %s\n", extracted_message);

    free(watermark);
    free(extracted_message);

    return 0;
}