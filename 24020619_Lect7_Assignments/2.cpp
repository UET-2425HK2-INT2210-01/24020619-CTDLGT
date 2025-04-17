#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    // đọc file 
    ifstream fin;
    fin.open("matrix.txt");
    fin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> v[i][j];
        }
    }
    fin.close();
    // tọa độ của hình CN cần tìm 
    int startRow = 0, startCol = 0, endRow = 0, endCol = 0;
    int maxSum = v[0][0];
    // brute force 
    // chọn tất cả điểm bắt đầu 
    for (int rowStart = 0; rowStart < m; rowStart++) {
        for (int colStart = 0; colStart < n; colStart++) {
            // chọn tất cả điểm kết thúc có thể
            for (int rowEnd = rowStart; rowEnd < m; rowEnd++) {
                for (int colEnd = colStart; colEnd < n; colEnd++) {
                    // tính tổng
                    int sum = 0;
                    for (int i = rowStart; i <= rowEnd; i++) {
                        for (int j = colStart; j <= colEnd; j++) {
                            sum += v[i][j];
                        }
                    }
                    // cật nhật 
                    if (sum > maxSum) {
                        maxSum = sum;
                        startRow = rowStart;
                        endRow = rowEnd;
                        startCol = colStart;
                        endCol = colEnd;
                    }
                }
            }
        }
    }
    // do trong đề bài m và n chạy từ 1 còn em làm là chạy từ 0 nên em cộng thêm 1 ạ 
    startCol++;
    startRow++;
    endRow++;
    endCol++;
    // viết vào file
    ofstream fout;
    fout.open("matrix.out");
    fout << startRow << " " << startCol << " " << endRow << " " << endCol << " " << maxSum;
    
    return 0;
}