//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: multiplayer
#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  
#include <string.h>  
#include <sys/socket.h>  
#include <sys/types.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <unistd.h>  
#include <netdb.h>  
#include <errno.h>  

// Function declarations  
bool is_proxy_request(char *buffer);  
int get_request_header_length(char *buffer);  
char *get_host_name(char *buffer, int header_length);  
void parse_request(char *buffer, int header_length);  
bool connect_to_server(char *host_name, int port, int *server_socket);  

int main(int argc, char *argv[])  
{  
    if (argc != 2) {  
        fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);  
        exit(EXIT_FAILURE);  
    }  

    int proxy_port = atoi(argv[1]);  

    int server_socket, client_socket;  
    char buffer[10000];  

    struct sockaddr_in proxy_address, client_address;  
    socklen_t address_length = sizeof(client_address);  

    // create proxy server socket  
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {  
        perror("Failed to create socket");  
        exit(EXIT_FAILURE);  
    }  

    // set proxy server socket options  
    int opt = 1;  
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {  
        perror("Failed to set socket options");  
        exit(EXIT_FAILURE);  
    }  

    // bind proxy server socket to localhost and given port number  
    proxy_address.sin_family = AF_INET;  
    proxy_address.sin_addr.s_addr = INADDR_ANY;  
    proxy_address.sin_port = htons(proxy_port);  

    if (bind(server_socket, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) < 0) {  
        perror("Failed to bind socket");  
        exit(EXIT_FAILURE);  
    }  

    // listen for incoming connections from client  
    if (listen(server_socket, 3) < 0) {  
        perror("Failed to listen for connections");  
        exit(EXIT_FAILURE);  
    }  

    printf("Proxy server is running on port %d\n", proxy_port);  

    // accept incoming connections from client  
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &address_length))) {  
        // receive request from client  
        memset(buffer, 0, sizeof(buffer));  
        int read_result = read(client_socket, buffer, sizeof(buffer));  

        if (read_result < 0) {  
            perror("Failed to receive client request");  
            exit(EXIT_FAILURE);  
        }  

        // check if request is a proxy request  
        if (is_proxy_request(buffer)) {  
            int header_length = get_request_header_length(buffer);  

            char *host_name = get_host_name(buffer, header_length);  

            parse_request(buffer, header_length);  

            connect_to_server(host_name, 80, &server_socket);  
        }  

        // forward request to server  
        if (write(server_socket, buffer, strlen(buffer)) < 0) {  
            perror("Failed to send request to server");  
            exit(EXIT_FAILURE);  
        }  

        // receive response from server  
        memset(buffer, 0, sizeof(buffer));  
        read(server_socket, buffer, sizeof(buffer));  

        // forward response to client  
        if (write(client_socket, buffer, strlen(buffer)) < 0) {  
            perror("Failed to send response to client");  
            exit(EXIT_FAILURE);  
        }  

        close(client_socket);  
    }  

    exit(EXIT_SUCCESS);  
}  

bool is_proxy_request(char *buffer)  
{  
    if (strncmp(buffer, "CONNECT", 7) == 0) {  
        return true;  
    }  

    return false;  
}  

int get_request_header_length(char *buffer)  
{  
    char *header_end = strstr(buffer, "\r\n\r\n");  

    if (header_end == NULL) {  
        return 0;  
    }  

    return (int)(header_end - buffer) + 4;  
}  

char *get_host_name(char *buffer, int header_length)  
{  
    char *host_start = strstr(buffer, "Host: ") + 6;  

    if (host_start == NULL) {  
        return NULL;  
    }  

    char *host_end = strstr(host_start, "\r\n");  

    if (host_end == NULL) {  
        return NULL;  
    }  

    int host_length = (int)(host_end - host_start);  

    char *host_name = calloc(host_length + 1, sizeof(char));  

    strncpy(host_name, host_start, host_length);  

    return host_name;  
}  

void parse_request(char *buffer, int header_length)  
{  
    char *request_start = buffer + header_length;  
    char *request_end = strstr(request_start, "HTTP/1.1");  

    if (request_end == NULL) {  
        return;  
    }  

    int request_length = (int)(request_end - request_start);  

    char *request = calloc(request_length + 1, sizeof(char));  

    strncpy(request, request_start, request_length);  

    printf("Request:\n%s\n", request);  
}  

bool connect_to_server(char *host_name, int port, int *server_socket)  
{  
    // get server host information  
    struct hostent *server_host = gethostbyname(host_name);  

    if (server_host == NULL) {  
        perror("Failed to get server host information");  
        return false;  
    }  

    // create server socket  
    if ((*server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {  
        perror("Failed to create server socket");  
        return false;  
    }  

    struct sockaddr_in server_address;  
    memset(&server_address, '0', sizeof(server_address));  

    server_address.sin_family = AF_INET;  
    server_address.sin_port = htons(port);  
    server_address.sin_addr = *((struct in_addr *)server_host->h_addr);  

    // connect to server  
    if (connect(*server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {  
        perror("Failed to connect to server");  
        return false;  
    }  

    printf("Connected to %s:%d\n", host_name, port);  

    return true;  
}