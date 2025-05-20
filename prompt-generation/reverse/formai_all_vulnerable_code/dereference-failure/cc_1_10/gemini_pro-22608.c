//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <openssl/aes.h>

#define BUF_SIZE 1024
#define KEY_SIZE 32
#define IV_SIZE 16

char key[KEY_SIZE];
char iv[IV_SIZE];

void encrypt_message(char *message, char *encrypted_message, size_t message_length) {
    AES_KEY aes_key;
    AES_set_encrypt_key((unsigned char *)key, 256, &aes_key);
    AES_cbc_encrypt((unsigned char *)message, (unsigned char *)encrypted_message, message_length, &aes_key, (unsigned char *)iv, AES_ENCRYPT);
}

void decrypt_message(char *encrypted_message, char *message, size_t message_length) {
    AES_KEY aes_key;
    AES_set_decrypt_key((unsigned char *)key, 256, &aes_key);
    AES_cbc_encrypt((unsigned char *)encrypted_message, (unsigned char *)message, message_length, &aes_key, (unsigned char *)iv, AES_DECRYPT);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <port> <key>", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    strncpy(key, argv[2], KEY_SIZE);

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        close(server_socket);
        return 1;
    }

    client_addr_size = sizeof(client_addr);
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        char message[BUF_SIZE];
        int message_length;

        while ((message_length = recv(client_socket, message, BUF_SIZE, 0)) > 0) {
            char encrypted_message[BUF_SIZE];
            encrypt_message(message, encrypted_message, message_length);

            send(client_socket, encrypted_message, message_length, 0);
        }

        if (message_length == -1) {
            perror("recv");
        }

        close(client_socket);
    }

    close(server_socket);

    return 0;
}