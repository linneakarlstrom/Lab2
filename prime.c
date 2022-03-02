/*
 prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <math.h>

int is_prime(int n){
  if(n==2 || n==3 || n== 5 || n==7)
    return 1;

  else{
    if(n%2==0 || n%3==0 || n%5==0 || n%7==0) // alla ental som är primtal
      return 0; 
    else
      return 1;
  }
}   
int main(void){
  printf("%d\n", is_prime(11));  // 11 is a prime.      Should print 1.
  printf("%d\n", is_prime(383)); // 383 is a prime.     Should print 1.
  printf("%d\n", is_prime(987)); // 987 is not a prime. Should print 0.
}
