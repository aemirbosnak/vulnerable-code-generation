//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SIZE 1024
#define PORT 143

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname username password\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Error opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: No such host exists\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("Error in connection");

    bzero(buffer,SIZE);
    n = read(sockfd, buffer, SIZE);
    if (n < 0) error("Error in reading response from server");

    printf("%s", buffer);

    char *username = argv[2];
    char *password = argv[3];

    char login_cmd[SIZE];
    sprintf(login_cmd, "LOGIN %s %s\r\n", username, password);
    n = write(sockfd, login_cmd, strlen(login_cmd));
    if (n < 0) error("Error in login command");

    bzero(buffer, SIZE);
    n = read(sockfd, buffer, SIZE);
    if (n < 0) error("Error in reading response from server");

    printf("%s", buffer);

    char list_cmd[] = "LIST \"\" *\r\n";
    n = write(sockfd, list_cmd, strlen(list_cmd));
    if (n < 0) error("Error in list command");

    bzero(buffer, SIZE);
    n = read(sockfd, buffer, SIZE);
    if (n < 0) error("Error in reading response from server");

    printf("%s", buffer);

    return 0;
}