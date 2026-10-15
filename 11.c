#include <stdio.h>
static int _seed =42;
int my_rand(void)
{
    _seed = _seed * 1103515245 + 12345;
    return (_seed >> 16) & 0x7fff;
}
int main(){
int used[10] = {0};
int a[6];
int d;
int cnt;
for(int i = 0;i < 6;i++){
    do{
d = my_rand() % 10;
    }while(used[d]);
used[d] = 1;
a[i] = d;

}
for(int cnt = 0; cnt < 6;cnt++){

    printf("%d ",a[cnt]);
}





return 0;
}