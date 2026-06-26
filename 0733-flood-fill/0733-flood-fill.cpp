class Solution {
public:

    void dfs(vector<vector<int>>& image,
             int i,
             int j,
             int original,
             int color,
             int n,
             int m)
    {
        // Base condition
        if(i < 0 || j < 0 || i >= n || j >= m ||
           image[i][j] != original)
        {
            return;
        }

        // Change color
        image[i][j] = color;

        // Visit 4 neighbours
        dfs(image, i - 1, j, original, color, n, m); // Up
        dfs(image, i + 1, j, original, color, n, m); // Down
        dfs(image, i, j - 1, original, color, n, m); // Left
        dfs(image, i, j + 1, original, color, n, m); // Right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr,
                                  int sc,
                                  int color)
    {

        int n = image.size();
        int m = image[0].size();

        int original = image[sr][sc];

        if(original == color)
            return image;

        dfs(image, sr, sc, original, color, n, m);

        return image;
    }
};