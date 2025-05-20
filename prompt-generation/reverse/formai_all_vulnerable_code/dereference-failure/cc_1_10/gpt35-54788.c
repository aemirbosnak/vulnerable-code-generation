//FormAI DATASET v1.0 Category: QR code generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "qrencode.h"

#define MAX_THREADS 10
#define MAX_CODE_LENGTH 129 

pthread_mutex_t mutex;
char code[MAX_THREADS][MAX_CODE_LENGTH];

void* generate_code(void* arg) {

  int id = *((int*)arg);
  QRcode* qrcode;

  char my_code[MAX_CODE_LENGTH];
  sprintf(my_code, "ABC%d123", id);

  qrcode = QRcode_encodeString(my_code, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
  if(qrcode) {
    pthread_mutex_lock(&mutex);
    sprintf(code[id], "%s", qrcode->data);
    pthread_mutex_unlock(&mutex);
    QRcode_free(qrcode);
  }
  return NULL;
}

int main() {

  pthread_t threads[MAX_THREADS];
  int thread_ids[MAX_THREADS]; 
  int i;

  pthread_mutex_init(&mutex, NULL);

  for(i = 0; i < MAX_THREADS; i++) {
    thread_ids[i] = i;
    pthread_create(&threads[i], NULL, generate_code, &thread_ids[i]);
  }

  for(i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
    printf("Thread %d generated QR code: %s\n", i, code[i]);
  }

  pthread_mutex_destroy(&mutex);

  return 0;
}