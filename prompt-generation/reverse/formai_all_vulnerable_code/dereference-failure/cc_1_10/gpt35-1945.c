//FormAI DATASET v1.0 Category: Port Scanner ; Style: light-weight
#include<stdio.h> 
#include<string.h> 
#include<sys/socket.h>    
#include<arpa/inet.h> 

int main(int argc, char *argv[]) 
{ 
    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Create a socket
    int socket_desc; 
    if ((socket_desc = socket(AF_INET , SOCK_STREAM , 0)) < 0) { 
        perror("socket creation failed"); 
        return 1; 
    }

    // Define the target IP
    struct sockaddr_in target; 
    target.sin_addr.s_addr = inet_addr(ip); 
    target.sin_family = AF_INET; 
     
    // Scan each port in the range
    int i;
    for (i = start_port; i <= end_port; i++) { 

        // Define the target port
        target.sin_port = htons(i); 
        
        // Try connecting to the target port
        if (connect(socket_desc , (struct sockaddr *)&target , sizeof(target)) < 0) 
        { 
            printf("Port %d is closed\n" , i); 
            fflush(stdout);
        } 
        else { 
            printf("Port %d is open\n" , i); 
            fflush(stdout);
        } 
        
        // Close the connection
        close(socket_desc);
        if ((socket_desc = socket(AF_INET , SOCK_STREAM , 0)) < 0) { 
            perror("socket creation failed"); 
            return 1; 
        }
    }

    printf("Scan complete\n"); 
    fflush(stdout);
    
    return 0; 
}