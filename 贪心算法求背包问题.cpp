//贪心算法求背包问题，可以切割那种
#include <iostream>
#include <algorithm>
using namespace std;
struct bag
{
    int weight;//总重量
    int value;//总价值
    float bi;//单位重量的价值
    float rate;//使用率：1代表完整放入，小于1代表被分割后放入
} bags[50];

//初始物品信息
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
    
    M=150;//背包容量
	n=7; //物品数量 
    
    //插入数据 
    for(int i=0; i<n; i++)
    {
        bags[i].weight=w[i]; bags[i].value=v[i];//录入物品重量和价值。
        bags[i].bi=(float)bags[i].value/bags[i].weight;//计算单位重量价值。
        bags[i].rate=0;//初始化每件物品使用率。
    }
    
    sort(bags,bags+n,compare);//将物品按照单位重量价值由大到小排序
    
    for(j=0; j<n; j++)
    {
        if(bags[j].weight<=M)
        {
            bags[j].rate=1;
            sum+=bags[j].weight;
            M-=bags[j].weight;//减去已经加上去的数据，然后就可以参加下一趟了 
            
            cout<<"-----------------------------------"<<endl;
            cout<<"总重："<<bags[j].weight<<"价值："<<bags[j].value<<"的物品被放入了背包"<<endl;
			cout<<"放入比例:"<<bags[j].rate<<"放入的单重量的价值:"<<bags[j].bi<<endl; 
			cout<<"...................................."<<endl;
        }
        else {//若是已经完全大于了，就不能整个加上去了 
        	break;
		}
    }
    
    //若是还没全部放进去，就放一点点进去就好了 
    if(j<n)
    {
        bags[j].rate=M/bags[j].weight;
        sum+=bags[j].rate*bags[j].weight;
        cout<<"重："<<bags[j].weight<<"价值："<<bags[j].value<<"被放入了背包"<<endl<<"放入比例:"<<bags[j].rate<<endl;
    }

    return 0;
} 
