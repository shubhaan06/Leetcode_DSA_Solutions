class Solution {
public:
    int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    void solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &vis)
    {
        int n=grid.size(),m=grid[0].size();
        vis[i][j]=0; //mark it as visited;

        for(int k=0;k<4;k++)
        {
            int x=i+dir[k][0];
            int y=j+dir[k][1];

            if(x<0 || y<0 || x>=n || y>=m)
                continue;

            if(vis[x][y])
            {
                solve(x,y,grid,vis);
            }
        }

    }
    int numIslands(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        vector<vector<int>> vis=grid;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]) //starting point
                {
                    solve(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }

    int minDays(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans = numIslands(grid);

        if(ans!=1)
        return 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]) //starting point
                {
                    grid[i][j]=0;
                    int cnt = numIslands(grid);
                    if(cnt!=1)
                    return 1;
                    grid[i][j]=1;
                }
            }
        }

        return 2;
    }
};