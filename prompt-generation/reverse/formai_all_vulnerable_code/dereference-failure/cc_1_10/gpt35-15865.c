//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

//Function to connect to the server
int connectToServer(char* hostname, int port){
    int sockfd;
    struct hostent* server;
    struct sockaddr_in serv_addr;

    //Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    //Get the server name
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    //Set up the server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(port);

    //Connect to the server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    return sockfd;
}

//Function to send a message to the server
void sendMessage(int sockfd, char* message){
    int n;
    char buffer[256];

    bzero(buffer,256);
    sprintf(buffer, "%s", message);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0){
        perror("ERROR writing to socket");
        exit(1);
    }
}

//Function to receive a message from the server
char* receiveMessage(int sockfd){
    int n;
    char buffer[256];

    bzero(buffer,256);

    //Read from the server
    n = read(sockfd, buffer, 255);
    if (n < 0){
        perror("ERROR reading from socket");
        exit(1);
    }

    //Copy the buffer to a new string
    char* message = (char*)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(message, buffer);

    return message;
}

int main(int argc, char* argv[]){
    //Check that the user provided enough arguments
    if (argc < 4) {
        fprintf(stderr,"usage %s hostname port username\n", argv[0]);
        exit(0);
    }

    int sockfd, n;
    char buffer[256];
    char* message;
    char* username = argv[3];

    //Connect to the server
    sockfd = connectToServer(argv[1], atoi(argv[2]));

    //Send the username to the server
    sendMessage(sockfd, username);

    //Receive a welcome message from the server
    message = receiveMessage(sockfd);
    printf("%s\n",message);

    while(1){
        //Get a line of input from the user
        printf("%s> ",username);
        bzero(buffer,256);
        fgets(buffer,255,stdin);

        //Remove the newline character from the end of the buffer
        buffer[strlen(buffer)-1] = '\0';

        //Send the message to the server
        sendMessage(sockfd, buffer);

        //Receive a message from the server
        message = receiveMessage(sockfd);
        printf("%s\n",message);
    }

    return 0;
}