#include <stdio.h>


int main() {
    int x = 20;   //variável comum (inteira)
    int *p = &x;  //ponteiro -> recebe o endereço de X

    printf("\n\nX = %d \n", x); //imprime o valor de x
    printf("&x = %p \n", (void*)&x); // endereço do x
    printf("p = %p \n", (void*)p); // endereço do p (que é igual ao X)
    printf("*p = %d \n", *p);  // valor o qual ele aponta (igual ao X)


}