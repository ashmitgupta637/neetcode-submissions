class Solution {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        if(strs.empty()) return "__EMPTY_LIST__";
        string ans = "";

        for(string s : strs) {

            ans += s;
            ans += char(257);   // separator
        }

        if(ans.size() > 0)
            ans.pop_back();     // remove last separator

        return ans;
    }


    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        if (s == "__EMPTY_LIST__") return {};
        vector<string> ans;

        string temp = "";

        for(char c : s) {

            if(c == char(257)) {

                ans.push_back(temp);
                temp = "";
            }
            else {
                temp += c;
            }
        }

        ans.push_back(temp);

        return ans;
    }
};
