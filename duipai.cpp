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
    cout<<"��ӭ������������\n";
    cout<<"1:������ʽ����\n";
    cout<<"2:������Ϣ\n";
    cout<<"3:�������Ȩ��Ϣ\n";
    cout<<"4:�˳�\n";
    cout<<"�������ּ�ѡ��:";
    cin>>ch;
    return ch;
}

bool detect_file(string filename){
    filename=ostype=='L'?"ls "+filename:"dir "+filename+".exe";
    filename+=" > tmp1";
    return system(filename.c_str());
}

void Error_file(){
    cout<<"�ļ������ڡ�\n"<<"���������롣\n";
    return;
}

void detect_OS_type(){
    cout<<"���ϵͳ������......"<<endl;
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
    printf("����������ĵĳ������ƣ�������չ�������磺problem����");
    getline(cin,sour);
    if(detect_file(sour)!=0){
        Error_file();
    }
    printf("�������׼�������ƣ��磺std����");
    getline(cin,st);
    if(detect_file(st)!=0){
        Error_file();
    }
    printf("����������������������ƣ��磺rand����");
    getline(cin,ran);
    if(detect_file(ran)!=0){
        Error_file();
    }
    printf("��������Ĵ�����");
    cin>>cnt;
    for(int i=1;i<=cnt;i++){
        clear_screen();
        printf("���Ե�#%d:\n",i);
        printf("��������...\n");
        sleep(0.2);
        sys="./"+ran+" > tmp.in";
        system(sys.c_str());
        sys="./"+st+" < tmp.in > tmp.ans";
        system(sys.c_str());
        sys="./"+sour+" < tmp.in > tmp.out";
        system(sys.c_str());
        printf("������...\n");
        sleep(0.2);
        if(!compare()){
            cout<<"ͨ���˲��Ե㣬OK\n";
            sleep(0.2);
        }
        else{
            cout<<"δͨ���˲��Ե�\n����Դ����\n";
            cout<<"���������ѱ�����tmp.in������Խ�����ݵ��Գ���\n";
            cout<<"3��󷵻����˵���\n";
            sleep(3.0);
            return;
        }
    }
    clear_screen();
    cout<<"ȫ��ͨ�������Ľ�����\n";
    cout<<"3��󷵻����˵���\n";
    sleep(3.0);
    return;
}

void print_help(){
    clear_screen();
    cout<<"1.ʲô�Ƕ��ģ�\n"\
        <<"���ľ��ǽ�һ���Լ���д��Դ�������׼������бȽϵĹ��̡�\n"\
        <<"�ںܶ�ʱ�򣬶��Ŀ�����Ч�ļ�����Ĵ��󣬲����в������ݷ�����ԡ�\n"\
        <<"���ԣ������ǵ��Թ��̵���Ҫһ����\n"\
        <<"2.���ĵ�ԭ��\n"\
        <<"����ͨ�����������������������ݣ�Ȼ��ͨ����׼�����֪��׼����ļ���Ҳ���Ǵ𰸣��������������ĵ��Լ��ĳ��������Լ�������ļ�\n"\
        <<"���ţ��Ƚ����ߵ�����ļ�������һ���������ҳ��Լ�����Ĵ���ͬʱ���в������ݣ�������ԡ�\n"\
        <<"���ĵ�ԭ�������Щ��\n"\
        <<"3.���ĵļ���?\n"\
        <<"(1)������������������趨Ϊ����Сһ������ݣ��������\n"\
        <<"(2)��׼����Խ��Խ�ã����ع����עʱ�临�Ӷȣ���һ��Ҫ��֤��ȷ��\n"\
        <<"(3)����ʹ�ñ�������׼������Ϊ�����Ƚ����״�ԣ�������ʵ�֣�\n"\
        <<"3.���ʹ�ñ�����\n"\
        <<"���ȣ���׼�����������Լ�д�Ĵ���Ŀ�ִ�г��򣨼�.exe�Ǹ�������׼����Ŀ�ִ�г��򣬼�������ݵ����ɳ���\n"\
        <<"Ȼ�����б����򣬰���ָ�����ɡ�\n";
    cout<<"��0����..."<<endl;
    while(getchar()!='0');
    return;
}

void print_copy(){
    clear_screen();
    cout<<"������ 0.8 Beta\n";
    cout<<"Author:zhs\n";
    cout<<"����Ⱥ�ڲ����á�\n";
    cout<<"Github��Ŀ��ַ:https://github.com/AcceptedZhs/Multi-System-Duipai\n";
    cout<<"��л֧�֣�"<<endl;
    cout<<"��0����..."<<endl;
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
            cout<<"��������������롣\n";
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