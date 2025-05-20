//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFFER_SIZE 1024

int main(){
    struct sockaddr_in server;
    int socket_ftp, r_size, fileSize;
    char buffer[BUFFER_SIZE], command[BUFFER_SIZE], filename[BUFFER_SIZE], *ptr;
    FILE *fileptr;
    
    printf("Enter the server IP address: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(21);
    server.sin_addr.s_addr = inet_addr(buffer);
    
    printf("Connecting to the FTP server...\n");
    socket_ftp = socket(AF_INET, SOCK_STREAM, 0);
    
    if(connect(socket_ftp, (struct sockaddr *)&server, sizeof(server)) < 0){
        printf("Error in establishing the FTP connection");
        close(socket_ftp);
        exit(1);
    }
    
    printf("Successfully connected to the FTP server\n");
    printf("Enter the filename: ");
    fgets(filename, BUFFER_SIZE, stdin);
    
    ptr = strrchr(filename, '/');
    
    if(ptr == NULL){
        ptr = filename;
    }else{
        ptr++;
    }
    
    sprintf(command, "SIZE %s", ptr);
    send(socket_ftp, command, strlen(command), 0);
    recv(socket_ftp, buffer, BUFFER_SIZE, 0);
    
    ptr = strstr(buffer, " ");
    ptr++;
    fileSize = atoi(ptr);
    
    sprintf(command, "RETR %s", filename);
    send(socket_ftp, command, strlen(command), 0);
    
    fileptr = fopen(ptr, "ab");
    
    while((r_size = recv(socket_ftp, buffer, BUFFER_SIZE, 0)) > 0){
        fwrite(buffer, 1, r_size, fileptr);
        fileSize -= r_size;
        
        if(fileSize == 0){
            printf("File transfer completed successfully\n");
            break;
        }
    }
    
    fclose(fileptr);
    close(socket_ftp);
    
    return 0;
}