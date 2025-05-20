//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/nameser.h>

#define PORT 8080

struct word {
    char *word;
    int count;
};

int main(int argc, char *argv[]) {
    int sock, cli_sock;
    struct sockaddr_in server_addr, cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    char buffer[1024];
    struct word *words;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        exit(1);
    }

    // Create a client socket
    cli_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (cli_sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set up the client address
    memset(&cli_addr, 0, sizeof(cli_addr));
    cli_addr.sin_family = AF_INET;
    cli_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &cli_addr.sin_addr);

    // Send the list of words to the server
    words = (struct word *)malloc(sizeof(struct word) * 10);
    for (int i = 0; i < 10; i++) {
        words[i].word = argv[i];
        words[i].count = 1;
    }
    send(sock, words, sizeof(struct word) * 10, 0);

    // Receive the word count from the server
    recv(sock, buffer, 1024, 0);
    buffer[1024] = 0; // null-terminate the string
    char *words_str = buffer;
    char *token;
    int i = 0;
    while ((token = strtok_r(words_str, " ", &i)) != NULL) {
        printf("%s: %d\n", token, atoi(token));
    }

    // Close the sockets
    close(sock);
    close(cli_sock);
    free(words);
    return 0;
}