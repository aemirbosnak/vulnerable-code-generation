//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

// Global Variables
int portNumber = 8080;
int serverSocketFD = 0;
struct sockaddr_in serverAddress;
char buffer[256];

void server_loop() {
    serverSocketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocketFD == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(portNumber);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    listen(serverSocketFD, 5);

    while (1) {
        if (connect(serverSocketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
            perror("connect");
            exit(EXIT_FAILURE);
        }

        printf("Waiting for client to connect...\n");
        while (1) {
            int clientFD = accept(serverSocketFD, (struct sockaddr *)NULL, NULL);
            if (clientFD == -1) {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            printf("Client connected.\n");

            while (1) {
                char *message;
                message = (char *)malloc(sizeof(char) * 256);
                read(clientFD, message, 255);
                message[255] = '\0';
                printf("Client: %s\n", message);
                if (strcmp(message, "quit") == 0) {
                    printf("Client: %s\n", message);
                    break;
                }
                write(clientFD, buffer, 255);
            }
            printf("Client disconnected.\n");
            close(clientFD);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s portNumber\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    portNumber = atoi(argv[1]);
    server_loop();
}