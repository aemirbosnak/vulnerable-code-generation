//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 8080

int main(){

    //Creating the server socket
    int server_fd, new_socket, val_read;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[4096] = {0};
    char response[4096] = {0};
    char *proxy_addr = "127.0.0.1";
    char *server_addr = "www.example.com";
    
    //Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("In socket");
        exit(EXIT_FAILURE);
    }
    
    //Set the socket option (allow multiple connections on same port)
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt");
        exit(EXIT_FAILURE);
    }
    
    //Set address server to bind
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(proxy_addr);
    address.sin_port = htons(PORT);
    
    //Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("In bind");
        exit(EXIT_FAILURE);
    }
    printf("Proxy is ready, listening on %s:%d\n", proxy_addr, PORT);
    
    while(1){
        //Listen for incoming connections on the server socket
        if (listen(server_fd, 3) < 0) {
            perror("In listen");
            exit(EXIT_FAILURE);
        }
        
        //Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("In accept");
            exit(EXIT_FAILURE);
        }
        
        printf("Client connection accepted!\n");
        
        //Create socket to connect to server
        int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        
        //Set server address to connect
        struct hostent *he = gethostbyname(server_addr);
        struct in_addr **addr_list;
        addr_list = (struct in_addr **) he->h_addr_list;
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_addr = *addr_list[0];
        server_address.sin_port = htons(80);
        
        //Connect to server
        connect(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
        
        //Read from client
        val_read = read(new_socket , buffer, 4096);
        printf("%s\n", buffer);
        
        //Send request to server
        send(server_sockfd, buffer, strlen(buffer), 0);
        
        //Read response from server
        int is_html = 0;
        val_read = read(server_sockfd, response, 4096);
        printf("%s\n", response);        
        if(strstr(response, "Content-Type: text/html")!=NULL)
            is_html = 1;
        
        //Send response back to client
        send(new_socket, response, strlen(response), 0);
        
        //Close sockets
        close(new_socket);
        close(server_sockfd);
        
        //Print stats
        printf("Request served!\n");
        if(is_html)
            printf("Content-Type: text/html\n");
        else
            printf("Content-Type: not html\n");
    }
    
    return 0;
}