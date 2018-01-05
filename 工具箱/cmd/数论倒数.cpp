using namespace std;
int main() {}
#include<cstdio>




struct _Main {
	typedef long long LL;

	LL exgcd(LL a,LL b,LL &x,LL &y) {
		if(b==0) {
			x=1,y=0;
			return a;
		}
		LL ret=exgcd(b,a%b,y,x);
		y=y-a/b*x;
		return ret;
	}


	_Main() {
		long long x,y,a,b,gcd;
		while(~scanf("%lld%lld",&a,&b)) {
			gcd=exgcd(a,b,x,y);
			if(x<0){
				x+=b;
				y-=a;
			}
			printf("x=%lld,y=%lld,gcd=%lld\n",x,y,gcd);
		}
	}






} exgcd;
