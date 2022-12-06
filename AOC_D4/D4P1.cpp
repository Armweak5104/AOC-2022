#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(){
  string content;
  ifstream grouping("testinput.txt");
  string range1;
  int range1l;
  int range1u;
  string range2;
  int range2l;
  int range2u;
  int counter=0;
  while (getline(grouping,content)){
    range1 = content.substr(0,content.find(","));
    range1l = stoi(range1.substr(0,range1.find("-")));
    range1u = stoi(range1.substr(range1.find("-")+1));
    range2 = content.substr(content.find(",")+1);
    range2l = stoi(range2.substr(0,range2.find("-")));
    range2u = stoi(range2.substr(range2.find("-")+1));
    // cout<<range1<<endl;
    // cout<<range1l<<endl;
    // cout<<range1u<<endl;
    // cout<<range2<<endl;
    // cout<<range2l<<endl;
    // cout<<range2u<<endl;
    if (range1l<=range2l && range1u>=range2u){
      counter+=1;
    }else if(range2l<=range1l && range2u>=range1u){
      counter+=1;
    }
  }
  cout<<counter<<endl;
}