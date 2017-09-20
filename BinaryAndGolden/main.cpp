#include <iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>

using namespace std;

int BinarySerching(vector<int>a,int length,int k);//二分法
int GoldenSerching(vector<int>a,int length,int k);//黄金分割

int main()
{
    int N;
    cin>>N;
    vector<int>a(N);
    srand((unsigned)time(0));
    for(int i=0;i<N;i++)
        a[i]=rand()%100;

    sort(a.begin(),a.end());
    for(int i=0;i<N;i++)
       cout<<a[i]<<" ";

    cout<<endl;
    clock_t start=clock(),endt;
    for(int i=1000000;i>0;i--)
        BinarySerching(a,N,33);
    endt=clock();
    cout<<(double)(endt-start)/(CLK_TCK*1000000)<<endl;

    start=clock();
    for(int i=1000000;i>0;i--)
        GoldenSerching(a,N,101);
    endt=clock();
    cout<<(double)(endt-start)/(CLK_TCK*1000000)<<endl;

    return 0;
}

int BinarySerching(vector<int>a,int length,int k)
{
    int left=0,mid,right=length;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(a[mid]>k) left=mid+1;
        else if(a[mid]<k) right=mid-1;
        else if(a[mid]==k) return mid;
    }

    return -1;
}

int GoldenSerching(vector<int>a,int length,int k)
{
    int left=0,mid,right=length;
    while(left<=right)
    {
        mid=left+0.618*(right-left);
        if(a[mid]>k) left=mid+1;
        else if(a[mid]<k) right=mid-1;
        else if(a[mid]==k) return mid;
    }

    return -1;
}
