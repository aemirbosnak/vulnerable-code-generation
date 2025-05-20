//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<pthread.h>

#define BUFFER_SIZE 1024

void *download_file(void *args) {
    int sock = *(int*)args;
    char buffer[BUFFER_SIZE];
    int recv_size;
    FILE *file;

    //receive filename
    memset(buffer, 0, BUFFER_SIZE);
    if((recv_size = recv(sock, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("Filename receive error");
    }

    char filename[BUFFER_SIZE];
    strcpy(filename, buffer);
    filename[recv_size] = '\0';
    printf("Downloading file: %s\n", filename);

    //open file for writing
    file = fopen(filename, "wb");
    if(file == NULL) {
        perror("File open error");
        return NULL;
    }

    //receive file contents
    memset(buffer, 0, BUFFER_SIZE);
    while((recv_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, recv_size, file);
    }

    fclose(file);
    printf("Download complete for: %s\n", filename);

    return NULL;
}

int main(int argc, char **argv) {
    int sock;
    struct sockaddr_in server;
    char server_address[50], filename[50], buffer[BUFFER_SIZE];

    //create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        perror("Socket create error");
        exit(EXIT_FAILURE);
    }

    //get server address and filename
    printf("Enter server address: ");
    scanf("%s", server_address);
    printf("Enter file name: ");
    scanf("%s", filename);

    //set server details
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(21);

    //connect to server
    if(connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Connect error");
        exit(EXIT_FAILURE);
    }

    //send filename to server
    if(send(sock, filename, strlen(filename), 0) < 0) {
        perror("Filename send error");
        exit(EXIT_FAILURE);
    }

    //start download thread
    pthread_t download_thread;
    int *sock_ptr = malloc(sizeof(*sock_ptr));
    *sock_ptr = sock;
    if(pthread_create(&download_thread, NULL, download_file, sock_ptr) < 0) {
        perror("Thread create error");
        exit(EXIT_FAILURE);
    }

    //wait for download thread to complete
    if(pthread_join(download_thread, NULL) < 0) {
        perror("Thread join error");
        exit(EXIT_FAILURE);
    }

    close(sock);
    return 0;
}