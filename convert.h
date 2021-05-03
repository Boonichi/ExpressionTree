vector<string> operatorst;
vector<string> outputq; 
void processing(string c){
        if (!isoperator(c) && !isfunc(c) && c != "(" && c != ")"){
            outputq.push_back(c);
        }
        else if (isfunc(c)){
        	operatorst.push_back(c);
		}
        else if (isoperator(c) == true){
            while ((!operatorst.empty()) 
                && ((priority_num(operatorst.back()) > priority_num(c))
                    || (is_left_associative(c) == true && priority_num(c) == priority_num(operatorst.back())))
                && (operatorst.back() != "("))
            { 
                string ch = operatorst.back();
                operatorst.pop_back();
                outputq.push_back(ch);
            }
            operatorst.push_back(c);
        }
        else if (c == "(") operatorst.push_back(c);
        else if (c == ")"){
            while ((operatorst.back() != "(")){
                string ch = operatorst.back();
                operatorst.pop_back();
                outputq.push_back(ch);
            }
            if (!operatorst.empty() && operatorst.back() == "(") operatorst.pop_back();
            if (!operatorst.empty() && isfunc(operatorst.back())){
            	string ch = operatorst.back();
				operatorst.pop_back();
				outputq.push_back(ch);
			}
    }
}
vector<string> convert(string s){
	string getstr = "";
	int i = 0;
	while (i < s.length()){
    	getstr+=s[i];
    	int j = i + 1;
    	string temp = "";
    	if (j < s.length()){
    		temp+=s[j];
    		if (!isoperator(temp) && temp != "(" && temp != ")" && getstr != "(" && getstr != ")" && !isoperator(getstr)) i++;
    		else{
    			processing(getstr);
    			i++;
    			getstr = "";
			}
		}
		else{
			processing(getstr);
			i++;
		}
	}
    while (!operatorst.empty() == true){
        string ch = operatorst.back();
        operatorst.pop_back();
        outputq.push_back(ch);
    }  
    return outputq;
}
