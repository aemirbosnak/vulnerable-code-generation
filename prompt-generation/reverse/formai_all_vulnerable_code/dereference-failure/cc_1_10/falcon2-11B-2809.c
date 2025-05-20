//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: genius
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <target hostname>\n", argv[0]);
        return 1;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: %s not found\n", argv[1]);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    memcpy(&server.sin_addr, host->h_addr_list[0], host->h_length);

    int connect_result = connect(sockfd, (struct sockaddr *)&server, sizeof(server));
    if (connect_result < 0) {
        perror("Error connecting to server");
        return 1;
    }

    char buffer[256];
    int numbytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (numbytes < 0) {
        perror("Error receiving data");
        return 1;
    }

    printf("Received %d bytes from server: %s\n", numbytes, buffer);

    close(sockfd);

    return 0;
}