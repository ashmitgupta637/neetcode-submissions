class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9) ; 
        vector<unordered_set<char>> cols(9) ; 
        vector<unordered_set<char>> boxes(9) ; 

        for(int r = 0 ; r < 9 ; r++) {
            for(int c = 0 ; c < 9 ; c++) {
                char values = board[r][c] ; 
                if(values == '.') {
                    continue ; 
                }
                if(rows[r].count(values)) {
                    return false; 
                }
                rows[r].insert(values) ; 
                if(cols[c].count(values)) {
                    return false ; 
                }
                cols[c].insert(values) ; 
                int boxIndex = (r/3) *3 +(c/3) ; 
                if(boxes[boxIndex].count(values)) {
                    return false ; 
                }
                boxes[boxIndex].insert(values) ;
            }
        }
        return true ; 
    }
};
