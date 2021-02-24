#include "lab6.h"

int menu()
{
  int theValue = 0, error = 0;
  do
  {
    if (error)
    {
      printf("-----------------------------------------------------------------------------\n");
      printf("[ERROR]: Please input value between 1 to 5 \n");
      printf("-----------------------------------------------------------------------------\n");
    }
    else
    {
      error = 1;
    }
    printf("\n-----------------------------------------------------------------------------\n");
    printf("MENU \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("The menu choices are \n");
    printf("  1. Enter a new number\n");
    printf("  2. Print the number of odd digits, even digits and zeros in the integer \n");
    printf("  3. Print the prime numbers between 2 and the integer (inclusive) \n");
    printf("  4. Print the number in reverse order \n");
    printf("  5. Quit the program \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("User Choice [1-5]: ");
    scanf("%d", &theValue);
  } while (theValue <= 0 || theValue>5);

  return theValue;
}

int readPosNum()
{
  int theValue = 0, error = 0;
  do
  {
    if (error)
    {
      printf("[try again]:You did not enter a valid number \n");
    }
    else
    {
      error = 1;
    }

    printf("User Input (Positive number) : ");
    scanf("%d", &theValue);
  } while (theValue < 0);

  return theValue;
}

void oddEvenZero(int theNum)
{

  int zero = 0, odd = 0, even = 0, one_number;
  while (theNum != 0)
  {
    one_number = theNum % 10;
    if (one_number == 0)
    {
      zero += 1;
    }
    else if (one_number % 2 == 0)
    {
      even += 1;
    }
    else
    {
      odd += 1;
    }
    theNum /= 10;
  }
  printf("\n[OUTPUT]\n");
  printf("Zero Count : %d | Odd Numbers Count : %d | Even Numbers Count : %d\n", zero, odd, even);
}

void printPrimes(int theNum)
{
  printf("\n[OUTPUT]\n");
  printf("Prime numbers between 2 and the %d (inclusive) : [", theNum);
  for (int number = 2; number <= theNum; number++)
  {
    int isPrime = 1;
    for (int div = 2; div < number; div++)
    {
      if (number % div == 0)
        isPrime = 0;
    }
    if (isPrime)
    {
      printf(" %d ", number);
    }
  }
  printf("]\n");
}

void printReverse(int theNum)
{
  int temp = theNum;
  int reverse = 0, remainder;
  while (theNum != 0)
  {
    remainder = theNum % 10;
    reverse = reverse * 10 + remainder;
    theNum /= 10;
  }
  printf("\n[OUTPUT]\n");
  printf("Number (%d) in reverse order : %d\n", temp,reverse);
}