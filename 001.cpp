#include<cstdio>
#include<vector>

using namespace std;

int main (){
    vector<int> vi ;
    for(int i = 0 ; i < 6 ; i++){

        vi.push_back(i);
    }
    vector<int>::iterator it = vi.begin(); //it 是指针 存储的是元素的地址。
    for(int i = 0 ; i < 6 ; i ++){

        printf("%d " , *(it +i));
    }
printf("\n " );
    for(vector<int> ::iterator it = vi.begin() ; it !=vi.end() ; it++){

        printf("%d " , *(it));
    }
    return 0;
}
