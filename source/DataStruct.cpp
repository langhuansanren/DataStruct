// DataStruct.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int gcd(int m, int n){
	if (n == 0) return m;
	return gcd(n, m%n);
}

int main()
{
	int s=gcd(12, 8);
	printf("最大公约数是：%d\n", s);
	return 0;
}

