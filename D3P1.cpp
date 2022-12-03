#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// lowercase --> ASCII - 96
// Uppercase --> ASCII - 38
int main() {
  vector<char> rucksack = {};
  ifstream contents("input3.txt");
  string item;
  int value = 0;
  string part1;
  string part2;
  while (getline(contents, item)) {
    part1 = item.substr(0, item.length()/2);
    part2 = item.substr(item.length()/2);
    for (int i = 0; i<part1.length(); ++i){
      for (int j = 0; j<part1.length(); ++j){
        if (part1[i]==part2[j]){
          rucksack.push_back(part1[i]);
        }
      }
    }
    if(isupper(rucksack[0])){
      value+=int(rucksack[0]) - 38;
      rucksack = {};
    }else{
      value+=int(rucksack[0]) - 96;
      rucksack = {};
    }
  }
  cout << value << endl;
}