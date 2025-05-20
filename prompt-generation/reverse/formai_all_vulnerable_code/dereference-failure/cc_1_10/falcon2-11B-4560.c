//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server_addr;
    int server_sockfd;
    int port_number;
    char *hostname;

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid hostname: %s\n", argv[1]);
        return 1;
    }

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(0);
    bzero(&(server_addr.sin_zero), 8);

    port_number = htons(50000);
    if (connect(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    if (listen(server_sockfd, 3) == -1) {
        perror("listen");
        return 1;
    }

    int client_sockfd;
    char buffer[1024];
    char *hello_str = "Hello, ";
    char *client_str[1024];
    char *hostname_str;
    int i;

    for (i = 0; i < 3; i++) {
        client_sockfd = accept(server_sockfd, NULL, NULL);
        if (client_sockfd == -1) {
            perror("accept");
            return 1;
        }

        read(client_sockfd, &hostname_str, sizeof(hostname_str));
        printf("%s\n", hello_str);
        printf("%s\n", hostname_str);
        printf("Type 'quit' to exit: ");
        fgets(buffer, sizeof(buffer), stdin);
        if (strcmp(buffer, "quit") == 0) {
            break;
        } else {
            printf("You entered: %s\n", buffer);
            for (int j = 0; j < 1024; j++) {
                read(client_sockfd, client_str[j], sizeof(client_str[j]));
                printf("%s", client_str[j]);
            }
            printf("\n");
        }

        close(client_sockfd);
    }

    return 0;
}