class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int cnt=1;
        int n = word.size();
        char ch = word[0];
        for(int i=1; i<n;i++){
            if(word[i] == ch && cnt < 9){
                cnt++;
            }
            else{
                comp.push_back(cnt+'0');
                comp.push_back(ch);
                ch = word[i];
                cnt =1;
            }
        }
        comp.push_back(cnt+'0');
        comp.push_back(ch);
        return comp;
    }
};
//TC=>O(n) and SC=>O(n)