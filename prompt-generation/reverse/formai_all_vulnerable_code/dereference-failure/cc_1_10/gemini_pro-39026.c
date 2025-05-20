//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/evp.h>

#define MAX_PLAYERS 5
#define KEY_SIZE 2048

struct Player {
  BIGNUM *p;
  BIGNUM *q;
  BIGNUM *n;
  BIGNUM *e;
  BIGNUM *d;
  RSA *rsa;
};

struct Game {
  struct Player players[MAX_PLAYERS];
  int num_players;
};

struct Game *game_init() {
  struct Game *game = malloc(sizeof(struct Game));
  game->num_players = 0;
  return game;
}

void game_add_player(struct Game *game, struct Player *player) {
  game->players[game->num_players++] = *player;
}

void player_init(struct Player *player) {
  player->p = BN_new();
  player->q = BN_new();
  player->n = BN_new();
  player->e = BN_new();
  player->d = BN_new();
  player->rsa = RSA_new();
}

void player_free(struct Player *player) {
  BN_free(player->p);
  BN_free(player->q);
  BN_free(player->n);
  BN_free(player->e);
  BN_free(player->d);
  RSA_free(player->rsa);
}

int player_generate_key(struct Player *player) {
  int ret = 0;
  BN_CTX *ctx = BN_CTX_new();
  BIGNUM *lcm = BN_new();

  BN_generate_prime_ex(player->p, KEY_SIZE / 2, 1, NULL, NULL, ctx);
  BN_generate_prime_ex(player->q, KEY_SIZE / 2, 1, NULL, NULL, ctx);
  BN_mul(player->n, player->p, player->q, ctx);

  BN_sub(lcm, player->p, BN_value_one());
  BN_sub(lcm, player->q, BN_value_one());
  BN_gcd(player->e, lcm, BN_value_one(), ctx);

  BN_mod_inverse(player->d, player->e, lcm, ctx);
  RSA_set0_key(player->rsa, player->n, player->e, player->d);

  BN_CTX_free(ctx);
  BN_free(lcm);
  return ret;
}

void player_encrypt(struct Player *player, unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext) {
  int ret = 0;
  int ciphertext_len = RSA_size(player->rsa);
  ret = RSA_public_encrypt(plaintext_len, plaintext, ciphertext, player->rsa, RSA_PKCS1_PADDING);
  if (ret < 0) {
    fprintf(stderr, "Error encrypting message: %s\n", ERR_error_string(ERR_get_error(), NULL));
    exit(1);
  }
}

void player_decrypt(struct Player *player, unsigned char *ciphertext, int ciphertext_len, unsigned char *plaintext) {
  int ret = 0;
  int plaintext_len = RSA_size(player->rsa);
  ret = RSA_private_decrypt(ciphertext_len, ciphertext, plaintext, player->rsa, RSA_PKCS1_PADDING);
  if (ret < 0) {
    fprintf(stderr, "Error decrypting message: %s\n", ERR_error_string(ERR_get_error(), NULL));
    exit(1);
  }
}

void game_loop(struct Game *game) {
  int i, j;
  unsigned char plaintext[1024];
  unsigned char ciphertext[1024];
  int plaintext_len, ciphertext_len;

  while (1) {
    for (i = 0; i < game->num_players; i++) {
      printf("Player %d: ", i + 1);
      fgets(plaintext, 1024, stdin);
      plaintext_len = strlen(plaintext);
      player_encrypt(&game->players[i], plaintext, plaintext_len, ciphertext);
      ciphertext_len = RSA_size(game->players[i].rsa);

      for (j = 0; j < game->num_players; j++) {
        if (i == j) {
          continue;
        }
        player_decrypt(&game->players[j], ciphertext, ciphertext_len, plaintext);
        printf("Player %d received: %s", j + 1, plaintext);
      }
    }
  }
}

int main() {
  struct Game *game = game_init();
  struct Player player;
  int i;

  player_init(&player);
  player_generate_key(&player);
  game_add_player(game, &player);

  for (i = 1; i < MAX_PLAYERS; i++) {
    player_init(&player);
    player_generate_key(&player);
    game_add_player(game, &player);
  }

  game_loop(game);

  return 0;
}