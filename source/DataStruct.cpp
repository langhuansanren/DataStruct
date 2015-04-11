// DataStruct.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define MAXLEN 100;
/*********递归求最大公约数**********/
int gcd(int m, int n){
	if (n == 0) return m;
	return gcd(n, m%n);
}

struct Stack{
	char* data;
	int top;
	int Maxlen;
};

void initS(Stack& s){
	s.data =(char*) malloc(100 * sizeof(char));
	s.top = 0;
	s.Maxlen = MAXLEN;
}
bool emptyS(Stack& s){
	return s.top == 0 ? 1 : 0;
}
bool fullS(Stack& s){
	return (s.top==s.Maxlen-1)?1 : 0;
}
void push(Stack &s, char c){
	if (fullS(s)) return;
	s.data[s.top] = c;
	s.top=(s.top+1)%s.Maxlen;
}

void pop(Stack &s, char& c){
	if (emptyS(s)) return;
	s.top = (s.top - 1) % s.Maxlen;
	c=s.data[s.top] ;
}
bool march(char a, char c){
	if ((a == '(' && c == ')') || (a == ')' && c == '('))
		return true;
	if ((a == '{' && c == '}') || (a == '}' && c == '{'))
		return true;
	if ((a == ']' && c == '[') || (a == '[' && c == ']'))
		return true;
	return false;
}

bool kuohaoMarch(char* str){
	char *tmp = str;
	//Stack* s=(Stack*)malloc(sizeof(Stack));
	Stack s;
	initS(s);

	while (*tmp != '\0'){
		if (*tmp == '(' || *tmp == '{' || *tmp == '[')
			push(s, *tmp);
		else if (*tmp == ')' || *tmp == '}' || *tmp == ']'){
			char t=' ';
			pop(s, t);
			if (!march(*tmp, t)){
				return false;
			}
		}
		tmp++;
	}

	if (emptyS(s))return true;
	return false;

}


int main()
{
	bool s =kuohaoMarch("{[(a+[]b)[111-22()]^(c-d)]}");
	if (s){
		printf("正确匹配！\n");
	}
	else{
		printf("匹配错误！\n");
	}
}

