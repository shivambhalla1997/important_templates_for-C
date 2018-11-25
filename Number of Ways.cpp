#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ll,double>
#define fi first
#define se second
#define fu(i,a,n) for(i=a;i<=n;i++)
#define fd(i,a,n) for(i=a;i>=n;i--)
#define rep(i,n)  for(i=0;i<n;i++)
#define si(i)  scanf("%d",&i)
#define ss(s)  scanf("%s",s)
#define sl(i)  scanf("%lld",&i)
#define pi(i)  printf("%d",i)
#define pl(i)  printf("%lld",i);
#define ps()   printf(" ");
#define pn()   printf("\n");
#define all(v)  v.begin(),v.end()
#define vi vector <int>
#define vl vector <ll>
#define N 2000008
ll fac[N],ifac[N];
ll mod=1e9+7;
ll mexp(ll a,ll b)
{
	if(b==0)return 1;
	ll tmp=mexp(a,b/2);
	if(b%2==0)
	{
		return (tmp*tmp)%mod;
	}
	else
	{
		return (((tmp*tmp)%mod)*(a%mod))%mod;
	}
}
void pre()
{
	ll i;
	fac[0]=fac[1]=ifac[0]=ifac[1]=1;
	fu(i,2,N-3)
	{
		fac[i]=(fac[i-1]*i)%mod;
		//ifac[i]=(ifac[i-1]*mexp(i,mod-2))%mod;
	}
}
ll ncr(ll n,ll r)
{
	ifac[n-r]=mexp(fac[n-r],mod-2);
	ifac[r]=mexp(fac[r],mod-2);
	return ((fac[n]*ifac[n-r])%mod*(ifac[r]))%mod;
}
int main()
{
	pre();
	ll t,n,k,ans;
	sl(t);
	while(t--)
	{
		sl(n);sl(k);
		if(n+k+1>=k+2)
		{
			ans=(2*ncr(n+k+1,k+2)-n+mod)%mod;
		}
		else
		{
			ans=0;
		}
		pl(ans);pn();
	}
	return 0;
}
