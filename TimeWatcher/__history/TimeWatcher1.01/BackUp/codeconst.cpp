#include<iostream>
#include<cstdio>
using namespace std;
int _TimeWatcherArray_[150010];
void _TimeWatcher_(){
	freopen("RunningResult.res","w",stdout);
	cout<<_TimeWatcherCount_<<endl;
	int i;
	for(i=1;i<=_TimeWatcherCount_;i++){
		cout<<_TimeWatcherArray_[i]<<endl;
	}
	fclose(stdout);
}
