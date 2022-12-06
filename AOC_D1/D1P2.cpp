#include <iostream>
#include <fstream>
using namespace std;


int main() {
  int total = 0;
  int max = 0;
  int second = 0;
  int third = 0;
  string strNums;
  int nums;
  ifstream data("input.txt");
  while(getline(data,strNums)){
    if (strNums.empty()){
        cout<<total<<endl;
        if (max == 0){
          max = total;
        }else if (total>max){
          max = total;
        }
        if(second == 0){
          second = total;
        }else if(total>second && total<max){
          second = total;
        }
        if (third == 0){
          third = total;
        }else if(total>third && total<second){
          third = total;
        }
        total = 0;
      }else{
        total += stoi(strNums);
      }
    }
  cout<<"The max is "<< max<<endl;
  cout<<"The second is "<< second<<endl;
  cout<<"The third is "<< third<<endl;
  cout<<max+second+third;

  return 0;
}