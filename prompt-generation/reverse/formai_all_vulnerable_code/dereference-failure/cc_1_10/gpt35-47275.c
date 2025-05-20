//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: complex
/*
 * C program to demonstrate FTP client connection using sockets
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

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
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    printf("Connected to FTP server on host %s\n", argv[1]);

    // Login with user and password
    char user[50],passwd[50];
    printf("Username: ");
    scanf("%s",user);
    printf("Password: ");
    scanf("%s",passwd);

    char msg[256];
    sprintf(msg,"USER %s\r\n",user);
    write(sockfd,msg,strlen(msg));  // send the message to FTP server
    bzero(buffer,256);
    read(sockfd,buffer,255);  // receive response from FTP server
    printf("%s",buffer);

    sprintf(msg,"PASS %s\r\n",passwd);
    write(sockfd,msg,strlen(msg));
    bzero(buffer,256);
    read(sockfd,buffer,255);
    printf("%s",buffer);

    // Switch to binary mode
    write(sockfd,"TYPE I\r\n",8);
    bzero(buffer,256);
    read(sockfd,buffer,255);
    printf("%s",buffer);

    // Download a file
    char filename[50];
    printf("Enter filename to download from FTP server: ");
    scanf("%s",filename);

    sprintf(msg,"RETR %s\r\n",filename);
    write(sockfd,msg,strlen(msg));
    bzero(buffer,256);
    read(sockfd,buffer,255);
    printf("%s",buffer);

    // Create the file on local machine
    FILE *f = fopen(filename,"wb");
    if(f==NULL)
    {
        printf("Error creating file\n");
        exit(1);
    }

    // Read the file data from FTP server and write it locally
    printf("Downloading file...\n");
    while((n = read(sockfd, buffer, 256)) > 0)
    {
        fwrite(buffer, sizeof(char), n, f);
        if(n < 256) break; // End of file
    }
    fclose(f);

    // Quit from FTP server
    write(sockfd,"QUIT\r\n",6);
    bzero(buffer,256);
    read(sockfd,buffer,255);
    printf("%s",buffer);

    close(sockfd);  // close the socket connection
    return 0;
}