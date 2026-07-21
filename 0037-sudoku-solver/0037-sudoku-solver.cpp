class Solution {
public:
    bool findEmptyCell(vector<vector<char>>& board,vector<int>&empty){
        // vector<int>empty(2);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') {
                    empty[0]=i;
                    empty[1]=j;
                    return true;
                }
            }
        }
        return false;
    }
    bool isSafe(vector<vector<char>>& board,int ri, int ci,  char val){
        for(int i=0;i<9;i++){
            if(board[ri][i]==val) return false;
        }

        for(int i=0;i<9;i++){
            if(board[i][ci]==val) return false;
        }

        int start_row= ri - (ri%3);
        int start_col= ci-(ci%3);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int actual_row=start_row+i;
                int actual_col=start_col+j;
                if(board[actual_row][actual_col]==val) return false;
            }
        }
        return true;
    }
    bool solveboard(vector<vector<char>>& board){
        vector<int>empty(2);
        
        if(!findEmptyCell(board,empty)){
            return true;
        }
        int row=empty[0];
        int col=empty[1];
        for(int i=1;i<=9;i++){
            char temp=(char)(i+'0');
            if(isSafe(board,row,col,temp)){
                board[row][col]=temp;
                if(solveboard(board)==true) return true;
                board[row][col]='.';
            }
        }
        return false;
    }



    void solveSudoku(vector<vector<char>>& board) {
        solveboard(board);
    }
};