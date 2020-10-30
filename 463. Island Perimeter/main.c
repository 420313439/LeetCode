int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int c = 0;

    int n = gridSize;
    int m = gridColSize[0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                c += 4;
            }

            // 中间
            if (i != 0 && i != n - 1 && j != 0 && j != m - 1){
                if (grid[i + 1][j] == 1)
                    c -= 1;
                if (grid[i - 1][j] == 1)
                    c -= 1;
                if (grid[i][j + 1] == 1)
                    c -= 1;
                if (grid[i][j - 1] == 1)
                    c -= 1;
            }
            
            if (i == 0 && j == 0) {     // 左上角
                if (grid[i + 1][j] == 1)
                    c -= 1;
                if (grid[i][j + 1] == 1)
                    c -= 1;
            }

            if (i == 0 && j == m - 1) {     // 右上角
                if (grid[i][j - 1] == 1)
                    c -= 1;
                if (grid[i + 1][j] == 1)
                    c -= 1;
            }

            //左下角
            if (i == n - 1 && j == 0) {
                if (grid[i - 1][j] == 1)
                    c -= 1;
                if (grid[i][j + 1] == 1)
                    c -= 1;
            }

            //右下角
            if (i == n - 1 && j == m - 1) {
                if (grid[i - 1][j] == 1)
                    c -= 1;
                if (grid[i][j - 1] == 1)
                    c -= 1;
            }

            // 第一行
            if (i == 0 && j != 0 && j != m - 1) {
                if (grid[i + 1][j] == 1)
                    c -= 1;
            }

            // 最后一行
            if (i == n - 1 && j != 0 && j != m - 1)
                if (grid[i - 1][j] == 1)
                    c -= 1;

            // 最左列
            if (i != 0 && i != gridSize - *gridColSize && j == 0)
                if (grid[i][j + 1] == 1)
                    c -= 1;

            // 最右列
            if (i != 0 && i != n - 1 && j == m - 1)
                if (grid[i][j - 1] == 1)
                    c -= 1;
        }
    }

    return c;
}