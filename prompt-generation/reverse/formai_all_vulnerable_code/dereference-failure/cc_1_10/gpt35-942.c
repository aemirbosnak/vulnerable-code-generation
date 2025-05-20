//FormAI DATASET v1.0 Category: Networking ; Style: content
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(int argc, char** argv){

    /* Checking arguments*/
    if(argc != 3){
        printf("Please enter two arguments: %s <server ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Converting input to usable variables*/
    char* server_ip = argv[1];
    int port = atoi(argv[2]);
    
    /* Creating socket descriptor for client*/
    int client_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(client_sock_fd < 0){
        printf("There was an error creating the socket\n");
        exit(EXIT_FAILURE);
    }

    /* Preparing server information*/
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(server_ip);
    serv_addr.sin_port = htons(port);

    /* Connecting to server*/
    if(connect(client_sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
        printf("There was an error connecting to the server\n");
        exit(EXIT_FAILURE);
    }

    /* Communication with server*/
    printf("Connection to server successful, enter messages to send or 'exit' to end:\n");
    char message[512] = {0};
    while(strncmp(message, "exit", 4) != 0){

        /* Reading client input*/
        fgets(message, 512, stdin);
        message[strcspn(message, "\n")] = 0;

        /* Sending message to server*/
        int send_res = send(client_sock_fd, message, strlen(message), 0);
        if(send_res < 0){
            printf("There was an error sending the message\n");
            exit(EXIT_FAILURE);
        }

        /* Receiving response from server*/
        char response[512] = {0};
        int recv_res = recv(client_sock_fd, response, 512, 0);
        if(recv_res < 0){
            printf("There was an error receiving the response\n");
            exit(EXIT_FAILURE);
        }

        printf("Server response: %s\n", response);
    }

    /* Closing connection*/
    close(client_sock_fd);
    printf("Connection closed\n");

    return 0;
}