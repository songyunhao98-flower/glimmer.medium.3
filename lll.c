#include <stdio.h>

void change(int num,int (*pb)[num],int (*pa)[num]);
int score(int a[],int num);

int main(){
    int num = 0;
    int max = 0;
    int res;
    scanf("%d",&num);
    int a[10] = {0};
    int b[10] = {0};

    for(int i = 0;i < num;i++){
        scanf("%d",&a[i]);
    }

    for(int turn = 1;turn <= num;turn++){
        change(num,&b,&a);
        for(int i = 0;i < num;i++){
            a[i] = b[i];
        }
        res = score(a,num);
        if(res > max){
            max = res;
        }
    }
    printf("%d\n",max);
    return 0;
}

int score(int a[],int num){
    int sum = 0;
    for(int i = 1;i <= num;i++){
        sum = sum + a[i - 1] * i;
    }
    return sum;
}

void change(int num,int (*pb)[num],int (*pa)[num])
{
    (*pb)[0] = (*pa)[num - 1];
    for(int i = 1; i <= (num - 1); i++)
    {
        (*pb)[i] = (*pa)[i - 1];
    }
}