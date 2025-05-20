//FormAI DATASET v1.0 Category: Networking ; Style: beginner-friendly
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <errno.h> 
  
#define PORT 8080 

// Function to create a Socket
int createSocket() 
{ 
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        perror("Error creating socket"); 
        exit(EXIT_FAILURE); 
    } 
    return sockfd; 
} 

// Function to connect to Server
void connectToServer(int sockfd, struct sockaddr_in server_address) 
{ 
    int connection_status = connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)); 
    if (connection_status == -1) { 
        perror("Error connecting to server"); 
        exit(EXIT_FAILURE); 
    } 
} 

// Function to Send Data
void sendData(int sockfd, char* buffer) 
{ 
    int bytes_sent = send(sockfd, buffer, strlen(buffer), 0); 
    if (bytes_sent == -1) { 
        perror("Error sending data to server"); 
        exit(EXIT_FAILURE); 
    } 
} 

// Function to Receive Data
void receiveData(int sockfd, char* buffer) 
{ 
    int bytes_received = recv(sockfd, buffer, 1024, 0); 
    if (bytes_received == -1) { 
        perror("Error receiving data from server"); 
        exit(EXIT_FAILURE); 
    } 
    buffer[bytes_received] = '\0'; 
} 

// Driver Function
int main(int argc, char* argv[]) 
{ 
    int sockfd; 
    struct sockaddr_in server_address; 
    char buffer[1024] = {0}; 
    
    // Creating Socket
    sockfd = createSocket(); 

    // Assigning Server Address
    memset(&server_address, '0', sizeof(server_address)); 
    server_address.sin_family = AF_INET; 
    server_address.sin_port = htons(PORT); 
    int return_value = inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr); 
    if (return_value == -1) { 
        perror("Error assigning server address"); 
        exit(EXIT_FAILURE); 
    } 

    // Connecting to Server
    connectToServer(sockfd, server_address); 
    
    // Sending Data to Server
    char* message = "Hello from client"; 
    sendData(sockfd, message); 
    printf("Data sent to server: %s\n", message); 
    
    // Receiving Data from Server
    receiveData(sockfd, buffer); 
    printf("Data received from server: %s\n", buffer); 
  
    close(sockfd); 
    return 0; 
}