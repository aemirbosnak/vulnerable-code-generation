//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) 
{
    // Define variables 
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    if (argc < 3) 
    {
        fprintf(stderr,"Usage %s hostname port\n",argv[0]);
        exit(0);
    }

    // Create socket file descriptor 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        perror("ERROR opening socket");
        exit(0);
    }

    // Set up the server address struct 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the server 
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
    {
        perror("ERROR connecting");
        exit(0);
    }

    // Send data to server 
    n = write(sockfd,argv[3],strlen(argv[3]));
    if (n < 0) 
    {
        perror("ERROR writing to socket");
        exit(0);
    }

    printf("Data sent successfully\n");

    // Close the socket 
    close(sockfd);

    return 0;
}