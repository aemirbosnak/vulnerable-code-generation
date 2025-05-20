//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>

#define BUF_SIZE 1024

int main(void){

    int sockfd, port, num_bytes = 0;
    struct sockaddr_in server_addr;
    struct hostent *he;
    char buffer[BUF_SIZE + 1];

    printf("=== IMAP Client ===\n\n");

    char username[50], password[50];

    printf("Enter your username:\n");
    scanf("%s", username);
    printf("Enter your password:\n");
    scanf("%s", password);

    printf("\nConnecting to the server...\n");

    // creating socket
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        printf("Failed to create the socket.\n");
        return 1;
    }

    // resolving server's IP address
    if((he = gethostbyname("mail.server.com")) == NULL){
        printf("Failed to resolve the host name.\n");
        return 1;
    }

    // setting up server's address
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(143);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);

    // connecting to the server
    if(connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1){
        printf("Failed to connect to the server.\n");
        return 1;
    }

    // sending login credentials to the server
    char login_command[100];
    sprintf(login_command, ". login %s %s\r\n", username, password);
    printf("\nSending login command to the server...\n");
    send(sockfd, login_command, strlen(login_command), 0);

    // receiving response from the server
    num_bytes = recv(sockfd, buffer, BUF_SIZE, 0);
    buffer[num_bytes] = '\0';
    printf("%s", buffer);

    // sending command to list the emails in the inbox
    printf("\nChecking inbox...\n");
    send(sockfd, ". list \"\" *\r\n", strlen(". list \"\" *\r\n"), 0);

    // receiving response from the server
    num_bytes = recv(sockfd, buffer, BUF_SIZE, 0);
    buffer[num_bytes] = '\0';
    printf("%s", buffer);

    // sending command to select the inbox
    printf("Opening inbox...\n");
    send(sockfd, ". select inbox\r\n", strlen(". select inbox\r\n"), 0);

    // receiving response from the server
    num_bytes = recv(sockfd, buffer, BUF_SIZE, 0);
    buffer[num_bytes] = '\0';
    printf("%s", buffer);

    // sending command to fetch the last email
    printf("Fetching the last email in the inbox...\n");
    send(sockfd, ". fetch * last\r\n", strlen(". fetch * last\r\n"), 0);

    // receiving response from the server
    num_bytes = recv(sockfd, buffer, BUF_SIZE, 0);
    buffer[num_bytes] = '\0';
    printf("%s", buffer);

    // closing the connection
    send(sockfd, ". logout\r\n", strlen(". logout\r\n"),0);
    close(sockfd);

    printf("\nConnection closed.\n");

    return 0;
}