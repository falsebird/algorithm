#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

struct mooncake{
    double value;//总价
    double store;//库存
    double price;//单价
}cake[1010];

int cmp(mooncake a , mooncake b ){
    return a.price> b.price ; // 按照单价从大到小排序
}

int main(){
    int n ;
    double D;
    scanf("%d%lf" , &n , &D);
    for(int i = 0 ; i < n ; i ++ ){
        scanf("%lf" , &cake[i].store);
    }
    for(int i = 0 ; i < n ; i ++ ){
        scanf("%lf" , &cake[i].value);
         cake[i].price = cake[i].value / cake[i].store;//求月饼的单价
    }
    sort(cake, cake + n , cmp);//按照月饼的单价进行排序
    for(int i = 0 ; i < n ; i ++){
        printf("%lf\n" , cake[i].price);
    }
    double gross_profit = 0 , sales_volume = 0 ; //总利润  已经销售出去的重量量
    for(int i = 0 ; i < n ; i++){
      //  if(cake[i].store < D - sales_volume && sales_volume < D){//当该月饼的存货量小于可销售额度时 全部取
         //   sales_volume += cake[i].store;
         //   gross_profit +=cake[i].value;
        //}else if(sales_volume < D){//当该月饼的存货量大于可销售额度时 只取部分
       //     sales_volume += (D - sales_volume);
       //     gross_profit += cake[i].price * (D - sales_volume);
        //}else{
       //     break;
       // }

        if(cake[i].store <= sales_volume ){
            D -=cake[i].store;
            gross_profit += cake[i].value;
        }else{
            gross_profit += cake[i].price *D;
            break;
        }


    }

    printf("%lf" , gross_profit);
    return 0;
}
