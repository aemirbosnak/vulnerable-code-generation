//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];
    char username[100];
    char password[100];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);    
    if (server == NULL) {
        fprintf(stderr,"Error, no such host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    printf("Connected to server\n");

    memset(buffer, 0, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE - 1);

    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    username[strlen(username) - 1] = '\0';

    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    password[strlen(password) - 1] = '\0';

    snprintf(buffer, BUF_SIZE - 1, "a001 LOGIN %s %s\r\n", username, password);
    n = write(sockfd, buffer, strlen(buffer));
    memset(buffer, 0, BUF_SIZE);

    n = read(sockfd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);

    snprintf(buffer, BUF_SIZE - 1, "a002 LIST \"\" *\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    memset(buffer, 0, BUF_SIZE);

    n = read(sockfd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);

    snprintf(buffer, BUF_SIZE - 1, "a003 LOGOUT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    memset(buffer, 0, BUF_SIZE);

    n = read(sockfd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}