#include <iostream>
#include <fstream>
//#include <iomanip>
//#include <cmath>
//#include <stack>
//#include <queue>
//#include <unordered_set>
//#include <list>
//#include <map>
//#include <deque>

/*
Problem Name:    temp
Contest:         pr
*/
using namespace std;
int main() {

    ifstream infile;
    infile.open("infile.txt");
    ofstream outfile;
    outfile.open("outfile.txt");

    int T;
    infile >> T;
    for (int t = 1; t <= T; t++) {


        outfile << "Case #" << t << ": " << endl;
    }

    return 0;
}