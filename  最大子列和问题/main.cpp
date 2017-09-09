#include <iostream>

using namespace std;

int maxSum=0;
int thisSum=0;
int start=0;
int stop=0;

void MaxSubseqSum(int *a,int N)//������к��������ߴ���
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
    a=new int [N];//������̬����洢����

    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }

    bool alln=true;
    bool has0=false;
    bool notp=true;
    for(int i=0;i<N;i++)
    {
        if(a[i]>=0)//�ж��Ƿ�ȫ��
            alln=false;
        if(a[i]==0)//�ж��Ƿ���0
            has0=true;
        if(a[i]>0)//�ж��Ƿ����0
            notp=false;
    }

    if(alln)//���ȫ����ֱ�����
    {
        cout<<0<<" "<<a[0]<<" "<<a[N-1];
        return 0;
    }

    if(has0&&notp)//���ȫ0ֱ�����
    {
        cout<<0<<" "<<0<<" "<<0;
        return 0;
    }


    MaxSubseqSum(a,N);//���������

    delete []a;//�ͷŶ�̬����

    return 0;
}
