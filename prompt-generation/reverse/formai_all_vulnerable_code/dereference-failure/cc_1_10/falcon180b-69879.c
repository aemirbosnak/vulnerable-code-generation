//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sock;
    struct sockaddr_in server_addr;
    int opt = 1;
    char buffer[BUFFER_SIZE];
    int nbytes;
    char *message;
    int message_len;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <Port number>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error opening socket\n");
        exit(1);
    }

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        nbytes = recv(sock, buffer, BUFFER_SIZE, 0);
        if (nbytes <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        message = strtok(buffer, "\n");
        while (message!= NULL) {
            message_len = strlen(message);
            printf("Received message: %.*s\n", message_len, message);
            message = strtok(NULL, "\n");
        }
    }

    close(sock);
    return 0;
}