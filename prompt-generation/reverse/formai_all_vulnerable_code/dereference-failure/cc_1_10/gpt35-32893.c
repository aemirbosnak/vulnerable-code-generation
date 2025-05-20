//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <fcntl.h>

#define MAXSIZE 1048576

void ftp_get(int sock, char* fname){
    char buffer[1024];
    char filesize[20];
    char* curr_position;
    long int total = 0, size;
    int filefd;

    printf("Downloading %s...\n", fname);

    // Send RETR command
    snprintf(buffer, sizeof(buffer), "RETR %s\n", fname);
    send(sock, buffer, strlen(buffer), 0);

    // Wait for server response
    recv(sock, buffer, sizeof(buffer), 0);

    if(strncmp(buffer, "550", 3) == 0){
        printf("File not found on server\n");
        return;
    }

    // Get size of file and create file if it doesn't exit
    curr_position = strstr(buffer, "(");
    if(curr_position == NULL){
        printf("Cannot get file size\n");
        return;
    }

    curr_position++;
    size = atoi(curr_position);
    filefd = open(fname, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    // Retrieve file from server and write data to file
    while((total < size) && (recv(sock, buffer, sizeof(buffer), 0) > 0)){

        curr_position = strstr(buffer, "(");
        if(curr_position != NULL){
            curr_position++;
            strncpy(filesize, curr_position, strstr(curr_position, "bytes") - curr_position);
            filesize[strstr(curr_position, "bytes") - curr_position] = '\0';
        } else {
            write(filefd, buffer, strlen(buffer));
            total += strlen(buffer);
            printf("Downloaded: %ld / %ld bytes\r", total, size);
            fflush(stdout);
        }
    }

    // Close file and print completion message
    close(filefd);
    printf("Download from server to %s complete\n", fname);
}

int ftp_connect(char* ip, int port){
    char buffer[1024];
    int sockfd;
    struct sockaddr_in server_address;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        printf("Error creating socket\n");
        return -1;
    }

    // Initialize sockaddr_in structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(ip);

    // Connect to server
    if(connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0){
        printf("Error connection to server\n");
        return -1;
    }

    // Wait for response from server
    recv(sockfd, buffer, sizeof(buffer), 0);

    printf("%s", buffer);

    return sockfd;
}

int main(int argc, char *argv[]){

    int sockfd;
    char buffer[1024];
    char server_reply[MAXSIZE];

    if(argc != 3){
        printf("Usage: ./ftpclient <server IP> <server port>\n");
        return 0;
    }

    // Connect to server
    sockfd = ftp_connect(argv[1], atoi(argv[2]));

    if(sockfd < 0){
        printf("Error connecting to server\n");
        return 0;
    }

    // Login as anonymous user
    send(sockfd, "USER anonymous\n", strlen("USER anonymous\n"), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    send(sockfd, "PASS anonymous\n", strlen("PASS anonymous\n"), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    // Main loop
    while(1){
        printf("Enter command: ");
        fgets(buffer, sizeof(buffer), stdin);

        if(strncmp(buffer, "quit", 4) == 0){
            printf("Exiting...\n");
            send(sockfd, "QUIT\n", strlen("QUIT\n"), 0);
            recv(sockfd, server_reply, sizeof(server_reply), 0);
            break;
        }

        // GET command
        if(strncmp(buffer, "get", 3) == 0){
            char* token = strtok(buffer, " ");
            token = strtok(NULL, " ");
            if(token != NULL){
                ftp_get(sockfd, strtok(buffer, "\n"));
            } else {
                printf("Usage: get <filename>\n");
            }
        } else {
            printf("Invalid command\n");
        }
    }

    close(sockfd);
    return 0;
}