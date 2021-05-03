#include <bits/stdc++.h>
using namespace std;
#include "utils.h"
#include "convert.h"
#include "visualize.h"

int main(){
    freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    string infixstring;
    string str;
    while (cin >> str){
        infixstring+=str;
    }
    infixstring.erase(remove(infixstring.begin(), infixstring.end(), ' '), infixstring.end());
    vector<string> postfixstring = convert(infixstring);
    //for (auto i : postfixstring) cout << i << ' ';
    visualize(postfixstring);
}
