//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_STOCKS 100

struct stock {
  char symbol[10];
  float price;
  float change;
};

struct stock_list {
  struct stock stocks[MAX_STOCKS];
  int num_stocks;
};

struct client {
  int socket;
  struct stock_list stock_list;
};

void* client_thread(void* arg) {
  struct client* client = (struct client*)arg;
  int socket = client->socket;
  struct stock_list* stock_list = &client->stock_list;

  while (1) {
    // Receive request from client
    char buffer[1024];
    int n = recv(socket, buffer, sizeof(buffer), 0);
    if (n <= 0) {
      // Client disconnected
      close(socket);
      free(client);
      return NULL;
    }

    // Parse request
    char* request = strtok(buffer, " ");
    if (!strcmp(request, "get_stocks")) {
      // Send stock list to client
      char response[1024];
      int i;
      for (i = 0; i < stock_list->num_stocks; i++) {
        sprintf(response + strlen(response), "%s %.2f %.2f\n", stock_list->stocks[i].symbol, stock_list->stocks[i].price, stock_list->stocks[i].change);
      }
      send(socket, response, strlen(response), 0);
    } else if (!strcmp(request, "add_stock")) {
      // Add stock to stock list
      char* symbol = strtok(NULL, " ");
      float price = atof(strtok(NULL, " "));
      float change = atof(strtok(NULL, " "));
      if (stock_list->num_stocks < MAX_STOCKS) {
        strcpy(stock_list->stocks[stock_list->num_stocks].symbol, symbol);
        stock_list->stocks[stock_list->num_stocks].price = price;
        stock_list->stocks[stock_list->num_stocks].change = change;
        stock_list->num_stocks++;
        send(socket, "OK", 2, 0);
      } else {
        send(socket, "ERROR: Stock list is full", 25, 0);
      }
    } else if (!strcmp(request, "remove_stock")) {
      // Remove stock from stock list
      char* symbol = strtok(NULL, " ");
      int i;
      for (i = 0; i < stock_list->num_stocks; i++) {
        if (!strcmp(stock_list->stocks[i].symbol, symbol)) {
          // Found stock, remove it
          for (int j = i + 1; j < stock_list->num_stocks; j++) {
            stock_list->stocks[j - 1] = stock_list->stocks[j];
          }
          stock_list->num_stocks--;
          send(socket, "OK", 2, 0);
          return NULL;
        }
      }
      // Stock not found
      send(socket, "ERROR: Stock not found", 20, 0);
    } else {
      // Invalid request
      send(socket, "ERROR: Invalid request", 21, 0);
    }
  }
}

int main() {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(5000);

  if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
    perror("bind");
    return 1;
  }

  if (listen(sockfd, 5) == -1) {
    perror("listen");
    return 1;
  }

  while (1) {
    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);
    int connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
    if (connfd == -1) {
      perror("accept");
      continue;
    }

    // Create client thread
    struct client* client = (struct client*)malloc(sizeof(struct client));
    client->socket = connfd;
    client->stock_list.num_stocks = 0;
    pthread_t tid;
    pthread_create(&tid, NULL, client_thread, (void*)client);
  }

  close(sockfd);
  return 0;
}