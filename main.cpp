#include <iostream>
#include <vector>
#include<time.h>
#include<string>
#include <windows.h>
void print_vec(std::vector<int>&the_list,int inc,HANDLE hConsole){
    int counter=0;
 for(int i:the_list){
        std::string amount(i,'#');
        std::cout<<amount<<std::endl;
        counter+=1;
        if(counter==inc){
            SetConsoleTextAttribute(hConsole, 34);
        }
    }
}
void bubble_sort(std::vector<int>&the_list){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout<<std::string(50,'\n');
    int inc=20;
    bool swapped = true;
        while(swapped)
        {
            swapped = false;
            for (int i = 0; i < the_list.size()-1; i++)
            {
                if (the_list[i]>the_list[i+1] )
                {
                    the_list[i] += the_list[i+1];
                    the_list[i+1] = the_list[i] - the_list[i+1];
                    the_list[i] -=the_list[i+1];
                    swapped = true;
                }
            }
            inc-=1;
            SetConsoleTextAttribute(hConsole, 255);
            print_vec(the_list,inc,hConsole);
            SetConsoleTextAttribute(hConsole, 7);
            do{std::cout<<'\n' << "press enter to continue...";} while (std::cin.get() != '\n');
            std::cout<<std::string(50,'\n');
        }
    SetConsoleTextAttribute(hConsole, 34);
    print_vec(the_list,0,hConsole);
    SetConsoleTextAttribute(hConsole, 7);
    std::cout<<"Sort Finished"<<std::endl;
}
int main()
{
    std::vector<int> the_list;
    srand(time(0));
    for(int i=0;i<20;i++){
        int rand_num = rand() % 100+10;
        the_list.push_back(rand_num);
    }
    std::cout<<"A random graph shall now be produced."<<std::endl;
    do{std::cout<<'\n' << "Beginning bubble sort, press enter to continue...";} while (std::cin.get() != '\n');
    bubble_sort(the_list);
}
