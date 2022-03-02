/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

int is_prime(int n){
  if(n==2 || n==3 || n==5 || n==7)
  {
    return 1;
  }
  else{
    if(n%2==0 || n%3==0 || n%5==0 || n%7==0) // alla ental som är primtal
      return 0; 
    else{
      return 1;
    }
  }
}


void print_number(int n){
  printf("%10d", n);
}

void print_primes(int n){
  // Should print out all prime numbers less than 'n'
  // with the following formatting. Note that
  // the number of columns is stated in the define
  // COLUMNS
  
  int j = 0;
  for(int i = 2;i < n; i++)
  {
    if(COLUMNS==j)
    {
      printf("\n");
      j = 0;
    }

    else
    {
      if(is_prime(i)==1)
      {
        print_number(i);
        j++;
      }
    }
  }
}


// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){ 
  if(argc == 2) 
    print_primes(atoi(argv[1])); 
  else
    printf("Please state an interger number.\n"); 
  return 0;
}