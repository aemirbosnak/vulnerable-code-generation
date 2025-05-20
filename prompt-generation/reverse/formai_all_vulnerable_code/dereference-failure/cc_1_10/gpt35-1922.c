//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110
#define BUFSIZE 1024

int sockfd;

void error(char *msg) {
    perror(msg);
    exit(1);
}

void send2server(char* message) {
    //Send the message to the server
    int n;
    n = write(sockfd, message, strlen(message));     
    if (n < 0) error("ERROR writing to socket");
}

char* receive4mserver() {
    int n;
    char buffer[BUFSIZE];
    bzero(buffer, BUFSIZE);

    //Read the response from the server
    n = read(sockfd, buffer, BUFSIZE);  
    if (n < 0) error("ERROR reading from socket");

    return strdup(buffer);
}

void login(char* username, char* password) {
    //Send the username to the server
    char message[BUFSIZE];
    sprintf(message, "USER %s\r\n", username);
    send2server(message);
    printf("%s", receive4mserver());

    //Send the password to the server
    sprintf(message, "PASS %s\r\n", password);
    send2server(message);
    printf("%s", receive4mserver());
}

void retrieve() {
    //Send the retrieve command to the server
    char message[BUFSIZE];
    sprintf(message, "RETR 1\r\n");
    send2server(message);
    printf("%s", receive4mserver());
}

int main(int argc, char *argv[]) {
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFSIZE];

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname username\n", argv[0]);
       exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) error("ERROR, no such host");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(POP3_PORT);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    printf("%s", receive4mserver()); //Receive the welcome message

    login(argv[2], getpass("Password:")); //Get the password without displaying it

    retrieve(); //Retrieve the first email

    close(sockfd);
    return 0;
}