#include <iostream>
#include <vector>
#include <cassert>
#include <limits.h>
#include <limits>


int main() {
    std::vector<int> a(5);
    int num=0; 
    bool firstFiveFilled=false;
    int firstFive=0;
    int maxFive=0;
    while (num!=-2) {
        std::cout<<"Введите число: ";
        std::cin>>num;
        if (std::cin.fail()) {
            std::cout<<"Wrong num, wb rounded"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        //first Five
        } else if (!firstFiveFilled) {
            //five elements filling
            if (num==-1 || num==-2) {
                std::cout<<"First five numbers are not filled yet\n";
            } else {
                a[firstFive]=num;
                firstFive++;
            }
            //five elements filling
            if (firstFive==5) {
                firstFiveFilled=true;
                maxFive=std::max(std::max(std::max(a[0],a[1]),std::max(a[2],a[3])),a[4]);
                std::cout<<"First five filled\n";
            }          
        }
        //first Five
        else if (num==-1) {
            std::cout<<"Max fifth: "<<maxFive<<std::endl;
            std::cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<"\n";
        }
        else {
            if (num<maxFive) {
                bool found =false;
                for (int i=0;i<5 && !found;i++) {
                    if (a[i]==maxFive && !found) {
                        a[i]=num;
                        found=true;
                    }
                }
                maxFive=std::max(std::max(std::max(a[0],a[1]),std::max(a[2],a[3])),a[4]);
            }
        }
    }

    
}