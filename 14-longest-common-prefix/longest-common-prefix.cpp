class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = strs[0];  // Assume the first string as prefix
        
        for (int i = 1; i < strs.size(); i++) {
            // Shrink prefix until it matches the start of strs[i]
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";
            }
        }
        
        return prefix;
    }
};
