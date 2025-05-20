//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>

#define POP3_PORT 110 //POP3 default port

int main()
{
    int sockfd, numBytes;
    struct sockaddr_in servAddr; //creating instance of server address
    struct hostent *server;
    char buffer[1024];
    char user[50], pass[50];

    sockfd = socket(AF_INET, SOCK_STREAM, 0); //opening a TCP socket for stream communication

    if(sockfd<0) //socket checking
    {
        perror("Error opening socket");
        return 0;
    }

    server = gethostbyname("pop.gmail.com"); //Gmail POP3 server

    if(server==NULL) //check for valid server
    {
        perror("ERROR: No such host exists");
        return 0;
    }

    //Initializing the server address structure
    bzero((char *) &servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servAddr.sin_addr.s_addr, server->h_length);
    servAddr.sin_port = htons(POP3_PORT); //parsing the port number

    //Connecting to the POP3 server through the socket
    if(connect(sockfd,(struct sockaddr *) &servAddr,sizeof(servAddr)) < 0)
    {
        perror("ERROR connecting");
        return 0;
    }
    else
    {
        printf("\nEstablished connection to server... Waiting for response...");

        //Receiving server response for connection establishment
        bzero(buffer,1024);
        numBytes = read(sockfd,buffer,1024);

        printf("\nServer: %s", buffer);

        //User authentication process
        printf("\nEnter username: ");
        scanf("%s",user);

        printf("\nEnter password: ");
        scanf("%s",pass);

        char* usrmsg = (char*) malloc( sizeof(char) * strlen(user) + 1 ); //memory allocation for user message
        snprintf(usrmsg, strlen(user) + 1, "%s", user ); //copying user input to message
        char msg[1024] = "USER "; //preparing server message
        strcat(msg,usrmsg); //appending user message to server message

        //Sending user name
        numBytes = write(sockfd,msg,strlen(msg));
        bzero(buffer,1024);
        numBytes = read(sockfd,buffer,1024);

        printf("\nServer: %s", buffer);

        char* pswdmsg = (char*) malloc( sizeof(char) * strlen(pass) + 1 ); //memory allocation for password message
        snprintf(pswdmsg, strlen(pass) + 1, "%s", pass ); //copying password input to message
        char pswd[1024] = "PASS "; //preparing server message
        strcat(pswd,pswdmsg); //appending password message to server message

        //Sending password
        numBytes = write(sockfd,pswd,strlen(pswd));
        bzero(buffer,1024);
        numBytes = read(sockfd,buffer,1024);

        printf("\nServer: %s", buffer);
    }

    //Closing the socket
    close(sockfd);
    return 0;
}