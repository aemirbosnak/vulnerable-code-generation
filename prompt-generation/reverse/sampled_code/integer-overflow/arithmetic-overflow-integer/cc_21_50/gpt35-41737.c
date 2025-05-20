//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: distributed
/*
  A simple traffic light controller program in a distributed style using message
  passing architecture. The program simulates a four-way intersection with four
  traffic lights. Each traffic light runs on a separate process and communicates
  with the other traffic lights to keep traffic flowing smoothly.

  The program uses inter-process communication (IPC) using message queues. It
  creates four processes, one for each traffic light. Each traffic light listens
  for messages on its own message queue and sends messages to the other three
  traffic lights.

  The program uses a non-blocking method to receive messages. When a traffic light
  receives a message, it updates its own state accordingly. Each traffic light
  has three states: green, yellow, and red. The traffic lights alternate between
  green and red states every 20 seconds. The yellow state lasts for 5 seconds.

  When a traffic light changes state, it sends a message to the other traffic lights
  informing them of the change. The message contains the new state of the traffic
  light and the time at which it will change again.

  At the end of the program, all message queues are deleted.

  Written by: Jane Doe
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

#define KEY1 1234
#define KEY2 2345
#define KEY3 3456
#define KEY4 4567
#define PERMS 0666

/** Define colors **/
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define RESET "\033[0m"

/** Define traffic light states **/
#define TL_STATE_GREEN 0
#define TL_STATE_YELLOW 1
#define TL_STATE_RED 2

/** Define message types **/
#define MSG_TYPE_GREEN 1
#define MSG_TYPE_YELLOW 2
#define MSG_TYPE_RED 3

/** Define message structure **/
typedef struct {
    long mtype;     /* message type */
    int state;      /* traffic light state */
    time_t timer;   /* time when state changes */
} msg_t;

int main()
{
    /* Create message queues */
    int qid1 = msgget(KEY1, PERMS | IPC_CREAT);
    int qid2 = msgget(KEY2, PERMS | IPC_CREAT);
    int qid3 = msgget(KEY3, PERMS | IPC_CREAT);
    int qid4 = msgget(KEY4, PERMS | IPC_CREAT);

    /* Initialize traffic light states and timers */
    int tl1_state = TL_STATE_GREEN;
    int tl2_state = TL_STATE_RED;
    int tl3_state = TL_STATE_RED;
    int tl4_state = TL_STATE_RED;

    time_t tl1_timer = time(NULL) + 20;
    time_t tl2_timer = time(NULL) + 5;
    time_t tl3_timer = time(NULL) + 5;
    time_t tl4_timer = time(NULL) + 5;

    /* Start traffic light processes */
    pid_t pid1, pid2, pid3, pid4;

    if ((pid1 = fork()) < 0) {
        perror("fork error");
        exit(1);
    } else if (pid1 == 0) {
        /* Traffic light 1 */
        while (1) {
            /* Check for incoming messages */
            msg_t msg;
            if (msgrcv(qid1, &msg, sizeof(msg_t), 0, IPC_NOWAIT) != -1) {
                tl1_state = msg.state;
                tl1_timer = msg.timer;
            }

            /* Check timer */
            time_t now = time(NULL);
            if (now >= tl1_timer) {
                if (tl1_state == TL_STATE_GREEN) {
                    tl1_state = TL_STATE_YELLOW;
                    tl1_timer = now + 5;
                } else {
                    tl1_state = TL_STATE_GREEN;
                    tl1_timer = now + 20;
                }

                /* Send message to other traffic lights */
                msg_t msg;
                msg.mtype = MSG_TYPE_GREEN;
                msg.state = tl1_state;
                msg.timer = tl1_timer;
                msgsnd(qid2, &msg, sizeof(msg_t), 0);
                msgsnd(qid3, &msg, sizeof(msg_t), 0);
                msgsnd(qid4, &msg, sizeof(msg_t), 0);
            }

            /* Print traffic light state */
            if (tl1_state == TL_STATE_GREEN) {
                printf(GREEN "Traffic Light 1: GREEN\n" RESET);
            } else if (tl1_state == TL_STATE_YELLOW) {
                printf(YELLOW "Traffic Light 1: YELLOW\n" RESET);
            } else if (tl1_state == TL_STATE_RED) {
                printf(RED "Traffic Light 1: RED\n" RESET);
            }

            /* Sleep for 1 second */
            sleep(1);
        }
        exit(0);
    }

    if ((pid2 = fork()) < 0) {
        perror("fork error");
        exit(1);
    } else if (pid2 == 0) {
        /* Traffic light 2 */
        while (1) {
            /* Check for incoming messages */
            msg_t msg;
            if (msgrcv(qid2, &msg, sizeof(msg_t), 0, IPC_NOWAIT) != -1) {
                tl2_state = msg.state;
                tl2_timer = msg.timer;
            }

            /* Check timer */
            time_t now = time(NULL);
            if (now >= tl2_timer) {
                if (tl2_state == TL_STATE_GREEN) {
                    tl2_state = TL_STATE_YELLOW;
                    tl2_timer = now + 5;
                } else {
                    tl2_state = TL_STATE_GREEN;
                    tl2_timer = now + 20;
                }

                /* Send message to other traffic lights */
                msg_t msg;
                msg.mtype = MSG_TYPE_GREEN;
                msg.state = tl2_state;
                msg.timer = tl2_timer;
                msgsnd(qid1, &msg, sizeof(msg_t), 0);
                msgsnd(qid3, &msg, sizeof(msg_t), 0);
                msgsnd(qid4, &msg, sizeof(msg_t), 0);
            }

            /* Print traffic light state */
            if (tl2_state == TL_STATE_GREEN) {
                printf(GREEN "Traffic Light 2: GREEN\n" RESET);
            } else if (tl2_state == TL_STATE_YELLOW) {
                printf(YELLOW "Traffic Light 2: YELLOW\n" RESET);
            } else if (tl2_state == TL_STATE_RED) {
                printf(RED "Traffic Light 2: RED\n" RESET);
            }

            /* Sleep for 1 second */
            sleep(1);
        }
        exit(0);
    }

    if ((pid3 = fork()) < 0) {
        perror("fork error");
        exit(1);
    } else if (pid3 == 0) {
        /* Traffic light 3 */
        while (1) {
            /* Check for incoming messages */
            msg_t msg;
            if (msgrcv(qid3, &msg, sizeof(msg_t), 0, IPC_NOWAIT) != -1) {
                tl3_state = msg.state;
                tl3_timer = msg.timer;
            }

            /* Check timer */
            time_t now = time(NULL);
            if (now >= tl3_timer) {
                if (tl3_state == TL_STATE_GREEN) {
                    tl3_state = TL_STATE_YELLOW;
                    tl3_timer = now + 5;
                } else {
                    tl3_state = TL_STATE_GREEN;
                    tl3_timer = now + 20;
                }

                /* Send message to other traffic lights */
                msg_t msg;
                msg.mtype = MSG_TYPE_GREEN;
                msg.state = tl3_state;
                msg.timer = tl3_timer;
                msgsnd(qid1, &msg, sizeof(msg_t), 0);
                msgsnd(qid2, &msg, sizeof(msg_t), 0);
                msgsnd(qid4, &msg, sizeof(msg_t), 0);
            }

            /* Print traffic light state */
            if (tl3_state == TL_STATE_GREEN) {
                printf(GREEN "Traffic Light 3: GREEN\n" RESET);
            } else if (tl3_state == TL_STATE_YELLOW) {
                printf(YELLOW "Traffic Light 3: YELLOW\n" RESET);
            } else if (tl3_state == TL_STATE_RED) {
                printf(RED "Traffic Light 3: RED\n" RESET);
            }

            /* Sleep for 1 second */
            sleep(1);
        }
        exit(0);
    }

    if ((pid4 = fork()) < 0) {
        perror("fork error");
        exit(1);
    } else if (pid4 == 0) {
        /* Traffic light 4 */
        while (1) {
            /* Check for incoming messages */
            msg_t msg;
            if (msgrcv(qid4, &msg, sizeof(msg_t), 0, IPC_NOWAIT) != -1) {
                tl4_state = msg.state;
                tl4_timer = msg.timer;
            }

            /* Check timer */
            time_t now = time(NULL);
            if (now >= tl4_timer) {
                if (tl4_state == TL_STATE_GREEN) {
                    tl4_state = TL_STATE_YELLOW;
                    tl4_timer = now + 5;
                } else {
                    tl4_state = TL_STATE_GREEN;
                    tl4_timer = now + 20;
                }

                /* Send message to other traffic lights */
                msg_t msg;
                msg.mtype = MSG_TYPE_GREEN;
                msg.state = tl4_state;
                msg.timer = tl4_timer;
                msgsnd(qid1, &msg, sizeof(msg_t), 0);
                msgsnd(qid2, &msg, sizeof(msg_t), 0);
                msgsnd(qid3, &msg, sizeof(msg_t), 0);
            }

            /* Print traffic light state */
            if (tl4_state == TL_STATE_GREEN) {
                printf(GREEN "Traffic Light 4: GREEN\n" RESET);
            } else if (tl4_state == TL_STATE_YELLOW) {
                printf(YELLOW "Traffic Light 4: YELLOW\n" RESET);
            } else if (tl4_state == TL_STATE_RED) {
                printf(RED "Traffic Light 4: RED\n" RESET);
            }

            /* Sleep for 1 second */
            sleep(1);
        }
        exit(0);
    }

    /* Wait for traffic light processes to exit */
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);
    waitpid(pid4, NULL, 0);

    /* Delete message queues */
    msgctl(qid1, IPC_RMID, NULL);
    msgctl(qid2, IPC_RMID, NULL);
    msgctl(qid3, IPC_RMID, NULL);
    msgctl(qid4, IPC_RMID, NULL);

    return 0;
}