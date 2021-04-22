#include <iostream>
#include <vector>
using namespace std;

//钢条问题
int func(vector<int>&price,int len)
{
    if(len==0)
        return 0;
    int q=INT_MIN;
    for(int i=0;i<len;++i)
    {
        q=max(q,price[i]+func(price,len-i-1));//切割分段：len-i-1，主要看len-i，当前从长度剪剩下可以剪
    }
    return q>0?q:0;
}
//打家劫舍
int func2(vector<int>&house)//1 2 3 1 ,  2 7 9 3 1, 2 7 9 3 1 0
{
    if(house.size()==0)return 0;
    else if(house.size()<2)
        return max(house[0],house[1]);
    //dp{0,````````}
    vector<int>dp(house.size());
    dp[0]=house[0];
    dp[1]=max(house[0],house[1]);
    for(int i=2;i<house.size();++i)
    {
        dp[i]=max(dp[i-1],dp[i-2]+house[i]);//方程：max(dp[i-1],dp[i-2]+money
    }
    cout<<endl;
    for(auto i:dp)
        cout<<i<<'\t';
    cout<<endl;
    return dp[house.size()-1];
}
//3步问题 dp方程[i-1]+[i-2]+[i-3]
int func3(int n)
{

}
//LC91 解码方法（斐波那契数列)，非0个字符串,传入"21102"
int numDecodings(string s="21102")//答案:2
{
    int len=s.length();
    s=" "+s;
    //建立dp
    vector<int>dp(len+1);
    //默认情况存在一种方法
    dp[0]=1;

    for(int i=1;i<s.length();++i){
        int a=s[i]-'0';//后一位
        int b=(s[i-1]-'0')*10 + (s[i]-'0');//前一位和后一位组成十位数,算一种解码方法
        if(a>=1&&a<=9)
            dp[i]=dp[i-1];
        if(b>=10&&b<=26)//检查组成的十位数
            dp[i]+=dp[i-2];//若十位数是合法的，表示有两种情况的组合，如1,0 和10。
        //dp[i]+=dp[i-2]位置 i 既能作为独立方法也能与上一位置形成独立方法,因此转移方程为：dp[i]=dp[i-1]+dp[i-2]

    }
    return dp[len];
}
int main()
{
    vector<int>price{1,5,8,9,10,17,17,20,24,30};//要先塞个0
    cout<<func(price,3)<<endl;
    vector<int>house{2,7,9,3,1};
    cout<<endl;
    cout<<func2(house)<<endl;

    cout<<"解码方法LC91答案:  "<<numDecodings();
    return 0;
}
