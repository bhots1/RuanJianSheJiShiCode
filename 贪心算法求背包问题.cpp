//̰���㷨�󱳰����⣬�����и�����
#include <iostream>
#include <algorithm>
using namespace std;
struct bag
{
    int weight;//������
    int value;//�ܼ�ֵ
    float bi;//��λ�����ļ�ֵ
    float rate;//ʹ���ʣ�1�����������룬С��1�����ָ�����
} bags[50];

//��ʼ��Ʒ��Ϣ
int w[7]={35,30,60,50,40,10,25};
int v[7]={10,40,30,50,35,40,30}; 

bool compare(const bag &bag1,const bag &bag2)
{
    return  bag1.bi>bag2.bi;
}
int main()
{
    int sum=0,n;
    float M;
    int j=0;
    
    M=150;//��������
	n=7; //��Ʒ���� 
    
    //�������� 
    for(int i=0; i<n; i++)
    {
        bags[i].weight=w[i]; bags[i].value=v[i];//¼����Ʒ�����ͼ�ֵ��
        bags[i].bi=(float)bags[i].value/bags[i].weight;//���㵥λ������ֵ��
        bags[i].rate=0;//��ʼ��ÿ����Ʒʹ���ʡ�
    }
    
    sort(bags,bags+n,compare);//����Ʒ���յ�λ������ֵ�ɴ�С����
    
    for(j=0; j<n; j++)
    {
        if(bags[j].weight<=M)
        {
            bags[j].rate=1;
            sum+=bags[j].weight;
            M-=bags[j].weight;//��ȥ�Ѿ�����ȥ�����ݣ�Ȼ��Ϳ��Բμ���һ���� 
            
            cout<<"-----------------------------------"<<endl;
            cout<<"���أ�"<<bags[j].weight<<"��ֵ��"<<bags[j].value<<"����Ʒ�������˱���"<<endl;
			cout<<"�������:"<<bags[j].rate<<"����ĵ������ļ�ֵ:"<<bags[j].bi<<endl; 
			cout<<"...................................."<<endl;
        }
        else {//�����Ѿ���ȫ�����ˣ��Ͳ�����������ȥ�� 
        	break;
		}
    }
    
    //���ǻ�ûȫ���Ž�ȥ���ͷ�һ����ȥ�ͺ��� 
    if(j<n)
    {
        bags[j].rate=M/bags[j].weight;
        sum+=bags[j].rate*bags[j].weight;
        cout<<"�أ�"<<bags[j].weight<<"��ֵ��"<<bags[j].value<<"�������˱���"<<endl<<"�������:"<<bags[j].rate<<endl;
    }

    return 0;
} 
