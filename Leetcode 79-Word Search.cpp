/**faster than 30%**/


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        if (row==0 or col==0 or word.length()==0) return false;
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (DFS(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
    
    bool DFS(vector<vector<char>>& board, string word,int i,int j,int pos)
    {
        if (pos==word.length()) return true;
        if (i<0 || j<0 || i>=board.size() || j>=board[0].size()) return false;
        if (word[pos]!=board[i][j]) return false;
        
        char tmp=board[i][j];
        board[i][j]='*';
        bool result = (DFS(board,word,i+1,j,pos+1) || DFS(board,word,i-1,j,pos+1) || DFS(board,word,i,j+1,pos+1) || DFS(board,word,i,j-1,pos+1));
        board[i][j]=tmp;
        return result;
    }
};