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
                 tmp=_str[j];
                _str[j]=_str[j+1];
                 cout<<"_str[j+1]="<<_str[j];
                _str[j+1]=tmp;
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
  
  //  std::string *pt;
  //  std::string st="da";
  //  std::string *pt2;

  //  pt=&st;

  //  cout<<"st-val="<<st<<"\n";
  //  cout<<"st-add="<<&st<<"\n";

  //  cout<<"pt-val="<<pt<<"\n";
  //  cout<<"pt-add="<<&pt<<"\n";

  //  pt2=pt;
  //  cout<<"pt2-val="<<pt2<<"\n";
  //  cout<<"pt2-add="<<&pt2<<"\n";
  
  std::cout<<"\n\n\n";
  return 0;
}