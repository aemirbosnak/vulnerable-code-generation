//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define PORT 21 //FTP Port Number

//Function to connect and authenticate to FTP server
int connect_to_ftp_server(char* hostname, char* username, char* password, int* control_socket) {
    
    //Create a socket for the control connection
    *control_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (*control_socket < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        return -1;
    }
    
    //Set up server address information
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &server_address.sin_addr);
    
    //Connect to the server
    if (connect(*control_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return -1;
    }
    
    //Receive the server greeting message
    char rec_buf[1024];
    if (recv(*control_socket, rec_buf, sizeof(rec_buf), 0) < 0) {
        printf("Error receiving data: %s\n", strerror(errno));
        return -1;
    }
    printf("%s\n", rec_buf);
    
    //Send the username to the server
    char username_command[1024];
    sprintf(username_command, "USER %s\r\n", username);
    if (send(*control_socket, username_command, strlen(username_command), 0) < 0) {
        printf("Error sending data: %s\n", strerror(errno));
        return -1;
    }
    printf("%s", username_command);
    
    //Receive the response to the username command
    if (recv(*control_socket, rec_buf, sizeof(rec_buf), 0) < 0) {
        printf("Error receiving data: %s\n", strerror(errno));
        return -1;
    }
    printf("%s\n", rec_buf);
    
    //Send the password to the server
    char password_command[1024];
    sprintf(password_command, "PASS %s\r\n", password);
    if (send(*control_socket, password_command, strlen(password_command), 0) < 0) {
        printf("Error sending data: %s\n", strerror(errno));
        return -1;
    }
    printf("%s", password_command);
    
    //Receive the response to the password command
    if (recv(*control_socket, rec_buf, sizeof(rec_buf), 0) < 0) {
        printf("Error receiving data: %s\n", strerror(errno));
        return -1;
    }
    printf("%s\n", rec_buf);
    
    return 0;
}

//Function to request and receive file from FTP server
int receive_file_from_ftp_server(char* filename, int* data_socket, int* control_socket) {
    
    //Send the PASV command to the server to initiate data transfer
    if (send(*control_socket, "PASV\r\n", strlen("PASV\r\n"), 0) < 0) {
        printf("Error sending data: %s\n", strerror(errno));
        return -1;
    }
    
    //Receive the response to the PASV command
    char rec_buf[1024];
    if (recv(*control_socket, rec_buf, sizeof(rec_buf), 0) < 0) {
        printf("Error receiving data: %s\n", strerror(errno));
        return -1;
    }
    
    //Extract the IP address and port number from the PASV response
    char* loc = strstr(rec_buf, "(");
    int addr[6];
    sscanf(loc, "(%d,%d,%d,%d,%d,%d)", &addr[0], &addr[1], &addr[2], &addr[3], &addr[4], &addr[5]);
    char data_host[128];
    sprintf(data_host, "%d.%d.%d.%d", addr[0], addr[1], addr[2], addr[3]);
    int data_port = addr[4] * 256 + addr[5];
    
    //Create a socket for the data connection
    *data_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (*data_socket < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        return -1;
    }
    
    //Set up server address information
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(data_port);
    inet_pton(AF_INET, data_host, &server_address.sin_addr);
    
    //Connect to the server
    if (connect(*data_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return -1;
    }
    
    //Send the RETR command to the server to request the file
    char retr_command[1024];
    sprintf(retr_command, "RETR %s\r\n", filename);
    if (send(*control_socket, retr_command, strlen(retr_command), 0) < 0) {
        printf("Error sending data: %s\n", strerror(errno));
        return -1;
    }
    
    //Receive the response to the RETR command
    if (recv(*control_socket, rec_buf, sizeof(rec_buf), 0) < 0) {
        printf("Error receiving data: %s\n", strerror(errno));
        return -1;
    }
    printf("%s\n", rec_buf);
    
    //Receive the file data and save to file
    FILE* file = fopen(filename, "w");
    char data_buf[1024];
    int n;
    while ((n = recv(*data_socket, data_buf, sizeof(data_buf), 0)) > 0) {
        fwrite(data_buf, sizeof(char), n, file);
    }
    fclose(file);
    
    //Receive the response to the RETR command
    if (recv(*control_socket, rec_buf, sizeof(rec_buf), 0) < 0) {
        printf("Error receiving data: %s\n", strerror(errno));
        return -1;
    }
    printf("%s\n", rec_buf);
    
    return 0;
}

int main() {
    
    printf("Welcome to the FTP Client program!\n");
    
    //Prompt user for server information
    char hostname[128];
    printf("Please enter the FTP server hostname: ");
    fgets(hostname, sizeof(hostname), stdin);
    hostname[strcspn(hostname, "\n")] = 0;
    
    char username[128];
    printf("Please enter the FTP username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;
    
    char password[128];
    printf("Please enter the FTP password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;
    
    //Connect and authenticate to the FTP server
    int control_socket;
    if (connect_to_ftp_server(hostname, username, password, &control_socket) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }
    
    //Prompt the user for the filename to download
    char filename[128];
    printf("Please enter the filename to download: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;
    
    //Request and receive the file from the FTP server
    int data_socket;
    if (receive_file_from_ftp_server(filename, &data_socket, &control_socket) < 0) {
        printf("Error receiving file\n");
        exit(0);
    }
    
    //Close the sockets and exit the program
    close(data_socket);
    close(control_socket);
    printf("File successfully downloaded!\n");
    return 0;
}