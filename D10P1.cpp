#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


int main(){
  ifstream data("input10.txt");
  string content;
  int cycles = 0;
  int x = 1;
  int signalS = 0;
  int increment;
  int signal = 1;
  while(getline(data,content)){
    if (content[0]=='a'){
      increment = stoi(content.substr(4,4));
      if(cycles+2>=20*signal){
        signalS += 20*signal*x;
        signal+=2;
      }
      x+=increment;
      cycles+=2;
    }else{
      if(cycles+2>20*signal || cycles == 20*signal){
        signalS += 20*signal*x;
        signal+=2;
      }
      cycles+=1;
    }
    if (signal == 13){
      cout<<signalS<<endl;
      break;
    }
  }
}