//FormAI DATASET v1.0 Category: Client Server Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

//function to display error messages
void errorMsg(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    //checking if both port number and client name/ip are not provided
    if(argc < 3){
        fprintf(stderr, "Port number or client name/ip not provided\n");
        exit(1);
    }

    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    //creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        errorMsg("ERROR opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    //binding socket with port number
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        errorMsg("ERROR on binding");
    }

    //listening for incoming requests with a queue of size 5
    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    //accepting connection request
    newsockfd = accept(sockfd, 
                (struct sockaddr *) &cli_addr, 
                &clilen);

    if (newsockfd < 0) {
        errorMsg("ERROR on accept");
    }

    //displaying client ip address and port number
    printf("Client connected from %s port %d\n", 
                inet_ntoa(cli_addr.sin_addr),
                ntohs(cli_addr.sin_port));

    while(1){
        bzero(buffer,256);

        //receiving message from client
        n = read(newsockfd,buffer,255);

        if (n < 0) {
            errorMsg("ERROR reading from socket");
        }

        printf("Message from Client: %s\n",buffer);

        if(strcmp(buffer, "quit\n") == 0){
            break;
        }

        bzero(buffer,256);
        //sending message back to client
        printf("Enter Message for Client: ");
        fgets(buffer, 255, stdin);
        n = write(newsockfd,buffer,strlen(buffer));

        if (n < 0) {
            errorMsg("ERROR writing to socket");
        }
    }

    //closing open sockets
    close(newsockfd);
    close(sockfd);

    return 0; 
}