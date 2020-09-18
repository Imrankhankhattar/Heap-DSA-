#include<iostream>
using namespace std;

class heap{
private:
  int array[15]={0};
  int start=0;
public:
  void add(int d){
    array[start]=d;
    start++;
  }

  void display(){
    for(int i=0; i<15; i++){
      cout<<array[i]<<" ";
    }
    cout<<endl;
  }


  void isheap(){
    if(checktree()==false){
      cout<<"Not Heap"<<endl;
      return;
    }
    if(checkchilds()==true){
    cout<<"Heap"<<endl;
    return;
    }
    cout<<"Not heap"<<endl;

  }

  bool checktree(){
    int count=0;
    for(int i=0; i<start; i++){
      if(array[i]==0){
        count++;
      }
    }
    if(count==0)
    return true;
    return false;
  }

  bool checkchilds(){
    int left;
    int right;
    for(int i=0; i<start; i++){
      left= (2*i)+1;
      right= (2*i)+2;

      if(array[i]<array[left] || array[i]<array[right]){
        return false;
      }
    }
    return true;
  }
};


int main()
{
  heap h;
  cout<<"Enter values:"<<endl;
  int data;
  int i=0;
  while(i<15){
    cin>>data;
    if(data==-1){
    break;
    }
    h.add(data);
    i++;
  }


  h.display();
  h.isheap();
  return 0;
}
