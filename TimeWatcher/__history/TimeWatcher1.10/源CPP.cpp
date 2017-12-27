void dfs(int iter){
	if(iter==5000){
		return;
	}else{
		dfs(iter+1);
	}
}
struct TestType{
	int a,b;

	bool  operator < (const TestType &c) const {
		if(a==c.a){/*第一关键字相同*/
			return b<c.b;
		}else/*吼吼吼*/{//sss
			return a<c.a;
		}
	}
}ss;
void func(){int c;c++;}
int main(){
	int a,b;
	if(a==b){a++;}
	char st[]="if(a==b){a++;}\"void func(){int c;c++;}";
	ss=(TestType){15,3};
	int i,j,k;
	
	for(i=1;i<=15;i++){
		dfs(1);
	}
	/*
	for(i=1;i<=15;i++){
		dfs(1);
	}	
	*/
//if(a==b){a++;}	*/ if(a==b){a++;} // if(a==b){a++;}/* if(a==b){a++;} */ if(a==b){a++;}
	
	if(i){
		i--;
	}
	
	
	switch (i){
		case 1:{
			j++;
			break;
		}
		default:{
			k--;
			break;
		}
	}
	switch(i!=1){
		case 1:{
			j++;
			break;
		}
		default:{
			k--;
			break;
		}
	}	
	if (i!=1){
		i--;
	}	
}
