//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 4096

void error(char *msg) {
     perror(msg);
     exit(1);
}

void send_message(int sockfd, char* message) {
    int n;
    char buf[BUF_SIZE];
    sprintf(buf, "%s\r\n", message);
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) 
         error("ERROR writing to socket");
}

char* receive_message(int sockfd) {
    int n;
    char buf[BUF_SIZE];
    bzero(buf, BUF_SIZE);
    n = read(sockfd, buf, BUF_SIZE-1);
    if (n < 0)
         error("ERROR reading from socket");
    return buf;
}

int main(int argc, char *argv[]) {
     int sockfd, portno, n;
     struct sockaddr_in serv_addr;
     struct hostent *server;

     char buffer[BUF_SIZE];

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

     while(1) {
         printf("Enter message: ");
         bzero(buffer,BUF_SIZE);
         /* fgets reads character from stdin to buffer with max length BUF_SIZE */
         fgets(buffer,BUF_SIZE-2,stdin);

         send_message(sockfd, buffer);

         if (!strcmp(buffer,"exit\n")) {
             printf("Closing connection.\n");
             close(sockfd);;
             exit(0);
         }

         char* response = receive_message(sockfd);
         printf("Server response: %s", response);
     }

     return 0;
}