//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

void error_handler(char* message);

int main(int argc, char **argv) {
    int sock;
    struct sockaddr_in serv_addr;
    char message[MAXSIZE], response[MAXSIZE];

    if(argc != 3) {
        fprintf(stderr, "Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        error_handler("socket() error");
    }

    // Set the server's address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handler("connect() error!");
    } else {
        printf("Connected to the POP3 server.\n");
    }

    while(1) {
        // Get user input
        printf("> ");
        fgets(message, MAXSIZE, stdin);

        // Send the command to the server
        write(sock, message, strlen(message));

        // Read the response from the server
        memset(response, 0, sizeof(response));
        read(sock, response, MAXSIZE);

        // Print the response
        printf("%s", response);
    }

    // Close the socket
    close(sock);

    return 0;
}

void error_handler(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}