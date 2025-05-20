//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUF_SIZE 4096

void proxy(int client_socket, char *host_name, int port){

    char buffer[BUF_SIZE];
    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(server_socket < 0){
        perror("error creating server socket.");
        exit(1);
    }

    struct hostent *host = gethostbyname(host_name);
    struct sockaddr_in server_address = {0};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if((host == NULL) || (host->h_addr == NULL)){
        printf("Unknown host %s.\n", host_name);
        exit(1);
    }

    memcpy((char*) &server_address.sin_addr.s_addr, host->h_addr, host->h_length);
    if(connect(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0){
        perror("error connecting to server socket.");
        exit(1);
    }

    printf("Connected to %s:%d\n", host_name, port);

    while(1){
        memset(buffer, 0, BUF_SIZE);
        int bytes_read_client = read(client_socket, buffer, BUF_SIZE);
        if(bytes_read_client <= 0)
            break;

        write(server_socket, buffer, bytes_read_client);
        memset(buffer, 0, BUF_SIZE);
        int bytes_read_server = read(server_socket, buffer, BUF_SIZE);
        if(bytes_read_server <= 0)
            break;

        write(client_socket, buffer, bytes_read_server);
    }

    close(client_socket);
    close(server_socket);
    printf("Connection closed\n");
}

int main(int argc, char* argv[]){

    if(argc != 3){
        printf("Usage: proxy [host] [port]\n");
        exit(1);
    }

    int port = atoi(argv[2]);
    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(server_socket < 0){
        perror("error creating server socket.");
        exit(1);
    }

    struct sockaddr_in server_address = {0};
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);

    if(bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0){
        perror("error binding server socket.");
        exit(1);
    }

    if(listen(server_socket, 100) < 0){
        perror("error listening on server socket.");
        exit(1);
    }
    
    while(1){
        struct sockaddr_in client_address = {0};
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_length);
        if(client_socket < 0){
            perror("error accepting client socket.");
            exit(1);
        }

        char *client_ip = inet_ntoa(client_address.sin_addr);
        printf("Accepted connection from %s:%d\n", client_ip, ntohs(client_address.sin_port));
        proxy(client_socket, argv[1], port);
    }

    return 0;
}