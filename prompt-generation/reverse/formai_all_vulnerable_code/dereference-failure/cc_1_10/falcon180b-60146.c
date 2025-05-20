//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <hostname> <username> <password>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    char *login_msg = "USER ";
    strcat(login_msg, username);
    strcat(login_msg, "\r\n");
    send(sockfd, login_msg, strlen(login_msg), 0);

    char *pass_msg = "PASS ";
    strcat(pass_msg, password);
    strcat(pass_msg, "\r\n");
    send(sockfd, pass_msg, strlen(pass_msg), 0);

    char buffer[1024];
    if (recv(sockfd, buffer, sizeof(buffer), 0) <= 0) {
        perror("recv");
        return 1;
    }

    printf("FTP server replied: %s", buffer);

    char *ls_cmd = "LIST\r\n";
    send(sockfd, ls_cmd, strlen(ls_cmd), 0);

    if (recv(sockfd, buffer, sizeof(buffer), 0) <= 0) {
        perror("recv");
        return 1;
    }

    printf("FTP server replied: %s", buffer);

    close(sockfd);
    return 0;
}