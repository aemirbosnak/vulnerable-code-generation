//GEMINI-pro DATASET v1.0 Category: Networking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Did you know you can use macros to make your code more readable?
#define SOCKET_ERROR ((int)-1)
#define BUFFER_SIZE 1024

int main(int argc, char** argv) {

    // Gasp! I can't believe you didn't specify a host!
    if (argc < 2) {
        printf("You forgot to tell me the host!\n");
        return EXIT_FAILURE;
    }

    // Whoa, that's a big port number!
    if (argc < 3) {
        printf("I'm not sure what port that is!\n");
        return EXIT_FAILURE;
    }

    // Look at all these file descriptors!
    int fileDescriptors[2];

    // Oh no! socket() failed!
    if ((fileDescriptors[0] = socket(AF_INET, SOCK_STREAM, 0)) == SOCKET_ERROR) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }

    // Wait, what's this sockaddr_in structure?
    struct sockaddr_in serverAddress;

    // Server address? Is that a thing?
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(atoi(argv[2]));

    // Inet_addr? What sorcery is this?
    if (inet_pton(AF_INET, argv[1], &serverAddress.sin_addr) <= 0) {
        perror("inet_pton() failed");
        return EXIT_FAILURE;
    }

    // Connect? But I don't know anyone!
    if (connect(fileDescriptors[0], (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        perror("connect() failed");
        return EXIT_FAILURE;
    }

    // I can't believe you're sending me a message!
    char buffer[BUFFER_SIZE];
    strcpy(buffer, "Hello from the client!");

    // Send? This is so exciting!
    if (send(fileDescriptors[0], buffer, strlen(buffer), 0) == SOCKET_ERROR) {
        perror("send() failed");
        return EXIT_FAILURE;
    }

    // But wait, there's more!
    memset(buffer, 0, BUFFER_SIZE);

    // Receive? Oh my, this is getting intense!
    if (recv(fileDescriptors[0], buffer, BUFFER_SIZE, 0) == SOCKET_ERROR) {
        perror("recv() failed");
        return EXIT_FAILURE;
    }

    // What's this? A message from the server?
    printf("Server says: %s\n", buffer);

    // Close? But I don't want to say goodbye!
    close(fileDescriptors[0]);

    return EXIT_SUCCESS;
}