//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20

typedef struct invaders_s {
  int x, y, direction, speed;
  struct invaders_s* next;
} invaders_t;

void initialize_invaders(invaders_t** head) {
  *head = malloc(sizeof(invaders_t));
  (*head)->x = 0;
  (*head)->y = BOARD_SIZE - 1;
  (*head)->direction = 1;
  (*head)->speed = 1;
  (*head)->next = NULL;
}

void move_invaders(invaders_t** head) {
  invaders_t* current = *head;
  while (current) {
    switch (current->direction) {
      case 1:
        current->x++;
        break;
      case 2:
        current->x--;
        break;
      case 3:
        current->y--;
        break;
    }
    current = current->next;
  }
}

void draw_invaders(invaders_t* head) {
  system("clear");
  invaders_t* current = head;
  while (current) {
    switch (current->direction) {
      case 1:
        printf("%c ", '>' + current->x);
        break;
      case 2:
        printf("%c ", '<' + current->x);
        break;
      case 3:
        printf("%c ", '_' + current->x);
        break;
    }
    current = current->next;
  }
  printf("\n");
}

int main() {
  invaders_t* head = NULL;
  initialize_invaders(&head);

  int score = 0;
  while (!head->x >= BOARD_SIZE - 1) {
    move_invaders(&head);
    draw_invaders(head);

    score++;
  }

  printf("Game Over! Your score is: %d", score);

  return 0;
}