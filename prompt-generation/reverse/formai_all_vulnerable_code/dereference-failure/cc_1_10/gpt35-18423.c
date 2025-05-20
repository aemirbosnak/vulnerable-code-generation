//FormAI DATASET v1.0 Category: Encryption ; Style: futuristic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char* encrypt(char* message, char* key);
void print_encrypted_message(char* encrypted_message, int size);
void decrypt(char* encrypted_message, char* key);

int main(){
  char* message = "Protect the world at all costs!";
  char* key = "FutureEncryption";
  char* encrypted_message = encrypt(message, key);
  print_encrypted_message(encrypted_message, strlen(encrypted_message));
  decrypt(encrypted_message, key);
  return 0;
}

char* encrypt(char* message, char* key){
  int message_length = strlen(message);
  int key_length = strlen(key);
  
  char* encrypted_message = malloc(message_length+1);
  srand(time(NULL));
  int i;
  for(i=0; i<message_length; i++){
    int shift = rand() % 10 + 1;
    char old_char = message[i];
    char new_char = old_char + shift + key[i%key_length];
    encrypted_message[i] = new_char;
  }
  encrypted_message[message_length] = '\0';
  return encrypted_message;
}

void print_encrypted_message(char* encrypted_message, int size){
  int i;
  printf("Encrypted message: ");
  for(i=0; i<size; i++){
    printf("%d ", encrypted_message[i]);
  }
  printf("\n");
}

void decrypt(char* encrypted_message, char* key){
  int message_length = strlen(encrypted_message);
  int key_length = strlen(key);
  
  char* decrypted_message = malloc(message_length+1);
  int i;
  for(i=0; i<message_length; i++){
    char old_char = encrypted_message[i];
    int shift = key[i%key_length] - 'A' + 1;
    char new_char = old_char - shift - key[i%key_length];
    decrypted_message[i] = new_char;
  }
  decrypted_message[message_length] = '\0';
  printf("Decrypted message: %s\n", decrypted_message);
}