//FormAI DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>

int main() {
  int a, b; // we will be taking 2 integer inputs from the user
  char opr; // the operation we want to perform

  printf("Hey! I am a curious calculator chatbot. Please give me two values and an arithmetic operator. I will perform the operation and give you the result. Let's begin!\n");
  printf("Enter the first value: ");
  scanf("%d", &a);
  printf("Enter the second value: ");
  scanf("%d", &b);
  printf("Enter the operation you want me to perform (+, -, *, /): ");
  scanf(" %c", &opr); // we need to put a space before %c to avoid input buffer issues

  switch(opr) {
    case '+':
      printf("The result of %d + %d is %d. I am curious... \n", a, b, a+b);

      if(a > b) {
        printf("%d is greater than %d. I wonder what will happen if I add %d to %d? Let's try...", a, b, a, b);
        printf("The result of %d + %d is %d. Interesting, right? Now let me add %d to %d.", a, b, a+b, b, a);
        printf("The final result is %d. Looks like addition is commutative :)", a+b);
      }
      else if(a < b) {
        printf("%d is greater than %d. I wonder what will happen if I add %d to %d? Let's try...", b, a, a, b);
        printf("The result of %d + %d is %d. Interesting, right? Now let me add %d to %d.", b, a, a+b, a, b);
        printf("The final result is %d. Looks like addition is commutative :)", a+b);
      }
      else {
        printf("Looks like both numbers are equal! Adding them up will give %d. So, looks like addition is not only commutative but also associative ;)", a+b);
      }
      break;
      
    case '-':
      printf("The result of %d - %d is %d. Now I am curious...", a, b, a-b);

      if(a > b) {
        printf("%d is greater than %d. I wonder what will happen if I subtract %d from %d? Let's try...", a, b, b, a);
        printf("The result of %d - %d is %d. Interesting, right? Now let me subtract %d from %d.", a, b, a-b, a, b);
        printf("The final result is %d. Looks like subtraction is not commutative :)", b-a);
      }
      else if(a < b) {
        printf("%d is greater than %d. I wonder what will happen if I subtract %d from %d? Let's try...", b, a, a, b);
        printf("The result of %d - %d is %d. Interesting, right? Now let me subtract %d from %d.", b, a, b-a, a, b);
        printf("The final result is %d. Looks like subtraction is not commutative :)", a-b);
      }
      else {
        printf("Looks like both numbers are equal! Subtracting them will give %d. So, looks like subtraction is not only commutative but also not associative ;)", a-b);
      }
      break;

    case '*':
      printf("The result of %d * %d is %d. I am curious...", a, b, a*b);

      if(a > b) {
        printf("%d is greater than %d. I wonder what will happen if I multiply %d with %d? Let's try...", a, b, b, a);
        printf("The result of %d * %d is %d. Interesting, right? Now let me multiply %d with %d.", a, b, a*b, b, a);
        printf("The final result is %d. Looks like multiplication is commutative :)", a*b);
      }
      else if(a < b) {
        printf("%d is greater than %d. I wonder what will happen if I multiply %d with %d? Let's try...", b, a, a, b);
        printf("The result of %d * %d is %d. Interesting, right? Now let me multiply %d with %d.", b, a, a*b, a, b);
        printf("The final result is %d. Looks like multiplication is commutative :)", a*b);
      }
      else {
        printf("Looks like both numbers are equal! Multiplying them will give %d. So, looks like multiplication is not only commutative but also associative ;)", a*b);
      }
      break;
      
    case '/':
      printf("The result of %d / %d is %d. I am curious...", a, b, a/b);

      if(a > b) {
        printf("%d is greater than %d. I wonder what will happen if I divide %d by %d? Let's try...", a, b, b, a);
        printf("The result of %d / %d is %d with remainder %d. Interesting, right? Now let me divide %d by %d.", a, b, a/b, a%b, b, a);
        printf("The final result is %d with remainder %d. Looks like division is not commutative :)", b/a, b%a);
      }
      else if(a < b) {
        printf("%d is greater than %d. I wonder what will happen if I divide %d by %d? Let's try...", b, a, a, b);
        printf("The result of %d / %d is %d with remainder %d. Interesting, right? Now let me divide %d by %d.", b, a, b/a, b%a, a, b);
        printf("The final result is %d with remainder %d. Looks like division is not commutative :)", a/b, a%b);
      }
      else {
        printf("Looks like both numbers are equal! Dividing them will give %d with remainder %d. So, looks like division is not only not commutative but also not associative ;)", a/b, a%b);
      }
      break;
      
    default:
      printf("Oops! I see an invalid operation. Please check and try again.");
      break;
  }

  return 0;
}