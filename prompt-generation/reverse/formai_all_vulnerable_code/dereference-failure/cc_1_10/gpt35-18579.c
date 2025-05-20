//FormAI DATASET v1.0 Category: Simple Web Server ; Style: recursive
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 

#define BUFSIZE 1024
#define PORT 8080

int send_file(int fd, int sockfd) 
{ 
    char buffer[BUFSIZE]; 
    ssize_t bytes_read; 
  
    bytes_read = read(fd, buffer, BUFSIZE); 
    if (bytes_read == -1) { 
        perror("read"); 
        return -1; 
    } 
    if (bytes_read == 0) { 
        return 0; 
    } 
  
    if (send(sockfd, buffer, bytes_read, 0) == -1) { 
        perror("send"); 
        return -1; 
    } 
  
    return send_file(fd, sockfd); 
} 

int handle_request(int sockfd) 
{ 
    char buffer[BUFSIZE]; 
    ssize_t bytes_read; 

    memset(buffer, 0, sizeof(buffer)); 
    bytes_read = recv(sockfd, buffer, sizeof(buffer), 0); 
    if (bytes_read == -1) { 
        perror("recv"); 
        return -1; 
    } 
    if (bytes_read == 0) { 
        return 0; 
    } 
  
    char *method, *url, *http_version; 
    method = strtok(buffer, " \t\r\n"); 
    url = strtok(NULL, " \t"); 
    http_version = strtok(NULL, " \t\r\n"); 
  
    if (strcmp(method, "GET") != 0) { 
        write(sockfd, "HTTP/1.0 501 Not Implemented\r\n", 30); 
        return -1; 
    } 
  
    char filename[1024]; 
    char *p = url+1; 
    sprintf(filename, "%s", p); 

    int fd = open(filename, O_RDONLY); 
    if (fd == -1) { 
        write(sockfd, "HTTP/1.0 404 Not Found\r\n", 23); 
        return -1; 
    } 
  
    struct stat filestat; 
    fstat(fd, &filestat); 
    if (S_ISDIR(filestat.st_mode)) { 
        write(sockfd, "HTTP/1.0 404 Not Found\r\n", 23); 
        return -1; 
    } 
  
    char header[1024]; 
    int len = filestat.st_size; 
    sprintf(header, "HTTP/1.0 200 OK\r\nContent-Length: %d\r\n\r\n", len); 
    write(sockfd, header, strlen(header)); 
  
    send_file(fd, sockfd); 
    close(fd); 
    return 0; 
} 

void start_server() 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd < 0) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
  
    memset(&servaddr, 0, sizeof(servaddr)); 
  
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
  
    if (listen(sockfd, 5) < 0) { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
  
    while (1) { 
        socklen_t len = sizeof(cli); 
        connfd = accept(sockfd, (struct sockaddr*)&cli, &len); 
        if (connfd < 0) { 
            perror("accept"); 
            exit(EXIT_FAILURE); 
        } 
  
        handle_request(connfd); 

        close(connfd); 
    } 
} 

int main() 
{ 
    start_server(); 
    return 0; 
}