#include<iostream>
using namespace std;

class Maxheap{
private:
  int heap[7];

public:
  //CONSTRUCTOR
  Maxheap(){
    for(int i=0; i<7; i++){
      heap[i]=9;
    }
  }

  // INSERT------------------------------------------------------------------
  void Insert(int data){
    if(heap[0]==9){
      heap[0]=data;
      return;
    }
    else{
        int i=0;
        int right;
        int left;
      while(i<7){

        left= (2*i)+1;
        right= (2*i)+2;
        if(heap[left]==9){
          heap[left]=data;
          Swap(left);
          return;
        }
        if(heap[right]==9){
          heap[right]=data;
          Swap(right);
          return;
        }
        i++;
      }
      cout<<"No Space"<<endl;
    }
  }
  //  CHECK---------------------------------------------------------------
  void Swap(int index){
    int parent;
    while(index>0){
    parent=(index-1)/2;
    if(heap[parent]>heap[index]){
      int a=heap[parent];
      heap[parent]=heap[index];
      heap[index]=a;
    }
    index=parent;
    }
    return;
  }

  // GET HIGHEST PRIORITY--------------------------------------------------
void GetHighest(){
  if(heap[0]==9){
    cout << "Heap is Empty" << endl;
    return;
  }
  cout<<"Lowest Priority Item = "<<heap[0]<<endl;
}

 // DELETE-----------------------------------------------------------------
void Delete(){
  if(heap[0]==9){
    cout << "Heap is Empty" << endl;
    return;
  }
  int i=0;
  while(heap[i]!=9){
    i++;
  }
  heap[0]=heap[i-1];
  heap[i-1]=9;
  Deletecheck();
}

// DELETE CHECK-----------------------------------------------------------
void Deletecheck(){

  int i=0;
  int left;
  int right;
  while(true){
    left=(2*i)+1;
    right=(2*i)+2;
    if(heap[i]<= heap[left] && heap[i]<=heap[right]){
      return;
    }
    if(heap[left]<heap[i]){
      int a=heap[i];
      heap[i]=heap[left];
      heap[left]=a;
    }
    if(heap[right]<heap[i]){
      int a=heap[i];
      heap[i]=heap[right];
      heap[right]=a;
    }
    i++;
  }
}


  // DISPLAY---------------------------------------------------------------
  void Display(){
    for(int i=0 ; i<7 ; i++){
      if(heap[i]!=9){
      cout<<heap[i]<<"  ";
      }
    }
    cout<<endl;
  }

};

int main(){
Maxheap m;
int input;
do{
  cout<<"Enter 1 to Insert"<<endl;
  cout<<"Enter 2 to Delete"<<endl;
  cout<<"Enter 3 to Get Highest Priority"<<endl;
  cout<<"Enter 4 to Display"<<endl;
  cout<<"Enter 0 to Exit"<<endl;

  cin>>input;
  switch(input){
    case 1:
      int data;
      cout<<"Enter Data"<<endl;
      cin>>data;
      m.Insert(data);
      break;

    case 2:
      m.Delete();
      break;

    case 3:
      m.GetHighest();
      break;

    case 4:
      m.Display();
      break;

    default:
      if(input!=0)
      cout << "Invalid Input" << endl;
      break;
  }
}while(input!=0);

return 0;
}
