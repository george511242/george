#include <iostream>
using namespace std;

int main()
{
  int students = 0, groups = 0 ,flag = 0;
  
  cin >> students ;//�W���˔� 
  cin >> groups ;//С�M�˔� 
  
  if(students < groups)//�Д��˔� 
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
