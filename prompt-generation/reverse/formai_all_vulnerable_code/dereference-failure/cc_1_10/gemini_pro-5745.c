//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define MSGQ_KEY 12345

struct msgbuf {
  long mtype;
  char mtext[1024];
};

int main() {
  int msgqid, rc;
  struct msgbuf msg;
  key_t key = MSGQ_KEY;

  // Create a message queue
  msgqid = msgget(key, IPC_CREAT | IPC_EXCL | 0666);
  if (msgqid < 0) {
    if (errno == EEXIST) {
      // Message queue already exists, open it instead
      msgqid = msgget(key, 0666);
    } else {
      perror("msgget");
      exit(1);
    }
  }

  // Send a message to the message queue
  msg.mtype = 1;
  strcpy(msg.mtext, "Hello from IPC!");
  if (msgsnd(msgqid, &msg, sizeof(msg) - sizeof(long), 0) < 0) {
    perror("msgsnd");
    exit(1);
  }

  printf("Message sent successfully!\n");

  // Receive a message from the message queue
  if (msgrcv(msgqid, &msg, sizeof(msg) - sizeof(long), 0, 0) < 0) {
    perror("msgrcv");
    exit(1);
  }

  printf("Message received: %s\n", msg.mtext);

  // Remove the message queue
  rc = msgctl(msgqid, IPC_RMID, NULL);
  if (rc < 0) {
    perror("msgctl");
    exit(1);
  }

  return 0;
}