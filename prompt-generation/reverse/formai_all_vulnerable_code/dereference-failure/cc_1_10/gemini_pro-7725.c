//GEMINI-pro DATASET v1.0 Category: Pong Game with AI Opponent ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 24
#define PADDLE_WIDTH 4
#define BALL_SIZE 2

typedef struct {
  int x, y;
} Vector;

typedef struct {
  Vector pos;
  Vector vel;
} Ball;

typedef struct {
  Vector pos;
  int score;
} Paddle;

Ball ball;
Paddle player, ai;
int running = 1;

void draw() {
  system("clear");
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if (y == 0 || y == HEIGHT - 1)
        printf("#");
      else if (x == 0 || x == WIDTH - 1) {
        if (y == player.pos.y || y == player.pos.y + PADDLE_WIDTH - 1)
          printf("|");
        else if (y == ai.pos.y || y == ai.pos.y + PADDLE_WIDTH - 1)
          printf("|");
        else
          printf(" ");
      } else if (x == ball.pos.x && y == ball.pos.y)
        printf("O");
      else
        printf(" ");
    }
    printf("\n");
  }
  printf("Player: %d  AI: %d\n", player.score, ai.score);
}

void move_player(int dy) {
  player.pos.y = fmin(fmax(player.pos.y + dy, 0), HEIGHT - PADDLE_WIDTH);
}

void *move_ai(void *arg) {
  while (running) {
    ai.pos.y = fmin(fmax(ball.pos.y - PADDLE_WIDTH / 2, 0), HEIGHT - PADDLE_WIDTH);
    usleep(100000);
  }
  return NULL;
}

void update_ball() {
  ball.pos.x += ball.vel.x;
  ball.pos.y += ball.vel.y;

  if (ball.pos.x < 0 || ball.pos.x > WIDTH - 1) {
    ball.vel.x = -ball.vel.x;
  }

  if (ball.pos.y < 0 || ball.pos.y > HEIGHT - 1) {
    ball.vel.y = -ball.vel.y;
  }

  if (ball.pos.x == 0 && (ball.pos.y >= player.pos.y && ball.pos.y <= player.pos.y + PADDLE_WIDTH - 1)) {
    ball.vel.x = -ball.vel.x;
  } else if (ball.pos.x == WIDTH - 1 && (ball.pos.y >= ai.pos.y && ball.pos.y <= ai.pos.y + PADDLE_WIDTH - 1)) {
    ball.vel.x = -ball.vel.x;
  }

  if (ball.pos.x < 0) {
    ai.score++;
    ball.pos.x = WIDTH / 2;
    ball.pos.y = HEIGHT / 2;
    ball.vel.x = rand() % 2 == 0 ? 1 : -1;
    ball.vel.y = rand() % 2 == 0 ? 1 : -1;
  } else if (ball.pos.x > WIDTH - 1) {
    player.score++;
    ball.pos.x = WIDTH / 2;
    ball.pos.y = HEIGHT / 2;
    ball.vel.x = rand() % 2 == 0 ? 1 : -1;
    ball.vel.y = rand() % 2 == 0 ? 1 : -1;
  }
}

void *input_thread(void *arg) {
  char c;
  while (running) {
    c = getchar();
    if (c == 'w' || c == 'W') {
      move_player(-1);
    } else if (c == 's' || c == 'S') {
      move_player(1);
    } else if (c == 'q' || c == 'Q') {
      running = 0;
      break;
    }
  }
  return NULL;
}

int main() {
  srand(time(NULL));

  ball.pos.x = WIDTH / 2;
  ball.pos.y = HEIGHT / 2;
  ball.vel.x = rand() % 2 == 0 ? 1 : -1;
  ball.vel.y = rand() % 2 == 0 ? 1 : -1;

  player.pos.x = 0;
  player.pos.y = HEIGHT / 2 - PADDLE_WIDTH / 2;
  player.score = 0;

  ai.pos.x = WIDTH - 1;
  ai.pos.y = HEIGHT / 2 - PADDLE_WIDTH / 2;
  ai.score = 0;

  pthread_t ai_thread, input_thread;
  pthread_create(&ai_thread, NULL, move_ai, NULL);
  pthread_create(&input_thread, NULL, input_thread, NULL);

  while (running) {
    update_ball();
    draw();
    usleep(10000);
  }

  pthread_join(ai_thread, NULL);
  pthread_join(input_thread, NULL);

  return 0;
}