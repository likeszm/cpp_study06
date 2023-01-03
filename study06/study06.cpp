/*
* 名称：函数、数学库 测试
* 
* 收获：
* 1、利用引用可以不写&来传参就能达到访问指针的目的
* 2、函数参数的默认值在定义的时候写一次就够了，写具体实现的时候不要写！
* 3、生成随机数
*/

#include <iostream>

#define TYPE 0
/*
* 0:不做测试
* 1:指针传参测试
* 2:引用传参测试
*/

//#define MATH_TEST
#ifdef MATH_TEST

#include <cmath>

#endif  

//#define RAND
#ifdef RAND
#include <ctime>
#include <cstdlib>
#endif // RAND


void pointer_swap(int*, int*);
void cite_swap(int&, int&);
int max_test(int x = 0, int y = 0);

int main()
{

#if (TYPE == 1) || (TYPE == 2)        //原始数据展示
    int number_1 = 11;
    int number_2 = 12;

    std::cout << "原数据：" << std::endl;
    std::cout << "number_1 = " << number_1 << std::endl;
    std::cout << "number_2 = " << number_2 << std::endl;
#endif 



#if TYPE == 0

#elif TYPE == 1

    int* p_number_1 = &number_1;
    int* p_number_2 = &number_2;

    std::cout << std::endl << "通过指针交换数据" << std::endl;
    pointer_swap(p_number_1, p_number_2);

#elif TYPE == 2

    std::cout << std::endl << "通过指引用交换数据" << std::endl;
    cite_swap(number_1, number_2);

#elif TYPE == 3

    std::cout << "max_test(11,12) = " << max_test(11, 12) << std::endl;
    std::cout << "max_test(11) = " << max_test(11) << std::endl;
    std::cout << "max_test() = " << max_test() << std::endl;


#else
#error "TYPE" 数值非法!
#endif 


#if (TYPE == 1) || (TYPE == 2)             //交换结果展示
    std::cout << "number_1 = " << number_1 << std::endl;
    std::cout << "number_2 = " << number_2 << std::endl;
#endif 


#ifdef MATH_TEST

    std::cout << "cos(1.1) = \t" << cos(1.1) << std::endl;
    std::cout << "sin(1.1) = \t" << sin(1.1) << std::endl;
    std::cout << "tan(1.1) = \t" << tan(1.1) << std::endl;
    std::cout << "log(100.0) = \t" << log(100.0) << std::endl;
    std::cout << "pow(2.1,3.0) = \t" << pow(2.1,3.0) << std::endl;
    std::cout << "hypot(3.1,4.0)=\t" << hypot(3.1, 4.0) << std::endl;
    std::cout << "sqrt(16.1) = \t" << sqrt(16.1) << std::endl;
    std::cout << "abs(-1112) = \t" << abs(-1112) << std::endl;
    std::cout << "fabs(-1112.1) =\t" << abs(-1112.1) << std::endl;
    std::cout << "floor(1112.1) =\t" << floor(1112.1) << std::endl;

#endif


#ifdef RAND

    srand((unsigned)time(NULL));        //利用当前的系统时间设置为种子

    for (int i = 1; i <= 10; i++)
    {
        std::cout << "第" << i << "个生成的随机数为：\t " << rand() << std::endl;
    }


#endif // RAND


    std::cout << "\n测试完成\n";
    return 0;
}

void pointer_swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void cite_swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

int max_test(int x , int y )
{
    return (x > y ? x : y);
}
 