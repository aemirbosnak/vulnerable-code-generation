//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void print_buffer(char *buffer, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%c", buffer[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    int n;

    if (argc!= 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("No such host\n");
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    printf("Connecting to %s on port %d...\n", argv[1], portno);

    if (connect(sockfd, (struct sockaddr *)server, sizeof(struct sockaddr)) < 0) {
        printf("Error connecting\n");
        exit(1);
    }

    printf("Connected\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE-1);
        if (n <= 0) {
            printf("Disconnected\n");
            break;
        }
        buffer[n] = '\0';
        printf("Received: %s", buffer);
    }

    close(sockfd);
    return 0;
}