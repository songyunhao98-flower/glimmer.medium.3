#include <stdio.h>
#include <stdlib.h>
int judge(char a){
 int cnt = 0;
if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')){
cnt = 1;
}
return cnt;
}
char zuji[100] = {0};

    /* code */
int main(){
if(fgets(zuji,sizeof(zuji),stdin) == NULL){
    return 0;
}
int state = 0;
int input = 0;
int words = 0;
char word[100] = {0};
int len = 0;
char* p = NULL;
for(int idx = 0;zuji[idx] != '\0';idx++){
input = judge(zuji[idx]);
if(state == 0 && input == 0){
continue;
}
else if(state == 0 && input == 1){
len = 0;
state = 1;
words++;
len++;
word[idx] = zuji[idx];
p = &word[idx];
}
else if(state == 1 && input == 1){
len++;
word[idx] = zuji[idx];

}
else if(state == 1 && input == 0){
state =0;

printf("find %d word\n",words);
printf("this is %s\n",p);
printf("lenth is %d\n",len );
}
}
printf("all %d words ware found\n",words);

}