#include <iostream>
#include <sstream>

using namespace std;

//字符串流方法
//int countSegments(string s){
//    istringstream input(s);
//    int cnt=0;
//    string temp;
//    while (input>>temp)
//        cnt++;
//    return cnt;
//}
int countSegments(string s) {
    auto pos = s.find_first_not_of(' ');
    int cnt = 0;
    while (pos != string::npos) {
        cnt += 1;
        pos = s.find_first_not_of(' ', s.find_first_of(' ', pos));
    }
    return cnt;
}

int main() {
    //C++字符串可以直接换行拼接，只需将每段都加上双引号
    string s = "The one-hour drama series Westworld is a dark odyssey about the dawn of artificial consciousness and the "
            "evolution of sin. Set at the intersection of the near future and the reimagined past, it explores a world "
            "in which every human appetite, no matter how noble or depraved, can be indulged.";
    std::cout << countSegments(s) << std::endl;
    return 0;
}