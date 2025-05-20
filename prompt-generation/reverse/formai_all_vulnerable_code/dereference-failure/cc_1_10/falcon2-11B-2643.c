//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: complete
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>

#define PORT 8080
#define BUFSIZE 1024

int main(int argc, char **argv) {
    struct sockaddr_in serverAddr;
    struct hostent *serverHostInfo;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        return 1;
    }

    serverHostInfo = gethostbyname(argv[1]);
    if (serverHostInfo == NULL) {
        fprintf(stderr, "Error: No such host\n");
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr = *((struct in_addr *)serverHostInfo->h_addr);
    serverAddr.sin_port = htons(PORT);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("connect");
        return 1;
    }

    char buf[BUFSIZE];
    int n = read(sockfd, buf, BUFSIZE);
    if (n < 0) {
        perror("read");
        return 1;
    }

    printf("Received: %s\n", buf);

    write(sockfd, "Hello, World!", 13);

    close(sockfd);

    return 0;
}