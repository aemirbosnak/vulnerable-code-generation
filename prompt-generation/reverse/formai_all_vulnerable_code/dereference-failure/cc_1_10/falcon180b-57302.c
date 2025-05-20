//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 21

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *host;
    int port;
    char buffer[BUFFER_SIZE];
    int n;

    if (argc!= 5) {
        printf("Usage:./ftp_client <host> <username> <password> <command>\n");
        exit(1);
    }

    host = argv[1];
    port = PORT;
    char *username = argv[2];
    char *password = argv[3];
    char *command = argv[4];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to server.\n");

    char *auth_str = malloc(strlen(username) + strlen(password) + 3);
    sprintf(auth_str, "%s:%s", username, password);
    send(sockfd, auth_str, strlen(auth_str), 0);
    free(auth_str);

    while ((n = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    exit(0);
}