//A*B
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>



std::vector<std::vector<long double>> Multiply(const std::vector<std::vector<long double>>A , const std::vector<std::vector<long double>>B){

    std::vector<std::vector<long double>> Answer(A.size(), std::vector<long double>(B[0].size(), 0.0L));

    int ARows = A.size();
    int ACols = A[0].size();
    int BRows = B.size();
    int BCols = B[0].size();
    for (int i = 0; i < ARows; ++i) {
        for (int j = 0; j < BCols; ++j) {
            for (int k = 0; k < ACols; ++k) {
                Answer[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return Answer;
}




int checking(std::vector<std::vector<long double>> A, std::vector<std::vector<long double>> B) {

    int ACols = A[0].size();
    int BRows = B.size();
    if(ACols != BRows){
        return 0;
    }
    std::vector<std::vector<long double>> Answer = Multiply(A,B);
    for (const auto& row : Answer) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    return 1;
}



std::vector<std::vector<long double>> readMatrixFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file '" << filename << "'" << std::endl;
        return {};
    }

    std::vector<std::vector<long double>> matrix;
    std::string line;
    while (std::getline(file, line) && !line.empty()) {
        std::vector<long double> row;
        std::istringstream iss(line);
        int value;
        while (iss >> value) {
            row.push_back(value);
        }
        matrix.push_back(row);
    }

    return matrix;
}


int main() {
    std::vector<std::vector<long double>> A = readMatrixFromFile("a.txt");
    std::vector<std::vector<long double>> B = readMatrixFromFile("b.txt");

    if(checking(A,B) == 0){
        std::cout << "Cant be multiplied";
    }
    else{std::cout << "Done";}
    return 0;
}

