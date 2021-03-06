struct Node
{
    string data;
    Node *left, *right;
 
    Node(string data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
struct Trunk
{
    Trunk *prev;
    string str;
    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};
void showTrunks(Trunk *p)
{
    if (p == nullptr) {
        return;
    }
 
    showTrunks(p->prev);
    cout << p->str;
}
 
void printTree(Node* root, Trunk *prev, bool isLeft)
{
    if (root == nullptr) {
        return;
    }
 
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);
 
    printTree(root->right, trunk, true);
 
    if (!prev) {
        trunk->str = "--";
    }
    else if (isLeft)
    {
        trunk->str = ".--";
        prev_str = "   |";
    }
    else {
        trunk->str = "`--";
        prev->str = prev_str;
    }
 
    showTrunks(trunk);
    cout << root->data << endl;
 
    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";
 
    printTree(root->left, trunk, false);
}
Node* constructTree(vector<string> postfix)
{
    stack<Node *> st;
    Node *t, *t1, *t2;
    for (int i=0; i< postfix.size(); i++)
    {
        if (!isoperator(postfix[i]) && !isfunc(postfix[i]))
        {
            t = new Node(postfix[i]);
            st.push(t);
        }
        else if (isfunc(postfix[i])){
        	t = new Node(postfix[i]);
        	t1 = st.top();
        	st.pop();
        	t->left = t1;
        	st.push(t);
		}
        else 
        {
            t = new Node(postfix[i]);
            t1 = st.top(); 
            st.pop();     
            t2 = st.top();
            st.pop();
            t->right =  t1;
            t->left = t2 ;
            st.push(t);
        }
    }
    t = st.top();
    st.pop();
 
    return t;
}
void visualize(vector<string> postfix)
{
    Node* Tree = constructTree(postfix);
    printTree(Tree, nullptr, false);
}
