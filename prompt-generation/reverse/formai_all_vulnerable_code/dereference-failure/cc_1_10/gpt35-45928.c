//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 25

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    // Check for command line arguments
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname message\n", argv[0]);
       exit(0);
    }

    // Get the server host name
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set the server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send the message to the server
    char message[512];
    bzero(buffer,256);
    sprintf(message, "HELO %s\r\nMAIL FROM:<%s>\r\nRCPT TO:<%s>\r\nDATA\r\n%s\r\n.\r\nQUIT\r\n", 
        argv[1], argv[2], argv[3], argv[4]);
    n = write(sockfd,message,strlen(message));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Receive the response from the server
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n",buffer);

    // Close the socket and exit
    close(sockfd);
    return 0;
}