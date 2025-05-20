//FormAI DATASET v1.0 Category: Networking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024
#define DEFAULT_PORT 8080

int main(int argc , char *argv[])
{
    int socket_desc, client_sock, read_size;
    struct sockaddr_in server, client;
    char client_message[MAX_BUFFER_SIZE];

    //Set default port
    int port = DEFAULT_PORT;

    //Check for command line arguments
    if(argc > 1) {
        port = atoi(argv[1]);
    }

    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1) {
        perror("Could not create socket");
        return 1;
    }

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    //Bind socket to port
    if (bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("Could not bind socket to port");
        return 1;
    }

    //Listen for incoming connections
    listen(socket_desc , 3);

    //Accept incoming connection
    int client_size = sizeof(struct sockaddr_in);
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&client_size);
    if (client_sock < 0) {
        perror("Could not accept incoming connection");
        return 1;
    }

    //Send welcome message to client
    char *welcome_message = "Welcome to the server!";
    write(client_sock , welcome_message , strlen(welcome_message));

    //Handle incoming messages from client
    while( (read_size = recv(client_sock , client_message , MAX_BUFFER_SIZE , 0)) > 0 ) {
        //End of string marker
        client_message[read_size] = '\0';

        //Print message received from client
        printf("Message received from client: %s\n", client_message);

        //Send message back to client
        write(client_sock , client_message , strlen(client_message));
    }

    if(read_size == 0) {
        printf("Client disconnected\n");
    } else if(read_size == -1) {
        perror("Could not receive message from client");
    }

    //Close connection
    close(client_sock);
    close(socket_desc);

    return 0;
}