//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: Ken Thompson
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[100];
    char *s;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(12345);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        exit(1);
    }

    printf("Enter your name: ");
    fgets(buffer, sizeof(buffer), stdin);
    s = buffer;

    while (1) {
        if (read(sockfd, buffer, 100) < 0) {
            perror("read error");
            exit(1);
        }
        printf("%s", buffer);
        printf("\n");
        printf("Enter your response: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(sockfd, buffer, strlen(buffer));
    }

    return 0;
}