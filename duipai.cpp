#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<sstream>
using namespace std;
string st,sour,ran,sys;
char ostype;
int cnt;
void sleep(double sec){
    for(int i=1;i<=sec*400000000;i++);
    return;
}

void clear_screen(){
    system(ostype=='L'?"clear":"cls");
}

int compare(){
    return system(ostype=='L'?"diff tmp.out tmp.ans > /dev/null":"fc tmp.out tmp.ans ? null");
}

char print_menu(){
    char ch;
    cout<<"欢迎来到对拍器！\n";
    cout<<"1:进入正式对拍\n";
    cout<<"2:帮助信息\n";
    cout<<"3:关于与版权信息\n";
    cout<<"4:退出\n";
    cout<<"输入数字键选择:";
    cin>>ch;
    return ch;
}

bool detect_file(string filename){
    filename=ostype=='L'?"ls "+filename:"dir "+filename+".exe";
    filename+=" > tmp1";
    return system(filename.c_str());
}

void Error_file(){
    cout<<"文件不存在。\n"<<"请重新输入。\n";
    return;
}

void detect_OS_type(){
    cout<<"检测系统类型中......"<<endl;
    sleep(0.8);
    if(!system("ls > tmp")){
        ostype='L';
        cout<<"Linux\n";
    }
    else{
        ostype='W';
        cout<<"Windows\n";
        system("@echo off");
    }
    sleep(1);
}

void duipai(){
    getchar();
    sleep(1);
    clear_screen();
    printf("请输入需对拍的程序名称（无须扩展名）（如：problem）：");
    getline(cin,sour);
    if(detect_file(sour)!=0){
        Error_file();
    }
    printf("请输入标准程序名称（如：std）：");
    getline(cin,st);
    if(detect_file(st)!=0){
        Error_file();
    }
    printf("请输入随机数产生程序名称（如：rand）：");
    getline(cin,ran);
    if(detect_file(ran)!=0){
        Error_file();
    }
    printf("请输入对拍次数：");
    cin>>cnt;
    for(int i=1;i<=cnt;i++){
        clear_screen();
        printf("测试点#%d:\n",i);
        printf("生成数据...\n");
        sleep(0.2);
        sys="./"+ran+" > tmp.in";
        system(sys.c_str());
        sys="./"+st+" < tmp.in > tmp.ans";
        system(sys.c_str());
        sys="./"+sour+" < tmp.in > tmp.out";
        system(sys.c_str());
        printf("测评中...\n");
        sleep(0.2);
        if(!compare()){
            cout<<"通过此测试点，OK\n";
            sleep(0.2);
        }
        else{
            cout<<"未通过此测试点\n请检查源程序！\n";
            cout<<"测试数据已保存至tmp.in。你可以借此数据调试程序。\n";
            cout<<"3秒后返回主菜单。\n";
            sleep(3.0);
            return;
        }
    }
    clear_screen();
    cout<<"全部通过！对拍结束。\n";
    cout<<"3秒后返回主菜单。\n";
    sleep(3.0);
    return;
}

void print_help(){
    clear_screen();
    cout<<"1.什么是对拍？\n"\
        <<"对拍就是将一份自己编写的源程序与标准程序进行比较的过程。\n"\
        <<"在很多时候，对拍可以有效的检测程序的错误，并留有测试数据方便调试。\n"\
        <<"所以，对拍是调试过程的重要一环。\n"\
        <<"2.对拍的原理？\n"\
        <<"对拍通过随机数生成器生成随机数据，然后通过标准程序获知标准输出文件（也就是答案），最后运行需对拍的自己的程序生成自己的输出文件\n"\
        <<"接着，比较两者的输出文件，若不一样，即可找出自己程序的错误，同时留有测试数据，方便调试。\n"\
        <<"对拍的原理就是这些。\n"\
        <<"3.对拍的技巧?\n"\
        <<"(1)随机数生成器精良先设定为生成小一点的数据，方便调试\n"\
        <<"(2)标准程序越简单越好，不必过多关注时间复杂度，但一定要保证正确性\n"\
        <<"(3)可以使用暴力当标准程序（因为暴力比较容易打对，且容易实现）\n"\
        <<"3.如何使用本程序？\n"\
        <<"首先，请准备三个程序：自己写的代码的可执行程序（即.exe那个），标准代码的可执行程序，及随机数据的生成程序\n"\
        <<"然后，运行本程序，按照指引即可。\n";
    cout<<"按0返回..."<<endl;
    while(getchar()!='0');
    return;
}

void print_copy(){
    clear_screen();
    cout<<"对拍器 0.8 Beta\n";
    cout<<"Author:zhs\n";
    cout<<"仅供群内测试用。\n";
    cout<<"Github项目地址:https://github.com/AcceptedZhs/Multi-System-Duipai\n";
    cout<<"感谢支持！"<<endl;
    cout<<"按0返回..."<<endl;
    while(getchar()!='0');
    return;
}

void work(){
    clear_screen();
    int choose=print_menu()-'0';
    switch(choose){
        case 1:{
            duipai();
            break;
        }
        case 2:{
            print_help();
            break;
        }
        case 3:{
            print_copy();
            break;
        }
        case 4:{
            exit(0);
            break;
        }
        default:{
            cout<<"输入错误！重新输入。\n";
            work();
        }
    }
    return;
}

int main(){
    detect_OS_type();
    while(1){
        work();
    }
    return 0;
}