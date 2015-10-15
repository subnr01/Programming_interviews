// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            return;
        }
        bool has_zero = false;
        int zero_i = -1;
        int zero_j = -1;

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    if (!has_zero) {
                        zero_i = i;
                        zero_j = j;
                        has_zero = true;
                    }
                    matrix[zero_i][j] = 0;
                    matrix[i][zero_j] = 0;
                }
            }
        }

        if (has_zero) {
            for (int i = 0; i < matrix.size(); ++i) {
                if (i == zero_i) {
                    continue;
                }
                for (int j = 0; j < matrix[0].size(); ++j) {
                    if (j == zero_j) {
                        continue;
                    }
                    if (matrix[zero_i][j] == 0 || matrix[i][zero_j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][zero_j] = 0;
            }
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[zero_i][j] = 0;
            }
        }

    }
};
