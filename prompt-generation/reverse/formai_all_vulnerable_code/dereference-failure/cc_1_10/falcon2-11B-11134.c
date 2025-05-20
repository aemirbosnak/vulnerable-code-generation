//Falcon2-11B DATASET v1.0 Category: System event logger ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

void sighandler(int sig)
{
  printf("Signal %d received!\n", sig);
}

int main()
{
  int fd, pid, status;
  char buf[256];
  char filename[256];
  char event[256];
  char eventtype[256];

  pid = getpid();

  if ((fd = open("event.log", O_CREAT | O_WRONLY, 0666)) < 0) {
    perror("open");
    return 1;
  }

  if ((pid = fork()) == 0) {
    sleep(10);

    snprintf(event, sizeof(event), "Event: Forked %d", pid);
    snprintf(eventtype, sizeof(eventtype), "Fork");
    write(fd, event, strlen(event));
    write(fd, eventtype, strlen(eventtype));
    printf("Forked %d\n", pid);
  } else {
    wait(&status);
    snprintf(event, sizeof(event), "Event: Child Terminated %d", pid);
    snprintf(eventtype, sizeof(eventtype), "Termination");
    write(fd, event, strlen(event));
    write(fd, eventtype, strlen(eventtype));
    printf("Child Terminated %d\n", pid);
  }

  close(fd);
  return 0;
}