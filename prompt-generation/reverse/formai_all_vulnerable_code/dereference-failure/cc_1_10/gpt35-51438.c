//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Connect to FTP server
int connect_to_ftp(char *ip_address, int port_number) {
    struct sockaddr_in server_address;
    int sock_fd;

    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);

    if(inet_pton(AF_INET, ip_address, &server_address.sin_addr) <= 0){
        perror("Invalid address specified");
        exit(EXIT_FAILURE);
    }

    if(connect(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0){
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    return sock_fd;
}

// Send command to FTP server
void send_ftp_command(int sock_fd, char *command) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    if(send(sock_fd, command, strlen(command), 0) < 0){
        perror("Command send failed");
        exit(EXIT_FAILURE);
    }

    if(recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0){
        perror("Response receive failed");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);
}

// Download file from FTP server
void download_file(int sock_fd, char *filename) {
    char command[BUFFER_SIZE];
    sprintf(command, "RETR %s\n", filename);
    send_ftp_command(sock_fd, command);

    FILE* fp = fopen(filename, "w");
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while((bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0)) > 0){
        fwrite(buffer, 1, bytes_received, fp);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if(argc != 4){
        printf("Usage: %s <IP address> <port number> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);
    char *filename = argv[3];

    int sock_fd = connect_to_ftp(ip_address, port_number);
    send_ftp_command(sock_fd, "USER anonymous\n");
    send_ftp_command(sock_fd, "PASS password\n");
    download_file(sock_fd, filename);

    close(sock_fd);
    exit(EXIT_SUCCESS);
}