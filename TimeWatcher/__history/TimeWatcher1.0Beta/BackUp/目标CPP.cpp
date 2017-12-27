#define _TimeWatcherCount_ 15
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

void dfs(int iter){_TimeWatcherArray_[1]++;
	if(iter==5000){_TimeWatcherArray_[2]++;
		return;
	}else{_TimeWatcherArray_[3]++;
		dfs(iter+1);
	}
}
struct TestType{
	int a,b;

	bool  operator < (const TestType &c) const {_TimeWatcherArray_[4]++;
		if(a==c.a){_TimeWatcherArray_[5]++;/*第一关键字相同*/
			return b<c.b;
		}else/*吼吼吼*/{_TimeWatcherArray_[6]++;//sss
			return a<c.a;
		}
	}
}ss;
int main(){_TimeWatcherArray_[7]++;
	int a,b;
	if(a==b){_TimeWatcherArray_[8]++;a++;}
	char st[]="if(a==b){a++;}";
	ss=(TestType){15,3};
	int i,j,k;
	
	for(i=1;i<=15;i++){_TimeWatcherArray_[9]++;
		dfs(1);
	}
	/*
	for(i=1;i<=15;i++){
		dfs(1);
	}	
	*/
//if(a==b){a++;}	*/ if(a==b){a++;} // if(a==b){a++;}/* if(a==b){a++;} */ if(a==b){a++;}
	
	if(i){_TimeWatcherArray_[10]++;
		i--;
	}
	
	
	switch (i){
		case 1:{_TimeWatcherArray_[11]++;
			j++;
			break;
		}
		default:{_TimeWatcherArray_[12]++;
			k--;
			break;
		}
	}
	switch (i!=1){
		case 1:{_TimeWatcherArray_[13]++;
			j++;
			break;
		}
		default:{_TimeWatcherArray_[14]++;
			k--;
			break;
		}
	}	
	if(i!=1){_TimeWatcherArray_[15]++;
		i--;
	}	
	_TimeWatcher_();
}
