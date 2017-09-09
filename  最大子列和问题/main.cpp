#include <iostream>

using namespace std;

int maxSum=0;
int thisSum=0;
int start=0;
int stop=0;

void MaxSubseqSum(int *a,int N)//最大子列函数，在线处理
{
    int i=0;
    int pos=0;
    start=i;
    for(i;i<N;i++)
    {
        thisSum+=a[i];
        if(thisSum>maxSum)
        {
            maxSum=thisSum;
            start=pos;
            stop=i;
        }
        else if(thisSum<0)
        {
            thisSum=0;
            pos=i+1;
        }
    }
    cout<<maxSum<<" "<<a[start]<<" "<<a[stop];

    return;
}

int main()
{

    int N;
    cin>>N;

    int *a;
    a=new int [N];//创建动态数组存储数列

    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }

    bool alln=true;
    bool has0=false;
    bool notp=true;
    for(int i=0;i<N;i++)
    {
        if(a[i]>=0)//判断是否全负
            alln=false;
        if(a[i]==0)//判断是否有0
            has0=true;
        if(a[i]>0)//判断是否大于0
            notp=false;
    }

    if(alln)//如果全负则直接输出
    {
        cout<<0<<" "<<a[0]<<" "<<a[N-1];
        return 0;
    }

    if(has0&&notp)//如果全0直接输出
    {
        cout<<0<<" "<<0<<" "<<0;
        return 0;
    }


    MaxSubseqSum(a,N);//求最大子列

    delete []a;//释放动态数组

    return 0;
}
