//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: shape shifting
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    portno = 25;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server = gethostbyname("smtp.example.com");

    memset(&serv_addr,0,sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);

    // Connect to the server
    if( connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) == -1 )
    {
        printf("Unable to connect to server\n");
        return 1;
    }

    // Receive greeting from server
    bzero(buffer,256);
    recv(sockfd,buffer,255,0);
    printf("%s\n",buffer);

    // Send HELO command
    bzero(buffer,256);
    sprintf(buffer,"HELO smtpclient\r\n");
    send(sockfd,buffer,strlen(buffer),0);

    // Receive response
    bzero(buffer,256);
    recv(sockfd,buffer,255,0);
    printf("%s\n",buffer);

    // Close the socket
    close(sockfd);
    return 0;
}