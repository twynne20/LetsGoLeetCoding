#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

bool judgeCircle(string moves) {
    bool answer = false;
    int a = 0;
    int b = 0;
    for(int i = 0; i < moves.size(); i++)
    {
        if(moves[i] == 'U')
        {
            a++;
        }
        else if(moves[i] == 'D')
        {
            a--;
        }
        else if(moves[i] == 'L')
        {
            b++;
        }
        else if(moves[i] == 'R')
        {
            b--;
        }
    }
    if ((a == 0) && (b == 0))
    {
        answer = true;
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    string input = "UDLR";
    bool answer = judgeCircle(input);
    cout << answer << endl;
    return 0;
}
