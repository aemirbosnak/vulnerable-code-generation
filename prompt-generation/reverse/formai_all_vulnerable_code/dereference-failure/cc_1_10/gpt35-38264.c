//FormAI DATASET v1.0 Category: Log analysis ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>

// Define the LogEvent struct to represent a single log message
typedef struct LogEvent {
  char timestamp[20];
  char level[10];
  char message[100];
} LogEvent;

// Define a struct to hold variables used by our application
typedef struct {
  int max_events;
  int num_events;
  bool running;
  FILE* file;
  LogEvent* events;
  pthread_mutex_t lock;
  pthread_cond_t cond;
} LogWatcher;

// Define a function that reads log messages from a file and adds them to our LogWatcher's events array
void* watch_logs(void* arg) {
  LogWatcher* watcher = (LogWatcher*)arg;
  
  while (watcher->running) {
    pthread_mutex_lock(&watcher->lock);
    
    // Check if we've hit our limit on total events
    if (watcher->num_events >= watcher->max_events) {
      pthread_mutex_unlock(&watcher->lock);
      break;
    }
    
    // Read a line from the log file
    char line[200];
    if (!fgets(line, sizeof(line), watcher->file)) {
      // Wait a bit and try again if we didn't get a line of text
      pthread_mutex_unlock(&watcher->lock);
      usleep(100000);
      continue;
    }
    
    // Parse the message level and timestamp from the line
    char level[10], ts[20], message[100];
    int num_fields = sscanf(line, "%9s %19s %99[^\n]", level, ts, message);
    if (num_fields < 3) {
      pthread_mutex_unlock(&watcher->lock);
      continue;
    }
    
    // Copy the parsed fields into a new LogEvent struct and add it to our events array
    LogEvent event;
    strncpy(event.timestamp, ts, sizeof(event.timestamp));
    strncpy(event.level, level, sizeof(event.level));
    strncpy(event.message, message, sizeof(event.message));
    watcher->events[watcher->num_events++] = event;
    
    // Notify our main thread that we have new events
    pthread_cond_signal(&watcher->cond);
    pthread_mutex_unlock(&watcher->lock);
  }
  
  return NULL;
}

// Define a function that prints out all of the events in our LogWatcher's events array
void print_events(LogWatcher* watcher) {
  printf("\n");
  for (int i = 0; i < watcher->num_events; i++) {
    LogEvent event = watcher->events[i];
    printf("%s [%s] %s\n", event.timestamp, event.level, event.message);
  }
  printf("\n");
}

// Define the main function that kicks off our program
int main(int argc, char* argv[]) {
  if (argc < 3) {
    printf("Usage: logwatcher <logfile> <max_events>\n");
    return 1;
  }
  
  // Parse the command line arguments
  char* logfile = argv[1];
  int max_events = atoi(argv[2]);
  
  // Open the log file
  FILE* file = fopen(logfile, "r");
  if (!file) {
    printf("Unable to open log file '%s'\n", logfile);
    return 1;
  }
  
  // Initialize our LogWatcher struct
  LogWatcher watcher;
  watcher.max_events = max_events;
  watcher.num_events = 0;
  watcher.file = file;
  watcher.events = (LogEvent*)malloc(sizeof(LogEvent) * max_events);
  watcher.running = true;
  pthread_mutex_init(&watcher.lock, NULL);
  pthread_cond_init(&watcher.cond, NULL);
  
  // Start watching the log file in a separate thread
  pthread_t thread;
  pthread_create(&thread, NULL, watch_logs, &watcher);
  
  // Wait for events to accumulate in our LogWatcher struct and print them out periodically
  while (watcher.running) {
    pthread_mutex_lock(&watcher.lock);
    pthread_cond_wait(&watcher.cond, &watcher.lock);
    
    if (watcher.num_events >= watcher.max_events) {
      watcher.running = false;
    } else {
      print_events(&watcher);
    }
    
    pthread_mutex_unlock(&watcher.lock);
  }
  
  // Clean up resources
  pthread_join(thread, NULL);
  fclose(file);
  free(watcher.events);
  
  pthread_mutex_destroy(&watcher.lock);
  pthread_cond_destroy(&watcher.cond);
  
  return 0;
}