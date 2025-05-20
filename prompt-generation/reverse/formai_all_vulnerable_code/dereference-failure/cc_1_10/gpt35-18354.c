//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: creative
/*
******************************************************************************************
Program Name:	Basic FTP Client
Author:			John Doe
Date:			Oct 21, 2021
Description:	A basic FTP client that enables a user to download files. 
*******************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    // Check if hostname and port number are provided in the command line arguments
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Get the server's hostname and port number
    portno = atoi(argv[2]);
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Set the server's address and port number
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // Receive a welcome message from the server
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s",buffer);

    // Ask the user for the filename to download
    printf("Enter the filename: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    strtok(buffer, "\n"); // Remove the trailing newline character

    // Send the filename to the server
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0)
         error("ERROR writing to socket");

    // Receive the file contents from the server and write it to a new file
    FILE *fp;
    fp = fopen("downloaded_file.txt", "w+");
    bzero(buffer,256);
    while ((n = read(sockfd, buffer, 255)) > 0) {
        if (n < 0)
             error("ERROR reading from socket");
        fwrite(buffer, sizeof(char), n, fp);
        bzero(buffer, 256);
    }
    fclose(fp);

    // Print a success message
    printf("\nFile downloaded successfully!\n");

    // Close the socket
    close(sockfd);
    return 0;
}