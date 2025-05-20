//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: could not create socket\n");
        exit(EXIT_FAILURE);
    }

    struct hostent *server = gethostbyname("imap.gmail.com");
    if (server == NULL) {
        printf("Error: could not resolve hostname\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(993);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: could not connect to server\n");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    int n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        printf("Error: could not read from socket\n");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s", buffer);

    char user[100];
    printf("Username: ");
    fgets(user, sizeof(user), stdin);
    user[strcspn(user, "\n")] = '\0';

    char pass[100];
    printf("Password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = '\0';

    char cmd[100];
    sprintf(cmd, "LOGIN %s %s\r\n", user, pass);
    write(sockfd, cmd, strlen(cmd));
    memset(buffer, 0, sizeof(buffer));

    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        printf("Error: could not read from socket\n");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s", buffer);

    sprintf(cmd, "SELECT INBOX\r\n");
    write(sockfd, cmd, strlen(cmd));
    memset(buffer, 0, sizeof(buffer));

    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        printf("Error: could not read from socket\n");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s", buffer);

    sprintf(cmd, "FETCH 1:* (FLAGS BODY[HEADER.FIELDS (SUBJECT FROM)])\r\n");
    write(sockfd, cmd, strlen(cmd));
    memset(buffer, 0, sizeof(buffer));

    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        printf("Error: could not read from socket\n");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s", buffer);

    close(sockfd);
    return 0;
}