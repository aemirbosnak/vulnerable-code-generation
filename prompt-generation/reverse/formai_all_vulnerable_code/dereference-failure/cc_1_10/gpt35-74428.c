//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char to[BUFFER_SIZE];
    char from[BUFFER_SIZE];
    char subject[BUFFER_SIZE];
    char message[BUFFER_SIZE*10];
    char *host;
    char *end_of_headers;
    char *line;
    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]);
    host = argv[1];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }
    printf("Enter From:");
    fgets(from,BUFFER_SIZE,stdin);
    printf("Enter To:");
    fgets(to,BUFFER_SIZE,stdin);
    printf("Enter Subject:");
    fgets(subject,BUFFER_SIZE,stdin);
    printf("Enter Message:\n");
    fgets(message,BUFFER_SIZE*10,stdin);
    sprintf(buffer,"From: %sTo: %sSubject: %s\n%s",from,to,subject,message);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    memset(buffer,0,BUFFER_SIZE);
    while (read(sockfd,buffer,BUFFER_SIZE - 1) != 0) {
        printf("%s",buffer);
        if ((end_of_headers = strstr(buffer,"\r\n\r\n")) != NULL) {
            end_of_headers += 4;
            break;
        }
        memset(buffer,0,BUFFER_SIZE);
    }
    printf("\n");
    line = strtok(end_of_headers,"\n");
    while (line != NULL) {
        printf("%s\n",line);
        line = strtok(NULL,"\n");
    }
    close(sockfd);
    return 0;
}