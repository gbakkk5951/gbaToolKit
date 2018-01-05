/* Replace "dll.h" with the name of your header */
#include <windows.h>
#include<string.h>
#include"gbadll.h"
#include<cstdio>
#define ll long long
using namespace std;
long long hash(int p,int mod);
int base=37;
DLLIMPORT void hash_clear(char *ash){
memset(ash,0,320000);
}
DLLIMPORT void hash_insert(char *a,char *ash){
int p=(int )a;
	
//	printf("%d ",p);
	int  h[4];
	h[0]=hash(p,999983);
	h[1]=hash(p,1000039)+999983;
		
	h[2]=hash(p,313333)+1000039+999983;
	h[3]=hash(p,213337)+1000039+999983+313333;
	ash[h[0]/8]|=1<<(h[0]%8);
	ash[h[1]/8]|=1<<(h[1]%8);
	ash[h[2]/8]|=1<<(h[2]%8);	
	ash[h[3]/8]|=1<<(h[3]%8);	
}
DLLIMPORT bool hash_find(char *a,char *ash){
	int p=(int )a;
	int i=0;
	int  h[4];
	h[0]=hash(p,999983);
	h[1]=hash(p,1000039)+999983;
	h[2]=hash(p,313333)+1000039+999983;
	h[3]=hash(p,213337)+1000039+999983+313333;
	puts("query ");
	printf("h1=%d ",h[0]);
	printf("h2=%d ",h[1]);
	printf("h3=%d ",h[2]);
	printf("h4=%d ",h[3]);
	puts("");
	
	
	if((ash[h[0]/8]&(1<<(h[0]%8)))&&(ash[h[1]/8]&(1<<(h[1]%8)))&&(ash[h[2]/8]&(1<<(h[2]%8)))&&(ash[h[3]/8]&(1<<(h[3]%8)))){
		return true;
	}return false;
	
}
long long hash(int p,int mod){
	
	char *a=(char *)p;
	//	printf("%d",a);
	int i=0;
	long long temp=0;
	while(a[i]!='\0'){
		temp=(long long)37*temp%mod;
		temp=(long long)(temp+a[i]%base)%mod;
		i++;
	}
	return temp;
}


ll mul(ll a,ll b,ll m){
	a=(a*b-(ll)((long double)a/m*b)*m+m)%m;
	return a>0?a%m:a+m;
}

ll pow(ll a,ll t,ll m){
	ll r=1;
	for(;t;t>>=1,a=mul(a,a,m)){
		if(t&1){
			r=mul(r,a,m);
		}
	}
	return r;
}


bool Miller_Rabin(long long in){
	ll p[]={2,3,5,7,11,13,17,19,23};
	long long j,k;
	int i;
	if(in<2){
		return false;		
	}
	for(i=0;i<9;i++){
	
		j=in-1;
		do{
			if(in==p[i]){
				return true;
			}
			k=pow( p[i], j, in);
			if(k==1){
				if(!(j%2)){
					j/=2;
				}
			else break;
			}
	    else if(k==in-1){
	    		break;
			}
		else {
				return false;
			}
		}while(1);
	}
	return true;
}	


DLLIMPORT bool is_prime(long long in){
	return Miller_Rabin(in);
}
BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}
