//FormAI DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct music
{
   char song[50];
   char artist[50];
   char album[50];
   int year;
   float duration;
   struct music *next;
}*head=NULL;

void add_song()
{
   struct music *new_song=(struct music*)malloc(sizeof(struct music));
   printf("\nEnter song name: ");
   scanf("%s",new_song->song);
   printf("\nEnter artist name: ");
   scanf("%s",new_song->artist);
   printf("\nEnter album name: ");
   scanf("%s",new_song->album);
   printf("\nEnter year of release: ");
   scanf("%d",&new_song->year);
   printf("\nEnter duration of the song: ");
   scanf("%f",&new_song->duration);
   new_song->next=NULL;

   if(head==NULL)
   {
      head=new_song;
   }
   else
   {
      struct music *temp=head;
      while(temp->next!=NULL)
      {
         temp=temp->next;
      }
      temp->next=new_song;
   }

   printf("\nSong added successfully!");
}

void display_all()
{
   if(head==NULL)
   {
      printf("\nMusic Library is empty.");
   }
   else
   {
      printf("\n----------------------------------------\n");
      printf("\t\t   Music Library\n");
      printf("----------------------------------------\n");
      printf("S.No. %-20s%-20s%-20s%-10s%s\n", "Song", "Artist", "Album", "Year", "Duration");
      struct music *temp=head;
      int count=1;
      while(temp!=NULL)
      {
         printf("%-4d. %-20s%-20s%-20s%-10d%.2f\n", count, temp->song, temp->artist, temp->album, temp->year, temp->duration);
         count++;
         temp=temp->next;
      }
   }
}

void search_song()
{
   if(head==NULL)
   {
      printf("\nMusic Library is empty.");
   }
   else
   {
      char search_name[50];
      printf("\nEnter the name of the song you want to search: ");
      scanf("%s",search_name);
      struct music *temp=head;
      int count=1,flag=0;
      while(temp!=NULL)
      {
         if(strcmp(temp->song, search_name)==0)
         {
            flag=1;
            printf("\n----------------------------------------");
            printf("\nDetails of the Song:");
            printf("\n----------------------------------------");
            printf("\nS.No. %-20s%-20s%-20s%-10s%s\n", "Song", "Artist", "Album", "Year", "Duration");
            printf("%-4d. %-20s%-20s%-20s%-10d%.2f\n", count, temp->song, temp->artist, temp->album, temp->year, temp->duration);
            printf("\n----------------------------------------");
         }
         temp=temp->next;
         count++;
      }
      if(flag==0)
      {
         printf("\n%s not found in the Music Library.",search_name);
      }
   }
}

void delete_song()
{
   if(head==NULL)
   {
      printf("\nMusic Library is empty.");
   }
   else
   {
      char delete_name[50];
      printf("\nEnter the name of the song you want to delete: ");
      scanf("%s",delete_name);
      struct music *temp=head, *prev=NULL;
      int flag=0;
      while(temp!=NULL)
      {
         if(strcmp(temp->song, delete_name)==0)
         {
            flag=1;
            if(temp==head)
            {
               head=temp->next;
            }
            else
            {
               prev->next=temp->next;
            }
            free(temp);
            printf("\n%s deleted successfully!",delete_name);
            break;
         }
         prev=temp;
         temp=temp->next;
      }
      if(flag==0)
      {
         printf("\n%s not found in the Music Library.",delete_name);
      }
   }
}

int main()
{
   int choice;
   do
   {
      printf("\n========================================\n");
      printf("\t Music Library Management System \n");
      printf("========================================\n");
      printf("Menu:\n1. Add a song to the Library\n2. Display all songs in the Library\n3. Search a song\n4. Delete a song from the Library\n5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1: add_song();
                 break;
         case 2: display_all();
                 break;
         case 3: search_song();
                 break;
         case 4: delete_song();
                 break;
         case 5: exit(0);
         default: printf("\nInvalid choice entered. Please try again.");
      }
   } while(choice!=5);
   return 0;
}