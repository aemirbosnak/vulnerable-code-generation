//FormAI DATASET v1.0 Category: Networking ; Style: accurate
//Header Files
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

//Main Function
int main(int argc , char *argv[]) {
    int client_socket , port_number , result;
    struct sockaddr_in server_address;
    char *message , server_reply[2000];

    //Command Line Arguments
    if (argc < 2) {
        printf("Please provide the server IP address and port number\n");
        return 1;
    }

    //Create the client socket
    client_socket = socket(AF_INET , SOCK_STREAM , 0);
    if (client_socket == -1) {
        printf("Could not create socket\n");
    }

    //Server Details
    port_number = atoi(argv[2]);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr)<=0){
        printf("Invalid server IP address\n");
        return 1;
    }

    //Connect to remote server
    if (connect(client_socket , (struct sockaddr *)&server_address , sizeof(server_address)) < 0){
        printf("Could not connect to server\n");
        return 1;
    }

    //Send message to server
    message = "Hello server!\n";
    if( send(client_socket , message , strlen(message) , 0) < 0){
        printf("Could not send message\n");
        return 1;
    }

    //Receive a reply from the server
    if( recv(client_socket , server_reply , 2000 , 0) < 0){
        printf("Could not receive reply\n");
    }
    printf("Server replied: %s\n", server_reply);

    close(client_socket);

    return 0;
}