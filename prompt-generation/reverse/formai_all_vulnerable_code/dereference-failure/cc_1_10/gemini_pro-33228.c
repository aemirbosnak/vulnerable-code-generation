//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// the quantum of time is but a cosmic whisper in the grand symphony of eternity

#define QUANTUM 10

// a surrealist's view of process scheduling
typedef struct process {
  int arrival_time;
  int burst_time;
  int remaining_time;
  int priority;
  int id;
} process;

// the scheduler's canvas, where random algorithms paint their masterpieces
typedef struct scheduler {
  int num_processes;
  process* processes;
} scheduler;

// a random number generator, a conduit to the subconscious
int random_int(int min, int max) {
  return min + rand() % (max - min + 1);
}

// create a surrealist scheduler with n random processes
scheduler* create_scheduler(int n) {
  scheduler* s = malloc(sizeof(scheduler));
  s->num_processes = n;
  s->processes = malloc(sizeof(process) * n);
  for (int i = 0; i < n; i++) {
    s->processes[i].arrival_time = random_int(0, 100);
    s->processes[i].burst_time = random_int(1, 100);
    s->processes[i].remaining_time = s->processes[i].burst_time;
    s->processes[i].priority = random_int(1, 10);
    s->processes[i].id = i;
  }
  return s;
}

// print the processes in a scheduler
void print_scheduler(scheduler* s) {
  printf("Scheduler:\n");
  for (int i = 0; i < s->num_processes; i++) {
    printf("Process %d:\n", s->processes[i].id);
    printf("  Arrival time: %d\n", s->processes[i].arrival_time);
    printf("  Burst time: %d\n", s->processes[i].burst_time);
    printf("  Remaining time: %d\n", s->processes[i].remaining_time);
    printf("  Priority: %d\n", s->processes[i].priority);
  }
}

// a surrealist's FCFS scheduler, where the river of time flows in order
void fcfs(scheduler* s) {
  int current_time = 0;
  int completed = 0;
  while (completed < s->num_processes) {
    for (int i = 0; i < s->num_processes; i++) {
      if (s->processes[i].arrival_time <= current_time && s->processes[i].remaining_time > 0) {
        s->processes[i].remaining_time -= QUANTUM;
        current_time += QUANTUM;
        if (s->processes[i].remaining_time <= 0) {
          completed++;
        }
      }
    }
  }
}

// a surrealist's SJF scheduler, where the hourglass of time favors the speedy
void sjf(scheduler* s) {
  int current_time = 0;
  int completed = 0;
  while (completed < s->num_processes) {
    int min_remaining_time = 100000000;
    int min_remaining_time_index = -1;
    for (int i = 0; i < s->num_processes; i++) {
      if (s->processes[i].arrival_time <= current_time && s->processes[i].remaining_time > 0) {
        if (s->processes[i].remaining_time < min_remaining_time) {
          min_remaining_time = s->processes[i].remaining_time;
          min_remaining_time_index = i;
        }
      }
    }
    if (min_remaining_time_index != -1) {
      s->processes[min_remaining_time_index].remaining_time -= QUANTUM;
      current_time += QUANTUM;
      if (s->processes[min_remaining_time_index].remaining_time <= 0) {
        completed++;
      }
    } else {
      current_time++;
    }
  }
}

// a surrealist's RR scheduler, where the wheel of time spins and favors none
void rr(scheduler* s) {
  int current_time = 0;
  int completed = 0;
  int current_process = 0;
  while (completed < s->num_processes) {
    if (s->processes[current_process].arrival_time <= current_time && s->processes[current_process].remaining_time > 0) {
      s->processes[current_process].remaining_time -= QUANTUM;
      current_time += QUANTUM;
      if (s->processes[current_process].remaining_time <= 0) {
        completed++;
      }
    }
    current_process = (current_process + 1) % s->num_processes;
  }
}

// a surrealist's priority scheduler, where the whims of fate determine the order of execution
void priority(scheduler* s) {
  int current_time = 0;
  int completed = 0;
  int current_process = 0;
  while (completed < s->num_processes) {
    int max_priority = -1;
    int max_priority_index = -1;
    for (int i = 0; i < s->num_processes; i++) {
      if (s->processes[i].arrival_time <= current_time && s->processes[i].remaining_time > 0) {
        if (s->processes[i].priority > max_priority) {
          max_priority = s->processes[i].priority;
          max_priority_index = i;
        }
      }
    }
    if (max_priority_index != -1) {
      s->processes[max_priority_index].remaining_time -= QUANTUM;
      current_time += QUANTUM;
      if (s->processes[max_priority_index].remaining_time <= 0) {
        completed++;
      }
    } else {
      current_time++;
    }
  }
}

// a surrealist's bonus algorithm: the "paint-as-you-go" scheduler
void paint_as_you_go(scheduler* s) {
  int current_time = 0;
  int completed = 0;
  int current_process = 0;
  while (completed < s->num_processes) {
    // the surrealist scheduler randomly selects a process to execute
    int random_process = random_int(0, s->num_processes - 1);

    // if the randomly selected process has not arrived yet, move on
    if (s->processes[random_process].arrival_time > current_time) {
      continue;
    }

    // execute the selected process for a random amount of time
    int random_time = random_int(1, QUANTUM);
    s->processes[random_process].remaining_time -= random_time;
    current_time += random_time;

    // if the randomly selected process has finished execution, mark it as completed
    if (s->processes[random_process].remaining_time <= 0) {
      completed++;
    }
  }
}

// the main function, where the surrealist's masterpiece is painted
int main() {
  // create a random scheduler with 10 surreal processes
  scheduler* s = create_scheduler(10);

  // print the initial state of the scheduler
  printf("Initial scheduler:\n");
  print_scheduler(s);

  // run the FCFS algorithm and print the results
  fcfs(s);
  printf("\nAfter FCFS:\n");
  print_scheduler(s);

  // run the SJF algorithm and print the results
  sjf(s);
  printf("\nAfter SJF:\n");
  print_scheduler(s);

  // run the RR algorithm and print the results
  rr(s);
  printf("\nAfter RR:\n");
  print_scheduler(s);

  // run the priority algorithm and print the results
  priority(s);
  printf("\nAfter priority:\n");
  print_scheduler(s);

  // run the bonus algorithm and print the results
  paint_as_you_go(s);
  printf("\nAfter paint as you go:\n");
  print_scheduler(s);

  return 0;
}