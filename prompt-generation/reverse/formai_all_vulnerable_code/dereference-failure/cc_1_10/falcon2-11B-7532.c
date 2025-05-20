//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: Host '%s' not found\n", argv[1]);
        exit(1);
    }

    struct sockaddr_in dest_addr;
    bzero((char *) &dest_addr, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    memcpy((char *) &dest_addr.sin_addr.s_addr, (char *) host->h_addr, host->h_length);
    dest_addr.sin_port = htons(80);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    int rv = connect(sockfd, (struct sockaddr *) &dest_addr, sizeof(dest_addr));
    if (rv < 0) {
        perror("Error connecting");
        exit(1);
    }

    char buffer[1024];
    int n = 0;
    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("%s", buffer);
    }
    if (n == 0) {
        printf("Server closed the connection\n");
    } else if (n < 0) {
        perror("Error receiving data");
    }

    close(sockfd);
    return 0;
}