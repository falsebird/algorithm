#include<iostream>
//#include<cstdio>
using namespace std;

int main(){
    int N , tcase = 1;
    cin>> N;
    long long a ,b , c;
    while(N--){
        cin >>a>>b>>c;
        if(a+b>c){
            cout<<"Case #"<< tcase ++<<": true";
        }else{
            cout<<"Case #"<< tcase ++<<": false";
        }
    }
}
