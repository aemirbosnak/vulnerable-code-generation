//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MAX_LENGTH 1024
#define MAX_THREADS 5

typedef struct{
    int fd;
    char path[MAX_LENGTH];
} thread_param;

void *ftp_client(void *param){
    thread_param *tp = (thread_param*) param;
    char buffer[MAX_LENGTH];
    ssize_t bytes_read, bytes_sent;

    // open file
    int file_descriptor = open(tp->path, O_RDONLY);
    if(file_descriptor == -1){
        perror("Error opening file");
        return NULL;
    }

    // read file
    while((bytes_read = read(file_descriptor, buffer, MAX_LENGTH)) > 0){
        // send data to server
        bytes_sent = send(tp->fd, buffer, bytes_read, 0);
        if(bytes_sent == -1){
            perror("Error sending data to server");
            break;
        }
    }

    // close file and socket
    close(file_descriptor);
    close(tp->fd);

    return NULL;
}

void create_thread(char *server_ip, int port, char *file_path){
    // create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1){
        perror("Error creating socket");
        return;
    }

    // set server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if(inet_pton(AF_INET, server_ip, &server_addr.sin_addr) == -1){
        perror("Error setting server address");
        return;
    }

    // connect to server
    if(connect(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1){
        perror("Error connecting to server");
        return;
    }

    // create thread parameter and start thread
    thread_param *tp = malloc(sizeof(thread_param));
    tp->fd = server_fd;
    strcpy(tp->path, file_path);
    pthread_t thread_id;
    if(pthread_create(&thread_id, NULL, ftp_client, (void*) tp) == -1){
        perror("Error creating thread");
        return;
    }
}

int main(){
    char server_ip[MAX_LENGTH], file_path[MAX_LENGTH];
    int port;

    printf("Enter server IP: ");
    fgets(server_ip, MAX_LENGTH, stdin);
    printf("Enter port number: ");
    scanf("%d", &port);
    printf("Enter file path: ");
    scanf("%s", file_path);

    create_thread(server_ip, port, file_path);

    return 0;
}