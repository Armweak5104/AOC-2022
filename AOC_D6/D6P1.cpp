#include<bits/stdc++.h>
using namespace std;

                   
int main(){
  string content;
  string packet = "";
  ifstream data("testinput.txt");
  string test;
  string sref = "";
  bool overlap = false;
  while(getline(data,content)){
    packet+=content;
  }
  //cout<<packet<<endl;
  for(int i = 0; i<packet.length()-2;++i){
    test = content.substr(i,4);
    sort(test.begin(),test.end());
    set<char> ref(test.begin(),test.end());
    for (auto it: ref){
      sref+=it;
    }
    cout<<sref<<" and "<<test<<endl;
    if (sref == test){
      cout<<i+4<<endl;
      break;
    }
    sref ="";
  }
}