//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <pthread.h>

// Function to convert an image to ASCII art
void convertImageToASCII(char* imagePath) {
    // Open the image file
    FILE* imageFile = fopen(imagePath, "r");
    if (imageFile == NULL) {
        fprintf(stderr, "Error opening image file\n");
        return;
    }

    // Read the image data
    char buffer[1024];
    int numBytesRead = fread(buffer, sizeof(char), sizeof(buffer), imageFile);

    // Convert the image data to ASCII art
    char* asciiArt = (char*)malloc(numBytesRead * 2);
    for (int i = 0; i < numBytesRead; i++) {
        char charCode = buffer[i];
        if (charCode >= 32 && charCode <= 126) {
            asciiArt[i * 2] = charCode;
            asciiArt[i * 2 + 1] = '\n';
        } else {
            asciiArt[i * 2] = '.';
            asciiArt[i * 2 + 1] = '.';
        }
    }

    // Write the ASCII art to the standard output
    printf("%s", asciiArt);

    // Clean up resources
    free(asciiArt);
    fclose(imageFile);
}

// Function to handle client connections
void* handleClientConnection(void* clientSocket) {
    // Get the client socket from the argument
    int clientSocketFD = *(int*)clientSocket;

    // Receive the image path from the client
    char buffer[1024];
    int numBytesRead = recv(clientSocketFD, buffer, sizeof(buffer), 0);
    if (numBytesRead < 0) {
        fprintf(stderr, "Error receiving image path from client\n");
        return NULL;
    }

    // Convert the image to ASCII art
    convertImageToASCII(buffer);

    // Close the client socket
    close(clientSocketFD);

    return NULL;
}

// Main function
int main(int argc, char* argv[]) {
    // Initialize variables
    int serverSocketFD, clientSocketFD;
    struct sockaddr_in serverAddr, clientAddr;
    int addrLen = sizeof(struct sockaddr_in);

    // Create a socket
    serverSocketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocketFD < 0) {
        fprintf(stderr, "Error creating socket\n");
        return 1;
    }

    // Set socket options
    int optVal = 1;
    if (setsockopt(serverSocketFD, SOL_SOCKET, SO_REUSEADDR, &optVal, sizeof(int)) < 0) {
        fprintf(stderr, "Error setting socket options\n");
        return 1;
    }

    // Set socket address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8080);

    // Bind the socket to the address
    if (bind(serverSocketFD, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr_in)) < 0) {
        fprintf(stderr, "Error binding socket to address\n");
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocketFD, 5) < 0) {
        fprintf(stderr, "Error listening for connections\n");
        return 1;
    }

    // Create a thread pool with 5 threads
    pthread_t threadID[5];
    pthread_attr_t threadAttr;
    pthread_attr_init(&threadAttr);
    pthread_attr_setdetachstate(&threadAttr, PTHREAD_CREATE_JOINABLE);
    pthread_attr_setscope(&threadAttr, PTHREAD_SCOPE_SYSTEM);

    // Create threads
    for (int i = 0; i < 5; i++) {
        pthread_create(&threadID[i], &threadAttr, handleClientConnection, &serverSocketFD);
    }

    // Wait for all threads to complete
    for (int i = 0; i < 5; i++) {
        pthread_join(threadID[i], NULL);
    }

    // Clean up resources
    close(serverSocketFD);
    pthread_attr_destroy(&threadAttr);

    return 0;
}