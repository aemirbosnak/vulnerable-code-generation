//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: realistic
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define MAX_CLIENTS 5

int main() {
    int server_fd, client_fd, valread, n;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *server;

    int i;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname("localhost");

    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    memset((char *) &server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    server_addr.sin_port = htons(5000);

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error on binding");
        exit(1);
    }

    listen(server_fd, MAX_CLIENTS);

    for (;;) {
        client_fd = accept(server_fd, (struct sockaddr *) &client_addr, (socklen_t *) &n);

        if (client_fd == -1) {
            perror("Error on accept");
            exit(1);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        for (i = 0; i < 10; i++) {
            valread = recv(client_fd, &i, sizeof(int), 0);

            if (valread == -1) {
                perror("Error on receive");
                close(client_fd);
                break;
            }

            printf("Received: %d\n", i);

            if (send(client_fd, &i, sizeof(int), 0) == -1) {
                perror("Error on send");
                close(client_fd);
                break;
            }

            printf("Sent: %d\n", i);
        }

        close(client_fd);
    }

    close(server_fd);
    return 0;
}