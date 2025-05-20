//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: interoperable
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LINE_SIZE 1024

void error(char *msg){
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]){
    struct hostent *hp;
    struct sockaddr_in serv_addr;
    int sockfd, portno, n;

    char buffer[MAX_LINE_SIZE];
    if(argc != 4){
        fprintf(stderr, "Usage: %s <hostname> <portnumber> <username>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    /* create socket, get sockfd handle */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    
    /* fill in server address */
    hp = gethostbyname(argv[1]);
    if (hp == 0) 
        error("ERROR gethostbyname");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)hp->h_addr, (char *)&serv_addr.sin_addr.s_addr, hp->h_length);
    serv_addr.sin_port = htons(portno);

    /* connect to server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    /* login */
    sprintf(buffer, "a01 LOGIN %s password\r\n", argv[3]);
    write(sockfd,buffer,strlen(buffer));
    bzero(buffer, MAX_LINE_SIZE);
    n = read(sockfd, buffer, MAX_LINE_SIZE-1);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("Response from server: %s\n", buffer);

    /* select inbox */
    sprintf(buffer, "a02 SELECT INBOX\r\n");
    write(sockfd,buffer,strlen(buffer));
    bzero(buffer, MAX_LINE_SIZE);
    n = read(sockfd, buffer, MAX_LINE_SIZE-1);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("Response from server: %s\n", buffer);

    /* fetch message count */
    sprintf(buffer, "a03 STATUS INBOX (messages)\r\n");
    write(sockfd,buffer,strlen(buffer));
    bzero(buffer, MAX_LINE_SIZE);
    n = read(sockfd, buffer, MAX_LINE_SIZE-1);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("Response from server: %s\n", buffer);
    
    /* logout */
    sprintf(buffer, "a04 LOGOUT\r\n");
    write(sockfd,buffer,strlen(buffer));
    bzero(buffer, MAX_LINE_SIZE);
    n = read(sockfd, buffer, MAX_LINE_SIZE-1);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("Response from server: %s\n", buffer);

    /* close socket */
    close(sockfd);

    return 0;
}