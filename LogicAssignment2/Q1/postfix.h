/**
 *  Task 1: Convert the given infix expression to postfix expression.

        Method:
        1. If a literal is encountered push it into temporary vector s1.
        2. Else push the symbol(except for ')') into vector st.
        3. If ')' is encountered, pop the symbols from st till '(' is encountered and push it into s1.
        4. Repeat steps 1-3 until the all symbols and literals are encountered.
        5. Pop all elements from st and push it into s1.
        6. Swap original vector s with s1.
        7. Exit
 * @param s is a vector containing the infix expression passed by reference
 */
void postfix(vector<char> &s){
    vector<char> st; ///< st is a vector that stores the symbols of the expression
	int n=s.size();
	vector<char> s1; ///< s1 is a temporary vector for storing the postfix expression
	for(int i=0;i<n;i++){
		if(issymbol(s[i])==0){
            s1.push_back(s[i]);
	}
		else{
			if(s[i]==')'){
				int i=0;
				for(i=st.size()-1;st[i]!='(';i--){
                    s1.push_back(st[i]);
                    st.pop_back();
				}
				st.pop_back();
				i--;
				if(st[i]=='~'){
                    s1.push_back(st[i]);
                    st.pop_back();
				}
			}
			else if(s[i]=='~'&&s[i+1]!='('){
				i++;
				s1.push_back(s[i]);
				s1.push_back('~');
			}
			else {
                st.push_back(s[i]);
			}
		}
	}
	for(int i=st.size()-1;i>=0;i--){
        s1.push_back(st[i]);
        st.pop_back();
	}
    s.swap(s1); ///< s and s1 are swapped

}
