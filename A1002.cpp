#include<cstdio>
#include

int main(){
    int a[1003];//use a store zhushu of a weizhishang de ;
    int x,c;//xiangshu he zhishu
    while(scanf("%d%d",&x,&c)!= EOF){
        a[c] = x;
    }
    a[0] = 0 ;
    int count;
    for(int i = 1 ;i < 1000 ; i++){
        a[i-1] = a[i]*i;
        a[i] =0;
        if(a[i-1] !=0)count++;
    }
    if(count == 0) printf("0 0");
    else{
        for (int i = 1000; i >=0 ; i-- ){//从小到大输出
            if(a[i] != 0){
                printf("%d %d" , a[i] , i);
                count --;
                if(count !=0)printf(" ");
            }
        }

    }
    return 0;

}
