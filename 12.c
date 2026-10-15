#include <stdio.h>
#include <stdlib.h>
int shuzi(char a);

int main (){
char a[100] = {0};

int judge = 0;
int state = 0;
int count = 0;
int state1 = 0;
if(fgets(a,sizeof(a),stdin) == NULL){
    return 1;
}
for(int cnt = 0;a[cnt] != '\n' ; cnt++){
judge = shuzi(a[cnt]);

if(state == 0 && judge == 1 && state1 == 0){
printf("%c",a[cnt]);
state = 1;
count++;
state1 = 1;
}
else if(state ==  0 && judge == 1 && state1 == 1 ){
count++;
printf(",");
state = 1;
printf("%c",a[cnt]);
}
else if(state == 1 && judge == 1 && state1 == 1){
printf("%c",a[cnt]);}
else if(state == 1 && judge == 0 && state1 == 1 ){
state = 0;
}



}
printf("\n");
if(count == 0){
    printf("none");
}else {
printf("%d\n",count);
}
}

int shuzi(char a){
int cnt = 0;
if((a > 'a' && a < 'z') || (a > 'A' && a < 'Z')){
cnt =1;
}
return cnt;
}


