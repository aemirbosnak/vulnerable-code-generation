//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void generate_RSA_keys(RSA **publicKey, RSA **privateKey) {
    *privateKey = RSA_generate_key(2048, RSA_F4, NULL, NULL);
    BIO *bp_public = BIO_new(BIO_s_mem());
    BIO *bp_private = BIO_new(BIO_s_mem());

    PEM_write_bio_RSAPublicKey(bp_public, *privateKey);
    PEM_write_bio_RSAPrivateKey(bp_private, *privateKey, NULL, NULL, 0, NULL, NULL);

    size_t public_len = BIO_ctrl_pending(bp_public);
    size_t private_len = BIO_ctrl_pending(bp_private);

    char *publicKeyStr = malloc(public_len + 1);
    char *privateKeyStr = malloc(private_len + 1);

    BIO_read(bp_public, publicKeyStr, public_len);
    BIO_read(bp_private, privateKeyStr, private_len);

    publicKeyStr[public_len] = '\0';
    privateKeyStr[private_len] = '\0';

    *publicKey = PEM_read_bio_RSAPublicKey(bp_public, NULL, NULL, NULL);
    
    BIO_free_all(bp_public);
    BIO_free_all(bp_private);
    free(publicKeyStr);
    free(privateKeyStr);
}

void encrypt_message(RSA *publicKey, const char *message, unsigned char *encrypted) {
    RSA_public_encrypt(strlen(message) + 1, (unsigned char *)message, encrypted, publicKey, RSA_PKCS1_OAEP_PADDING);
}

void decrypt_message(RSA *privateKey, unsigned char *encrypted, char *decrypted) {
    RSA_private_decrypt(RSA_size(privateKey), encrypted, (unsigned char *)decrypted, privateKey, RSA_PKCS1_OAEP_PADDING);
}

void server_function() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1, addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options error");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    RSA *publicKey, *privateKey;
    generate_RSA_keys(&publicKey, &privateKey);

    // Send public key to client
    BIO *bp = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPublicKey(bp, publicKey);
    size_t publicKeyLen = BIO_ctrl_pending(bp);
    char *publicKeyStr = malloc(publicKeyLen + 1);
    BIO_read(bp, publicKeyStr, publicKeyLen);
    publicKeyStr[publicKeyLen] = '\0';

    send(new_socket, publicKeyStr, publicKeyLen, 0);
    printf("Public key sent to client.\n");

    // Encrypt a message
    unsigned char encrypted[256];
    const char *message = "Hello, encrypted world!";
    encrypt_message(publicKey, message, encrypted);
    send(new_socket, encrypted, sizeof(encrypted), 0);
    printf("Encrypted message sent to client.\n");

    free(publicKeyStr);
    BIO_free_all(bp);
    RSA_free(publicKey);
    RSA_free(privateKey);
    close(new_socket);
}

void client_function() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    unsigned char buffer[BUFFER_SIZE] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    // Receive public key
    int valread = read(sock, buffer, BUFFER_SIZE);
    buffer[valread] = '\0';
    printf("Received public key: \n%s\n", buffer);

    // Receive encrypted message
    unsigned char encrypted[256];
    read(sock, encrypted, sizeof(encrypted));
    printf("Received encrypted message.\n");

    // Normally, a client would send a decryption request with the private key here.
    // In this mock-up, we just output the received message.

    close(sock);
}

int main(int argc, char const *argv[]) {
    if (fork() == 0) {
        // Run server
        server_function();
    } else {
        // Run client
        sleep(1); // Ensure server starts first
        client_function();
    }

    return 0;
}