//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAXSIZE 1024
char buffer[MAXSIZE];

//function to parse URL
void parseURL(char* url, char* hostname, char* path, int* port) {
    char* p1, *p2;
    int i, len;
    p1 = strstr(url, "://");
    if(p1) {
        p1 += 3;
    } else {
        p1 = url;
    }
    p2 = strstr(p1, "/");
    if(p2) {
        len = p2 - p1;
    } else {
        len = strlen(p1);
    }
    memcpy(hostname, p1, len);
    hostname[len] = '\0';
    if(p2) {
        strcpy(path, p2);
    } else {
        strcpy(path, "/");
    }
    // Check for port number in the hostname
    p1 = strchr(hostname, ':');
    if(p1) {
        *p1++ = '\0';
        *port = atoi(p1);
    }
}

//function to print error message
void printError(const char* errorMessage) {
    perror(errorMessage);
    exit(1);
}

//function to receive response from FTP server
void receiveResponse(int socket_fd) {
    memset(buffer, 0, MAXSIZE);
    int bytesRead = read(socket_fd, buffer, MAXSIZE);
    if(bytesRead < 0) {
        printError("Error while reading response from FTP server");
    }
    printf("%s", buffer);
}

//function to send command to FTP server
void sendCommand(int socket_fd, const char* command) {
    if(write(socket_fd, command, strlen(command)) < 0) {
        printError("Failed to send command to FTP server");
    }
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s ftp://[username:password@]hostname[:port]/filename\n", argv[0]);
        exit(1);
    }
    char url[MAXSIZE], hostname[MAXSIZE], path[MAXSIZE], username[MAXSIZE], password[MAXSIZE];
    int port = 21;
    strcpy(url, argv[1]);
    parseURL(url, hostname, path, &port);
    printf("Connecting to FTP server %s ...\n", hostname);

    //creating TCP socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(socket_fd < 0) {
        printError("Failed to create socket");
    }

    //resolving hostname to ip address
    struct hostent* server = gethostbyname(hostname);
    if(server == NULL) {
        printError("Failed to find server address");
    }
    struct in_addr **addr_list;
    addr_list = (struct in_addr **) server->h_addr_list;
    char ip_str[20];
    strcpy(ip_str, inet_ntoa(*addr_list[0]));
    printf("Connecting to server with IP address: %s\n", ip_str);

    //connecting to server
    struct sockaddr_in server_address;
    bzero((char*) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip_str);
    server_address.sin_port = htons(port);
    if(connect(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        printError("Connection failed");
    }
    printf("Connected to FTP server\n");

    //receiving welcome message from server
    receiveResponse(socket_fd);

    //sending user command
    printf("Sending USER command\n");
    printf("Enter username: ");
    scanf("%s", username);
    char userCommand[MAXSIZE];
    sprintf(userCommand, "USER %s\r\n", username);
    sendCommand(socket_fd, userCommand);
    receiveResponse(socket_fd);

    //sending password command
    printf("Sending PASS command\n");
    printf("Enter password: ");
    scanf("%s", password);
    char passCommand[MAXSIZE];
    sprintf(passCommand, "PASS %s\r\n", password);
    sendCommand(socket_fd, passCommand);
    receiveResponse(socket_fd);

    //sending type command
    printf("Sending TYPE command\n");
    char* typeCommand = "TYPE I\r\n";
    sendCommand(socket_fd, typeCommand);
    receiveResponse(socket_fd);

    //sending pasv command
    printf("Sending PASV command\n");
    char* pasvCommand = "PASV\r\n";
    sendCommand(socket_fd, pasvCommand);
    receiveResponse(socket_fd);

    //parsing response to get dataport
    int d1, d2, d3, d4, p1, p2;
    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)\n", &d1, &d2, &d3, &d4, &p1, &p2);
    char dataport_ip[MAXSIZE];
    sprintf(dataport_ip, "%d.%d.%d.%d", d1, d2, d3, d4);
    int dataport = p1 * 256 + p2;

    //connecting to dataport
    printf("Connecting to dataport at %s:%d\n", dataport_ip, dataport);
    int dataport_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(dataport_fd < 0) {
        printError("Failed to create socket for dataport");
    }
    struct sockaddr_in dataport_address;
    dataport_address.sin_family = AF_INET;
    dataport_address.sin_port = htons(dataport);
    dataport_address.sin_addr.s_addr = inet_addr(dataport_ip);
    if(connect(dataport_fd, (struct sockaddr*) &dataport_address, sizeof(dataport_address)) < 0) {
        printError("Connection to dataport failed");
    }

    //sending retr command for downloading file
    printf("Sending RETR command\n");
    char retrCommand[MAXSIZE];
    sprintf(retrCommand, "RETR %s\r\n", path);
    sendCommand(socket_fd, retrCommand);
    receiveResponse(socket_fd);

    FILE *file;
    char filename[MAXSIZE];
    printf("Enter filename to save the file: ");
    scanf("%s", filename);
    file = fopen(filename, "wb");
    if(file == NULL) {
        printError("Failed to create file");
    }
    memset(buffer, 0, MAXSIZE);

    //receiving data from dataport and writing to file
    int bytesRead;
    while((bytesRead = read(dataport_fd, buffer, MAXSIZE)) > 0) {
        fwrite(buffer, 1, bytesRead, file);
        memset(buffer, 0, MAXSIZE);
    }
    if(bytesRead < 0) {
        printError("Error while receiving data from dataport");
    }

    //receiving response from server after file is downloaded
    receiveResponse(socket_fd);

    //sending quit command
    printf("Sending QUIT command\n");
    char* quitCommand = "QUIT\r\n";
    sendCommand(socket_fd, quitCommand);
    receiveResponse(socket_fd);

    //closing the connections and file
    printf("Closing connections and file\n");
    close(socket_fd);
    close(dataport_fd);
    fclose(file);
    printf("File downloaded successfully and saved as %s\n", filename);

    return 0;
}