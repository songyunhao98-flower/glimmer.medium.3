#include <stdio.h>
#include <stdlib.h>
static unsigned int _seed = 42;

int my_rand(void)
{
    _seed = _seed * 1103515245 + 12345;
    return (_seed >> 16) & 0x7fff;
}
int main(){

    int num;
    scanf("%d",&num);
int used[10] = {0};
int a[num];
for(int idx = 0; idx < num;idx++){

int d;
do{
d = my_rand() % 10;
}while(used[d]);
used[d] = 1;
a[idx] = d;
}

for(int idx = 0;idx < num; idx++){
printf("%d ",a[idx]);
}

return 0;
}