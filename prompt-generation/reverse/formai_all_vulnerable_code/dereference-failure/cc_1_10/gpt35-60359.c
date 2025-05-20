//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_MSG 2048

/*
 * Functions to handle errors and messages
 */
void error(char *msg) {
    perror(msg);
    exit(0);
}

void handle_error(int code) {
    if(code < 0) {
        error("Error");
    }
}

/*
 * Function to send a message to the server
 */
void send_message(int sockfd,char* msg) {
    int n;

    n = write(sockfd,msg,strlen(msg));
    handle_error(n);
}

int main(int argc, char *argv[]) {

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_MSG];
    char msg[MAX_MSG];

    // Checking if the command is correct
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    //Getting the port number and the server name and creating its socket
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    handle_error(sockfd);

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    //Connecting to the server
    n = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    handle_error(n);

    //Get the message from the user
    printf("Enter the message: ");
    memset(msg,0,MAX_MSG);
    fgets(msg,MAX_MSG-1,stdin);

    //Send the message to the server
    send_message(sockfd,msg);

    //Get the response from the server
    memset(buffer,0,MAX_MSG);
    n = read(sockfd,buffer,MAX_MSG-1);
    handle_error(n);

    printf("Response from server: %s\n",buffer);

    //Close the connection
    close(sockfd);

    return 0;
}