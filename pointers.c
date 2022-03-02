


#include <stdio.h>

char* text1 = "This is a string."; //text1: .asciiz
char* text2 = "Yet another thing.";//text2 .asciiz

// 4 bytes per list element <--> .space 80 = int list[20];
int   list1[20];
int   list2[20];

// count: .word 0 <--> int count = 0;
int count = 0;

void copycodes(char* text, int* list, int* count){
  while( *text!=0){
    *list = *text; // lb	$t0,0($a0)  & sw	$t0,0($a1) 
    // eftersom det i assembly bara är 0($x) fungerar detta. ?

    /* Note that when an integer pointer  is incremented with 1, the pointer 
    address value is increased by four (assuming that the word size is 4 bytes) */
    text+=1; // addi	$a0,$a0,1 // är typ en lista så därför görs detta
    list+=1; // addi	$a1,$a1,4 // är typ en lista så därför görs detta

    ++*count;
  }
}

void work(){
  copycodes(text1, list1, &count); // & används för att göra om från ett värde till en pointer.
  copycodes(text2, list2, &count);
}

void printlist(const int* lst){
  printf("ASCII codes and corresponding characters.\n");
  while(*lst != 0){
    printf("0x%03X '%c' ", *lst, (char)*lst);
    lst++;
  }
  printf("\n");
}

void endian_proof(const char* c){
  printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n", 
         (int)*c,(int)*(c+1), (int)*(c+2), (int)*(c+3));
  
}

int main(void){
  work();

  printf("\nlist1: ");
  printlist(list1);
  printf("\nlist2: ");
  printlist(list2);
  printf("\nCount = %d\n", count);

  endian_proof((char*) &count);
}
