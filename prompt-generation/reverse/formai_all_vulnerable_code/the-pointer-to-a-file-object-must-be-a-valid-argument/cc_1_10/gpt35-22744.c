//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#define MAXHISTOGRAM 20
#define MAXLINE 1000

int total;
float loadavg[MAXHISTOGRAM];
char display[MAXLINE];

void update_display()
{
    int i,j;
    int bar;
    char bar_element;
    int bar_length;

    for(i = 0; i < MAXLINE; i++)  
        display[i]='\0';

    sprintf(display, "CPU Usage: |"); 
    for(i = 0; i < MAXHISTOGRAM; i++)
    {
        bar_length = (int)(loadavg[i] * MAXLINE);
        bar = (bar_length > 0) ? bar_length : 0;
        bar_element = (i == (MAXHISTOGRAM - 1)) ? '\n' : '-';
     
        for(j = 0; j < bar; j++)
            strncat(display, &bar_element, 1);
        strncat(display,"|",1); 
    }   
}

void *loadavg_monitor(void *arg)
{
    char buffer[1024];
    FILE *file;
    while(1) 
    {
        file = fopen("/proc/loadavg", "r");
        fgets(buffer, sizeof(buffer), file);
        sscanf(buffer, "%f %*f %*f", &loadavg[0]);
        fclose(file);

        total++;
        if(total >= MAXHISTOGRAM) 
        {
            memmove(loadavg, &loadavg[1], (MAXHISTOGRAM - 1) * sizeof(float));
            total = MAXHISTOGRAM - 1;
        }

        update_display();
        printf("%s", display); 

        sleep(2); 
    }
}

int main()
{
    pthread_t loadavg_thread_id;
    int ret;
    ret = pthread_create(&loadavg_thread_id, NULL, &loadavg_monitor, NULL);
    if(ret != 0) 
    {
        printf("Error: pthread_create() failed\n");
        exit(EXIT_FAILURE);
    }

    pthread_join(loadavg_thread_id, NULL); 
    return 0;
}