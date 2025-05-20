//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>
#include<errno.h>
#include<pthread.h>


//Define a struct to store client connection information
struct client_info {
    int client_socket;
    struct sockaddr_in client_addr;
};


//Function to handle individual client requests in a thread
void* handle_client(void* arg) {
    struct client_info* info = (struct client_info*)arg;
    int client_socket = info->client_socket;
    struct sockaddr_in client_addr = info->client_addr;
    free(arg);
    
    char request[1024];
    char method[16], path[64], version[16];
    memset(request, 0, sizeof(request));
    memset(method, 0, sizeof(method));
    memset(path, 0, sizeof(path));
    memset(version, 0, sizeof(version));
    
    read(client_socket, request, sizeof(request));
    sscanf(request, "%s %s %s", method, path, version);
    
    //Handle only GET methods
    if(strcmp(method, "GET") != 0) {
        char* message = "HTTP/1.1 405 Method Not Allowed\r\n\r\n";
        write(client_socket, message, strlen(message));
        close(client_socket);
        return NULL;
    }
    
    //Extract the host name from the request path
    int i;
    for(i=7; i<strlen(path); i++) {
        if(path[i] == '/') {
            break;
        }
    }
    char* hostname = (char*)malloc(i-6);
    memcpy(hostname, &path[7], i-7);
    hostname[i-7] = '\0';
    
    //Make a DNS lookup to get the IP address
    struct hostent* server_hp = gethostbyname(hostname);
    if(server_hp == NULL) {
        char* message = "HTTP/1.1 500 Internal Server Error\r\n\r\n";
        write(client_socket, message, strlen(message));
        close(client_socket);
        return NULL;
    }
    char* server_ip = inet_ntoa(*((struct in_addr*)server_hp->h_addr_list[0]));
    
    //Create a socket to connect to the web server
    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(server_socket < 0) {
        char* message = "HTTP/1.1 500 Internal Server Error\r\n\r\n";
        write(client_socket, message, strlen(message));
        close(client_socket);
        return NULL;
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(80);
    if(connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        char* message = "HTTP/1.1 500 Internal Server Error\r\n\r\n";
        write(client_socket, message, strlen(message));
        close(client_socket);
        return NULL;
    }
    
    //Build the request string to send to the web server
    char server_request[1024];
    memset(server_request, 0, sizeof(server_request));
    sprintf(server_request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", &path[i], hostname);
    
    //Send the request to the web server
    write(server_socket, server_request, strlen(server_request));
    
    //Read the response from the web server and send it to the client
    char response[1024];
    memset(response, 0, sizeof(response));
    int bytes_read;
    while((bytes_read = read(server_socket, response, sizeof(response))) > 0) {
        write(client_socket, response, bytes_read);
        memset(response, 0, sizeof(response));
    }
    
    //Close the sockets and return
    close(server_socket);
    close(client_socket);
    return NULL;
}


int main(int argc, char* argv[]) {
    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(server_socket < 0) {
        printf("Failed to create socket: %s\n", strerror(errno));
        return 1;
    }
    
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);
    if(bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to bind socket: %s\n", strerror(errno));
        return 1;
    }
    
    listen(server_socket, 5);
    printf("Simple HTTP Proxy started on port 8888\n");
    
    while(1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if(client_socket < 0) {
            printf("Failed to accept connection: %s\n", strerror(errno));
        }
        else {
            struct client_info* info = (struct client_info*)malloc(sizeof(struct client_info));
            info->client_socket = client_socket;
            int client_addr_size = sizeof(info->client_addr);
            getpeername(client_socket, (struct sockaddr*)&(info->client_addr), (socklen_t*)&client_addr_size);
            pthread_t thread;
            pthread_create(&thread, NULL, handle_client, (void*)info);
            pthread_detach(thread);
        }
    }
    
    close(server_socket);
    return 0;
}