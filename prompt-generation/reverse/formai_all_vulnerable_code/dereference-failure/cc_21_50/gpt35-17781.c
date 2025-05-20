//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_CLIENTS 100
#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    int server_fd, client_socket[MAX_CLIENTS], max_clients = MAX_CLIENTS;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_BUFFER];
    fd_set read_fds;
    int max_sd, activity, sd, optval = 1;
    socklen_t client_len = sizeof(client_addr);
    
    // Create a server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }
    
    // Set server socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) < 0) {
        perror("Failed to set server socket options");
        exit(EXIT_FAILURE);
    }
    
    // Set server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    
    // Bind server socket to server address and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind server socket");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }
    
    printf("HTTP proxy server listening on port 8080\n");
    
    while (1) {
        // Clear file descriptor set
        FD_ZERO(&read_fds);
        
        // Add server file desciptor to set
        FD_SET(server_fd, &read_fds);
        max_sd = server_fd;
        
        // Add client file desciptors to set
        for (int i = 0; i < max_clients; i++) {
            sd = client_socket[i];
            
            if (sd > 0) {
                FD_SET(sd, &read_fds);
                
                if (sd > max_sd) {
                    max_sd = sd;
                }
            }
        }
        
        // Wait for activity on any file descriptor in set
        activity = select(max_sd + 1, &read_fds, NULL, NULL, NULL);
        
        if (activity < 0 && errno != EINTR) {
            perror("Error in select call");
            exit(EXIT_FAILURE);
        }
        
        // New connection request
        if (FD_ISSET(server_fd, &read_fds)) {
            int new_socket;
            
            if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
                perror("Error in accept call");
                exit(EXIT_FAILURE);
            }
            
            printf("New connection, socket fd is %d, IP is : %s, port : %d\n", new_socket, 
                    inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            
            // Add new socket to array of sockets
            for (int i = 0; i < max_clients; i++) {
                if (client_socket[i] == 0) {
                    client_socket[i] = new_socket;
                    printf("Adding to list of sockets as %d\n", i);
                    break;
                }
            }
        }
        
        // Incoming client data
        for (int i = 0; i < max_clients; i++) {
            sd = client_socket[i];
            
            if (FD_ISSET(sd, &read_fds)) {
                int bytes_read, target_fd;
                char target_host[MAX_BUFFER], target_port[MAX_BUFFER], target_buffer[MAX_BUFFER], *request_line, *request_method, *request_url, *request_version;
                
                if ((bytes_read = read(sd, buffer, MAX_BUFFER)) == 0) {
                    // Client disconnected
                    getpeername(sd, (struct sockaddr*)&client_addr, &client_len);
                    printf("Host disconnected, ip %s, port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                    close(sd);
                    client_socket[i] = 0;
                } else {
                    // Parse incoming HTTP request
                    request_line = strtok(buffer, "\n");
                    request_method = strtok(request_line, " ");
                    request_url = strtok(NULL, " ");
                    request_version = strtok(NULL, " \r");
                    
                    // Extract host and port from request URL
                    if (strncmp(request_url, "http://", 7) == 0) {
                        char *host_start = request_url + 7;
                        char *host_end = strstr(host_start, "/");
                        strncpy(target_host, host_start, host_end - host_start);
                        target_host[host_end - host_start] = '\0';
                        char *port_start = strstr(target_host, ":");
                        if (port_start == NULL) {
                            strcpy(target_port, "80");
                        } else {
                            strcpy(target_port, port_start + 1);
                            *port_start = '\0';
                        }
                    } else {
                        // Invalid request URL
                        printf("Invalid request URL: %s\n", request_url);
                        close(sd);
                        client_socket[i] = 0;
                        break;
                    }
                    
                    // Open connection to target server
                    if ((target_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                        perror("Error creating target socket");
                        break;
                    }
                    
                    struct hostent *host_info = gethostbyname(target_host);
                    if (host_info == NULL) {
                        perror("Error resolving target host");
                        close(target_fd);
                        break;
                    }
                    
                    struct sockaddr_in target_addr;
                    target_addr.sin_family = AF_INET; 
                    target_addr.sin_port = htons(atoi(target_port)); 
                    target_addr.sin_addr = *((struct in_addr*) host_info->h_addr);
                    
                    if (connect(target_fd, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
                        perror("Error connecting to target server");
                        close(target_fd);
                        break;
                    }
                    
                    // Forward the HTTP request to target server
                    sprintf(target_buffer, "%s %s %s\r\nHost: %s\r\nConnection: close\r\n\r\n", request_method, request_url, request_version, target_host);
                    if (write(target_fd, target_buffer, strlen(target_buffer)) < 0) {
                        perror("Error forwarding HTTP request to target server");
                        close(target_fd);
                        break;
                    }
                    
                    // Forward the response from target server to client
                    while ((bytes_read = read(target_fd, buffer, MAX_BUFFER)) > 0) {
                        if (write(sd, buffer, bytes_read) < 0) {
                            perror("Error forwarding HTTP response to client");
                            break;
                        }
                    }
                    
                    // Cleanup target socket
                    close(target_fd);
                }
            }
        }
    }
    
    return 0;
}