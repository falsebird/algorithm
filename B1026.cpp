#include<iostream>
#include<time.h>
using namespace std;

int main (){
    int c1 ,c2;
    cin>>c1 >>c2 ;

    int ans = c2 -c1;
    if(ans %100 >50){
        ans = ans/100+1;
    }else{
        ans = ans/100;
    }
    cout<<ans /3600<<":"<<ans%3600 /60 <<":"<<ans %60<<endl;
    return 0;
}
