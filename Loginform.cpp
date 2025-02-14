#include<iostream>
#include<fstream>
using namespace std;
  
  class temp{
    string username,Email,password;
    string searchName,searchPassword,searchEmail;
    fstream file;
    public:
    void login();
    void signup();
    void forgetpassword();
    void Exit();

  }obj;
int main(){
    char choice;
    cout<<"\n1-Login";
    cout<<"\n2-Sign-Up";
    cout<<"\n3-Forgot Password";
    cout<<"\n4-Exit";
    cout<<"\nEnter your Choice";
    cin>>choice;
    switch(choice){
        case '1':
        obj.login();
        break;
        case '2':
        obj.signup();
        break;

        case '3':
        break;
        obj.forgetpassword();
        case '4':
         return 0;
        break;
        default:
         cout<<"Invalid selection....!";
    }
  
}
 void temp :: signup(){
    cout<<"\n Enter your user name ::";
    getline(cin,username);
    cout<<"\n Enter your Email Address ::";
    getline(cin,Email);
    cout<<"\n Enter your Password ::";
    getline(cin,password);
    
    file.open("login.text",ios :: out| ios :: app);
    file<<username<<"*"<<Email<<"*"<<password<<endl;
    file.close();
 }
void temp :: login(){
  string searchname,searchPass;
  cout<<"-------Login---"<<endl;
  cout<<"Enter your user name::"<<endl;
  getline(cin,searchname);
   cout<<"Enter your user Password::"<<endl;
  getline(cin,searchPass);
  

  file.open("loginData.txt",ios ::in);
  getline(file,username,'*');
  getline(file,Email,'*');
  getline(file,password,'\n');
  while(!file.eof()){
     if(username==searchname){
      if(password==searchPass){
        cout<<"\n Account login successfully...!";
        cout<<"\n userName::"<<username;
        cout<<"\n Email ::"<<Email<<endl;
      } else{
      cout<<"Password is incorrect";
    }
  }
   getline(file,username,'*');
   getline(file,Email,'*');
   getline(file,password,'\n');
}
file.close();
}
void temp :: forgetpassword(){
  cout<<"Enter your userName ::";
  getline(cin,searchName);
  cout<<"\n Enter your EmailAddress";
  getline(cin,searchEmail);

  file.open("loginDate.txt", ios :: in);
  getline(file,username,'*');
   getline(file,Email,'*');
    getline(file,password,'*');
    while(!file.eof()){
    if(username==searchName){
      if(Email==searchEmail){
        cout<<"\n Account Found...!"<<endl;
        cout<<"\n your Password...!"<<password<<endl;
      }else{
        cout<<"Not fount...!\n";
      }
    } else{
      cout<<"Not found...!\n";
    }
  }
  file.close();
}
