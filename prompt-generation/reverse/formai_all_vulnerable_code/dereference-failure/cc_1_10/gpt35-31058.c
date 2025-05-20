//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_RECV_BUF_SIZE 4096
#define MAX_SEND_BUF_SIZE 4096

/* Method to create a new socket */
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    
    return sockfd;
}

/* Method to connect to the specified server */
int connect_to_server(int sockfd, char *server_name, int server_port) {
    struct sockaddr_in server_address;
    
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    
    struct hostent *server = gethostbyname(server_name);
    if (server == NULL) {
        perror("Error resolving hostname");
        exit(1);
    }
    
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
    
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }
    
    return sockfd;
}

/* Method to send an HTTP GET request to the specified server */
void send_http_get_request(int sockfd, char *resource_path, char *host_name) {
    char send_buf[MAX_SEND_BUF_SIZE];
    memset(send_buf, 0, MAX_SEND_BUF_SIZE);
    sprintf(send_buf, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", resource_path, host_name);
    
    if (send(sockfd, send_buf, strlen(send_buf), 0) < 0) {
        perror("Error sending HTTP GET request");
        exit(1);
    }
}

/* Method to receive the HTTP response from the server */
void receive_http_response(int sockfd) {
    char recv_buf[MAX_RECV_BUF_SIZE];
    int len;
    
    while ((len = recv(sockfd, recv_buf, MAX_RECV_BUF_SIZE, 0)) > 0) {
        fwrite(recv_buf, 1, len, stdout);
    }
    
    if (len < 0) {
        perror("Error receiving HTTP response");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server_name> <server_port>\n", argv[0]);
        exit(1);
    }
    
    char *server_name = argv[1];
    int server_port = atoi(argv[2]);
    
    int sockfd = create_socket();
    sockfd = connect_to_server(sockfd, server_name, server_port);
    
    send_http_get_request(sockfd, "/", server_name);
    receive_http_response(sockfd);
    
    close(sockfd);
    
    return 0;
}