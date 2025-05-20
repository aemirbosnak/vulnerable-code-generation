//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <ip>\n", argv[0]);
        return 1;
    }

    char ip[INET6_ADDRSTRLEN];
    struct sockaddr_in server_addr;
    struct hostent *server;

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: Invalid hostname\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Failed to create socket\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error: Failed to connect to server\n");
        return 1;
    }

    char input[1024];
    char output[1024];

    while (1) {
        printf("Enter a command: ");
        fgets(input, sizeof(input), stdin);
        strcpy(output, "ACK");
        send(sockfd, output, strlen(output), 0);

        printf("Server: %s\n", input);
    }

    return 0;
}