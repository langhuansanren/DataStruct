// DataStruct.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int gcd(int m, int n){
	if (n == 0) return m;
	return gcd(n, m%n);
}

int main()
{
	int s=gcd(12, 8);
	printf("���Լ���ǣ�%d\n", s);
	return 0;
}

