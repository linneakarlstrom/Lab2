#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COLUMNS 6

int column = 0;
void print_number(int n){
    printf("%10d", n);
    column++;
    if(COLUMNS==column)
    {
        printf("\n");
        column = 0;
    } 
    
}

void print_sieves(int n){
    char *primes=(char*) malloc(sizeof(char)*n);

    for(int i=0; i < n; i++){
        primes[i] = 1; // set to true
    }

    for(int i=2; i <= (int) sqrt(n); i++){
        if(primes[i] == 1){ // if primes[i] is true
            for(int j=i*i; j <= n; j+=i){
                primes[j]=0; // non-prime
            }
        } 

    }

    for(int i=2;i <= n; i++){
        if(primes[i] == 1)
        {
            print_number(i);
        }  
    }
    free(primes); // deallocate primes

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