//如何获取代码运行时间

#include<iostream>
#include<time.h>

int main(){
    clock_t start_time=clock();
    //被测试代码
    clock_t end_time=clock();
    cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;//输出运行时间
    return 0;
} 

//clock_t,clock()定义于time.h中，clock（）返回从程序运行时刻开始的时钟周期数(类型为long)
//CLOCKS_PER_SEC定义了每秒钟包含多少了时钟单元数，因为计算ms，所以*1000
