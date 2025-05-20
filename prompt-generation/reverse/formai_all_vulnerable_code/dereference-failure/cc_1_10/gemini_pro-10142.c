//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct appointment {
  int id;
  char *name;
  time_t start;
  time_t end;
} appointment;

typedef struct appointment_list {
  appointment *appointments;
  int count;
  int capacity;
} appointment_list;

pthread_mutex_t lock;

void init_appointment_list(appointment_list *list) {
  list->appointments = malloc(sizeof(appointment) * 10);
  list->count = 0;
  list->capacity = 10;
}

void free_appointment_list(appointment_list *list) {
  for (int i = 0; i < list->count; i++) {
    free(list->appointments[i].name);
  }
  free(list->appointments);
}

void add_appointment(appointment_list *list, appointment *appointment) {
  pthread_mutex_lock(&lock);
  if (list->count == list->capacity) {
    list->appointments = realloc(list->appointments, sizeof(appointment) * (list->capacity * 2));
    list->capacity *= 2;
  }
  list->appointments[list->count++] = *appointment;
  pthread_mutex_unlock(&lock);
}

void *thread_func(void *arg) {
  appointment_list *list = (appointment_list *)arg;

  while (1) {
    pthread_mutex_lock(&lock);

    if (list->count == 0) {
      pthread_mutex_unlock(&lock);
      continue;
    }

    appointment *appointment = &list->appointments[0];

    for (int i = 1; i < list->count; i++) {
      if (list->appointments[i].start < appointment->start) {
        appointment = &list->appointments[i];
      }
    }

    printf("Appointment with %s at %s\n", appointment->name, ctime(&appointment->start));

    for (int i = 0; i < list->count; i++) {
      if (&list->appointments[i] == appointment) {
        for (int j = i; j < list->count - 1; j++) {
          list->appointments[j] = list->appointments[j + 1];
        }
        list->count--;
        break;
      }
    }

    pthread_mutex_unlock(&lock);

    sleep(1);
  }

  return NULL;
}

int main() {
  pthread_mutex_init(&lock, NULL);

  appointment_list list;
  init_appointment_list(&list);

  pthread_t thread;
  pthread_create(&thread, NULL, thread_func, &list);

  appointment appointment1 = {1, "John Doe", time(NULL) + 3600, time(NULL) + 7200};
  add_appointment(&list, &appointment1);

  appointment appointment2 = {2, "Jane Doe", time(NULL) + 7200, time(NULL) + 10800};
  add_appointment(&list, &appointment2);

  pthread_join(thread, NULL);

  free_appointment_list(&list);

  pthread_mutex_destroy(&lock);

  return 0;
}