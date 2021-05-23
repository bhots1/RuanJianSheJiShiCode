//��̬�滮�� 0-1��������

#include <iostream>
using namespace std;
 
//��Ʒ���ݽṹ
typedef struct commodity
{
    int value;  //��ֵ
    int weight; //����
}commodity;
 
const int N = 3;  //��Ʒ����
const int W = 10; //����������
 
//��ʼ��Ʒ��Ϣ
commodity goods[N+1]={{0,0},{60,2},{100,4},{120,6}};
int select[N+1][W+1];//����Ʒ��Nʱ����ֵ������ɶ 
 
int max_value();
 
int main()
{
	//ֱ�Ӽ������������ 
    int maxvalue = max_value();
    cout<<"The max value is: ";
    cout<<maxvalue<<endl;
    
    
    int remainspace = W;//��������W=50 
    cout<<"���������� is "<<remainspace<<endl; 
    //�����ѡ�����Ʒ�б�
    cout<<"----------------------------"<<endl;
    for(int i=0; i<=N; i++)//�����������select���������� 
    {
        for(int j=0; j<=W; j++){
        	if(select[i][j]<10){
        		cout<<"00"<<select[i][j]<<" "; 
			}
			else if(select[i][j]>=10&&select[i][j]<100){
				cout<<"0"<<select[i][j]<<" ";  
			}
			else{
				cout<<select[i][j]<<" "; 
			}
        	
		}   
		 cout<<endl;         
    }
    cout<<"----------------------------"<<endl;
    
    for(int i=N; i>=1; i--)//��Ʒ�ĺ��濪ʼ���� 
    {
        if (remainspace >= goods[i].weight)//����Ʒ����������Ʒ������ʱ�� 
        {
            if ((select[i] [remainspace] - select[i-1][remainspace-goods[i].weight] == goods[i].value)){
            	 	
                cout << "���� " << i << " ��ѡ����!" << endl;
                remainspace = remainspace - goods[i].weight;//�����i����Ʒ��ѡ����ô����ʣ����������ȥ��i����Ʒ������ ;
            }
        }
    }
    return 0;
}
int max_value()
{
    //��ʼû����Ʒʱ�򣬱����ļ�ֵΪ0
    //����˵���߱ߵĵط���ֵΪ0 
    for(int j=1;j<=W;++j){
    	select[0][j] = 0;
	}
        
    for(int i=1;i<=N;++i)
    {
        select[i][0] = 0;  //��������Ϊ0ʱ������ֵΪ0�����߱߱�����Ϊ0 
        
       for(int j=1;j<=W;++j)
       {
           if(goods[i].weight <= j)  //��ǰ��Ʒi�Ŀ���װ����СΪj�ı���ʱִ�� 
           {
           		//��仰����˼�ǣ�����λ�ÿ��Է���i��Ʒ��ʱ���ǻ�û�������Ʒʱ�ļ�ֵ����һ��λ�ã� 
				//���Ƿ������Ʒ�ļ�ֵ�� 
				//����ж������ goods[i].value + select[i-1][j-goods[i].weight]����˼��
				//����Ʒ�ļ�ֵ+��һ��λ��ȥ���ܷ������Ʒ�ռ��ʱ�������ֵ �����ǿռ����ô��ȥ���ܷ���i��λ�õ�ʱ�������ֵ�� 
               if( (goods[i].value + select[i-1][ j-goods[i].weight ]) > select[i-1][j]){
               		//���ǱȲ�����󣬾͸���Ϊ�����ļ�ֵ 
               		select[i][j] = goods[i].value + select[i-1][j-goods[i].weight];
			   }                   
               else{
               		//�����˱�û��С���ͱ���δ����ļ�ֵ 
               		select[i][j] = select[i-1][j];
			   }                  
           }
           else{ //��ǰ��Ʒi������װ����СΪj�ı���ʱ���λ�õ�����һ��λ�õ�ֵ 
           
             	select[i][j] = select[i-1][j];
			}
       }
    }
    return select[N][W];  //����������ֵ
}


