#include <iostream>
using namespace std;

int main()
{
  int students = 0, groups = 0 ,flag = 0;
  
  cin >> students ;//學生人數 
  cin >> groups ;//小組人數 
  
  if(students < groups)//判斷人數 
  {
  	cout << "1" << "\n";
  }
  
  if(students >= groups)
  	cout << "1";
  
   flag = groups;
    
    while( students > flag)
  {
  	cout << "," << 1 + flag ;
  	flag = flag + groups; 
  }
  
  return 0;	
}
