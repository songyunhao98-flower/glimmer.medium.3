#include <stdio.h>
#include <stdlib.h>
void copy(char* p1,const char* p2){
int i = 0;
for(;*(p2 + i) != '\n';i++){
if(*(p2 + i) >= 'a' && *(p2 + i) <= 'z'){
*(p1 + i) = (*(p2 + i) - 32);
}
else {
*(p1 + i) = *(p2 + i);
}
}
*(p1 + i) = '\0';
}
int main(){
    
char a[100];
char b[100];
if(fgets(a,sizeof(a),stdin) == NULL){
    return 1;
}
copy(b,a);
printf("%s\n",b);
return 0;
}