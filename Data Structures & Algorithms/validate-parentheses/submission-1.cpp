class Solution {
public:
    bool isValid(string s) {
        unordered_map<char , int> brackets ; 
        brackets['{'] = '}' ; 
        brackets['['] = ']' ; 
        brackets['('] = ')' ; 

        stack<int> st   ;

        for(int i = 0 ; i < s.length() ; i++) {
            if(s[i] == '{' ||s[i] == '(' || s[i] == '['  ){
                st.push(s[i]) ; 

            }
            else{
                if(st.empty()) {
                    return false; 
                }
                char brac  = st.top() ; 
                st.pop() ; 
                if(brackets[brac] != s[i]) {
                    return false; 
                }
            }
        }
        return st.empty()  ;
        
    }
};
