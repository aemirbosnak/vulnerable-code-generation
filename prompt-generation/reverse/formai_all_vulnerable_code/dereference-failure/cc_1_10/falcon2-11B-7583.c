//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define MAX_CONNECTIONS 10

int main() {
    int server_fd, client_fd;
    int n;
    char buffer[1024];
    struct sockaddr_in server_addr, client_addr;
    struct hostent *server_host;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        return 1;
    }

    server_host = gethostbyname("localhost");
    if (server_host == NULL) {
        fprintf(stderr, "Hostname lookup failed\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    bcopy((char *)server_host->h_addr, (char *)&server_addr.sin_addr.s_addr, server_host->h_length);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind error");
        return 1;
    }

    listen(server_fd, MAX_CONNECTIONS);

    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&n)) < 0) {
            perror("accept error");
            return 1;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if (fork() == 0) {
            close(server_fd);
            close(client_fd);

            srand(time(NULL));
            n = rand() % 100 + 1;

            send(client_fd, &n, sizeof(n), 0);

            char guess[5];
            fgets(guess, 5, stdin);

            send(client_fd, guess, sizeof(guess), 0);

            close(client_fd);

            printf("You guessed: %s\n", guess);

            if (strcmp(guess, "12345") == 0) {
                printf("Congratulations! You guessed the number correctly!\n");
            }

            exit(0);
        }
    }

    close(server_fd);
    return 0;
}