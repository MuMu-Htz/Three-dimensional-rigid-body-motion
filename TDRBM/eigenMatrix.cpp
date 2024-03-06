#include <iostream>

#include <ctime>
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

#define MATRIX_SIZE 50

int main()
{
     // 声明一个2*3的float矩阵
     Matrix<float, 2, 3> matrix_23;
     // 声明一个3*1的double向量
     Vector3d v_3d;
     // 等价于
     Matrix<float, 3, 1> vd_3d;

     // Matrix3d 实质上是 Eigen::Matrix<double, 3, 3>
     Matrix3d matrix_33 = Matrix3d::Zero(); // 初始化为零
     // 动态大小的矩阵
     Matrix<double, Dynamic, Dynamic> matrix_dynamic;
     // 等价于
     MatrixXd matrix_x;

     // 输入数据（初始化）
     matrix_23 << 1, 2, 3, 4, 5, 6;
     // 输出
     cout << "matrix 2x3 from 1 to 6: \n"
          << matrix_23 << endl;

     // 访问矩阵中的元素
     cout << "print matrix 2x3: " << endl;
     for (int i = 0; i < 2; i++)
     {
          for (int j = 0; j < 3; j++)
               cout << matrix_23(i, j) << "\t";
          cout << endl;
     }

     // 矩阵和向量相乘
     v_3d << 3, 2, 1;
     vd_3d << 4, 5, 6;

     // 不能混合两种不同类型的矩阵，像这样是错的
     // Matrix<double, 2, 1> result_wrong_type = matrix_23 * v_3d;
     // 应该显式转换
     Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
     cout << "[1,2,3;4,5,6]*[3,2,1]=" << result.transpose() << endl;

     Matrix<float, 2, 1> result2 = matrix_23 * vd_3d;
     cout << "[1,2,3;4,5,6]*[4,5,6]: " << result2.transpose() << endl;

     // 一些矩阵运算
     matrix_33 = Matrix3d::Random(); // 随机数矩阵
     cout << "random matrix: \n"
          << matrix_33 << endl;
     cout << "transpose: \n"
          << matrix_33.transpose() << endl;          // 转置
     cout << "sum: " << matrix_33.sum() << endl;     // 各元素和
     cout << "trace: " << matrix_33.trace() << endl; // 迹
     cout << "times 10: \n"
          << 10 * matrix_33 << endl; // 数乘
     cout << "inverse: \n"
          << matrix_33.inverse() << endl;                // 逆
     cout << "det: " << matrix_33.determinant() << endl; // 行列式

     // 特征值
     // 实对称矩阵可以保证对角化成功
     SelfAdjointEigenSolver<Matrix3d> eigen_solver(matrix_33.transpose() * matrix_33);
     cout << "Eigen values = \n"
          << eigen_solver.eigenvalues() << endl;
     cout << "Eigen vectors = \n"
          << eigen_solver.eigenvectors() << endl;


     return 0;
}