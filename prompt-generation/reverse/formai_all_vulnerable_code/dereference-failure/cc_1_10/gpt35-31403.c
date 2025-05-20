//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUF_SIZE 1024
#define NUM_THREADS 4

char *virus_list[] = {"virus1", "virus2", "virus3", "virus4"}; //list of sample viruses

typedef struct {
   int client_fd;
   struct sockaddr_in client_addr;
} client_thread_arg;

typedef struct {
   char **files;
   int num_files;
   int start_index;
} file_thread_arg;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *client_handler(void *arg);
void *file_scanner(void *arg);
int is_virus(char *file_path);

int main(int argc, char **argv) {
   if (argc != 2) {
      fprintf(stderr, "Usage: %s <port>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   int port = atoi(argv[1]);

   int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
   if (sock_fd < 0) {
      perror("socket");
      exit(EXIT_FAILURE);
   }

   struct sockaddr_in addr = {0};
   addr.sin_family = AF_INET;
   addr.sin_port = htons(port);
   addr.sin_addr.s_addr = INADDR_ANY;

   if (bind(sock_fd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
      perror("bind");
      exit(EXIT_FAILURE);
   }

   if (listen(sock_fd, 5) < 0) {
      perror("listen");
      exit(EXIT_FAILURE);
   }

   while (1) {
      client_thread_arg *client_arg = malloc(sizeof(*client_arg));
      if (!client_arg) {
         perror("malloc");
         continue;
      }

      socklen_t client_addr_len = sizeof(client_arg->client_addr);
      client_arg->client_fd = accept(sock_fd, (struct sockaddr *) &client_arg->client_addr, &client_addr_len);
      if (client_arg->client_fd < 0) {
         perror("accept");
         free(client_arg);
         continue;
      }

      pthread_t client_thread;
      if (pthread_create(&client_thread, NULL, client_handler, client_arg) != 0) {
         perror("pthread_create");
         free(client_arg);
         close(client_arg->client_fd);
         continue;
      }

      pthread_detach(client_thread);
   }

   return 0;
}

void *client_handler(void *arg) {
   client_thread_arg *client_arg = (client_thread_arg *) arg;

   char buf[BUF_SIZE];
   ssize_t bytes_read;
   int total_files = 0;

   while ((bytes_read = read(client_arg->client_fd, buf, BUF_SIZE)) > 0) {
      buf[bytes_read] = '\0';

      if (strcmp(buf, "exit") == 0) {
         break;
      }

      char *token = strtok(buf, ",");
      char **files = malloc(sizeof(*files));
      int num_files = 0;

      while (token != NULL) {
         files[num_files] = strdup(token);
         num_files++;
         token = strtok(NULL, ",");
      }

      file_thread_arg *file_arg = malloc(sizeof(*file_arg));
      if (!file_arg) {
         perror("malloc");
         continue;
      }

      file_arg->files = files;
      file_arg->num_files = num_files;

      pthread_t *file_threads = malloc(NUM_THREADS * sizeof(pthread_t));
      if (!file_threads) {
         perror("malloc");
         continue;
      }

      int files_per_thread = num_files / NUM_THREADS;

      for (int i = 0; i < NUM_THREADS; i++) {
         file_arg->start_index = i*files_per_thread;
         if (i == NUM_THREADS-1) {
            file_arg->num_files = num_files - (i*files_per_thread);
         } else {
            file_arg->num_files = files_per_thread;
         }

         if (pthread_create(&file_threads[i], NULL, file_scanner, file_arg) != 0) {
            perror("pthread_create");
            continue;
         }
      }

      for (int i = 0; i < NUM_THREADS; i++) {
         pthread_join(file_threads[i], NULL);
      }

      for (int i = 0; i < num_files; i++) {
         free(files[i]);
      }
      free(files);
      free(file_threads);

      total_files += num_files;
   }

   close(client_arg->client_fd);
   free(client_arg);

   return NULL;
}

void *file_scanner(void *arg) {
   file_thread_arg *file_arg = (file_thread_arg *) arg;

   for (int i = 0; i < file_arg->num_files; i++) {
      char *file_path = file_arg->files[file_arg->start_index+i];

      if (is_virus(file_path)) {
         // notify user that file contains a virus
         pthread_mutex_lock(&mutex);
         printf("Virus detected in file %s\n", file_path);
         pthread_mutex_unlock(&mutex);
      }
   }

   free(file_arg);
   return NULL;
}

int is_virus(char *file_path) {
   FILE *f = fopen(file_path, "r");
   if (!f) {
      return 0;
   }

   char buf[BUF_SIZE];

   while (fgets(buf, BUF_SIZE, f) != NULL) {
      for (int i = 0; i < sizeof(virus_list)/sizeof(virus_list[0]); i++) {
         if (strstr(buf, virus_list[i])) {
            fclose(f);
            return 1;
         }
      }
   }

   fclose(f);
   return 0;
}