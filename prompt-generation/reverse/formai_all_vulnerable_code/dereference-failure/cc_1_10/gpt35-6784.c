//FormAI DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>

// Initialize task struct and queue struct
typedef struct {
   int task_id;
   int delay;
   void (*fn_ptr)(void);
} task_t;

typedef struct {
   task_t* queue[100];
   int count;
} queue_t;

queue_t task_queue;

// Function that adds task to queue
void add_task(int id, int d, void (*func)(void)){
   for(int i = 0; i < task_queue.count; i++){
      if(task_queue.queue[i]->delay < d){
         // Insert task before i in queue
         task_t* tmp = task_queue.queue[i];
         task_queue.queue[i] = malloc(sizeof(task_t));
         task_queue.queue[i]->task_id = id;
         task_queue.queue[i]->delay = d;
         task_queue.queue[i]->fn_ptr = func;
         for(int j = i+1; j < task_queue.count+1; j++){
            task_t* tmp2 = task_queue.queue[j];
            task_queue.queue[j] = tmp;
            tmp = tmp2;
         }
         task_queue.count++;
         return;
      }
   }
   // Add task to end of queue
   task_queue.queue[task_queue.count] = malloc(sizeof(task_t));
   task_queue.queue[task_queue.count]->task_id = id;
   task_queue.queue[task_queue.count]->delay = d;
   task_queue.queue[task_queue.count]->fn_ptr = func;
   task_queue.count++;
}

// Function that executes tasks in queue
void execute_tasks(){
   while(task_queue.count > 0){
      task_queue.count--;
      (task_queue.queue[task_queue.count]->fn_ptr)();
      free(task_queue.queue[task_queue.count]);
   }
}

// Example tasks in medieval style
void repair_wall(){
   printf("Repairing the castle walls!\n");
}

void sharpen_swords(){
   printf("Sharpening the swords!\n");
}

void train_archers(){
   printf("Training archers!\n");
}

void main(){
   // Add tasks to queue with different delays
   add_task(1, 5, &repair_wall);
   add_task(2, 10, &sharpen_swords);
   add_task(3, 2, &train_archers);
   
   // Execute tasks in queue
   execute_tasks();
}