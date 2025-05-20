//FormAI DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  
  if(argc < 2)
  {
     printf("Usage : %s <hostname/IP> \n",argv[0]);
     return 1;            
  }
  
  char *hostname = argv[1];
  struct hostent *host_info = gethostbyname(hostname);

  if(!host_info)
  {
     printf("Error: Unable to resolve %s\n",hostname);
     return 1;
  }

  printf("Scanning ports on %s (%s):\n",hostname,inet_ntoa(*(struct in_addr*)host_info->h_addr));
  
  int sockfd, port;       
  struct sockaddr_in server_addr;

  for(port=1;port<65535;port++)
  {
     sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
     if (sockfd < 0)
     {
         perror("ERROR opening socket");
         return 1;
     }
     
     bzero((char *) &server_addr, sizeof(server_addr));
     server_addr.sin_family = AF_INET;
     bcopy((char *)host_info->h_addr, (char *)&server_addr.sin_addr.s_addr, host_info->h_length);
     server_addr.sin_port = htons(port);
    
     
     if (connect(sockfd,(struct sockaddr *) &server_addr,sizeof(server_addr)) == 0)
     {
         printf("Port %d is open\n", port);
         close(sockfd);         
     }
  }

  printf("Scan completed\n");
  return 0;
}