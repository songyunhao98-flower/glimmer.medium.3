#include <stdio.h>
static unsigned int _seed = 42;

int my_rand(void)
{
    _seed = _seed * 1103515245 + 12345;
    return (_seed >> 16) & 0x7fff;
}
void print();
int main(){
int num;
scanf("%d",&num);
for(int i = num; num >= 1;num--){
for(int cnt = 1; cnt <= num;cnt++){
    print();
}
printf("\n");
}

return 0;
}
void print(){

printf("%d%d",my_rand() % 10,my_rand() % 10);

}