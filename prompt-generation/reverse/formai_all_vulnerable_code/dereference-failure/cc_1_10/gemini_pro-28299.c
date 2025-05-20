//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#if !defined(_WIN32) && !defined(__linux__)
#error "Can be run on Windows or Linux only"
#endif

#if defined(_WIN32)
#include <Windows.h>
#elif defined(__linux__)
#include <sys/prctl.h>
#endif

int main() {
  int pid = getpid();
#if defined(_WIN32)
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  ZeroMemory(&pi, sizeof(pi));
  char szCmd[100];
  char buf[100];
  DWORD nRet;
  int hour, minute, second;
  time_t t;
  time(&t);
  struct tm *tm_t = localtime(&t);
  hour = tm_t->tm_hour;
  minute = tm_t->tm_min;
  second = tm_t->tm_sec;
  sscanf(buf, "%d:%d:%d", &hour, &minute, &second);
  sprintf(szCmd, "echo %d:%d:%d >> time.txt", hour, minute, second);
  CreateProcess(NULL, szCmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
  WaitForSingleObject(pi.hProcess, INFINITE);
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);
#elif defined(__linux__)
  pid_t child_pid = fork();
  int child_status;
  if (child_pid == 0) {
    int hour, minute, second;
    time_t t;
    time(&t);
    struct tm *tm_t = localtime(&t);
    hour = tm_t->tm_hour;
    minute = tm_t->tm_min;
    second = tm_t->tm_sec;
    char buf[100];
    sprintf(buf, "%d:%d:%d\n", hour, minute, second);
    FILE *f = fopen("time.txt", "a");
    if (f != NULL) {
      fprintf(f, "%s", buf);
      fclose(f);
    }
    exit(0);
  } else {
    waitpid(child_pid, &child_status, 0);
  }
#endif
  return 0;
}