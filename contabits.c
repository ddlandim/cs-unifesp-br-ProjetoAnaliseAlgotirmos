#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//retorna a quantidade de bits, para um numero de f bits setados em 1.
unsigned long long int formula (unsigned long long int f){
  return f*pow(2,(f-1));
}

unsigned long long int somaBits(unsigned long long int  a){
  if (a == 0) return 0;
  if (a == 1) return 1;
  unsigned long long int aux = a,
  pos = 0,
  sum = 1;
  while (aux > 1){
    aux /= 2;
    pos++;
    sum += pow(2,pos);
  }
  if (a == sum) return (formula(pos+1));
  else aux = a-(pow(2,pos));
  return (aux + 1) + formula(pos) + somaBits(aux);
}

int main(void) {
  unsigned long long int a,b;
  scanf("%llu %llu", &a, &b);
  printf("%llu\n", somaBits(b)-somaBits(a-1));
  return 0;
}
