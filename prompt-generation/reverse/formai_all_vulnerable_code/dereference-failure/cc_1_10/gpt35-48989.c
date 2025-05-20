//FormAI DATASET v1.0 Category: Networking ; Style: accurate
// A simple C program demonstrating networking using sockets

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define PORT 12345

int main(int argc, char *argv[])
{
    int sd;
    struct sockaddr_in serv_addr;
    char message[1024], reply[1024];
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);

    if (!server) {
        fprintf(stderr, "Error: %s\n", hstrerror(h_errno));
        exit(EXIT_FAILURE);
    }

    sd = socket(AF_INET, SOCK_STREAM, 0);

    if (sd < 0) {
        perror("Error: socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    while (1) {
        memset(message, 0, sizeof(message));
        printf("Enter message: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\r\n")] = 0;

        if (strcmp(message, "quit") == 0) {
            break;
        }

        if (send(sd, message, strlen(message), 0) < 0) {
            perror("Error: send failed");
            exit(EXIT_FAILURE);
        }

        memset(reply, 0, sizeof(reply));

        if (recv(sd, reply, sizeof(reply), 0) < 0) {
            perror("Error: receive failed");
            exit(EXIT_FAILURE);
        }

        printf("Server reply: %s\n", reply);
    }

    close(sd);
    return 0;
}