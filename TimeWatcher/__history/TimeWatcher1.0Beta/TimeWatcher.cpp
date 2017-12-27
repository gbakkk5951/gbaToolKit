using namespace std;
int main(){}
#include<cstring>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<sstream>
#include<stack>
struct Counter{
	int pos;
	string text;
}counter[150000];

const string dst="目标CPP.cpp",
			 org="源CPP.cpp" ,
			 ans="统计文档.cpp";
const string codeconst="codeconst.cpp";
string source;
char Buf[1000100];

struct _Main{
template<typename Type>
string tostring(Type a){
	stringstream s;
	string tmp;
	s<<a;
	s>>tmp;
	return tmp;
}
string source;
string output;


int readlen;
string temp;
bool del[150100];
int find(int beg){
	int i,j,k;int r,l;
	int cnt;
	for(;beg<source.size();beg++)if(!del[beg] && source[beg]=='{'){
		for(i=beg-1;i>=0;i--){
			if(!del[i] && !isspace(source[i])){
				r=i;
				break;
			}
		}
		if(r<0 || (source[r]!=')' && source[r]!=':') ){
			if(r>=4 &&source.substr(r-3,r)=="else"){
				if(del[r-4] || (!isdigit(source[r-4]) && !isalpha(source[r-4]))){
					return beg+1;
				}
			}else if(r>=5 &&source.substr(r-4,r)=="const" 
				&&del[r-5] || (!isdigit(source[r-5]) && !isalpha(source[r-5]) &&source[r-5]!='_') ){
				return beg+1;
			}
			continue;
		}else if(source[r]==')'){
			for(i=r-1;i>=0;i--){
				if(!del[i] && source[i]=='('){
					l=i;break;
				}
			}
			for(cnt=0,i=l+1;i<=r-1;i++){
				if(!del[i] && (isalpha(source[i])||source[i]=='_'||isdigit(source[i]))){
					cnt++;
					while(i<=r-1&&!del[i] && (isalpha(source[i])||source[i]=='_'||isdigit(source[i]))){
						i++;
					}
				}
			}
			for(i=l-1;i>=0;i--)if(!del[i] && !isspace(source[i])){
				break;
			}
			if(cnt==1){
	
				if( i>=2 && source.substr(i-1,2)=="if"
				&&(del[i-2] || (!isdigit(source[i-2]) && !isalpha(source[i-2]) &&source[i-2]!='_'))){
					cnt=2;
				}else if(i>=3 && source.substr(i-2,3)=="for"
				&&(del[i-3] || (!isdigit(source[i-3]) && !isalpha(source[i-3]) &&source[i-3]!='_'))){
					cnt=2;
				}else if(i>=5 && source.substr(i-4,5)=="while"
				&&(del[i-5] || (!isdigit(source[i-5]) && !isalpha(source[i-5]) &&source[i-5]!='_'))){
					cnt=2;
				}
			}else if(i>=6 &&source.substr(i-5,6)=="switch"
				&&(del[i-6] || (!isdigit(source[i-6]) && !isalpha(source[i-6]) &&source[i-6]!='_'))){
				cnt=1;
			}

			if(cnt!=1){
				return beg+1;
			}
		}else if(source[r]==':'){
			return beg+1;
		}
	}
	return -1;
	
}
void delnote(){
	char mod=0;//0为普通 1为// 2为/* 3为双引号 4为单引号 
	char gang=0; 
	int i;
	memset(del,1,source.size()*sizeof(bool));
	for(i=0;i<source.size();i++){
		if(mod==1){
			if(source[i]=='\n'){
				del[i]=false;
				mod=0;
				continue;
			}
			continue;
		}else if(mod==2){
			if(source[i]=='*' && i+1<source.size() && source[i+1]=='/'){
				del[i]=del[i+1]=true;
				i++;
				mod=0;
				continue; 
			}
			continue;
		}else if(mod==3){
			if(source[i]=='"'&& gang==0){
				mod=0;
			}else if(source[i]=='\\'){
				gang^=1;
			}else{
				gang=0;
			}
			continue;
		}else if(mod==4){
			if(source[i]=='\'' && gang==0){
				mod=0;
			}else if(source[i]=='\\'){
				gang^=1;
			}else{
				gang=0;
			}
			continue;
		}if(mod==0){
			if( source[i]=='"'){
				mod=3;continue;
			}else if(source[i]=='/'){
				if(i+1<source.size()){
					if(source[i+1]=='/'){
						mod=1;del[i]=del[i+1]=1;
						i++;
						continue;
					}else if(source[i+1]=='*'){
						mod=2;del[i]=del[i+1]=1;
						i++;
						continue;
					}else{
						del[i]=false;
					}
				}else{
					del[i]=false;
				}
			}else if(source[i]=='\''){
				mod=4;continue;
			}else{
				del[i]=false;
			}
		}
	}
	
}
int totcnt;
void process(){
	int i;
	int pos;
	totcnt=0;int cnt;
	freopen(dst.c_str(),"w",stdout);
	freopen(org.c_str(),"r",stdin);
	readlen=fread(Buf,1,(int)1e6,stdin);
	Buf[readlen]='\0';
	source=Buf;
	delnote();
	output=source;
	for(pos=0,cnt=0;(pos=find(pos))!=-1;pos++){
		totcnt++;
		counter[totcnt].pos=pos;
		counter[totcnt].text="_TimeWatcherArray_["+tostring(totcnt)+"]++;";
	}
	freopen(codeconst.c_str(),"r",stdin);
	readlen=fread(Buf,1,100000,stdin);
	Buf[readlen]='\0';
	cout<<"#define _TimeWatcherCount_ "<<totcnt<<endl;
	cout<<Buf<<endl;	
	for(i=0,cnt=1;i<source.size();i++){
		if(cnt<=totcnt && i==counter[cnt].pos){
			cout<<counter[cnt].text;
			cnt++;
		}
		putchar(source[i]);
	}
	fclose(stdout);
}

void print(){
	int i,cnt;int tmp;
	freopen("RunningResult.res","r",stdin);
	cin>>tmp;
	if(tmp!=totcnt){
		cerr<<"数据不匹配，请检查是否已经添加统计函数,重新处理并编译运行"<<endl;
		return; 
	}
	for(cnt=1;cnt<=totcnt;cnt++){
		cin>>tmp;
		counter[cnt].text="/* Counter: "+tostring(tmp)+" */"; 
	}
	freopen(ans.c_str(),"w",stdout);
	for(i=0,cnt=1;i<source.size();i++){
		if(cnt<=totcnt && i==counter[cnt].pos){
			cout<<counter[cnt].text;
			cnt++;
		}
		putchar(source[i]);
	}
	fclose(stdout);
	
	
}
string cmd;
_Main(){
	
	printf("输入process以处理源码，编译运行后输入print以打印结果\n");
	while(1){
		freopen("Con","r",stdin);
		cin>>cmd;
		if(cmd=="process"){
			process();
		}else if(cmd=="print"){
			print();
		}
	}
}
	
	
	
	
	
	
	
}TimeWatcher;
