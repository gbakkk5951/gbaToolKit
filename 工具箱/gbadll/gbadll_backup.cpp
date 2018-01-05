/* Replace "dll.h" with the name of your header */
#include <windows.h>
#include<string.h>
#include"gbadll.h"
#include<cstdio>
#define ll long long
using namespace std;
long long hash(char *a,int mod);
int base=37;
enum{
	shift=3,
	mask=7
};
DLLIMPORT void hash_clear(unsigned char *ash){
memset(ash,0,320000);
}
DLLIMPORT void hash_insert(char *a,unsigned char *ash){
	int  h[4];
	h[0]=hash(a,999983);
	h[1]=hash(a,1000039)+999983;
	h[2]=hash(a,313333)+2000022;
	h[3]=hash(a,213337)+2313355;
	ash[h[0]>>shift]|=1<<(h[0]&mask);
	ash[h[1]>>shift]|=1<<(h[1]&mask);
	ash[h[2]>>shift]|=1<<(h[2]&mask);	
	ash[h[3]>>shift]|=1<<(h[3]&mask);	
}
DLLIMPORT bool hash_find(char *a,unsigned char *ash){
	int i=0;
	int  h[4];
	h[0]=hash(a,999983);
	h[1]=hash(a,1000039)+999983;
	h[2]=hash(a,313333)+2000022;
	h[3]=hash(a,213337)+2313355;
	if((ash[h[0]>>shift]&(1<<(h[0]&mask)))
	&&(ash[h[1]>>shift]&(1<<(h[1]&mask)))
	&&(ash[h[2]>>shift]&(1<<(h[2]&mask)))
	&&(ash[h[3]>>shift]&(1<<(h[3]&mask)))){
		return true;
	}return false;
	
}
long long hash(char *p,int mod){
	int i=0;
	int temp=0;
	while(p[i]!='\0'){
		temp=(37*temp+p[i]%base)%mod;
		i++;
	}
	return temp;
}


inline ll mul(ll a,ll b,ll m){
	a=(a*b-(ll)((long double)a/m*b)*m)%m;
	return a>=0?a:(a+m);
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
