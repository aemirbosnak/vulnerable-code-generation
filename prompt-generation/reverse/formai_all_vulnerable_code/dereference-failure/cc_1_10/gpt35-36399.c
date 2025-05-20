//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    
    if (argc != 4) {
        printf("Usage: ./program <server_ip> <server_port> <path_to_page>\n");
        return 1;
    }
    
    const char *server_ip = argv[1];
    const int server_port = atoi(argv[2]);
    const char *path_to_page = argv[3];
    
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);
    
    int client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client_socket < 0) {
        printf("Error: Could not create socket\n");
        return 1;
    }
    
    int connect_status = connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (connect_status < 0) {
        printf("Error: Could not connect to server\n");
        return 1;
    }
    
    char request[1000];
    sprintf(request, "GET %s HTTP/1.0\r\nHost: %s:%d\r\nUser-Agent: HTTPClient/1.0\r\n\r\n", path_to_page, server_ip, server_port);
    
    int send_status = send(client_socket, request, strlen(request), 0);
    if (send_status < 0) {
        printf("Error: Could not send request to server\n");
        return 1;
    }
    
    char response[100000];
    memset(response, 0, sizeof(response));
    
    int response_size = recv(client_socket, response, sizeof(response), 0);
    if (response_size < 0) {
        printf("Error: Could not receive response from server\n");
        return 1;
    }
    
    printf("Server response:\n%s\n", response);
    
    close(client_socket);
    
    return 0;
}