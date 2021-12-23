#include<iostream>
#include<cstring>
using namespace std;

void con1(char str[], char goal[], int z, int number)
{
	if(z == number - 1)
	cout << 10000;
	else
	cout << 10000 << ",";
}
void con2(char str[], char goal[], int z, int number)
{
	int a = 0, b = 0;
	char* search = strstr(str, goal);
	while(search != nullptr)
	{
		a++;
		search = strstr(search + 1, goal);//找到後    下一個繼續找 
	}	
	b = 1000 + a;
	
	if(z < (number - 1))
		cout << b << ",";
	else if(z == (number - 1))
		cout << b;
}
void con3(char str[], char goal[], int z, int number)
{
	int max = 0;
	for(int i = 0; i < strlen(goal); i++)
	{
		char* c = strchr(str, goal[i]);
 
		while(c != nullptr)
		{
			int a = 1;
			for(int j = 1; j < strlen(goal) - i; j++)
			{
				if(*(c + j) == goal[i + j] && goal[i + j] != '\0')
					a++;
				else
					break;
			}
			if(a > max)
				max = a;
			c = strchr(c + 1, goal[i]);//$
		}	
	}
	if(z < (number - 1))
		cout << max * 10 << ",";
	else if(z == (number - 1))
		cout << max * 10;
}

int main()
{
	int number = 5,b_len = 0;
	char** str = new char* [number];
	for(int j = 0;j < number;j++)
	{
		str[j] = new char[25];
	}
	//int score[10000] = {0};
	int* a_len = new int [number];
	
	cin >> number;
	cin.getline(str[0], 25);
	for(int i = 0;i < number;i++)
	{
		cin.getline(str[i], 25);
		a_len[i] = strlen(str[i]);
	}
	char goal[25];
	cin.getline(goal, 25);
	b_len = strlen(goal);
	
	char search[100][100];
	char* p = strchr(goal , ' ');
	while((p != nullptr) && (p != '\0'))
	{
		
		p++;
	}
	
	for(int i = 0;i < number;i++)
	{ 
		if(a_len[i] == b_len)//長度相等狀況 
		{
			char* p = strstr(str[i],goal);
			if(p != nullptr)
			{
				con1(str[i],goal,i,number);//全一樣狀況 
			}
			else
			{
				con3(str[i],goal,i,number);//只有部分字元相同狀況 
			}
		}
		if(a_len[i] > b_len)
		{
			char* p = strstr(str[i],goal);
			if(p != nullptr)
			{
				con2(str[i],goal,i,number);//有包含全一樣之狀況 
			}
			else
			{
				con3(str[i],goal,i,number);
			}
		}
		if(a_len[i] < b_len)
		{
			con3(str[i],goal,i,number);
		}
	}
	
	for(int i = 0;i < number;i++)
	{
		delete [] str[i];
	}
	delete [] str;
	delete [] a_len;
	return 0;
}


