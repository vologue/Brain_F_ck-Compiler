
#include<string>
#include<stdio.h>
#include<iostream>
using namespace std;

int compile(char code[10000]){
	int c=0,j=0,fn,fp;
	while(code[j]!='\0'){
		if(code[j]=='['){
			c++;
			fp=j;
		}
		else if(code[j]==']'){
			c--;
			fn=j;
		}j++;
	}
	if(c==0){
		cout<<"Compile Succesful-0 Errors\n";
		return 1;
	}
	else if(c<0){
		cout<<"Expected '[' before"<<code[fn-1]<<code[fn]<<code[fn+1]<<"\n";
		return 0;
	}
	else if(c>0){
		cout<<"Expected ']' after"<<code[fp-1]<<code[fp]<<code[fp+1]<<"\n";
		return 0;
	}
}
int main(){
	static char base[5000];
  	char code[10000];
	int i,j;
	i=0;
	j=0;
	cout<<"* Use e to signify the end*\n Enter code:";
	cin.getline(code,10000,'e');
	if(compile(code)==1){
	cout<<"Execute?(y/n)";
	char choice;
	cin>>choice;
	if(choice=='y'){
	while (code[j]!='\0'){
		switch(code[j]){
			case ',':cin>>base[i];
				break;
			case '+':base[i]++;
				break;
			case '-':base[i]--;
				break;
			case '>':i++;
				break;
			case '<':i--;
				break;
			case '.':cout<<base[i];
				break;
			case ']': if(base[i]!=0){
					while(code[j]!='['){
						j--;
					}break;
				}
			}
		j++;
		}
	}
}
cout<<"\n\n\n";	return 0;
}

