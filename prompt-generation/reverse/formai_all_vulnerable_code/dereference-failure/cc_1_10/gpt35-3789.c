//FormAI DATASET v1.0 Category: Task Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function pointer typedef for task functions
typedef void (* task_func_t) (void);

// Task struct
typedef struct task
{
     task_func_t function;
     time_t time_interval;
     time_t next_exec_time;
} task_t;

// Global array of tasks
task_t *task_list[10];
int num_tasks = 0;

// Example task function #1
void task1(void)
{
   printf("Task 1 executed!\n");
}

// Example task function #2
void task2(void)
{
   printf("Task 2 executed!\n");
}

// Add task function
void add_task(task_func_t function, time_t interval)
{
   if (num_tasks >= 10)
   {
      printf("Cannot add task: maximum number of tasks reached.\n");
      return;
   }
   task_t *t = (task_t*) malloc(sizeof(task_t));
   t->function = function;
   t->time_interval = interval;
   t->next_exec_time = time(NULL) + interval;
   task_list[num_tasks++] = t;
   printf("Task added!\n");
}

// Remove task function
void remove_task(int index)
{
   if (index < 0 || index >= num_tasks)
   {
       printf("Cannot remove task: index is out of range.\n");
       return;
   }
   free(task_list[index]);
   for (int i = index; i < num_tasks - 1; i++)
   {
       task_list[i] = task_list[i+1];
   }
   num_tasks--;
   printf("Task removed!\n");
}

// Main function
int main()
{
   printf("Welcome to Task Scheduler!\n");
 
   add_task(task1, 5);
   add_task(task2, 10);
   
   // Main loop
   while (1)
   {
      for (int i = 0; i < num_tasks; i++)
      {
          if (task_list[i]->next_exec_time <= time(NULL))
          {
              task_list[i]->function();
              task_list[i]->next_exec_time += task_list[i]->time_interval;
          }
      }
   }

   return 0;
}