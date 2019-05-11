/**
faster than 26%
**/

class Solution {
public:
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size()==0 || matrix[0].size()==0) return 0;
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> res=matrix;
        int result=1;
        for (auto &v: res) {
            std::fill(v.begin(), v.end(), 0);
        }
        for (int i=0;i<row;i++){
            for (int j=0; j<col; j++){
                result=max(result,DFS(matrix,res,i,j));
            }
        }
        return result;
    }
    
    int DFS(vector<vector<int>>& matrix,vector<vector<int>>& res,int i, int j)
    {
        if (res[i][j]!=0) return res[i][j];
        int mx = 1, m = matrix.size(), n = matrix[0].size();
        for (auto a : dirs) {
            int x = i + a[0], y = j + a[1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
            int len = 1 + DFS(matrix, res, x, y);
            mx = max(mx, len);
        }
        res[i][j]=mx;
        return mx;
    }
    
};