#include<iostream>
#include<fstream>

using namespace std;

namespace AutoShut
{
  class String
   {
     public:
     static int Compare(std::string str1, std::string str2)
     {
       int flag=0;
       
       for(int i=0;;i++)
       {
          if((str1)[i]>(str2)[i])
          {
              flag=1;
              break;
          }
          else if((str2)[i]>(str1)[i])
          {
              flag=2;
              break;
          }
          else if((str1)[i]=='\0' && (str2)[i]!='\0')
          {
              flag=2;
              break;
          }
          else if((str1)[i]!='\0' && (str2)[i]=='\0')
          {
              flag=1;
              break;
          }
          else if((str1)[i]=='\0' && (str2)[i]=='\0')
          {
              flag=0;
              break;
          }
       }
       return flag;
     }

     static int Sort(std::string str[],int size)
     {
        std::string *_str[size]; //this will point to the array of random strings
        
        //initialize the pointer to the address of strin array
        for(int i=0;i<size;i++)
        {
          _str[i]=&str[i];
          std::cout<<_str[i]<<","<<&str[i]<<"="<<*_str[i]<<'\n';
        }

        std::string *tmp;
        for(int i=0;i<size;i++) //This is the bubble sort algorithm.
        {
          for(int j=0;j<3;j++)
          {
             if(Compare((*_str)[j],(*_str)[j+1])==1)
             {
                 cout<<"_str[j]="<<_str[j]<<"="<<(*_str)[j]<<"\n";
                 tmp=_str[j];
                 cout<<"tmp="<<tmp<<"="<<*tmp<<"\n";
                _str[j]=_str[j+1];
                cout<<"_str[j=j+1]="<<_str[j]<<"="<<(*_str)[j]<<"\n";
                _str[j+1]=tmp;
                cout<<"_str[j+1]="<<_str[j+1]<<"="<<(*_str)[j+1]<<"\n\n\n";
             }
          }
        }

        for(int i=0;i<size;i++)
        {
          std::cout<<*_str[i]<<'\n';
        }
        
     }

   } ;
}

using namespace AutoShut;
int main()
{
  std::cout<<"OUTPUT::\n";
 

  // int size=10000;
  int size=4;
  std::string str[size]={"d","c","b","a"}; //we will use this array to store the random strings read from file
  
  // std::ifstream stringList;
  // stringList.open("string.txt");
  
  // int i=0;
  // for( std::string line;i<4, getline( stringList, line );)
  // {
  //   str[i]=line;
  //   i++;
  // }
  // stringList.close(); //close the file stream since it is no longer needed.

  String s;
  s.Sort(str, size);
  
  
  std::cout<<"\n\n\n";
  return 0;
}