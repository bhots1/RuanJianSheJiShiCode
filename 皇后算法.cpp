#include<stdio.h>
#include<cmath>
#define n 8 //���̴�С 
int queen[n+1];//�ʺ�İڷ�λ������ 

int num=0; 
void show(){ /*������лʺ�İڷŷ���*/
	int i;
	
	for(i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==queen[i]){
				printf("%d ",queen[i]);
			}
			else{
				printf("0 ");
			}
		}
		printf("\n");		
	}
	printf("-----------------------------");	
	printf("\n");
} 

int Place(int j){
	//��鵱ǰ���Ƿ���Է��ûʺ󣬲��ܷŷ���0���ܷŷ���1 
	int i;
	for(i=1;i<j;i++){
		if( queen[i]==queen[j]|| abs(queen[i]-queen[j])==(j-i) ){
		//�Ƿ����ѰںõĻʺ���ͬһ�л���ͬһб���� 
			return 0;
		}
	}
	return 1;
}

void Nqueen(int j){
	int i;
	for(i=1;i<=n;i++){
		queen[j]=i;
		//��һ����ʼ��ֱ���� queen[j]==i����������if�ж���ȷ������һ��Nqueen�����������queen[j]������һ��iֱ������Ϊֹ 
		if(Place(j)&&j<=n){
			if(j==n){//�Ƿ��Ѿ��ڷ���ϣ������Ѿ��ڷ���Ͼ�����������û�м����ڷ����� 
				num=num+1;
				if(num<=3){
					show();
					//������лʺ󶼰ڷźã��������ǰ�ڷŷ��� 
					//ֻ���ǰ�����͹��ˣ���Ȼ̫���� 
				} 
			 
			}else{
				Nqueen(j+1);//����ͼ����ڷ���һ���ʺ� 
			}
		}
	}
} 

int main(){
	Nqueen(1);
	printf("һ����%d�ֽ������",num);
	return 0;
} 






















