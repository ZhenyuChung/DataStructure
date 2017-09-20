/*
******��ƺ����ֱ�������һԪ����ʽ�ĳ˻���͡�******
*/

#include <iostream>
#include<stdlib.h>

using namespace std;


struct Node
{
    int coef;
    int expon;
    Node *link;
};
typedef Node *Polynamial;

Polynamial read();
void attach(int c,int e,Polynamial *pRear);
Polynamial Add(Polynamial P1,Polynamial P2);
Polynamial Mult(Polynamial P1,Polynamial P2);
void Print(Polynamial P);

int main()
{
    Polynamial P1,P2,PA,PM;
    P1=read();
    P2=read();
    //Print(P1);
    //Print(P2);

    PM=Mult(P1,P2);//������ʽ���
    Print(PM);
    PA=Add(P1,P2);//������ʽ���
    Print(PA);
    return 0;
}


Polynamial read()//�������ʽ
{
    Polynamial P,rear,t;
    P=(Polynamial)malloc(sizeof(Polynamial));
    P->link=0;
    rear=P;

    int n,c,e;
    cin>>n;
    while(n--)
    {
        cin>>c>>e;
        if(c||e)
            attach(c,e,&rear);
    }
    t=P;//ɾ������ͷ
    P=P->link;
    free(t);

    return P;
}

void attach(int c,int e,Polynamial *pRear)
{
    Polynamial P;
    P=(Polynamial)malloc(sizeof(Polynamial));
    P->coef=c;
    P->expon=e;
    P->link=0;//�½���Ϊ��
    (*pRear)->link=P;//ʹ��һ���ָ���½��
    *pRear=P;//βָ��ָ���½��

    return;
}

Polynamial Add(Polynamial P1,Polynamial P2)
{
    Polynamial t1,t2,P,temp,Rear;
    t1=P1;
    t2=P2;
    P=(Polynamial)malloc(sizeof(Polynamial));
    P->link=0;
    Rear=P;

    while(t1&&t2)
    {
        if(t1->expon==t2->expon)
        {
            if((t1->coef+t2->coef)!=0)
                attach(t1->coef+t2->coef,t1->expon,&Rear);
            t1=t1->link;
            t2=t2->link;
        }
        else if(t1->expon>t2->expon)
        {
            attach(t1->coef,t1->expon,&Rear);
            t1=t1->link;
        }
        else
        {
            attach(t2->coef,t2->expon,&Rear);
            t2=t2->link;
        }
    }

    while(t1)
    {
        attach(t1->coef,t1->expon,&Rear);
        t1=t1->link;
    }
     while(t2)
    {
        attach(t2->coef,t2->expon,&Rear);
        t2=t2->link;
    }

    Rear->link=0;
    temp=P;
    P=P->link;
    free(temp);

    return P;
}

Polynamial Mult(Polynamial P1,Polynamial P2)
{
    Polynamial t1,t2,P,rear;
    P=(Polynamial)malloc(sizeof(Polynamial));
    rear=P;
    P->link=0;
    t1=P1;
    t2=P2;

    Polynamial t;//��ʱ���
    while(t2)//�����ʼ����
    {
        attach(t1->coef*t2->coef,t1->expon+t2->expon,&rear);
        t2=t2->link;
    }
    rear->link=0;
    t=P;
    P=P->link;
    free(t);

    t1=t1->link;
    while(t1)//��t1ʣ���������t2��ˣ�ͨ��add�����������
    {
        Polynamial temp,t,t_rear;
        temp=(Polynamial)malloc(sizeof(Polynamial));
        t_rear=temp;
        temp->link=0;

        t2=P2;
        while(t2)
        {
            attach(t1->coef*t2->coef,t1->expon+t2->expon,&t_rear);
            t2=t2->link;
        }
        t_rear->link=0;
        t=temp;
        temp=temp->link;
        free(t);

        P=Add(P,temp);
        t1=t1->link;
    }

    return P;
}

void Print(Polynamial P)
{
    bool flag=0;

    if(!P)
        cout<<0<<" "<<0;

    while(P)
    {
        if(!flag)
            flag=1;
        else
            cout<<" ";

        cout<<P->coef<<" "<<P->expon;
        P=P->link;
    }
    cout<<endl;

    return;
}
