#include <iostream>
#include <fstream>
using namespace std;


int main() {
  int total = 0;
  int max = 0;
  string strNums;
  int nums;
  ifstream data("input.txt");
  while(getline(data,strNums)){
    if (strNums.empty()){
        if (max == 0){
          max = total;
        }else if (total>max){
          max = total;
        }
        total = 0;
      }else{
        total += stoi(strNums);
      }
    }
  cout<<"The largest value is "<< max;
  return 0;
}