//FormAI DATASET v1.0 Category: Socket programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int paranoid_send(int sock, char *buf, int len, int flags){
    if(len < 0 || len > 2048){
        printf("Invalid buffer length. Terminating connection.\n");
        close(sock);
        exit(EXIT_FAILURE);
    }

    if(!buf){
        printf("Null buffer detected. Terminating connection.\n");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // XOR encryption
    for(int i=0; i<len; i++){
        buf[i] ^= 0xFF;
    }

    int bytes_sent = send(sock, buf, len, flags);

    if(bytes_sent != len){
        printf("Failed to send complete message. Terminating connection.\n");
        close(sock);
        exit(EXIT_FAILURE);
    }

    return bytes_sent;
}

int paranoid_recv(int sock, char *buf, int len, int flags){
    if(len < 0 || len > 2048){
        printf("Invalid buffer length. Terminating connection.\n");
        close(sock);
        exit(EXIT_FAILURE);
    }

    int bytes_received = recv(sock, buf, len, flags);

    if(bytes_received < 0){
        printf("Failed to receive data. Terminating connection.\n");
        close(sock);
        exit(EXIT_FAILURE);
    }

    if(bytes_received == 0){
        printf("Connection terminated by remote host.\n");
        close(sock);
        exit(EXIT_SUCCESS);
    }

    // XOR decryption
    for(int i=0; i<bytes_received; i++){
        buf[i] ^= 0xFF;
    }

    return bytes_received;
}

int main(int argc, char const *argv[]) 
{ 
    int sock = 0; 
    struct sockaddr_in serv_addr; 

    char *hello = "Hello from client"; 
    char buffer[2048] = {0}; 

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){ 
        perror("Socket creation error"); 
        exit(EXIT_FAILURE); 
    } 

    // Assign values to server address struct
    memset(&serv_addr, '0', sizeof(serv_addr)); 
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IP address from string to binary
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){ 
        perror("Invalid address/ Address not supported"); 
        exit(EXIT_FAILURE); 
    } 

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){ 
        perror("Connection failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Send message to server
    paranoid_send(sock , hello , strlen(hello) , 0 ); 
    printf("Message sent to server: %s\n", hello); 

    // Receive message from server
    int bytes_received = paranoid_recv(sock, buffer, 2048, 0);

    printf("Server response: %s\n", buffer); 

    // Close socket
    close(sock);

    return 0; 
}