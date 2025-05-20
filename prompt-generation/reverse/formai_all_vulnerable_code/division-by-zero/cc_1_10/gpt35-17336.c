//FormAI DATASET v1.0 Category: File Encyptor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(char* filename, char** buffer, int* length) {
    FILE* file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    *length = ftell(file);
    fseek(file, 0, SEEK_SET);
    *buffer = (char*)malloc(*length);
    fread(*buffer, 1, *length, file);
    fclose(file);
}

void write_file(char* filename, char* buffer, int length) {
    FILE* file = fopen(filename, "wb");
    fwrite(buffer, 1, length, file);
    fclose(file);
}

void encrypt(char* data, char* key, int length) {
    int key_length = strlen(key);
    for (int i = 0; i < length; i++) {
        data[i] ^= key[i % key_length];
    }
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <filename> <key_length> <num_players>\n", argv[0]);
        return 1;
    }
    char* filename = argv[1];
    int key_length = atoi(argv[2]);
    int num_players = atoi(argv[3]);
    char* buffer;
    int length;
    read_file(filename, &buffer, &length);
    char* key = (char*)malloc(key_length + 1);
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 256;
    }
    key[key_length] = '\0';
    encrypt(buffer, key, length);
    // split the encrypted buffer into chunks
    int chunk_size = length / num_players;
    int leftover = length % num_players;
    int* chunk_lengths = (int*)malloc(num_players * sizeof(int));
    for (int i = 0; i < num_players; i++) {
        chunk_lengths[i] = chunk_size;
        if (i < leftover) {
            chunk_lengths[i]++;
        }
    }
    char** chunks = (char**)malloc(num_players * sizeof(char*));
    char* offset = buffer;
    for (int i = 0; i < num_players; i++) {
        chunks[i] = offset;
        offset += chunk_lengths[i];
    }
    // distribute the encrypted chunks to each player and wait for decryption
    for (int i = 0; i < num_players; i++) {
        // send the chunk to player i (network code here)
    }
    for (int i = 0; i < num_players; i++) {
        // wait for player i to send back their decrypted chunk (network code here)
    }
    // merge the decrypted chunks into a single buffer and write to file
    char* decrypted = (char*)malloc(length);
    offset = decrypted;
    for (int i = 0; i < num_players; i++) {
        memcpy(offset, chunks[i], chunk_lengths[i]);
        offset += chunk_lengths[i];
    }
    encrypt(decrypted, key, length);
    write_file("out.bin", decrypted, length);
    free(buffer);
    free(key);
    free(chunk_lengths);
    free(chunks);
    free(decrypted);
    return 0;
}