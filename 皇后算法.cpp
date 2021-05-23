#include<stdio.h>
#include<cmath>
#define n 8 //棋盘大小 
int queen[n+1];//皇后的摆放位置数组 

int num=0; 
void show(){ /*输出所有皇后的摆放方案*/
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
	//检查当前列是否可以放置皇后，不能放返回0，能放返回1 
	int i;
	for(i=1;i<j;i++){
		if( queen[i]==queen[j]|| abs(queen[i]-queen[j])==(j-i) ){
		//是否与已摆好的皇后在同一列或者同一斜线上 
			return 0;
		}
	}
	return 1;
}

void Nqueen(int j){
	int i;
	for(i=1;i<=n;i++){
		queen[j]=i;
		//这一步开始，直接让 queen[j]==i，若是下面if判断正确，这下一个Nqueen，否则继续让queen[j]等于下一个i直到满足为止 
		if(Place(j)&&j<=n){
			if(j==n){//是否已经摆放完毕，若是已经摆放完毕就输出表格，若是没有继续摆放棋子 
				num=num+1;
				if(num<=3){
					show();
					//如果所有皇后都摆放好，就输出当前摆放方案 
					//只输出前三个就够了，不然太多了 
				} 
			 
			}else{
				Nqueen(j+1);//否则就继续摆放下一个皇后 
			}
		}
	}
} 

int main(){
	Nqueen(1);
	printf("一共有%d种解决方法",num);
	return 0;
} 






















