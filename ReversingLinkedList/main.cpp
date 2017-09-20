/*
******Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L.
For example, given L being 1��2��3��4��5��6, if K=3, then you must output 3��2��1��6��5��4; if K=4, you must output 4��3��2��1��5��6.
*/

#include <iostream>
#include<vector>
#include<algorithm>

#define Max 100000

using namespace std;

struct node
{
    int data;
    int next;
};

int main()
{
    int HeadAddress,N,K;//�׵�ַ�����������ת����
    cin>>HeadAddress>>N>>K;

    vector<node>num(Max);//������������
    for(int i=0;i<N;i++)
    {
        int head,data,next;
        cin>>head>>data>>next;
        num[head].data=data;
        num[head].next=next;
    }

    int realNum=0;//ʵ�ʽ����
    int temp=HeadAddress;
    int adress[Max];//��adress����������洢������Ӧ��λ��
    while(temp!=-1)
    {
        adress[realNum++]=temp;
        temp=num[temp].next;
    }
    adress[realNum]=-1;

    int i=0;
    while(i+K<=realNum)
    {
        reverse(&adress[i],&adress[i+K]);
        i+=K;
    }

    int flag=0;
    for(int i=0;i<realNum;i++)
    {
        if(!flag)
            flag=1;
        else
            cout<<endl;
        cout.width(5);
        cout.fill('0');
        cout<<adress[i]<<" "<<num[(adress[i])].data<<" ";
        if(num[(adress[i])].next==-1)
            cout<<adress[i+1];
        else
        {
            cout.width(5);
            cout.fill('0');
            cout<<adress[i+1];
        }

    }

    return 0;
}
