#include<iostream>
//#include<cstdio>
using namespace std;

int main(){
    long long a ,b  ,da ,db;
    cin >>a >>da >>b >>db;
    long long temp  , pa =0, pb =0;
    while(a != 0 ){
        if(a%10 == aa) pa = pa*10 + da;
        a = a/10;
    }
    while(b != 0 ){
        if(b%10 == bb) pb = pb*10 +db;
        b = b/10;
    }
    cout<<pa+pb<<endl;

}
