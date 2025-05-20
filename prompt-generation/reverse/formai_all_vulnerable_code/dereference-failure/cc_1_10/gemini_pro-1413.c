//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

// process data structure
typedef struct {
    int id;
    int arrival_time;
    int burst_time;
} process;

// shared data structure
typedef struct {
    int time;
    int running_process;
    bool finished;
} shared_data;

// function to compare processes by arrival time
int compare_processes_by_arrival_time(const void *a, const void *b) {
    const process *pa = (const process *)a;
    const process *pb = (const process *)b;

    return pa->arrival_time - pb->arrival_time;
}

// function to simulate the execution of a process
void *execute_process(void *args) {
    shared_data *data = (shared_data *)args;
    process *p = &data->running_process;

    // simulate the execution of the process
    for (int i = 0; i < p->burst_time; i++) {
        // check if the process has finished executing
        if (data->finished) {
            break;
        }

        // increment the execution time
        data->time++;
    }

    // mark the process as finished
    p->burst_time = 0;

    return NULL;
}

// function to schedule processes using the Round Robin algorithm
void round_robin(process *processes, int num_processes, int time_slice) {
    // sort the processes by arrival time
    qsort(processes, num_processes, sizeof(process), compare_processes_by_arrival_time);

    // create a shared data structure
    shared_data data;
    data.time = 0;
    data.running_process = -1;
    data.finished = false;

    // create threads to execute the processes
    pthread_t threads[num_processes];
    for (int i = 0; i < num_processes; i++) {
        pthread_create(&threads[i], NULL, execute_process, (void *)&data);
    }

    // main loop
    while (!data.finished) {
        // find the next process to run
        int next_process = -1;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].burst_time > 0 && (next_process == -1 || processes[i].arrival_time <= data.time)) {
                next_process = i;
            }
        }

        // if there is a next process to run, run it
        if (next_process != -1) {
            // update running process data
            data.running_process = next_process;

            // run the process for the time slice
            int remaining_time = processes[next_process].burst_time;
            while (remaining_time > 0 && !data.finished) {
                remaining_time--;
                data.time++;

                // check if any other processes have arrived
                for (int i = 0; i < num_processes; i++) {
                    if (processes[i].arrival_time == data.time) {
                        pthread_create(&threads[i], NULL, execute_process, (void *)&data);
                    }
                }
            }
        } else {
            // if there are no processes to run, increment the time
            data.time++;
        }

        // check if all processes have finished executing
        int num_finished = 0;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].burst_time == 0) {
                num_finished++;
            }
        }
        if (num_finished == num_processes) {
            data.finished = true;
        }
    }

    // join threads
    for (int i = 0; i < num_processes; i++) {
        pthread_join(threads[i], NULL);
    }
}

// main function
int main() {
    // create processes
    process processes[] = {
        {1, 0, 5},
        {2, 3, 2},
        {3, 6, 4},
        {4, 9, 3}
    };
    int num_processes = sizeof(processes) / sizeof(processes[0]);

    // schedule processes using the Round Robin algorithm
    round_robin(processes, num_processes, 2);

    // print the execution time of each process
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d executed for %d time units.\n", processes[i].id, processes[i].burst_time);
    }

    return 0;
}