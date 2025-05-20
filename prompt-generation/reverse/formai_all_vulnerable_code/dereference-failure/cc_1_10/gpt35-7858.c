//FormAI DATASET v1.0 Category: Client Server Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

void error(char *msg){
    printf("%s\n",msg);
    exit(1);
}

int main(int argc, char *argv[]){

    int status, sockfd, clientfd, portnumber;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    //Check the arguments list
    if(argc < 2){
        error("Usage: ./server <port>");
    }

    portnumber = atoi(argv[1]);

    //Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        error("Socket creation failed");
    }

    //Initialize server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portnumber);

    //Bind the socket
    status = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if(status < 0){
        error("Binding error");
    }

    //Listen for connections
    status = listen(sockfd, 5);
    if(status < 0){
        error("Listening error");
    }

    printf("Server running on port %d\n", portnumber);

    //Accept connections
    clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if(clientfd < 0){
        error("Error accepting connection");
    }

    printf("Client connected\n");

    //Send message to client
    char message[] = "Server: Welcome to my unique Client-Server Application!\n";
    status = send(clientfd, message, strlen(message), 0);
    if(status < 0){
        error("Error sending message");
    }

    //Receive message from client
    char buffer[256];
    memset(buffer, 0, 256);
    status = recv(clientfd, buffer, 255, 0);
    if(status < 0){
        error("Error receiving message");
    }

    printf("Client: %s\n", buffer);

    //Close sockets
    close(clientfd);
    close(sockfd);

    return 0;
}