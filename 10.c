#include <stdio.h>
int main(){
int num;
int cnt;
int max;
scanf("%d",&num);
for(int i = 1;i <= num;i++){
if(i == 1){
    continue;
}
else if(i == 2){
    cnt = 1;
}
else {
for(int cnt1 = 2;cnt1 < i;cnt1++){

if(i % cnt1 == 0){
    cnt = 0;
    break;
}
cnt = 1;
}

}
if(cnt == 1){
    max = i;
}

}

printf("%d\n",max);
return 0;


}