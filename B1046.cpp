#include<iostream>
//#include<cstdio>
using namespace std;
//划拳

int main(){
    int N;
    int afail = 0, bfail = 0 ;
    cin>>N;
    int as , ah , bs ,bh; // s喊 h划
    while(N --){
        cin>>as>>ah>>bs>>bh;
        if(as +bs == ah  &&bs +as !=bh){
            bfail ++;
        }
        if(as +bs != ah  &&bs +as ==bh){
            afail ++;
        }
    }
    cout<<afail<<" "<<bfail<<endl;
}
