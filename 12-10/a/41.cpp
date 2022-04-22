#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=(1<<17)+17;//防越界
double dp[maxn][100];
double p[100];
int cnt[maxn];
int main(){
  double ans=0;
  int n,k,x;
  cin>>n>>k;//输入
  for(int i=1;i<=n;i++) cin>>p[i];
  for(int i=1;i<=(1<<n);i++){//预处理
    x=i;
    while(x) x&=x-1,cnt[i]++;
  }
  dp[0][0]=1;
  for(int i=0;i<=(1<<n);i++){//计算
    for(int j=0;j<=100;j++){
      if(cnt[i]+(j-cnt[i])/k==n){
        ans+=j*dp[i][j];
        continue;
      }
      for(int k=1;k<=n;k++){
        if(i&(1<<(k-1))) dp[i][j+1]+=dp[i][j]*p[k];
        else dp[i+(1<<(k-1))][j+1]+=dp[i][j]*p[k];
      }
    }
  }
  printf("%.5lf",ans);//注意输出时要保留5位（好像6位更保险，5位过不了官方数据）
  return 0;
}
