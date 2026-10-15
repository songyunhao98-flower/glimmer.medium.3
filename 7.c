#include <stdio.h>
#include <math.h>
typedef struct{
double x;
double y;
} point;
double juli(point a,point b);
int main(){
point a1;
point a2;
printf("第一个数");
scanf("%lf %lf",&a1.x,&a1.y);
printf("第二个数");
scanf("%lf %lf",&a2.x,&a2.y);
printf("%.2f\n",juli(a1,a2));

return 0;
}
double juli(point a,point b){

double dx = a.x - b.x;
double dy = a.y - b.y;
double result = sqrt(dx * dx + dy * dy);
return result;
}