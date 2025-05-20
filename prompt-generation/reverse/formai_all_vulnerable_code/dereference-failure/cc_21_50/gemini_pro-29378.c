//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int x, y;
} pos_t;

typedef struct {
  char *name;
  int hp, atk, def;
} entity_t;

int main() {
  srand(time(NULL));

  int w = 80, h = 25;
  char *map[h];
  for (int i = 0; i < h; i++) {
    map[i] = malloc(w + 1);
    for (int j = 0; j < w; j++) {
      map[i][j] = (rand() % 5) ? '#' : '.';
    }
    map[i][w] = '\0';
  }

  pos_t player = {w / 2, h / 2};
  entity_t *player_ent = malloc(sizeof(entity_t));
  player_ent->name = "Player";
  player_ent->hp = 100;
  player_ent->atk = 10;
  player_ent->def = 5;

  while (player_ent->hp > 0) {
    system("clear");
    for (int i = 0; i < h; i++) {
      puts(map[i]);
    }

    printf("HP: %d\n", player_ent->hp);

    char c = getchar();
    switch (c) {
    case 'w':
      if (map[player.y - 1][player.x] != '#') { player.y--; }
      break;
    case 's':
      if (map[player.y + 1][player.x] != '#') { player.y++; }
      break;
    case 'a':
      if (map[player.y][player.x - 1] != '#') { player.x--; }
      break;
    case 'd':
      if (map[player.y][player.x + 1] != '#') { player.x++; }
      break;
    }

    // Enemy generation
    if (rand() % 10 == 0) {
      pos_t enemy = {rand() % w, rand() % h};
      while (map[enemy.y][enemy.x] != '#' || (abs(player.x - enemy.x) + abs(player.y - enemy.y) < 5)) {
        enemy.x = rand() % w;
        enemy.y = rand() % h;
      }

      entity_t *enemy_ent = malloc(sizeof(entity_t));
      enemy_ent->name = "Enemy";
      enemy_ent->hp = 50;
      enemy_ent->atk = 5;
      enemy_ent->def = 2;

      // Battle
      while (player_ent->hp > 0 && enemy_ent->hp > 0) {
        int player_dmg = player_ent->atk - enemy_ent->def;
        int enemy_dmg = enemy_ent->atk - player_ent->def;
        player_dmg = player_dmg < 0 ? 0 : player_dmg;
        enemy_dmg = enemy_dmg < 0 ? 0 : enemy_dmg;

        player_ent->hp -= enemy_dmg;
        enemy_ent->hp -= player_dmg;

        printf("You attack the %s for %d damage!\n", enemy_ent->name, player_dmg);
        printf("The %s attacks you for %d damage!\n", enemy_ent->name, enemy_dmg);
      }

      if (player_ent->hp <= 0) {
        printf("You died!\n");
      } else {
        map[enemy.y][enemy.x] = '.';
      }

      free(enemy_ent);
    }

    map[player.y][player.x] = '@';
  }

  for (int i = 0; i < h; i++) {
    free(map[i]);
  }
  free(player_ent);

  return 0;
}