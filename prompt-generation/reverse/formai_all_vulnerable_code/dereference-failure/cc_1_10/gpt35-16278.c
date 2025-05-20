//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

// Function to print error message and exit
void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    struct sockaddr_in server_addr;
    struct hostent *server;
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    char *user, *pass, *file, *server_name;
    uint16_t port;

    if (argc < 5) {
        fprintf(stderr, "usage %s <server_name> <port> <username> <password> <filename>\n", argv[0]);
        exit(1);
    }

    server_name = argv[1];
    port = atoi(argv[2]);
    user = argv[3];
    pass = argv[4];
    file = argv[5];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    server = gethostbyname(server_name);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&server_addr.sin_addr.s_addr,
         server->h_length);
    server_addr.sin_port = htons(port);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) 
        error("ERROR connecting");

    // Send username
    bzero(buffer,BUFFER_SIZE);
    strncpy(buffer, user, strlen(user));
    strcat(buffer, "\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");

    // read response for username
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE-1);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s", buffer);

    // Send password
    bzero(buffer,BUFFER_SIZE);
    strncpy(buffer, pass, strlen(pass));
    strcat(buffer, "\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");

    // read response for password
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE-1);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s", buffer);

    // Send type
    bzero(buffer,BUFFER_SIZE);
    strncpy(buffer, "TYPE I\r\n", strlen("TYPE I\r\n"));
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");

    // read response for type
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE-1);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s", buffer);

    // Send pasv
    bzero(buffer,BUFFER_SIZE);
    strncpy(buffer, "PASV\r\n", strlen("PASV\r\n"));
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");

    // read response for pasv
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE-1);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s", buffer);

    // decode pasv response
    int ip[4];
    int port_hi, port_lo, data_port;
    sscanf(strchr(buffer, '(') + 1,
           "%d,%d,%d,%d,%d,%d",
           &ip[0], &ip[1], &ip[2], &ip[3], &port_hi, &port_lo);
    data_port = (port_hi << 8) | port_lo;

    // connect to data port
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    char ip_str[20];
    sprintf(ip_str, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
    inet_pton(AF_INET, ip_str, &data_addr.sin_addr);
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0)
        error("ERROR connecting to data socket");

    // Send retr
    bzero(buffer, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "RETR %s\r\n", file);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    // read retr response
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s", buffer);

    // read data and print to stdout
    bzero(buffer, BUFFER_SIZE);
    while ((n = read(data_sockfd, buffer, BUFFER_SIZE-1)) > 0) {
        fwrite(buffer, n, 1, stdout);
        bzero(buffer, BUFFER_SIZE);
    }

    // Clean up
    close(data_sockfd);
    close(sockfd);
    
    return 0;
}