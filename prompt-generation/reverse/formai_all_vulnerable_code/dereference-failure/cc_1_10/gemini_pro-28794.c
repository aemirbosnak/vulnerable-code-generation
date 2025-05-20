//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER 1024
#define KEY_LENGTH 16

char key[KEY_LENGTH];
char buffer[MAX_BUFFER];

void generate_key() {
    srand(time(NULL));
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char *plaintext, char *ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % KEY_LENGTH];
    }
    ciphertext[strlen(plaintext)] = '\0';
}

void decrypt(char *ciphertext, char *plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % KEY_LENGTH];
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip address> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Generate a random key
    generate_key();

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serveraddr.sin_addr) != 1) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the key to the server
    if (send(sockfd, key, KEY_LENGTH, 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the ciphertext from the server
    if (recv(sockfd, buffer, MAX_BUFFER, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Decrypt the ciphertext
    char plaintext[MAX_BUFFER];
    decrypt(buffer, plaintext);

    // Print the plaintext
    printf("%s\n", plaintext);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}