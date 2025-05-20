//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: satisfied
/*
FTP client example program in C
Author: [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21 //default FTP port
#define MAX 1024 //maximum buffer size

int createSocket(char *ip) {
    struct hostent *he;
    struct sockaddr_in server;

    if ((he = gethostbyname(ip)) == NULL) { //get host by name
        printf("Failed to resolve hostname\n");
        return -1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0); //create socket
    if (sockfd == -1) {
        printf("Failed to create socket\n");
        return -1;
    }

    server.sin_family = AF_INET; //IPv4
    server.sin_port = htons(PORT); //FTP port
    server.sin_addr = *((struct in_addr *) he->h_addr); //server IP
    memset(&(server.sin_zero), '\0', 8); //zero out the rest of the struct

    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) { //connect to the server
        printf("Failed to connect to server\n");
        return -1;
    }

    return sockfd;
}

int downloadFile(int sockfd, char *filename) {
    char buffer[MAX];
    FILE *file = fopen(filename, "wb"); //open file to write binary data
    if (file == NULL) {
        printf("Failed to create file\n");
        return -1;
    }

    ssize_t nread;
    while ((nread = read(sockfd, buffer, MAX)) > 0) { //read data from socket
        fwrite(buffer, 1, nread, file); //write data to file
    }

    fclose(file); //close file
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) { //check if enough arguments are provided
        printf("Usage: %s [HOSTNAME/IP] [USERNAME] [PASSWORD]\n", argv[0]);
        return -1;
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sockfd = createSocket(hostname); //create socket and connect to server
    if (sockfd == -1) {
        return -1;
    }

    char response[MAX];
    ssize_t nread;
    nread = read(sockfd, response, MAX); //read welcome message from server
    response[nread] = '\0';
    printf("%s", response);

    char userCommand[MAX];
    sprintf(userCommand, "USER %s\n", username); //create USER command
    write(sockfd, userCommand, strlen(userCommand)); //send USER command to server

    char passCommand[MAX];
    sprintf(passCommand, "PASS %s\n", password); //create PASS command
    write(sockfd, passCommand, strlen(passCommand)); //send PASS command to server

    char pasvCommand[] = "PASV\n";
    write(sockfd, pasvCommand, strlen(pasvCommand)); //send PASV command to server

    int port1, port2;
    char *pos;
    nread = read(sockfd, response, MAX); //read port information from server
    response[nread] = '\0';
    printf("%s", response);
    pos = strrchr(response, ')');
    sscanf(pos, ",%d,%d)", &port1, &port2); //parse port information

    char ip[MAX];
    sprintf(ip, "%d.%d.%d.%d", 127, 0, 0, 1); //set local IP address
    int dataSocket = createSocket(ip); //create data socket

    struct sockaddr_in serverData;
    serverData.sin_family = AF_INET; //IPv4
    serverData.sin_port = htons(port1 * 256 + port2); //data port
    serverData.sin_addr.s_addr = htonl(INADDR_ANY); //accept connection from any IP address
    memset(&(serverData.sin_zero), '\0', 8); //zero out the rest of the struct

    if (connect(dataSocket, (struct sockaddr *) &serverData, sizeof(serverData)) < 0) { //connect to data channel
        printf("Failed to connect to data channel\n");
        return -1;
    }

    char retrCommand[] = "RETR test.txt\n"; //retrieve test file
    write(sockfd, retrCommand, strlen(retrCommand)); //send RETR command to server

    downloadFile(dataSocket, "test.txt"); //download file from data channel

    char quitCommand[] = "QUIT\n";
    write(sockfd, quitCommand, strlen(quitCommand)); //send QUIT command to server

    close(dataSocket); //close data socket
    close(sockfd); //close command socket

    return 0;
}