//FormAI DATASET v1.0 Category: Port Scanner ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netinet/tcp.h>
#include<signal.h>
#include<pthread.h>
#include<string.h>
#include<ctype.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024 

int open_ports[MAX_PORTS] = {0};
int num_open = 0;
int num_alive_threads = 0;

int num_threads = 0;
int ports_per_thread = 0;
int start_port = 0;

char *ip_addr = "";

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *scan_ports(void *thread_id) {
     int port_num, sockfd, status;
     struct sockaddr_in server_addr;
     struct timeval timeout;

     timeout.tv_sec = 5;
     timeout.tv_usec = 0;

     for(int i = 0; i < ports_per_thread; i++) {

          port_num = start_port + (*(int*)thread_id * ports_per_thread) + i;

          sockfd = socket(AF_INET, SOCK_STREAM, 0);

          if(sockfd < 0) {
               perror("Socket Creation Failed!");
               pthread_exit(NULL);
          }

          setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));
          setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char*)&timeout, sizeof(timeout));

          server_addr.sin_family = AF_INET;
          server_addr.sin_port = htons(port_num);
          inet_aton(ip_addr, &server_addr.sin_addr);

          status = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

          if(status == 0) {
               pthread_mutex_lock(&mutex);
               printf("Port %d is open.\n", port_num);
               open_ports[num_open++] = port_num;
               pthread_mutex_unlock(&mutex);
          } else {
               close(sockfd); 
          } 
     }

     pthread_mutex_lock(&mutex);
     num_alive_threads--;
     pthread_mutex_unlock(&mutex);
     pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
     if(argc != 4) {
          printf("Usage: %s <ip_address> <num_threads> <end_port>.\n", argv[0]);
          return -1;
     }

     if(!isdigit(*argv[2])) {
          printf("Invalid thread count %s\n", argv[2]);
          return -1;
     }

     ip_addr = argv[1];
     num_threads = atoi(argv[2]);
     start_port = 1;
     int end_port = atoi(argv[3]);

    if(end_port <= 0 || end_port > MAX_PORTS) {
          printf("Invalid end port %d\n", end_port);
          return -1;
     }

     if(num_threads <= 0 || num_threads > MAX_THREADS) {
          printf("Invalid thread count %d\n", num_threads);
          return -1;
     }

     if(num_threads > end_port - start_port + 1) {
          printf("The number of threads is greater than the number of ports to be scanned.\nDecrease the number of threads or increase the range of ports to be scanned.\n");
          return -1;
     }

     ports_per_thread = (end_port - start_port + 1) / num_threads;

     pthread_t threads[num_threads];

     // Clear the array before inserting.
     memset(open_ports, 0, sizeof(open_ports));

     for(int i = 0; i < num_threads; i++) {
          int *thread_id = malloc(sizeof(*thread_id));
          *thread_id = i;

          pthread_mutex_lock(&mutex);
          num_alive_threads++;
          pthread_mutex_unlock(&mutex);

          if(pthread_create(&threads[i], NULL, scan_ports, (void*)thread_id) != 0) {
               perror("Thread creation Failed!\n");
          }
     }

     while(num_alive_threads > 0) {
          sleep(1);
     }

     printf("The following ports are open:\n");

     for(int i=0; i<num_open; i++) {
          printf("%d ", open_ports[i]);
     }

     printf("\n");
     return 0;
}