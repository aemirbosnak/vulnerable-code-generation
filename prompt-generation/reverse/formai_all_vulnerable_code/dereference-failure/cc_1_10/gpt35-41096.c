//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char *hostname, buf[BUFSIZE];

    /* check command line arguments */
    if (argc != 3) {
       fprintf(stderr,"usage: %s <hostname> <port>\n", argv[0]);
       exit(0);
    }
    hostname = argv[1];
    portno = atoi(argv[2]);

    /* socket: create the socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        perror("ERROR opening socket");

    /* gethostbyname: get the server's DNS entry */
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host as %s\n", hostname);
        exit(0);
    }

    /* build the server's Internet address */
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
	  (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(portno);

    /* connect: create a connection with the server */
    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) 
      perror("ERROR connecting");

    /* prompt for the message from the client */
    printf("Please enter the file name: ");
    bzero(buf, BUFSIZE);
    fgets(buf, BUFSIZE, stdin);

    /* send the message line to the server */
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) 
      perror("ERROR writing to socket");

    /* receive the file from the server */
    int cnt;
    FILE *fp;
    char filecnt[BUFSIZE];
    n = read(sockfd, filecnt, BUFSIZE);
    if (n < 0) 
      perror("ERROR reading from socket");
    else {
      cnt = atoi(filecnt);
      if (cnt > 0) {
        fp = fopen("ftp_client_file", "wb");
        while (cnt > 0) {
          int bytesReceived = recv(sockfd, buf, BUFSIZE, 0);
          if (bytesReceived < 0) 
            perror("ERROR reading from socket");
          cnt -= bytesReceived;
          fwrite(buf, sizeof(char), bytesReceived, fp);
        }
        fclose(fp);
      } else {
        printf("File not found on server.\n");
      }
    }

    close(sockfd);
    return 0;
}