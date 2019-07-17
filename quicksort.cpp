#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 100;
int once(int a[], int left, int right)
{
    int temp = a[left];
    while(left <right)
    {
        while(left<right &&a[right]>temp)right--;
        a[left] = a[right];
        while(left < right && a[left] <= temp)left++;
        a[right] = a[left];
    }
    a[left] = temp;
    return left;
}

void quicksort(int a[], int left,int right)
{
    if(left <right)
    {
        int mid = once(a, left, right);
        quicksort(a, left, mid-1);
        quicksort(a, mid + 1, right);

    }

}


int main()
{
    int a[maxn];
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d",&a[i]);
        }
        //quicksort(a,0,n-1);
        sort(a,a+n);
        for(int i = 0 ; i < n ; i++)
        {
            printf("%d ",a[i]);

        }
        printf("\n");
        if(n==1){
                printf("-1\n");
        }

    }
    return 0;
}
