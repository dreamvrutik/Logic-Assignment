/**
 *  Task 3: Traversing the parse tree and printing the infix expression

        Method:
        1. First traverse the left node until a literal is found.
        2. Then traverse back and print the symbol at the immediate node.
        3. Then traverse the right node until a literal is found.
        4. Traverse back from the current subtree.
        5. Repeat 1-4 till every node is covered.
        P.S.: Parenthesis is applied for every subtree.
 * @param currnode of type node having the address of the current node
 */
void infixtraversal(node *currnode){
    if(currnode->data!='~'&&currnode->left!=NULL){
        if(issymbol(currnode->left->data)&&(currnode->left->data!='~')){
            cout<<'(';
            infixtraversal(currnode->left);
            cout<<')';
        }
        else
            infixtraversal(currnode->left);
    }
    if(currnode!=NULL)
        cout<<currnode->data;
    if(currnode->right!=NULL){
        if(issymbol(currnode->right->data)&&(currnode->right->data!='~'||currnode->data=='~')){
            cout<<'(';
            infixtraversal(currnode->right);
            cout<<')';
        }
        else   infixtraversal(currnode->right);
    }
}
