//A*B
#include <iostream>
#include <vector>



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




int main() {
    std::vector<std::vector<long double>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::vector<std::vector<long double>> B = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    if(checking(A,B) == 0){
        std::cout << "Cant be multiplied";
    }
    else{std::cout << "Done";}
    return 0;
}
