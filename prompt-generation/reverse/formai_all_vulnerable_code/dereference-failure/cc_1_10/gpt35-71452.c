//FormAI DATASET v1.0 Category: System process viewer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int main() {
   DIR *dir_ptr;
   struct dirent *dirent_ptr;
   FILE *file_ptr;
   char file_name[100], line[512], status[50];
   int pid, ppid, cpu, mem;

   printf("#####################################################\n");
   printf("#                   PROCESS VIEWER                   #\n");
   printf("#####################################################\n\n");

   if ((dir_ptr = opendir("/proc/")) == NULL) {
      perror("Directory does not exist ");
      exit(1);
   }

   while ((dirent_ptr = readdir(dir_ptr)) != NULL) {
      if (isdigit(dirent_ptr->d_name[0])) {
         sprintf(file_name, "/proc/%s/status", dirent_ptr->d_name);
         if ((file_ptr = fopen(file_name, "r")) != NULL) {
            fgets(line, 512, file_ptr);
            sscanf(line, "%*s %s", status);
            if (strcmp(status, "R") == 0) {
               fgets(line, 512, file_ptr);
               strtok(line, "\n\t ");
               strtok(NULL, "\n\t ");
               pid = atoi(dirent_ptr->d_name);
               printf("Process ID:%d\t", pid);
               strtok(NULL, "\n\t ");
               ppid = atoi(strtok(NULL, "\n\t "));
               printf("Parent ID:%d\t", ppid);
               strtok(NULL, "\n\t ");
               strtok(NULL, "\n\t ");
               cpu = atoi(strtok(NULL, "\n\t "));
               printf("CPU Usage:%d%%\t", cpu);
               fgets(line, 512, file_ptr);
               strtok(line, "\n\t ");
               strtok(NULL, "\n\t ");
               mem = atoi(strtok(NULL, "\n\t "));
               printf("Memory Usage:%d KB\n", mem);
            }
            fclose(file_ptr);
         }
      }
   }
   closedir(dir_ptr);
   return 0;
}