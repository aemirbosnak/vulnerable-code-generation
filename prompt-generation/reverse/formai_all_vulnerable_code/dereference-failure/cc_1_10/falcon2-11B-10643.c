//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/ip.h>

#define PORT_RANGE 10000
#define MAX_BULK_CONNECTIONS 5

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    char hostname[256];
    strcpy(hostname, argv[1]);
    int port = atoi(argv[2]);

    struct hostent *host_entry;
    host_entry = gethostbyname(hostname);

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    bzero((char *) &(server_address.sin_addr.s_addr), 4);
    bcopy((char *) host_entry->h_addr, (char *) &(server_address.sin_addr.s_addr), host_entry->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("connect failed");
        return 1;
    }

    printf("Connected to %s:%d\n", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    while (1) {
        int bytes_read = read(sockfd, buffer, sizeof(buffer));
        if (bytes_read <= 0) {
            break;
        }
        printf("Received: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}