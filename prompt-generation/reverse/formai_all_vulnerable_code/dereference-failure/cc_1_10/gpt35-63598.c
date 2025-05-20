//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv){

    if(argc != 4){
        printf("Usage : %s [IP ADDRESS] [PORT] [PAGE NAME]\n", argv[0]);
        return 1;
    }

    //Create a socket
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(client_sock == -1){
        perror("Failed to create socket");
        return 1;
    }

    //Create server address struct
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    server_address.sin_addr.s_addr = inet_addr(argv[1]);

    //Connect to server
    if(connect(client_sock, (struct sockaddr*)&server_address, sizeof(server_address)) == -1){
        perror("Failed to connect with server");
        return 1;
    }

    //Prepare request message
    char request[BUFFER_SIZE];
    sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s:%s\r\n\r\n", argv[3], argv[1], argv[2]);

    //Send request to server
    if(send(client_sock, request, strlen(request), 0) == -1){
        perror("Failed to send request to server");
        return 1;
    }

    //Receive response from server
    char response[BUFFER_SIZE];
    int bytes_received = recv(client_sock, response, BUFFER_SIZE, 0);
    if(bytes_received == -1){
        perror("Failed to receive response from server");
        return 1;
    }

    //Print response
    printf("%s", response);

    //Cleanup
    close(client_sock);

    return 0;
}