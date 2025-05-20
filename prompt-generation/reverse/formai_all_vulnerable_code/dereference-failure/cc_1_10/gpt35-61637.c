//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXSIZE 1024

/*
 * Connects to the IMAP server using the given IP address and port number
 */
int connectToServer(char* ip, int port) {
    struct sockaddr_in serverAddress;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    serverAddress.sin_addr.s_addr = inet_addr(ip);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);

    if (connect(sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        printf("Error connecting to server\n");
        return -1;
    }

    printf("Successfully connected to server!\n");

    return sock;
}

/*
 * Reads a response from the server and returns it as a string.
 */
char* readResponse(int sock) {
    char* buffer = (char*)malloc(MAXSIZE*sizeof(char));
    memset(buffer, 0, MAXSIZE);

    int size = read(sock, buffer, MAXSIZE);
    if (size < 0) {
        printf("Error receiving response from server\n");
        return NULL;
    }

    return buffer;
}

int main() {
    char* ip = "127.0.0.1";     // IP address of IMAP server
    int port = 143;             // Port number used by IMAP server
    int sock = connectToServer(ip, port); // Connect to IMAP server

    if (sock == -1) {
        printf("Error connecting to server\n");
        return -1;
    }

    // Send a login command to the server
    char* username = "example.user";
    char* password = "password123";
    char buffer[MAXSIZE];
    memset(buffer, 0, MAXSIZE);

    sprintf(buffer, "LOGIN %s %s\r\n", username, password);
    write(sock, buffer, strlen(buffer));

    // Wait for response from server
    char* response = readResponse(sock);
    printf("Server response:\n%s\n", response);

    // Send a command to list all the available mailboxes on the server
    memset(buffer, 0, MAXSIZE);
    sprintf(buffer, "LIST \"\" *\r\n");
    write(sock, buffer, strlen(buffer));

    // Wait for response from server
    response = readResponse(sock);
    printf("Server response:\n%s\n", response);

    // Logout from server
    memset(buffer, 0, MAXSIZE);
    sprintf(buffer, "LOGOUT\r\n");
    write(sock, buffer, strlen(buffer));

    // Wait for response from server
    response = readResponse(sock);
    printf("Server response:\n%s\n", response);

    // Close the connection to the server
    close(sock);
    free(response);

    return 0;
}