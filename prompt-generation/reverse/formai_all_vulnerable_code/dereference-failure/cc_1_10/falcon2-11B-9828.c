//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    if (argc!= 3) {
        fprintf(stderr, "Usage %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Starting speed test...\n");
    printf("Enter 'quit' to stop the test.\n");
    while (1) {
        if (read(sockfd, buffer, sizeof(buffer)) < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        printf("%s", buffer);
        if (strcmp(buffer, "quit") == 0) {
            break;
        }
        if (write(sockfd, buffer, sizeof(buffer)) < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }

    printf("Speed test completed.\n");
    return 0;
}