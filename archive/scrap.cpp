#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int c=0;
  vector<string> text(2);
  text.push_back("XXXX");

  for (string val : text){
    cout << c << "-" << val << endl;
    c+=1;
  }
}
