//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket() failed: %s\n", strerror(errno));
        return 1;
    }

    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        printf("gethostbyname() failed: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("connect() failed: %s\n", strerror(errno));
        return 1;
    }

    char *response;
    char buf[BUF_SIZE];
    while (1) {
        response = fgets(buf, BUF_SIZE, stdin);
        if (response == NULL) {
            printf("fgets() failed: %s\n", strerror(errno));
            return 1;
        }
        buf[strcspn(buf, "\r\n")] = '\0'; // remove CR LF from input

        if (strcasecmp(response, "QUIT") == 0) {
            break;
        }

        send(sockfd, response, strlen(response), 0);
        memset(buf, 0, BUF_SIZE);
        if (recv(sockfd, buf, BUF_SIZE, 0) <= 0) {
            printf("recv() failed: %s\n", strerror(errno));
            return 1;
        }
        printf("%s", buf);
    }

    close(sockfd);
    return 0;
}