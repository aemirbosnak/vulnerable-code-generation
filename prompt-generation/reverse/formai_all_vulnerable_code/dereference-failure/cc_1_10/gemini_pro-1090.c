//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: shocked
// Welcome to the mind-boggling C Client-Server Extravaganza!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Server's exhilarating experience
void server() {
    int listen_fd, conn_fd;
    socklen_t addr_len;
    struct sockaddr_in serv_addr, client_addr;
    
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("Thunderstruck! Socket creation failed!");
        exit(EXIT_FAILURE);
    }
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5678);
    
    if (bind(listen_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("Wham! Bind malfunctioned!");
        exit(EXIT_FAILURE);
    }
    
    if (listen(listen_fd, 10) == -1) {
        perror("Ouch! Listen operation failed!");
        exit(EXIT_FAILURE);
    }
    
    conn_fd = accept(listen_fd, (struct sockaddr *) &client_addr, &addr_len);
    if (conn_fd == -1) {
        perror("Whoa! Accept operation went haywire!");
        exit(EXIT_FAILURE);
    }
    
    char buffer[1024];
    while (1) {
        int bytes_received = recv(conn_fd, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            perror("Zapped! Receive operation failed!");
            exit(EXIT_FAILURE);
        } else if (bytes_received == 0) {
            printf("Client has vanished into thin airs!\n");
            break;
        }
        
        printf("Received from the client: %s\n", buffer);
        
        printf("Enter your message to the client: ");
        fflush(stdout);
        fgets(buffer, sizeof(buffer), stdin);
        
        int bytes_sent = send(conn_fd, buffer, strlen(buffer), 0);
        if (bytes_sent == -1) {
            perror("Darn! Send operation failed!");
            exit(EXIT_FAILURE);
        }
    }
    
    close(conn_fd);
    close(listen_fd);
}

// Client's exhilarating experience
void client(char *ip_addr) {
    int sock_fd;
    struct sockaddr_in serv_addr;
    
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("Socket creation? Mind blown!");
        exit(EXIT_FAILURE);
    }
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5678);
    serv_addr.sin_addr.s_addr = inet_addr(ip_addr);
    
    if (connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("Connection? No way, dude!");
        exit(EXIT_FAILURE);
    }
    
    char buffer[1024];
    while (1) {
        printf("Enter your message to the server: ");
        fflush(stdout);
        fgets(buffer, sizeof(buffer), stdin);
        
        int bytes_sent = send(sock_fd, buffer, strlen(buffer), 0);
        if (bytes_sent == -1) {
            perror("Sending? Not my thing, man!");
            exit(EXIT_FAILURE);
        }
        
        int bytes_received = recv(sock_fd, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            perror("Receiving? Nah, that's lame!");
            exit(EXIT_FAILURE);
        } else if (bytes_received == 0) {
            printf("Server has vamoosed!\n");
            break;
        }
        
        printf("Received from the server: %s\n", buffer);
    }
    
    close(sock_fd);
}

// The grand finale!
int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Hey, where's the server IP address and mode (server/client)?");
        exit(EXIT_FAILURE);
    }
    
    if (strcmp(argv[2], "server") == 0) {
        server();
    } else if (strcmp(argv[2], "client") == 0) {
        client(argv[1]);
    } else {
        printf("What's this mode (server/client) you're talking about?");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}