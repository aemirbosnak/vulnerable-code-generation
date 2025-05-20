//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char username[50], password[50], buf[MAX_LINE_LENGTH];
    char *host;
    int port = POP3_PORT;

    if (argc!= 5) {
        printf("Usage:./pop3_client <host> <port> <username> <password>\n");
        exit(0);
    }

    host = argv[1];
    port = atoi(argv[2]);
    strcpy(username, argv[3]);
    strcpy(password, argv[4]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Unable to create socket\n");
        exit(0);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Unable to connect to server\n");
        exit(0);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buf, 0, MAX_LINE_LENGTH);
        n = read(sockfd, buf, MAX_LINE_LENGTH);
        if (n <= 0) {
            printf("Error: Unable to read from server\n");
            exit(0);
        }
        printf("%s", buf);
    }

    close(sockfd);
    return 0;
}