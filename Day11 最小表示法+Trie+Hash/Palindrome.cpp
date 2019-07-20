#include<iostream>
#include<cstring>
#include<sstream>
#include<string>
#include<cstdio>
#include<cctype>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#define fi first
#define se second
#define MP make_pair
#define P pair<int,int>
#define PLL pair<ll,ll>
#define pd push_back
#define Sca(x) scanf("%d",&x)
#define Sca2(x,y) scanf("%d%d",&x,&y)
#define Sca3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define Scl(x) scanf("%lld",&x)
#define Scl2(x,y) scanf("%lld%lld",&x,&y)
#define Scl3(x,y,z) scanf("%lld%wlld%lld",&x,&y,&z)
#define Pri(x) printf("%d\n",x)
#define Prl(x) printf("%lld\n",x)
#define For(i,x,y) for(int i=x;i<=y;i++)
#define _For(i,x,y) for(int i=x;i>=y;i--)
#define FAST_IO std::ios::sync_with_stdio(false)
#define ll long long
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
const double Pi = acos(-1.0);
using namespace std;
template <class T>void tomax(T&a,T b){ a=max(a,b); }  
template <class T>void tomin(T&a,T b){ a=min(a,b); }
const int N=1e6+5;
int p[N<<1];
string str;
inline int Manacher(string str){
    string res="@#";
    For(i,0,str.length()-1){
        res+=str[i];
        res+='#';
    }
    int len=res.length()-1;
    int right=0,mid=0,maxlen=0;
    For(i,1,len-1){
        p[i]=i<right?min(p[2*mid-i],right-i):1;
        while(res[i+p[i]]==res[i-p[i]]) p[i]++;
        if(right<i+p[i]){
            right=i+p[i];
            mid=i;
        } 
        tomax(maxlen,p[i]);
    }
    return maxlen-1;
}
int main(){
    int index=0;
    while(cin>>str){
    	if(str=="END") break;
		printf("Case %d: %d\n",++index,Manacher(str));
	}
}