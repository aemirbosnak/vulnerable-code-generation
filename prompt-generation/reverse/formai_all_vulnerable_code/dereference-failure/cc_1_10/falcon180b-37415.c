//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char **argv)
{
    int sockfd;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    // set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // get host information
    host = gethostbyname(hostname);
    if (host == NULL)
    {
        printf("Error: Host not found\n");
        exit(1);
    }

    // set server IP address
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    // send username
    char username[100];
    printf("Enter username: ");
    scanf("%s", username);
    send(sockfd, username, strlen(username), 0);

    // receive welcome message
    char welcome[100];
    recv(sockfd, welcome, sizeof(welcome), 0);
    printf("Welcome message: %s\n", welcome);

    // send password
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    send(sockfd, password, strlen(password), 0);

    // receive success/failure message
    char message[100];
    recv(sockfd, message, sizeof(message), 0);
    printf("Message: %s\n", message);

    // close connection
    close(sockfd);
    return 0;
}