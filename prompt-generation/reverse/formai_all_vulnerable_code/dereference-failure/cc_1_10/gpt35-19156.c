//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 2048
#define IP_ADDR "127.0.0.1" // Change this to the IP address of your server
#define PORT_NUM 3000 // Change this to the port number of your server

int sock_fd; // Socket file descriptor

// This function handles signals and will print out the QoS results when ctrl+c is pressed
void sig_handler(int signo)
{
    if (signo == SIGINT){
        char buffer[BUFFER_SIZE];
        sprintf(buffer, "QoS Results:\n");
        send(sock_fd, buffer, BUFFER_SIZE, 0);
        
        // TODO: Implement your QoS metrics and append the results to the buffer
        
        printf("%s", buffer);
        close(sock_fd);
        exit(0);
    }
}

int main()
{
    // Set up signal handler for SIGINT (ctrl+c)
    signal(SIGINT, sig_handler);
    
    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1)
    {
        printf("Failed to create socket: %s\n", strerror(errno));
        exit(1);
    }
    
    // Set up address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT_NUM);
    server_addr.sin_addr.s_addr = inet_addr(IP_ADDR);
    
    // Connect to the server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){
        printf("Failed to connect to server: %s\n", strerror(errno));
        close(sock_fd);
        exit(1);
    }
    
    // Send a test message to the server
    char test_message[] = "Test message";
    send(sock_fd, test_message, sizeof(test_message), 0);
    
    // Receive response from server
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1){
        printf("Failed to receive message from server: %s\n", strerror(errno));
        close(sock_fd);
        exit(1);
    }
    printf("Received message from server: %s", buffer);
    
    // Close connection
    close(sock_fd);
    
    return 0;
}