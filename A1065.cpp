#include<cstdio>
//a + b > c?

int main(){
    bool flag = false;
    long long a , b, c;
    int tca = 1;
    int ca ;
    scanf("%d" , &ca);
    while(ca!=0){
        scanf("%lld%lld%lld", &a , &b ,&c);
        long long ans = a+b;
        if(a > 0 && b > 0 &&ans <0)flag = true;//a b
        else if(a <0 && b < 0 && ans>=0) flag = false;
        else if(ans > c) flag = true;
        else flag = false;

        if(flag){
            printf("Case #%d: true\n" , tca++);
        }else{
            printf("Case #%d: false\n" , tca++);
        }
        ca--;
    }
    return 0;
}
