#include<iostream>
#include <cstring>
#include<cstdio>
#include <algorithm>
#include <stdio.h>
#include<iostream>
#include<cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{	
	int main
}
//
// vector 变长数组. 分配空间与大小没有关系和次数有关
//倍增思想 自动变长 
//#include <vector>
//vector<int>a;
//vector<int>a(10);
//vector<int>a(10,3); 
//vector<int>a[10]
//a.size 元素个数 On(1)
//a.empty 是不是空 On(1)
//a.clear 清空    
// back front
// push_back pop_back 
//iterator i  *i
//begin end->是最后一个数的后面一个数
// []
// 支持比较大小 按照字典序比较
// 
// 
//pair存储一个二元组
//pair <int,int>p  p.first p.second
//支持比较按照字典序比较 以first为第一关键字 以second为第一关键字 
//p=make_par(1,1) 
// pair <int,pair<int,int>>
// 
// 
//string substr->返回子串 c_str->对于字符数组的头指针
// size empty
// string a="yxv"
//子串=a.substr(1,len)
// printf("%s",a.c_str());
// 
// 
//queue 队列
//push pop front back 
//size empty
// q=queue<int>() 可以这样清空
// 
// 
//priority_queue 优先队列 堆 默认是大根堆
// pop top push
//	想小根堆
// 1.插入的时候插入负数
// 2.定义priority_queue<int, vector<int>, greater<int>>heap;
// 
// 
//stack 栈
// push top pop
// 
// 
//deque 双端队
//set map multiset multimap 基于平衡二叉树(红黑树),动态维护有序序列
//unnordered_set unordered_map unordered_multiset unordered_multimap基于哈希表
//bisset 压位