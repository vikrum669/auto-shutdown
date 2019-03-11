#include<iostream>
#include<string.h>

using namespace std;

namespace Autoshut {
  class Button {
    public:
      
    private:
      int height;
      int width;
      int x_cord;
      int y_cord;

    public:
      Button(int height, int width,int x_coordinate, int y_coordinate){
          this->height=height;
          this->width=width;
          x_cord=x_coordinate;
          y_cord=y_coordinate;
      } 

      void Display(){
          cout<<"Button Height="<<this->height<<"\n";
          cout<<"Button width="<<this->width<<"\n";
          cout<<"Button x-coordinate="<<this->x_cord<<"\n";
          cout<<"Button y-coordintate="<<this->y_cord<<"\n";
      } 
  };

//namespace ending brace
}

//Main function of the program. The Autoshut namespace contains all class and methods definition for our program.

using namespace Autoshut;

int main(){
  cout<<"OUTPUT:\n";
  int size=4;

//fill the array with random strbers
  string str[size]={"dog","cat","apple","ball"};

  string *a[size];
  string *tmp;
  

  for(int i=0;i<size;i++){
    a[i]=&str[i];
    cout<<"a["<<i<<"]="<<a[i]<<"\n";
  }

  string a("apple");
  string b("ball");

  cout<<a.compare(b);

  // for(int i=0;i<size;i++){
  //   for(int j=0;j<size-1-i;j++){
  //       if(*a[j]>*a[j+1]){
  //         tmp=&str[j];
  //         a[j]=a[j+1];
  //         a[j+1]=tmp;
  //       }
  //   }
  // }

  // cout<<"\n\n AFTER SORT str ADDRESS\n";
  // for(int i=0;i<size;i++){
  //   cout<<&str[i]<<"\n";
  // }

  // cout<<"\n\n AFTER SORT *a ADDRESS\n";
  // for(int i=0;i<size;i++){
  //   cout<<a[i]<<"\n";
  // }

  
  


  cout<<"\n\n\n";
  return 0; 
}