#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COLUMNS 6

void print_number(int n){
  printf("%10d", n);
}

void print_sieves(int n){
    int primes[n];
    int j=0;
   
    //creating a list of all numbers from 2 to n
    for(int i = 2; i <= n; i++)
    {
        primes[j] = i;
        j++;
    }

    // markera (ta bort?) alla nummer som är delbara med 2, 3, 5, och 7 (förutom de talen själva)
    // kvar är primtalen, skriv ut dem (samma output som i print-primes)

    for(int p = 2; p <= n; p++){
      if(p==2 || p==3 || p==5 || p==7)
      {
        primes[j] = p;
      }

      else if(p % 2 == 0 || p % 3 == 0 || p % 5 == 0 || p & 7 == 0){
        // gör ingenting (= ta bort dessa från listan)
      }

      else{
        primes[j] = p;
      }
      j++;
    }

    for(int prime = 0; prime < n; prime++){
      int o = primes[prime];
      print_number(o);
    }
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){ 
  if(argc == 2) 
    print_sieves(atoi(argv[1])); 
  else
    printf("Please state an interger number.\n"); 
  return 0;
}