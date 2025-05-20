//FormAI DATASET v1.0 Category: Firewall ; Style: beginner-friendly
#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(){
    int socket_fd, new_socket, client_sock, sock_len, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};
    char *message = "Hello Client! Welcome to the server.\n";
       
    //Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed.");
        exit(EXIT_FAILURE);
    }
       
    //Attaching socket to the port 8080
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Socket options assignment failed.");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
       
    //Binding the socket to server address
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Socket binding failed.");
        exit(EXIT_FAILURE);
    }
       
    //Creating queue for listening incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("Listen failed.");
        exit(EXIT_FAILURE);
    }

    sock_len = sizeof(client_addr);
    while(1){
        if ((new_socket = accept(socket_fd, (struct sockaddr *)&client_addr, (socklen_t*)&sock_len)) < 0) {
            perror("Accept failed.");
            exit(EXIT_FAILURE);
        }

        //Converts IP address from binary to text form
        char *client_ip = inet_ntoa(client_addr.sin_addr);
        printf("Connection established with %s\n", client_ip);

        //Blocking packets with specific IP
        if(strcmp(client_ip, "192.168.0.100") == 0){
            printf("Connection from IP %s is blocked!\n", client_ip);
            close(new_socket);
            continue; //Skip the packet from blocked IP
        }

        //Sending welcome message to client
        if(send(new_socket, message, strlen(message), 0) != strlen(message)){
            perror("Sending message failed.");
        }
        
        //Receiving data from client
        sock_len = recv(new_socket, buffer, BUFFER_SIZE, 0);
        printf("Received Message: %sFrom IP: %s\nTotal Bytes Received: %d\n", buffer, client_ip, sock_len);

        //Closing socket
        close(new_socket);    
    }
    return 0;
}