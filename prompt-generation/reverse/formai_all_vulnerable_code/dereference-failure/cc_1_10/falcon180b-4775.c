//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_LINE 1024
#define MAX_USERNAME 64
#define MAX_PASSWORD 64

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char message[MAX_LINE];
    int n;
    int port = 110;
    int ret;

    if (argc!= 3) {
        printf("Usage: %s <username> <password>\n", argv[0]);
        return 1;
    }

    strcpy(username, argv[1]);
    strcpy(password, argv[2]);

    host = gethostbyname("localhost");
    if (host == NULL) {
        printf("Error: could not resolve hostname\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = *(unsigned long *)host->h_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: could not create socket\n");
        return 1;
    }

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error: could not connect to server\n");
        return 1;
    }

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    while (1) {
        n = recv(sockfd, message, MAX_LINE, 0);
        if (n <= 0) {
            printf("Error: could not receive message\n");
            return 1;
        }
        message[n] = '\0';
        printf("%s\n", message);
    }

    close(sockfd);

    return 0;
}