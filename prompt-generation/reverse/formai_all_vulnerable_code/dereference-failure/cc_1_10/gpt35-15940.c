//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_MSG_LENGTH 1024

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Usage: ./client <ip> <port>\n");
        return -1;
    }
    int port = atoi(argv[2]);
    char *server_ip = argv[1];

    //Create socket
    int socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1){
        printf("Could not create socket");
        return -1;
    }

    //Set server address
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(server_ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    //Connect to remote server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0){
        printf("Connection error");
        return -1;
    }

    printf("Connected to server!\n");

    char msg[MAX_MSG_LENGTH];
    while(1){
        //Prompt user for input
        printf("Enter message: ");
        fgets(msg, MAX_MSG_LENGTH, stdin);

        //Send the message
        if(send(socket_desc , msg , strlen(msg) , 0) < 0){
            printf("Send failed");
            return -1;
        }
        printf("Message Sent!\n");

        //Receive a reply from the server
        char server_reply[MAX_MSG_LENGTH];
        if(recv(socket_desc, server_reply, MAX_MSG_LENGTH, 0) < 0){
            printf("Receive failed");
        }

        //Print server's reply
        printf("Server reply: %s", server_reply);
    }

    //Close the socket
    close(socket_desc);

    return 0;
}