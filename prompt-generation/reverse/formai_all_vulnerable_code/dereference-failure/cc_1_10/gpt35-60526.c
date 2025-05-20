//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // check if command line arguments are provided correctly
    if(argc != 3) {
        printf("Usage : %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // create socket descriptor
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("Error in socket creation");
        exit(1);
    }

    // get server information
    struct hostent *he;
    if((he = gethostbyname(argv[1])) == NULL) {
        perror("Error in hostname resolution");
        exit(1);
    }

    // set server socket address information
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *) he->h_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    // connect to the server
    if(connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error in socket connection");
        exit(1);
    }
    
    // receive server greeting
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // login to the server
    char username[BUFFER_SIZE];
    printf("Username: ");
    scanf("%s", username);
    char password[BUFFER_SIZE];
    printf("Password: ");
    scanf("%s", password);
    char login[BUFFER_SIZE];
    sprintf(login, "USER %s\r\n", username);
    send(sockfd, login, strlen(login), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    sprintf(login, "PASS %s\r\n", password);
    send(sockfd, login, strlen(login), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // retrieve mailbox information
    send(sockfd, "STAT\r\n", strlen("STAT\r\n"), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // retrieve message headers
    send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    char message_id[BUFFER_SIZE];
    printf("Enter message ID to view: ");
    scanf("%s", message_id);
    char command[BUFFER_SIZE];
    sprintf(command, "TOP %s 10\r\n", message_id);
    send(sockfd, command, strlen(command), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // logout
    send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // close the socket descriptor
    close(sockfd);

    return 0;
}