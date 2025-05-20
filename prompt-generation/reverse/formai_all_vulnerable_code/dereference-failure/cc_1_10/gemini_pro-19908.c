//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define WIDTH 80
#define HEIGHT 25

// Colors
#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7

// Directions
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// Snake
typedef struct snake {
  int x, y;
  int dx, dy;
  struct snake *next;
} snake;

// Food
typedef struct food {
  int x, y;
} food;

// Game
typedef struct game {
  snake *head;
  food f;
  int score;
  int speed;
  int running;
} game;

// Prototypes
void init_game(game *g);
void draw_game(game *g);
void update_game(game *g);
void input(game *g);
void move_snake(snake *s);
void add_snake(snake **s, int x, int y);
void remove_snake(snake **s);
void create_food(game *g);
int check_collision(game *g);

int main() {
  // Initialize the game
  game g;
  init_game(&g);

  // Main game loop
  while (g.running) {
    // Draw the game
    draw_game(&g);

    // Update the game
    update_game(&g);

    // Input
    input(&g);

    // Sleep
    usleep(1000000 / g.speed);
  }

  // Game over
  printf("Game over! Your score: %d\n", g.score);

  return 0;
}

void init_game(game *g) {
  // Initialize the snake
  g->head = malloc(sizeof(snake));
  g->head->x = WIDTH / 2;
  g->head->y = HEIGHT / 2;
  g->head->dx = 0;
  g->head->dy = 1;
  g->head->next = NULL;

  // Initialize the food
  create_food(g);

  // Initialize the game settings
  g->score = 0;
  g->speed = 10;
  g->running = 1;
}

void draw_game(game *g) {
  // Clear the screen
  printf("\033[2J");

  // Draw the snake
  snake *s = g->head;
  while (s != NULL) {
    printf("\033[%d;%dH\033[0;32m■\033[0m", s->y + 1, s->x + 1);
    s = s->next;
  }

  // Draw the food
  printf("\033[%d;%dH\033[0;31m@\033[0m", g->f.y + 1, g->f.x + 1);

  // Draw the score
  printf("\033[%d;%dHScore: %d\033[0m", HEIGHT + 1, 1, g->score);
}

void update_game(game *g) {
  // Move the snake
  move_snake(g->head);

  // Check for collision
  int collision = check_collision(g);
  if (collision == 1) {
    // Game over
    g->running = 0;
  } else if (collision == 2) {
    // Eat the food
    g->score++;
    g->speed++;
    create_food(g);
  }
}

void input(game *g) {
  // Get the input
  int ch = getch();

  // Update the snake's direction
  switch (ch) {
    case 'w':
      if (g->head->dy != 1) {
        g->head->dx = 0;
        g->head->dy = -1;
      }
      break;
    case 's':
      if (g->head->dy != -1) {
        g->head->dx = 0;
        g->head->dy = 1;
      }
      break;
    case 'a':
      if (g->head->dx != 1) {
        g->head->dx = -1;
        g->head->dy = 0;
      }
      break;
    case 'd':
      if (g->head->dx != -1) {
        g->head->dx = 1;
        g->head->dy = 0;
      }
      break;
    case 'q':
      // Quit the game
      g->running = 0;
      break;
  }
}

void move_snake(snake *s) {
  // Move the head
  s->x += s->dx;
  s->y += s->dy;

  // Wrap around the edges
  if (s->x < 0) {
    s->x = WIDTH - 1;
  } else if (s->x >= WIDTH) {
    s->x = 0;
  }
  if (s->y < 0) {
    s->y = HEIGHT - 1;
  } else if (s->y >= HEIGHT) {
    s->y = 0;
  }

  // Move the rest of the snake
  snake *prev = s;
  snake *curr = s->next;
  while (curr != NULL) {
    curr->x = prev->x;
    curr->y = prev->y;
    prev = curr;
    curr = curr->next;
  }
}

void add_snake(snake **s, int x, int y) {
  // Create a new snake segment
  snake *new_segment = malloc(sizeof(snake));
  new_segment->x = x;
  new_segment->y = y;
  new_segment->dx = 0;
  new_segment->dy = 0;
  new_segment->next = NULL;

  // Add the new segment to the end of the snake
  snake *last = *s;
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = new_segment;
}

void remove_snake(snake **s) {
  // Remove the last segment of the snake
  snake *last = *s;
  while (last->next->next != NULL) {
    last = last->next;
  }
  free(last->next);
  last->next = NULL;
}

void create_food(game *g) {
  // Generate a random position for the food
  srand(time(NULL));
  g->f.x = rand() % WIDTH;
  g->f.y = rand() % HEIGHT;

  // Check if the food is on the snake
  snake *s = g->head;
  while (s != NULL) {
    if (s->x == g->f.x && s->y == g->f.y) {
      create_food(g);
      break;
    }
    s = s->next;
  }
}

int check_collision(game *g) {
  // Check if the snake has hit itself
  snake *s = g->head;
  while (s->next != NULL) {
    if (s->x == g->head->x && s->y == g->head->y) {
      return 1;  // Collision with self
    }
    s = s->next;
  }

  // Check if the snake has hit the food
  if (g->head->x == g->f.x && g->head->y == g->f.y) {
    return 2;  // Collision with food
  }

  // No collision
  return 0;
}

// Getch function for non-canonical input
int getch() {
  int ch;
  struct termios oldt, newt;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return ch;
}