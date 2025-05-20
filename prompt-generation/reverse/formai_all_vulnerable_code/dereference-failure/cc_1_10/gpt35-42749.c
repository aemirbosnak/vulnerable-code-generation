//FormAI DATASET v1.0 Category: Educational ; Style: Claude Shannon
#include <stdio.h>
#define MAX 100

char* encrypt(char* message, int key) {
   int i = 0;
   char* encrypted_message = (char *) malloc(MAX * sizeof(char));  // allocate memory for encrypted message
   while (message[i] != '\0') {
      if (message[i] >= 'a' && message[i] <= 'z') {
         encrypted_message[i] = (((message[i] - 'a') + key) % 26) + 'a';   // apply Ceaser cipher
      } else if (message[i] >= 'A' && message[i] <= 'Z') {
         encrypted_message[i] = (((message[i] - 'A') + key) % 26) + 'A';   // apply Ceaser cipher
      } else {
         encrypted_message[i] = message[i];   // keep non-alphabetical characters unchanged
      }
      i++;
   }
   encrypted_message[i] = '\0';   // terminate the string with null character
   return encrypted_message;
}

char* decrypt(char* message, int key) {
   int i = 0;
   char* decrypted_message = (char *) malloc(MAX * sizeof(char));  // allocate memory for decrypted message
   while (message[i] != '\0') {
      if (message[i] >= 'a' && message[i] <= 'z') {
         decrypted_message[i] = (((message[i] - 'a') - key + 26) % 26) + 'a';   // apply reverse Ceaser cipher to decrypt
      } else if (message[i] >= 'A' && message[i] <= 'Z') {
         decrypted_message[i] = (((message[i] - 'A') - key + 26) % 26) + 'A';   // apply reverse Ceaser cipher to decrypt
      } else {
         decrypted_message[i] = message[i];   // keep non-alphabetical characters unchanged
      }
      i++;
   }
   decrypted_message[i] = '\0';   // terminate the string with null character
   return decrypted_message;
}

int main() {
   char message[MAX], *encrypted_message, *decrypted_message;
   int key;
   printf("Enter a message to encrypt: ");
   fgets(message, MAX, stdin);
   printf("Enter the key: ");
   scanf("%d", &key);
   encrypted_message = encrypt(message, key);
   printf("Encrypted message: %s\n", encrypted_message);
   decrypted_message = decrypt(encrypted_message, key);
   printf("Decrypted message: %s\n", decrypted_message);
   free(encrypted_message);   // deallocate memory of encrypted message
   free(decrypted_message);   // deallocate memory of decrypted message
   return 0;
}