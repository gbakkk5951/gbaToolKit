#ifndef _DLL_H_
#define _DLL_H_

#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif
DLLIMPORT void hash_clear();
DLLIMPORT void hash_insert(char *a);
DLLIMPORT bool hash_find(char *a);


#endif
