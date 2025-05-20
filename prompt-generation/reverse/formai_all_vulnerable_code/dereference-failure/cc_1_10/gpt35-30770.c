//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_SIZE 1024

typedef struct{
    char host[MAX_SIZE];
    int port;
    char path[MAX_SIZE];
} URL;

char* get_ip_address(char* hostname){
    struct hostent* he;
    struct in_addr** addr_list;
    if((he = gethostbyname(hostname)) == NULL){
        return NULL;
    }
    addr_list = (struct in_addr**) he->h_addr_list;
    for(int i = 0; addr_list[i] != NULL; i++){
        return inet_ntoa(*addr_list[i]);
    }
    return NULL;
}

void send_request(char* request, char* ip_address, int port){
    struct sockaddr_in server_address;
    int sock_fd;

    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if(inet_pton(AF_INET, ip_address, &server_address.sin_addr) <= 0){
        perror("Invalid IP Address");
        exit(EXIT_FAILURE);
    }

    if(connect(sock_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0){
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    if(send(sock_fd, request, strlen(request), 0) < 0){
        perror("Failed to send request");
        exit(EXIT_FAILURE);
    }

    char server_response[MAX_SIZE] = {0};
    if(read(sock_fd, server_response, sizeof(server_response)) < 0){
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", server_response);
    close(sock_fd);
}

void build_request(URL* url){
    char request[MAX_SIZE] = {0};
    strcat(request, "GET ");
    strcat(request, url->path);
    strcat(request, " HTTP/1.1\r\n");
    strcat(request, "Host: ");
    strcat(request, url->host);
    strcat(request, "\r\n");
    strcat(request, "Connection: close\r\n");
    strcat(request, "\r\n");

    char* ip_address = get_ip_address(url->host);
    send_request(request, ip_address, url->port);
}

void parse_url(char* url_str, URL* url){
    char* protocol;
    char* host;
    int port;
    char* path;

    protocol = strtok(url_str, "://");
    host = strtok(NULL, "/:");

    if((port = atoi(strtok(NULL, "/"))) == 0){
        port = 80;
    }

    path = strtok(NULL, "?#");

    strcpy(url->host, host);
    url->port = port;
    strcpy(url->path, path);
}

int main(){
    char url_str[MAX_SIZE] = {0};
    URL url;

    printf("Please enter the URL: ");
    fgets(url_str, MAX_SIZE, stdin);
    url_str[strcspn(url_str, "\n")] = 0;

    parse_url(url_str, &url);
    build_request(&url);

    return 0;
}