//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Function to connect to the POP3 server
int connectToServer(char * serverName, int port, char * userName, char * password)
{
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Connect to the server
    struct hostent *server = gethostbyname(serverName);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Log in to the server
    char buffer[1024];
    int n = read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    sprintf(buffer, "USER %s\r\n", userName);
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    return sockfd;
}

// Function to retrieve messages from the server
void retrieveMessages(int sockfd)
{
    char buffer[1024];
    int n;

    // Send the command to retrieve messages
    sprintf(buffer, "LIST\r\n");
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Read the response from the server
    sprintf(buffer, "RETR 1\r\n");
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);
}

int main(int argc, char *argv[])
{
    // Check the arguments
    if (argc < 5) {
        fprintf(stderr,"usage %s hostname port username password\n", argv[0]);
        exit(0);
    }

    // Connect to the server
    int sockfd = connectToServer(argv[1], atoi(argv[2]), argv[3], argv[4]);

    // Retrieve messages from the server
    retrieveMessages(sockfd);

    // Close the connection
    close(sockfd);

    return 0;
}