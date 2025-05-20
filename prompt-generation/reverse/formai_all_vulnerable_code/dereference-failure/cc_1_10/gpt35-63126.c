//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd, bytes_read;
    char buffer[1024];
    struct sockaddr_in server_addr;
    struct hostent *server_host;
    
    //check command line arguments
    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    
    //create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error opening socket");
        exit(1);
    }
    
    //get host information
    server_host = gethostbyname(argv[1]);
    if (server_host == NULL) {
        fprintf(stderr,"Error: no such host %s\n",argv[1]);
        exit(1);
    }
    
    //fill in server address structure
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server_host->h_addr, 
          (char *)&server_addr.sin_addr.s_addr, 
          server_host->h_length);
    server_addr.sin_port = htons(atoi(argv[2]));
    
    //connect to server
    if (connect(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    //send HTTP GET request to server
    char *get_request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    char request_buffer[1024];
    sprintf(request_buffer, get_request, argv[1]);
    write(sockfd, request_buffer, strlen(request_buffer));
    
    //read server response
    while ((bytes_read = read(sockfd, buffer, 1024)) > 0) {
        printf("%s", buffer);
    }
    if (bytes_read == -1) {
        perror("Error reading from server");
        exit(1);
    }
    
    //close socket
    close(sockfd);
    
    return 0;
}