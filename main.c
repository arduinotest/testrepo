#include <stdio.h>
#include <stdlib.h>

int test(){
    int lArray[4];
    int i = 0;
    for(i = 0 ;  ; 1){
        lArray[i] = i/2;
        printf("%d, %d\n",i, lArray[i++]);
    }
    return 0;
}

int main(){
    //printf("Hello world!\n");
    test();
    getchar();
    return 0;
}
