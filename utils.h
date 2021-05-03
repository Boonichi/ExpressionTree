string operators[10] = {"+","-","*","/","^","&"};
string funcs[20] = {"sin","cos","tan","cot","sinh","cosh","tanh","log","csc","sec","log"};
int priority_num(string c){
    if (c == "+" || c == "-" || c == "&") return 0;
    if (c == "*" || c == "/") return 1;
    if (c == "^") return 2;
    return 0;
}
bool isoperator(string c){
    for (string i : operators){
        if (c == i) return true;
    }
    return false;
}
bool is_left_associative(string c){
    if (c == "^") return false;
    return true;
}
bool isfunc(string c){
    for (auto i : funcs){
        if (i == c) return true;
    }
    return false;
}
