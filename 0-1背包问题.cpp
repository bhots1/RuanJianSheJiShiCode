//动态规划法 0-1背包问题

#include <iostream>
using namespace std;
 
//物品数据结构
typedef struct commodity
{
    int value;  //价值
    int weight; //重量
}commodity;
 
const int N = 3;  //物品个数
const int W = 10; //背包的容量
 
//初始物品信息
commodity goods[N+1]={{0,0},{60,2},{100,4},{120,6}};
int select[N+1][W+1];//当物品是N时，价值最大的是啥 
 
int max_value();
 
int main()
{
	//直接计算完后输出结果 
    int maxvalue = max_value();
    cout<<"The max value is: ";
    cout<<maxvalue<<endl;
    
    
    int remainspace = W;//背包容量W=50 
    cout<<"背包的容量 is "<<remainspace<<endl; 
    //输出所选择的物品列表：
    cout<<"----------------------------"<<endl;
    for(int i=0; i<=N; i++)//把这个该死的select表格遍历出来 
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
    
    for(int i=N; i>=1; i--)//物品的后面开始遍历 
    {
        if (remainspace >= goods[i].weight)//当物品容量大于物品质量的时候。 
        {
            if ((select[i] [remainspace] - select[i-1][remainspace-goods[i].weight] == goods[i].value)){
            	 	
                cout << "货物 " << i << " 被选中了!" << endl;
                remainspace = remainspace - goods[i].weight;//如果第i个物品被选择，那么背包剩余容量将减去第i个物品的重量 ;
            }
        }
    }
    return 0;
}
int max_value()
{
    //初始没有物品时候，背包的价值为0
    //或者说给边边的地方赋值为0 
    for(int j=1;j<=W;++j){
    	select[0][j] = 0;
	}
        
    for(int i=1;i<=N;++i)
    {
        select[i][0] = 0;  //背包容量为0时，最大价值为0，或者边边设置为0 
        
       for(int j=1;j<=W;++j)
       {
           if(goods[i].weight <= j)  //当前物品i的可以装进大小为j的背包时执行 
           {
           		//这句话的意思是，当该位置可以放入i物品的时候，是还没放入该物品时的价值大（上一个位置） 
				//还是放入该物品的价值大？ 
				//这个判断里面的 goods[i].value + select[i-1][j-goods[i].weight]的意思是
				//该物品的价值+上一个位置去掉能放入该物品空间的时候的最大价值 （就是空间就那么大，去掉能放入i的位置的时候的最大价值） 
               if( (goods[i].value + select[i-1][ j-goods[i].weight ]) > select[i-1][j]){
               		//若是比不放入大，就更新为放入后的价值 
               		select[i][j] = goods[i].value + select[i-1][j-goods[i].weight];
			   }                   
               else{
               		//若放了比没放小，就保持未放入的价值 
               		select[i][j] = select[i-1][j];
			   }                  
           }
           else{ //当前物品i不可以装进大小为j的背包时这个位置等于上一个位置的值 
           
             	select[i][j] = select[i-1][j];
			}
       }
    }
    return select[N][W];  //最终求得最大值
}


