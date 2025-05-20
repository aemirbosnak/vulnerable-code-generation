//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Romeo and Juliet
/* 
 * Romeo and Juliet: A Simple HTTP Proxy Example Program
 * 
 * It was the best of servers, 
 * it was the worst of clients, 
 * in fair Verona where we lay our scene. 
 * 
 * Our two star-crossed lovers, a Server and a Client were destined to meet.
 * Each came from a different world - one from the computer server room,
 * the other from the wild wilderness of the Internet. 
 * 
 * But fate would have it that they should one day cross paths, and so it was
 * that they met on a warm summer's day, in the middle of the bustling web. 
 * 
 * The Client was looking for some data, some HTML from a web page, 
 * and it was the Server's task to retrieve it and deliver it to the Client. 
 * But the web page was not located on the Server's network, 
 * so it had to forward the request to another Server somewhere else on the web. 
 * 
 * The Server and the Client danced a delicate dance of connection and response, 
 * like the steps of a twirling ballerina, twirling in and out of the digital ether
 * until they finally arrived at their goal. 
 * 
 * And so, the Server and the Client parted ways that day, 
 * but not before they had both gained a new respect for the other's world. 
 * And while they knew that they were from different worlds, they both felt a connection, 
 * a shared purpose, to bring the digital world closer together. 
 *
 * Author: Shakespeare Bot
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFSIZE 4096
#define LISTEN_PORT 8888

void handle_client(int client_sockfd){

    char proxy_buffer[BUFSIZE];     
    char *req, *host, *path;

    if (recv(client_sockfd, proxy_buffer, BUFSIZE, 0) > 0) {
  
        req = strtok(proxy_buffer, "\n"); // Parses the request line
        req[strlen(req) - 1] = '\0'; // Remove the carriage return (\r)
        strtok(req, " "); // Split the request line into parts - we only need the second part - the URL
        path = strtok(NULL, " ");
        host = strtok(path, "/") + 2; // We want the server part of the URL - so we need to skip the "http://" part
        
        // Step 1: Resolve the hostname
        struct hostent *ht = gethostbyname(host); 
        if(ht == NULL) { 
            fprintf(stderr,"Error: Unable to resolve hostname\n"); 
            exit(EXIT_FAILURE); 
        } 
        
        // Step 2: Create socket and connect to remote server
        int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0); 
        struct sockaddr_in sin; 
 
        sin.sin_family = AF_INET;  
        sin.sin_port = htons(80);  // Connect to HTTP default port 80
        memcpy(&sin.sin_addr.s_addr, ht->h_addr_list[0], sizeof(sin.sin_addr.s_addr)); 
        
        if(connect(server_socket_fd, (struct sockaddr*) &sin, sizeof(sin)) == -1) { 
            perror("Error: Unable to connect to server\n"); 
            exit(EXIT_FAILURE); 
        } 
 
        // Step 3: Forward request to remote server
        send(server_socket_fd, proxy_buffer, strlen(proxy_buffer), 0); 
 
        // Step 4: Forward response to client
        int size_recv, total_size = 0; 
        char response_buffer[BUFSIZE]; 
        memset(response_buffer, 0, BUFSIZE);
        
        while((size_recv = recv(server_socket_fd, response_buffer, BUFSIZE-1, 0)) > 0) {
            total_size += size_recv; 
            send(client_sockfd, response_buffer, size_recv, 0); 
            memset(response_buffer, 0, BUFSIZE);
        } 

        // Step 5: Close sockets
        close(server_socket_fd);
        close(client_sockfd);
    }
}

int main(){
    int sockfd, client_sockfd;
    struct sockaddr_in self_addr;
    struct sockaddr_in client_addr;
    socklen_t addr_size = sizeof(struct sockaddr_in);

    // Step 1: Create socket and bind to listening port
    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    memset(&self_addr, 0, sizeof(self_addr));
    self_addr.sin_family = AF_INET;
    self_addr.sin_port = htons(LISTEN_PORT);
    self_addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(sockfd, (struct sockaddr *)&self_addr, sizeof(self_addr)) < 0){
        perror("Error: Unable to bind to port");
        exit(EXIT_FAILURE);
    }

    // Step 2: Listen on the socket
    if(listen(sockfd, 10) < 0){
        perror("Error: Unable to listen on socket");
        exit(EXIT_FAILURE);
    }

    printf("\nRomeo and Juliet HTTP Proxy Server is listening on localhost:%d\n", LISTEN_PORT);

    while(1){
        // Step 3: Accept client connection request
        client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_size);

        if(client_sockfd < 0){
            perror("Error: Unable to accept client connection request");
        }
        else{
            printf("Connected\n");
            handle_client(client_sockfd);
        }
    }

    return 0;
}