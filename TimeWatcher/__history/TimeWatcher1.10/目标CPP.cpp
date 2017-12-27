#define _TimeWatcherCount_ 24
#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
int _TimeWatcherArray_[150010];
struct _TimeWatcherType_{

	~_TimeWatcherType_(){
		Print();
	}
	void  inline operator () (){
		Print();
	}
	void Print(){
		ofstream output("RunningResult.res");
		output<<_TimeWatcherCount_<<endl;
		int i;
		for(i=1;i<=_TimeWatcherCount_;i++){
			output<<_TimeWatcherArray_[i]<<endl;
		}
		output.close();
	}
	
}_TimeWatcher_;






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
void func(){_TimeWatcherArray_[7]++;int c;c++;}
int main(){_TimeWatcherArray_[8]++;
	int a,b;
	if(a==b){_TimeWatcherArray_[9]++;a++;}
	char st[]="if(a==b){_TimeWatcherArray_[10]++;a++;}\"void func(){_TimeWatcherArray_[11]++;int c;c++;}";
	ss=(TestType){15,3};
	int i,j,k;
	
	for(i=1;i<=15;i++){_TimeWatcherArray_[12]++;
		dfs(1);
	}
	/*
	for(i=1;i<=15;i++){_TimeWatcherArray_[13]++;
		dfs(1);
	}	
	*/
//if(a==b){_TimeWatcherArray_[14]++;a++;}	*/ if(a==b){_TimeWatcherArray_[15]++;a++;} // if(a==b){_TimeWatcherArray_[16]++;a++;}/* if(a==b){_TimeWatcherArray_[17]++;a++;} */ if(a==b){_TimeWatcherArray_[18]++;a++;}
	
	if(i){_TimeWatcherArray_[19]++;
		i--;
	}
	
	
	switch (i){
		case 1:{_TimeWatcherArray_[20]++;
			j++;
			break;
		}
		default:{_TimeWatcherArray_[21]++;
			k--;
			break;
		}
	}
	switch(i!=1){
		case 1:{_TimeWatcherArray_[22]++;
			j++;
			break;
		}
		default:{_TimeWatcherArray_[23]++;
			k--;
			break;
		}
	}	
	if (i!=1){_TimeWatcherArray_[24]++;
		i--;
	}	
}
