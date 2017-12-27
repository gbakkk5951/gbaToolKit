void dfs(int iter){/* Counter: 75000 */
	if(iter==5000){/* Counter: 15 */
		return;
	}else{/* Counter: 74985 */
		dfs(iter+1);
	}
}
struct TestType{
	int a,b;

	bool  operator < (const TestType &c) const {/* Counter: 0 */
		if(a==c.a){/* Counter: 0 *//*第一关键字相同*/
			return b<c.b;
		}else/*吼吼吼*/{/* Counter: 0 *///sss
			return a<c.a;
		}
	}
}ss;
int main(){/* Counter: 1 */
	int a,b;
	if(a==b){/* Counter: 1 */a++;}
	char st[]="if(a==b){a++;}";
	ss=(TestType){15,3};
	int i,j,k;
	
	for(i=1;i<=15;i++){/* Counter: 15 */
		dfs(1);
	}
	/*
	for(i=1;i<=15;i++){
		dfs(1);
	}	
	*/
//if(a==b){a++;}	*/ if(a==b){a++;} // if(a==b){a++;}/* if(a==b){a++;} */ if(a==b){a++;}
	
	if(i){/* Counter: 1 */
		i--;
	}
	
	
	switch (i){
		case 1:{/* Counter: 0 */
			j++;
			break;
		}
		default:{/* Counter: 1 */
			k--;
			break;
		}
	}
	switch (i!=1){
		case 1:{/* Counter: 1 */
			j++;
			break;
		}
		default:{/* Counter: 0 */
			k--;
			break;
		}
	}	
	if(i!=1){/* Counter: 1 */
		i--;
	}	
	_TimeWatcher_();
}
