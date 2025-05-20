//FormAI DATASET v1.0 Category: Chat server ; Style: multiplayer
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <netdb.h> 
#include <pthread.h> 
  
#define MAX_USERS 10 
#define MAX_MSG_LENGTH 500
  
static int clientCount = 0; 
static int uid = 10; 
  
typedef struct{ 
    
    struct sockaddr_in address; 
    int sockfd; 
    int uid; 
    char name[32]; 
} clientInfo; 
  
clientInfo* clientGroup[MAX_USERS]; 
  
pthread_mutex_t clientMutex = PTHREAD_MUTEX_INITIALIZER; 
  
void deleteClient(int index){ 
    pthread_mutex_lock(&clientMutex); 
    close(clientGroup[index]->sockfd); 
    printf("User %s left the chat\n", clientGroup[index]->name); 
    if (index != clientCount-1){ 
        clientGroup[index] = clientGroup[clientCount-1]; 
    } 
    free(clientGroup[clientCount - 1]); 
    clientCount--; 
    pthread_mutex_unlock(&clientMutex); 
} 
  
void addClient(clientInfo* client){ 
    pthread_mutex_lock(&clientMutex); 
    clientGroup[clientCount++] = client; 
    pthread_mutex_unlock(&clientMutex); 
} 
  
void sendMessage(char* message, int userid){ 
    pthread_mutex_lock(&clientMutex); 
    for (int i = 0; i < clientCount; i++){ 
        if (clientGroup[i]->uid != userid){ 
            write(clientGroup[i]->sockfd, message, strlen(message)); 
        } 
    } 
    pthread_mutex_unlock(&clientMutex); 
} 
  
void *clientThread(void *clientSock){ 
    clientInfo* client = (clientInfo*)clientSock; 
    char name[32]; 
    memset(name, 0, 32); 
  
    if (recv(client->sockfd, name, 32, 0) <= 0){ 
        printf("No name recevied\n"); 
        deleteClient(client->uid); 
        return NULL; 
    } 
  
    strcpy(client->name, name); 
    char message[MAX_MSG_LENGTH]; 
    sprintf(message, "%s has joined the chat.\n", client->name); 
    sendMessage(message, client->uid); 
  
    while (1){ 
        char buffer[MAX_MSG_LENGTH]; 
        int read = recv(client->sockfd, buffer, MAX_MSG_LENGTH, 0); 
        if (read == 0){ 
            printf("User %s lef the chat\n", client->name); 
            deleteClient(client->uid); 
            break; 
        } 
        sendMessage(buffer, client->uid); 
        memset(buffer, 0, sizeof(buffer)); 
    } 
    return NULL; 
} 
  
int main(int argc, char *argv[]){ 
    int sockfd, portno; 
    struct sockaddr_in servAddr, cliAddr; 
    pthread_t thread_id; 
  
    if (argc < 2){ 
        printf("Usage: ./server <port number>\n"); 
        exit(1); 
    } 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
  
    portno = atoi(argv[1]); 
    memset(&servAddr, 0, sizeof(servAddr)); 
  
    servAddr.sin_family = AF_INET; 
    servAddr.sin_port = htons(portno); 
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY); 
  
    if (bind(sockfd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0){ 
        perror("Error on binding"); 
        exit(1); 
    } 
  
    listen(sockfd, 10); 
    printf("Chat server started on port %d\n", portno); 
  
    while (1){ 
        socklen_t clilen = sizeof(cliAddr); 
        clientInfo* client = malloc(sizeof(clientInfo)); 
        client->sockfd = accept(sockfd, (struct sockaddr *)&cliAddr, &clilen); 
        client->address = cliAddr; 
        client->uid = uid++; 
        addClient(client); 
        pthread_create(&thread_id, NULL, clientThread, (void*)client); 
    } 
  
    return 0; 
}