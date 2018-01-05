/* Replace "dll.h" with the name of your header */
#include <windows.h>
#include<string.h>
#include"gbadll.h"
DLLIMPORT void HelloWorld()
{
//	MessageBox(0,"Hello World from DLL!\n","Hi",MB_ICONINFORMATION);
}
DLLIMPORT void hash_clear(){
	
	
	
}
DLLIMPORT void hash_search()


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
