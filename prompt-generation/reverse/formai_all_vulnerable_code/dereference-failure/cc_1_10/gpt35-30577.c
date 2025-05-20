//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>
#include <netdb.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int sockfd, new_sockfd, max_fd, ret, flags;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    fd_set set;
    struct timeval timeout;
    
    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }
    
    // set server_addr values
    memset(&server_addr, 0, sizeof(server_addr)); // clear structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    // bind socket to address and port
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error binding socket");
    }
    
    // start listening for incoming connections
    if (listen(sockfd, 5) < 0) {
        error("Error listening for connections");
    }
    
    // set socket to non-blocking mode
    flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
    
    // set select() parameters
    FD_ZERO(&set);
    FD_SET(sockfd, &set);
    max_fd = sockfd;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    
    // main loop
    while (true) {
        // wait for incoming connections or incoming data
        ret = select(max_fd + 1, &set, NULL, NULL, &timeout);
        
        if (ret == -1) {
            error("Error in select()");
        } else if (ret == 0) {
            printf("Timeout\n");
        } else {
            if (FD_ISSET(sockfd, &set)) {
                // accept new connection
                socklen_t client_len = sizeof(client_addr);
                new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
                if (new_sockfd < 0) {
                    error("Error accepting connection");
                }
                
                // set new_sockfd to non-blocking mode
                flags = fcntl(new_sockfd, F_GETFL, 0);
                fcntl(new_sockfd, F_SETFL, flags | O_NONBLOCK);
                
                // add new_sockfd to set
                FD_SET(new_sockfd, &set);
                
                // update max_fd if needed
                if (new_sockfd > max_fd) {
                    max_fd = new_sockfd;
                }
                
                // print client address
                char *client_ip = inet_ntoa(client_addr.sin_addr);
                printf("New connection from %s\n", client_ip);
            } else {
                // receive data
                int bytes_received = recv(new_sockfd, buffer, BUFFER_SIZE, 0);
                if (bytes_received < 0) {
                    error("Error receiving data");
                } else if (bytes_received == 0) {
                    // connection closed by client
                    close(new_sockfd);
                    FD_CLR(new_sockfd, &set);
                    printf("Connection closed\n");
                } else {
                    // display received data
                    buffer[bytes_received] = '\0';
                    printf("Received: %s\n", buffer);
                    
                    // send response
                    char *response = "Response from server";
                    int bytes_sent = send(new_sockfd, response, strlen(response), 0);
                    if (bytes_sent < 0) {
                        error("Error sending response");
                    }
                }
            }
        }
    }
    
    return 0;
}