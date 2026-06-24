class Solution {
public:

    int operation(int a, int b, char c) {
        if(c == '+') {
            return a + b;
        }
        else if(c == '*') {
            return a * b;
        }
        else if(c == '-') {
            return a - b;
        }
        else if(c == '/') {
            return a / b;
        }
        return 0;
    }

    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for(int i = 0; i < tokens.size(); i++) {

            string s = tokens[i];

            if(s != "+" && s != "-" && s != "*" && s != "/") {
                st.push(stoi(s));
            }
            else {

                int a = st.top(); 
                st.pop();

                int b = st.top(); 
                st.pop();

                int ans = operation(b, a, s[0]);

                st.push(ans);
            }
        }

        return st.top();
    }
};
