#include <stdio.h>
int sumnine(int a,int b,int c){
    int counter = 0;
for(int cnt = a;cnt <= b;cnt++){
int cnt1 = cnt;
while(cnt1 > 0){
if(cnt1 % 10 == c){

    counter++;
}
cnt1 = cnt1 / 10;
}

}
return counter;
}
int main(){

int a,b,c;
scanf("%d %d %d",&a,&b,&c);

printf("%d\n",sumnine(a,b,c));

return 0;
}