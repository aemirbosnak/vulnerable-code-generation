//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: automated
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    int port, sock, client_sock, read_val;
    struct sockaddr_in server, client;
    char message[1024];

    //Checking command line arguments
    if(argc < 2) {
        printf("Please provide port number as argument\n");
        return 1;
    }

    //Creating socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        printf("Could not create socket");
        return 1;
    }
    printf("Socket created successfully\n");

    //Preparing sockaddr_in structure
    port = atoi(argv[1]);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    //Binding socket with sockaddr_in structure
    if(bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Binding failed. Error");
        return 1;
    }
    printf("Binding done successfully\n");

    //Listening to incoming connections
    listen(sock, 3);

    //Accepting incoming connections
    printf("Waiting for incoming connections...\n");
    int c = sizeof(struct sockaddr_in);
    client_sock = accept(sock, (struct sockaddr *)&client, (socklen_t *)&c);
    if(client_sock < 0) {
        perror("Accepting failed. Error");
        return 1;
    }
    printf("Connection accepted successfully\n");

    //Reading incoming message
    memset(message, '\0', sizeof(message));
    read_val = read(client_sock, message, sizeof(message));
    if(read_val < 0) {
        perror("Reading failed. Error");
        return 1;
    }
    printf("Incoming message : %s\n", message);

    //Sending response
    char *response = "Message received successfully!";
    if(send(client_sock, response, strlen(response), 0) < 0) {
        perror("Sending failed. Error");
        return 1;
    }
    printf("Response sent successfully\n");

    //Closing sockets
    close(client_sock);
    close(sock);
    printf("Sockets closed successfully\n");

    return 0;
}