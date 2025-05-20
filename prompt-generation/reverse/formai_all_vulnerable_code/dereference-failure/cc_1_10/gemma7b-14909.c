//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Knight {
  char name[20];
  int socketfd;
  struct Knight *next;
} Knight;

Knight *head = NULL;

void knight_create(char *name)
{
  Knight *new_knight = malloc(sizeof(Knight));
  strcpy(new_knight->name, name);
  new_knight->socketfd = -1;
  new_knight->next = NULL;

  if (head == NULL)
  {
    head = new_knight;
  }
  else
  {
    Knight *temp = head;
    while (temp->next)
    {
      temp = temp->next;
    }
    temp->next = new_knight;
  }
}

void knight_connect(Knight *knight, int socketfd)
{
  knight->socketfd = socketfd;
}

int knight_send(Knight *knight, char *message)
{
  return write(knight->socketfd, message, strlen(message));
}

int knight_recv(Knight *knight, char *buffer, int size)
{
  return read(knight->socketfd, buffer, size);
}

int main()
{
  knight_create("Sir Robin");
  knight_create("Lady Alice");
  knight_create("The White Knight");

  Knight *knight = head;

  while (knight)
  {
    printf("Knight: %s, SocketFD: %d\n", knight->name, knight->socketfd);
    knight = knight->next;
  }

  return 0;
}