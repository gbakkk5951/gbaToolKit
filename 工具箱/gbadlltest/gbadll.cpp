/* Replace "dll.h" with the name of your header */
#include <windows.h>
#include<string.h>
#include"gbadll.h"
#include<bitset>
using namespace std;
bitset<999983>h1;
bitset<1000039>h2;
bitset<313333>h3;
bitset<213337>h4;
long long hash(char *a,int mod);
int base=37;
DLLIMPORT void hash_clear(){
	h1.reset();
	h2.reset();
	h3.reset();
	h4.reset();
}
DLLIMPORT void hash_insert(char *a){
	int  h[4];
	
	h[0]=hash(a,999983);
	h[1]=hash(a,1000039);	
	h[2]=hash(a,313333);
	h[3]=hash(a,213337);
	h1[h[0]]=1;
	h2[h[1]]=1;	
	h3[h[2]]=1;	
	h4[h[3]]=1;	
}
DLLIMPORT bool hash_find(char *a){
	int i=0;
	int  h[4];
	h[0]=hash(a,999983);
	h[1]=hash(a,1000039);	
	h[2]=hash(a,313333);
	h[3]=hash(a,213337);
	if(h1[h[0]]&&h2[h[1]]&&h3[h[2]]&&h4[h[3]]){
		return true;
	}return false;
	
}
long long hash(char *a,int mod){
	int i=0;
	long long temp=0;
	while(a[i]){
		temp=(long long)37*temp%mod;
		temp=(long long)(temp+a[i]%base)%mod;
	}
	return temp;
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
