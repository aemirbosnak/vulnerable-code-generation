//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/sha.h>
#include <openssl/aes.h>

#define PORT 8080
#define KEY_SIZE 32
#define BLOCK_SIZE 16

typedef struct {
    int sockfd;
    char *name;
    char *key;
} player;

player *players[2];

unsigned char *sha256(const unsigned char *data, size_t len) {
    unsigned char *hash = malloc(SHA256_DIGEST_LENGTH);
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, data, len);
    SHA256_Final(hash, &ctx);
    return hash;
}

unsigned char *aes_encrypt(const unsigned char *data, size_t len, const unsigned char *key) {
    unsigned char *ciphertext = malloc(len + BLOCK_SIZE);
    AES_KEY aes_key;
    AES_set_encrypt_key(key, KEY_SIZE * 8, &aes_key);
    AES_encrypt(data, ciphertext, &aes_key);
    return ciphertext;
}

unsigned char *aes_decrypt(const unsigned char *data, size_t len, const unsigned char *key) {
    unsigned char *plaintext = malloc(len + BLOCK_SIZE);
    AES_KEY aes_key;
    AES_set_decrypt_key(key, KEY_SIZE * 8, &aes_key);
    AES_decrypt(data, plaintext, &aes_key);
    return plaintext;
}

void send_message(player *sender, player *receiver, const char *message) {
    unsigned char *plaintext = (unsigned char *)message;
    size_t plaintext_len = strlen(message);

    unsigned char *hash = sha256(plaintext, plaintext_len);
    unsigned char *ciphertext = aes_encrypt(plaintext, plaintext_len, (unsigned char *)sender->key);

    char *buffer = malloc(plaintext_len + SHA256_DIGEST_LENGTH + BLOCK_SIZE);
    memcpy(buffer, ciphertext, plaintext_len + BLOCK_SIZE);
    memcpy(buffer + plaintext_len + BLOCK_SIZE, hash, SHA256_DIGEST_LENGTH);

    send(receiver->sockfd, buffer, plaintext_len + SHA256_DIGEST_LENGTH + BLOCK_SIZE, 0);
}

void receive_message(player *receiver) {
    char *buffer = malloc(1024);
    int len = recv(receiver->sockfd, buffer, 1024, 0);

    unsigned char *ciphertext = buffer;
    size_t ciphertext_len = len - SHA256_DIGEST_LENGTH;
    unsigned char *hash = buffer + ciphertext_len;

    unsigned char *plaintext = aes_decrypt(ciphertext, ciphertext_len, (unsigned char *)receiver->key);
    size_t plaintext_len = strlen((char *)plaintext);

    unsigned char *new_hash = sha256(plaintext, plaintext_len);

    if (memcmp(hash, new_hash, SHA256_DIGEST_LENGTH) == 0) {
        printf("%s: %s\n", receiver->name, plaintext);
    } else {
        printf("Message corrupted!\n");
    }
}

int main() {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    if (listen(server_sockfd, 2) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    while (1) {
        int len = sizeof(client_addr);
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        char *name = malloc(100);
        recv(client_sockfd, name, 100, 0);

        char *key = malloc(KEY_SIZE);
        recv(client_sockfd, key, KEY_SIZE, 0);

        player *player = malloc(sizeof(player));
        player->sockfd = client_sockfd;
        player->name = name;
        player->key = key;

        if (players[0] == NULL) {
            players[0] = player;
        } else {
            players[1] = player;
            send_message(players[0], players[1], "Welcome to the game!");
            send_message(players[1], players[0], "Welcome to the game!");
        }

        while (1) {
            receive_message(players[0]);
            receive_message(players[1]);
        }

        close(client_sockfd);
    }

    close(server_sockfd);

    return EXIT_SUCCESS;
}