//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOSTNAME 256
#define MAX_MSG_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char msg[MAX_MSG_SIZE];
    int len;

    if (argc!= 3) {
        printf("Usage: %s <host> <message>\n", argv[0]);
        exit(1);
    }

    strncpy(msg, argv[2], MAX_MSG_SIZE - 1);
    msg[MAX_MSG_SIZE - 1] = '\0';

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(1234);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to host\n");
        exit(1);
    }

    len = send(sockfd, msg, strlen(msg), 0);
    if (len == -1) {
        printf("Error sending message\n");
        exit(1);
    }

    close(sockfd);

    printf("Message sent successfully\n");
    return 0;
}