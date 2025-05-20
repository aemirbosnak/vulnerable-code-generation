//FormAI DATASET v1.0 Category: Mailing list manager ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Subscriber {
   char email[50];
   struct Subscriber* next;
};

struct List {
   struct Subscriber* head;
   struct Subscriber* tail;
};

struct List* createList() {
   struct List* newList = (struct List*)malloc(sizeof(struct List));
   newList->head = NULL;
   newList->tail = NULL;
   return newList;
}

void addSubscriber(struct List* list, char* email) {
   struct Subscriber* newSub = (struct Subscriber*)malloc(sizeof(struct Subscriber));
   strcpy(newSub->email, email);
   newSub->next = NULL;
   if (list->head == NULL) {
      list->head = newSub;
   }
   else {
      list->tail->next = newSub;
   }
   list->tail = newSub;
}

void deleteSubscriber(struct List* list, char* email) {
   struct Subscriber* currSub = list->head;
   struct Subscriber* prevSub = NULL;
   while (currSub != NULL) {
      if (strcmp(currSub->email, email) == 0) {
         if (prevSub == NULL) {
            list->head = currSub->next;
         }
         else {
            prevSub->next = currSub->next;
         }
         free(currSub);
         return;
      }
      prevSub = currSub;
      currSub = currSub->next;
   }
}

void printList(struct List* list) {
   struct Subscriber* currSub = list->head;
   printf("Subscribers:\n");
   while (currSub != NULL) {
      printf("%s\n", currSub->email);
      currSub = currSub->next;
   }
}

int main() {
   struct List* myList = createList();
   addSubscriber(myList, "johndoe@gmail.com");
   addSubscriber(myList, "janedoe@hotmail.com");
   addSubscriber(myList, "smith@gmail.com");
   printList(myList);
   deleteSubscriber(myList, "janedoe@hotmail.com");
   printList(myList);
   deleteSubscriber(myList, "johndoe@gmail.com");
   printList(myList);
   return 0;
}