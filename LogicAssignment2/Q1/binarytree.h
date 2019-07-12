/**
 *  Structure for the parse tree
 */
struct node
{
    char data; ///< data stores the character at the node
    node *left; ///< *left stores the address of the left node of the current node
    node *right; ///< *right stores the address of the right node of the current node
    node *root; ///< *root stores the address of the root node of the current node
};

/**
 *  Task 2: Make a parse tree from the postfix expression
 */
class binarytree
{
public:
    node *mainroot; ///< mainroot stores the address of the root node of the parse tree
    int i=0; ///< i is for iterating the postfix expression
    binarytree() ///< Constructor to assign NULL to mainroot
    {
        mainroot = NULL;
    }
    /**
    *  @param currnode of type node having the address of the current node
    *  @param s is a vector that contains the postfix expression passed by reference

    *  rightof makes the right node of the current node
    */
    void rightof(node *currnode,vector<char> &s)
    {
    	i++;
        node *tmp = new node;
        tmp->data = s[s.size()-1-i];
        tmp->left = NULL;
        tmp->right=NULL;
        tmp->root=NULL;
        currnode->right=tmp;
        tmp->root=currnode;
        if(tmp->data!='~'&&issymbol(tmp->data)){
        	rightof(tmp,s);
        	leftof(tmp,s);
        }
        else if(tmp->data=='~')
            rightof(tmp,s);
    }
    /**
    *  @param currnode of type node having the address of the current node
    *  @param s is a vector that contains the postfix expression passed by reference

    *  leftof makes the left node of the current node
    */
     void leftof(node *currnode,vector<char> &s)
    {
    	i++;
        node *tmp = new node;
        tmp->data = s[s.size()-1-i];
        tmp->left = NULL;
        tmp->right=NULL;
        tmp->root=NULL;
        currnode->left=tmp;
        tmp->root=currnode;
        if(tmp->data!='~'&&issymbol(tmp->data)){
        	rightof(tmp,s);
        	leftof(tmp,s);
        }
        else if(tmp->data=='~')
            rightof(tmp,s);
    }
    /**
    *  @param s is a vector that contains the postfix expression passed by reference

    *  maketree assigns the last element of the postfix expression to mainroot
                                         and calls leftof and rightof functions
    */
    void maketree(vector<char> &s){ /**<  */
        node *tmp = new node;
        tmp->data = s[s.size()-1];
        tmp->left = NULL;
        tmp->right=NULL;
        tmp->root=NULL;
        mainroot = tmp;
        rightof(mainroot,s);
        leftof(mainroot,s);
    }
};
