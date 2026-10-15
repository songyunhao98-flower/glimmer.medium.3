#include <stdio.h>
#define row 10
#define line 10
static int _seed = 42;
int my_rand(void)
{
    _seed = _seed * 1103515245 + 12345;
    return (_seed >> 16) & 0x7fff;
}

void gitboard(int* a){
    for(int cnt = 0;cnt < row * line;cnt++){
        *(a + cnt) = my_rand() % 2;
    }
}
void printboard(int a[][line]){
    for(int cnt1 = 0;cnt1 < row;cnt1++){
        for(int cnt2 = 0;cnt2 < line;cnt2++){
            printf("%d ",a[cnt1][cnt2]);
        }
        printf("\n");
    }
    
    
    
}
int main(){


int a[row][line];
gitboard(&a[0][0]);
printboard(a);








return 0;
}