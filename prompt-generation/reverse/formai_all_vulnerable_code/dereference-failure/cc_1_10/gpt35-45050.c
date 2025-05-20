//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#define MAXSIZE 100
#define FTP_PORT 21

// Function to handle FTP errors
void ftp_error(char *msg){
    perror(msg);
    exit(-1);
}

// Function to send data to server
void send_data(int sockFD, char *data){
    int len = strlen(data);
    if(send(sockFD, data, len, 0) != len){
        ftp_error("Send failed");
    }
}

// Function to receive data from server
int receive_data(int sockFD, char *recvBuf){
    int numBytes;
    if((numBytes = recv(sockFD, recvBuf, MAXSIZE, 0)) == -1){
        ftp_error("Receive failed");
    }
    recvBuf[numBytes] = '\0';
    return numBytes;
}

// Function to get control socket 
int get_control_socket(char *serverIP){
    int sockFD;
    struct sockaddr_in serverAddr;

    if((sockFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1){
        ftp_error("Socket creation failed");
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(FTP_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(serverIP);

    if(connect(sockFD, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1){
        ftp_error("Could not connect to server");
    }

    return sockFD;
}

// Function to login to the remote server
void login(int controlSockFD, char *username, char *password){
    char recvBuf[MAXSIZE];
    int numBytes;

    // Read welcome message
    if((numBytes = receive_data(controlSockFD, recvBuf)) == -1){
        ftp_error("Could not receive welcome message");
    }

    // Send username
    send_data(controlSockFD, "USER ");
    send_data(controlSockFD, username);
    send_data(controlSockFD, "\r\n");

    if((numBytes = receive_data(controlSockFD, recvBuf)) == -1){
        ftp_error("Could not receive reply for username");
    }

    // Send password
    send_data(controlSockFD, "PASS ");
    send_data(controlSockFD, password);
    send_data(controlSockFD, "\r\n");

    if((numBytes = receive_data(controlSockFD, recvBuf)) == -1){
        ftp_error("Could not receive reply for password");
    }

    printf("%s", recvBuf);
}

// Function to change the working directory
void change_directory(int controlSockFD, char *directory){
    char recvBuf[MAXSIZE];
    int numBytes;

    // Send CWD command
    send_data(controlSockFD, "CWD ");
    send_data(controlSockFD, directory);
    send_data(controlSockFD, "\r\n");

    if((numBytes = receive_data(controlSockFD, recvBuf)) == -1){
        ftp_error("Could not receive reply for CWD");
    }

    printf("%s", recvBuf);
}

// Function to request data transfer mode
void request_transfer_mode(int controlSockFD, char *mode){
    char recvBuf[MAXSIZE];
    int numBytes;

    // Send TYPE command
    send_data(controlSockFD, "TYPE ");
    send_data(controlSockFD, mode);
    send_data(controlSockFD, "\r\n");

    if((numBytes = receive_data(controlSockFD, recvBuf)) == -1){
        ftp_error("Could not receive reply for TYPE");
    }

    printf("%s", recvBuf);
}

// Function to retrieve a file
void retrieve_file(int controlSockFD, char *fileName){
    char dataBuf[MAXSIZE];
    char recvBuf[MAXSIZE];
    int dataSockFD, numBytes;

    // Send PASV command
    send_data(controlSockFD, "PASV\r\n");

    if((numBytes = receive_data(controlSockFD, recvBuf)) == -1){
        ftp_error("Could not receive reply for PASV");
    }

    // Parse PASV response to get data port
    char *startIndex = strstr(recvBuf, "(");
    char *endIndex = strstr(recvBuf, ")");
    startIndex += 1;
    int addrPart1, addrPart2, addrPart3, addrPart4, addrPort1, addrPort2;
    sscanf(startIndex, "%d,%d,%d,%d,%d,%d", &addrPart1, &addrPart2, &addrPart3, &addrPart4, &addrPort1, &addrPort2);
    char dataIP[MAXSIZE];
    sprintf(dataIP, "%d.%d.%d.%d", addrPart1, addrPart2, addrPart3, addrPart4);
    int dataPort = addrPort1 * 256 + addrPort2;

    // Open data connection
    struct sockaddr_in dataAddr;

    if((dataSockFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1){
        ftp_error("Data socket creation failed");
    }

    dataAddr.sin_family = AF_INET;
    dataAddr.sin_addr.s_addr = inet_addr(dataIP);
    dataAddr.sin_port = htons(dataPort);

    if(connect(dataSockFD, (struct sockaddr *) &dataAddr, sizeof(dataAddr)) == -1){
        ftp_error("Could not connect to data port");
    }

    // Send RETR command
    send_data(controlSockFD, "RETR ");
    send_data(controlSockFD, fileName);
    send_data(controlSockFD, "\r\n");

    // Receive data
    int fileFD;
    if((fileFD = open(fileName, O_WRONLY | O_CREAT, 0644)) == -1){
        ftp_error("Could not create file");
    }

    while((numBytes = recv(dataSockFD, dataBuf, MAXSIZE, 0)) > 0){
        write(fileFD, dataBuf, numBytes);
    }

    if(numBytes == -1){
        ftp_error("Data receive failed");
    }

    close(fileFD);

    if((numBytes = receive_data(controlSockFD, recvBuf)) == -1){
        ftp_error("Could not receive reply for RETR");
    }

    printf("%s", recvBuf);
}

// Function to quit the FTP session
void quit(int controlSockFD){
    char recvBuf[MAXSIZE];
    int numBytes;

    // Send QUIT command
    send_data(controlSockFD, "QUIT\r\n");

    if((numBytes = receive_data(controlSockFD, recvBuf)) == -1){
        ftp_error("Could not receive reply for QUIT");
    }

    printf("%s", recvBuf);

    close(controlSockFD);
}

// Main function
int main(){
    char serverIP[MAXSIZE], username[MAXSIZE], password[MAXSIZE], directory[MAXSIZE], fileName[MAXSIZE], mode[MAXSIZE], response[MAXSIZE];
    int controlSockFD;

    printf("FTP Client\n");

    // Read server details
    printf("Enter server IP: ");
    scanf("%s", serverIP);

    // Get control socket
    controlSockFD = get_control_socket(serverIP);

    // Read credentials and login
    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    login(controlSockFD, username, password);

    // Read directory and change to it
    printf("Enter directory: ");
    scanf("%s", directory);

    change_directory(controlSockFD, directory);

    // Get transfer mode
    printf("Enter transfer mode (ASCII or BINARY): ");
    scanf("%s", mode);

    request_transfer_mode(controlSockFD, mode);

    // Enter file name and retrieve it
    printf("Enter file name: ");
    scanf("%s", fileName);

    retrieve_file(controlSockFD, fileName);

    // Quit session
    quit(controlSockFD);

    return 0;
}