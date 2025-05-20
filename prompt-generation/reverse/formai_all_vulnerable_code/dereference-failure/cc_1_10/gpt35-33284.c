//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/types.h>

#define SHM_SIZE 512

typedef struct qosData{
    float latency;
    float download_speed;
    float upload_speed;
} QoS;

volatile sig_atomic_t stop;

void handler(int sig)
{
    stop = 1;
}

int main()
{
    key_t key = ftok(".", 'M');
    int shmid = shmget(key, SHM_SIZE, 0600 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget");
        return 1;
    }
    void *shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        return 1;
    }

    QoS* qos = (QoS*) shm;

    pid_t pid = fork();

    if (pid == 0){
        // Child process
        float download_speed = 0;
        float upload_speed = 0;
        float latency = 0;
        char cmd[256];
        while(!stop){
            // Send a ping request to google
            strcpy(cmd, "ping www.google.com -c 1 | grep time | awk '{print $7}' | cut -c 6- > latency.txt");
            system(cmd);
            FILE *fp = fopen("latency.txt","r");
            if (fp != NULL){
                fscanf(fp, "%f", &latency);
                fclose(fp);
            }

            // Check internet download speed using wget
            strcpy(cmd, "wget --output-document=/dev/null --report-speed=bits www.google.com > speed.txt 2>&1");
            system(cmd);
            fp = fopen("speed.txt","r");
            if (fp != NULL){
                char buf[256];
                fgets(buf,256,fp);
                sscanf(buf,"%f",&download_speed);
                fclose(fp);
            }

            // Check internet upload speed using curl
            strcpy(cmd, "curl -o /dev/null -sS -w '%{speed_upload}' http://ipv4.download.thinkbroadband.com/5MB.zip > upload_speed.txt");
            system(cmd);
            fp = fopen("upload_speed.txt","r");
            if (fp != NULL){
                fscanf(fp, "%f", &upload_speed);
                fclose(fp);
            }

            qos->latency = latency;
            qos->download_speed = download_speed;
            qos->upload_speed = upload_speed;

            sleep(10);
        }
        shmdt(shm);
        exit(0);
    }
    else {
        // Parent process
        signal(SIGINT, handler);

        while(!stop){
            printf("Latency: %.2fms\n",qos->latency);
            printf("Download Speed: %.2fMb/s\n", qos->download_speed/1000000);
            printf("Upload Speed: %.2fMb/s\n", qos->upload_speed/1000000);
            sleep(1);
        }

        int status;
        kill(pid, SIGTERM);
        waitpid(pid, &status, 0);
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}