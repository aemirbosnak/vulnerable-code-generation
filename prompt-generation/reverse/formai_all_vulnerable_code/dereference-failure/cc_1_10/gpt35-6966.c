//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>

#define MAXLINE 1024
#define MAXSOCKFD 64

int listenfd;
int clientfds[MAXSOCKFD];
fd_set allset;
int maxfd;

void handle_error(char* message){
    perror(message);
    exit(1);
}

void handle_signal(int signo){
    printf("Receive signal %d\n", signo);
    for(int i = 0; i < MAXSOCKFD; i++){
        if(clientfds[i] != -1){
            close(clientfds[i]);
        }
    }
    close(listenfd);
    exit(0);
}

void setup_server(char* ip_addr, int port_num){
    listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(listenfd < 0){
        handle_error("ERROR opening socket");
    }
    
    int opt = 1;
    if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0){
        handle_error("setsockopt error");
    }
    
    struct sockaddr_in serv_addr, cli_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_num);
    if(ip_addr){
        if(inet_pton(AF_INET, ip_addr, &(serv_addr.sin_addr)) <= 0){
            handle_error("inet_pton error");
        }
    } else{
        serv_addr.sin_addr.s_addr = INADDR_ANY;
    }
    
    if(bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
        handle_error("bind error");
    }
    
    if(listen(listenfd, 10) < 0){
        handle_error("listen error");
    }
    
    printf("Server is set up at %s:%d\n", ip_addr ? ip_addr : "0.0.0.0", port_num);
    
    for(int i = 0; i < MAXSOCKFD; i++){
        clientfds[i] = -1;
    }
    maxfd = listenfd;
    FD_ZERO(&allset);
    FD_SET(listenfd, &allset);
}

void handle_new_connection(){
    struct sockaddr_in cli_addr;
    socklen_t cli_size;
    int connfd;
    
    cli_size = sizeof(cli_addr);
    connfd = accept(listenfd, (struct sockaddr*)&cli_addr, &cli_size);
    
    if(connfd < 0){
        handle_error("accept error");
    }
    
    printf("New connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
    
    int i;
    for(i = 0; i < MAXSOCKFD; i++){
        if(clientfds[i] < 0){
            clientfds[i] = connfd;
            break;
        }
    }
    
    if(i == MAXSOCKFD){
        printf("Too many clients\n");
        close(connfd);
        return;
    }
    
    FD_SET(connfd, &allset);
    if(connfd > maxfd){
        maxfd = connfd;
    }
}

void handle_message(int sockfd){
    char buffer[MAXLINE];
    ssize_t n = read(sockfd, buffer, MAXLINE);
    
    if(n < 0){
        handle_error("read error");
    } else if(n == 0){
        printf("Client disconnected\n");
        close(sockfd);
        FD_CLR(sockfd, &allset);
        for(int i = 0; i < MAXSOCKFD; i++){
            if(clientfds[i] == sockfd){
                clientfds[i] = -1;
                break;
            }
        }
    } else{
        printf("Received message from client: %s\n", buffer);
        for(int i = 0; i < MAXSOCKFD; i++){
            if(clientfds[i] != -1 && clientfds[i] != sockfd){
                write(clientfds[i], buffer, strlen(buffer));
            }
        }
    }
}

int main(int argc, char** argv){
    if(argc < 2){
        printf("Usage: %s <port number>\n", argv[0]);
        exit(1);
    }
    
    signal(SIGINT, handle_signal);
    
    setup_server(NULL, atoi(argv[1]));
    
    while(1){
        fd_set rset = allset;
        int nready = select(maxfd+1, &rset, NULL, NULL, NULL);
        if(nready < 0){
            if(errno == EINTR){
                continue;
            }
            handle_error("select error");
        }
        if(FD_ISSET(listenfd, &rset)){
            handle_new_connection();
            nready--;
        }
        for(int i = 0; i < MAXSOCKFD && nready > 0; i++){
            int sockfd = clientfds[i];
            if(sockfd != -1 && FD_ISSET(sockfd, &rset)){
                handle_message(sockfd);
                nready--;
            }
        }
    }
    
    return 0;
}