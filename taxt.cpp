#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;


double getfree(int x ){
    double a ;
    if( x<=4 ){
        a=10.01;
        return a;
    }

    else if(x<=8)
        return (10 + (x-4) *2);
    else if(x -8 <4)
        return (18 + (x - 8) *2.4);
    else
        return 18 + getfree(x -8 );
}

int main(){
    int n;
    double fre =0 ;
    scanf("%d",&n);
    while(n!=0)
    {
        fre= getfree(n );
        //printf("%d\n",n);

        if(ceil(fre) != fre){//如果向下取整小于原数则输出一位小数
            printf("%.1f\n",fre);
        }else{ //否则输出不带小数位的数据
            printf("%d\n",(int)fre);
        }
        //printf("%f\n",floor(fre));

        scanf("%d",&n);

    }
    //while(n!=0){

    //}
    return 0;
}
