//动态规划法学习最大公共子序列，比较一下有啥不一样好吗
//子序列：不一定是连续的，但次序是一定的
//子串：既连续又持续一定
//https://blog.csdn.net/hrn1216/article/details/51534607 
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
string X="asdfghjkl",Y="qwefghnmasd";
int c[50][50];
int main(){
     
    int len1 = X.length();
	int len2 = Y.length();
	
	//把边边设置为0 
    for(int i = 1; i <= len1; i++){
    	c[i][0] = 0;//i=0或j=0，则有一个数组为空，那么最大公共子序列必为0 
    	c[0][i] = 0;
    }
    
    for(int i = 1; i <= len1; i++){
	    for(int j = 1; j <= len2; j++){
		    if(X[i-1] == Y[j-1]) {
				c[i][j] = c[i-1][j-1]+1;//若是xy的第一个值相等，就给其位置的值加上1 
				//如果末尾两个值相等，则i与j都减一，往对角线的左上角找/如果末尾两个值不相等，则i-1或j-1，即在回前一行或前一列一个位置找并+1。。就是靠这个+1把数字填上的 
			}
		    else{
		    	c[i][j] = max(c[i][j-1],c[i-1][j]);//如果末尾两个值不相等，则i-1或j-1，即在回前一行或前一列一个位置。 
			}		
	    }
    }
    
    //把相关数据遍历出来 
    for(int i = 0; i <= len2; i++){//第一个位置空白，Y从第二个位置开始输出。下面的X同理 
	  	if(i!=0){
	  		cout<<" "<<Y[i-1];//输出数组Y的值，在第一行。 （1个空格）
		}  
      	else{
      		cout<<"    ";//(4个空格，加上面的1个空格，共5个空格 ) 
		}        	
	}
    cout<<"\n";
    
    
    //把数组遍历出来 
    for(int i = 0 ; i <= len1; i++){
	  	if(i != 0){//故实际的X与Y是从第二个位置开始输出，X从第二列开始全部输出数组X的值。
        	cout<<" "<<X[i-1]; 
    	}
      	else{//else即i=0，即第一列（数组从0开始计数）,第一个位置输出空白，因为第一个位置默认为 空序列。
        	cout<<"  ";//2个空格 
        }
        
	    for(int j = 0; j <= len2; j++){
	        cout<<" "<<c[i][j];//前面1个空格，加else那里的2个空格，则此时空出3个空格，与上面对齐 
	    }
	    cout<<"\n";
    }
        
	cout<<"\n";  
    cout<<"MaxLength = "<<c[len1][len2];//最长公共子序列在两个数组尽头的交汇处，所以是Len1和Len2 
    return 0;
} 

