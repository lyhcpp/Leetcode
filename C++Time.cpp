如何获取代码运行时间
在调试中，经常需要计算某一段代码的执行时间，下面给出两种常用的方式：

第二种：使用clock()函数

#include<iostream>
#include<time.h>

int main(){
    clock_t start_time=clock();
    //被测试代码
}
clock_t end_time=clock();
cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;//输出运行时间
return 0;
} 

clock_t,clock()定义于time.h中，clock（）返回从程序运行时刻开始的时钟周期数(类型为long)CLOCKS_PER_SEC定义了每秒钟包含多少了时钟单元数，因为计算ms，所以*1000。

由上面分析可知，用clock()函数计算运行时间，表示范围一定大于GetTickCount（）函数，所以，建议使用clock()函数。


第一种：使用GetTickCount函数

#include<iostream>
#include<windows.h>

int main(){
    DWORD start_time=GetTickCount();
    //此处为被测试代码
    DWORD end_time=GetTickCount();
    cout<<"The run time is:"<<(end_time-start_time)<<"ms!"<<endl;//输出运行时间
    return 0;
} 

GetTickCount函数返回从系统运行到现在所经历的时间(类型为DWORD)，单位为ms,因为DWORD表示范围的限制，所以使用此种方法存在限制，即系统的运行时间的ms表示不能超出DWORD的表示范围。

