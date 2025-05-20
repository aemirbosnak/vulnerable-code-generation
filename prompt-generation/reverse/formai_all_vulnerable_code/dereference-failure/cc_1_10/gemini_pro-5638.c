//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#ifdef WIN_SYS
#include <windows.h>
#include <wingdi.h>

#define ERROR_CODE_MAX 32
#define ERROR_CODE_SIZE 500
char error_message[ERROR_CODE_MAX][ERROR_CODE_SIZE];
#endif

#define MAX 1000000

int *fib, *mem;

void fib_init() {
  fib = malloc(sizeof(int) * MAX);
  mem = malloc(sizeof(int) * MAX);

  fib[0] = 0;
  fib[1] = 1;
  mem[0] = 1;
  mem[1] = 1;

  for (int i = 2; i < MAX; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
    mem[i] = 0;
  }
}

int fib_get(int n) {
  if (mem[n]) return fib[n];
  return fib[n] = fib[n - 1] + fib[n - 2];
}

int main() {
  int counter = 0;
  fib_init();

  for (int i = 0; i < MAX; ++i) {
    if (fib_get(i) % 2 == 0) { counter += fib_get(i); }
  }

  #ifdef WIN_SYS
    MessageBox(NULL, "fib", "fib", 0);
  #endif

  assert(counter == 4613732);

  return 0;
}