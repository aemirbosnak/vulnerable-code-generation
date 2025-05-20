//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char username[20], password[20];
    char cmd[BUF_SIZE];
    char response[BUF_SIZE];
    int port = 21; // default ftp port

    if (argc!= 6) {
        printf("Usage:./ftp_client <server_address> <username> <password> <port>\n");
        exit(1);
    }

    // parse command line arguments
    strcpy(username, argv[2]);
    strcpy(password, argv[3]);
    port = atoi(argv[4]);

    // create socket
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

    // set up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // login to server
    sprintf(cmd, "USER %s\r\n", username);
    send(sockfd, cmd, strlen(cmd), 0);
    memset(response, 0, sizeof(response));
    recv(sockfd, response, sizeof(response), 0);

    sprintf(cmd, "PASS %s\r\n", password);
    send(sockfd, cmd, strlen(cmd), 0);
    memset(response, 0, sizeof(response));
    recv(sockfd, response, sizeof(response), 0);

    // send commands to server
    char *command = "ls -l\r\n";
    send(sockfd, command, strlen(command), 0);
    memset(response, 0, sizeof(response));
    recv(sockfd, response, sizeof(response), 0);
    printf("%s", response);

    // close connection
    close(sockfd);

    return 0;
}