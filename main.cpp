#include<iostream>
#include<time.h>
#include<cstring>
#include<iomanip>
#include<unistd.h>
#include<fstream>
#include<ncurses.h>
using namespace std;


class Personal_info
{
protected:
    char name[20]={'\0'};
    char address[30];
    char DOB[20];

public:
    void get_info()
    {
        ofstream Per_file("Personal_info.txt");
        cout<<"-#Ad_per/"<<"Name ";
        cin>>name;
        Per_file<<name<<" ";
        cout<<"("<<name<<"notebook"<<")~"<<"-#Ad-per/"<<"Address ";
        cin>>address;
        Per_file<<address<<" ";
        cout<<"("<<name<<"notebook"<<")~"<<"-#Ad-per/"<<"DOB ";
        cin>>DOB;
        Per_file<<DOB<<" ";
        Per_file.close();
        cout<<endl;
        cout<<"Information added sucessfully"<<endl;
        sleep(2);
        system("clear");
    }
    void View_info()
    {
        ifstream Per_file;
        char choice;
        Per_file.open("Personal_info.txt");
        if(!Per_file)
        {
            cout<<"("<<name<<"notebook"<<")~"<<"V_info-# "<<"No info exists"<<endl;
            cout<<"("<<name<<"notebook"<<")~"<<"V_info-# "<<"Add info Y/N"<<endl;
            cout<<"("<<name<<"notebook"<<")~"<<"V_info-# ";
            cin>>choice;
            if(choice=='Y')
            {
                get_info();
            }
            else
            {
                system("clear");
                exit(0);
            }
        }
        else
        {
            string info;
            while(Per_file >> name >> address>> DOB)
            {
                cout<<"Name: "<<" "<<name<<endl;
                cout<<"Address: "<<" "<<address<<endl;
                cout<<"DOB "<<" "<<DOB<<endl;

            }
            Per_file.close();
        }


    }

};
class Events:public Personal_info{
    protected:
        int id;
        string Event_detail;
        char Name[20];
        char Time[30];
    public:
        void add_event(){
            ofstream event;

            if(!event){
                event.open("Event.txt");
                cout<<"("<<name<<"notebook"<<")~"<<"Events-# "<<"Welcome to Event section"<<endl;
                cout<<"("<<name<<"notebook"<<")~"<<"Ad_Events/ID-# ";
                cin>>id;
                event<<id<<" ";
                cout<<"("<<name<<"notebook"<<")~"<<"Ad_Events/Time-# ";
                cin>>Time;
                event<<Time<<" "<<endl;
                cout<<"("<<name<<"notebook"<<")~"<<"Ad_Events/Name-# ";
                cin>>Name;
                cin.ignore();
                event<<Name;
                cin.ignore();
                cout<<"("<<name<<"notebook"<<")~"<<"Ad_Events/Type-# ";
                cin>>Event_detail;
                cin.ignore();
                event<<Event_detail<<" ";
                cin.ignore();

                event.close();
            }else{
                event.open("Event.txt",ios::app);
                cout<<"("<<name<<"notebook"<<")~"<<"Ad_Events/ID-# ";
                cin>>id;
                event<<id<<" ";
                cout<<"("<<name<<"notebook"<<")~"<<"Ad_Events/Time-# ";
                cin>>Time;
                event<<Time<<" "<<endl;
                cout<<"("<<name<<"notebook"<<")~"<<"Ad_Events/Name ";
                cin>>Name;
                event<<Name<<" ";
                cout<<"("<<name<<"notebook"<<")~"<<"Ad_Events/Event_detail-# ";
                cin>>Event_detail;
                event<<Event_detail<<" ";
                event.close();              

            }

        }
        void view_event(){
            char options;
            
            ifstream event;
            event.open("Event.txt");
            if(!event){
                cout<<"("<<name<<"notebook"<<")~"<<"V_Events-# ";
                cout<<"("<<name<<"notebook"<<")~"<<"No Events found "<<endl;
                cout<<"("<<name<<"notebook"<<")~"<<"V_Events-# "<<"Add Events Y/N"<<endl;
                cout<<"("<<name<<"notebook"<<")~"<<"V_Events-# ";
                cin>>options;
                if(options=='Y'){
                    add_event();
                }
                else{
                    system("clear");
                    exit(0);
                }
            }
            else{
                string events;
                ifstream event;
                event.open("Event.txt");
                while(event>>id>>Time>>Name>>Event_detail){
                    cout<<"ID :"<<" "<<id<<endl;
                    cout<<"Time :"<<" "<<Time<<endl;
                    cout<<"Name :"<<" "<<Name<<endl;
                    cout<<"Event_Details:"<<endl<<Event_detail<<endl;
                }
                event.close();

            }

        }
        void Delete_Events(){
            int find;
            string all_event;
            cout<<"("<<name<<"notebook"<<")~Delete_Event -# "<<"Date of the event"<<endl;
            cout<<"("<<name<<"notebook"<<")~Delete_Event -# ";
            cin>>id;
            ifstream event;
            ofstream newevent;
            newevent.open("new_Event.txt");
            event.open("Event.txt");
            if(!event){
                cout<<"("<<name<<"notebook"<<")~Delete_Event -#"<<"File not found"<<endl;
            }else{
                ofstream newevent;
                newevent.open("new_Event.txt");
                ifstream event;
                event.open("Event.txt");
                while(event >> id >> Time >> Event_detail >> name){
                    if(find==id){
                        newevent<<all_event<<endl;
                    }
                }
                event.close();
                newevent.close();
                cout<<"("<<name<<"notebook"<<")~Delete_Event -# "<<"Event deleted sucessfully"<<endl;
                remove("Event.txt");
                // rename("new_Event.txt","Event.txt");
            }

        }
        




};
class Reminder{
    protected:
    char Type[30];
    char name[20];
    char time[40];

    void Add_Reminder(){
        ofstream reminder;
        reminder.open("Reminders.txt");

            if(!reminder){
                reminder.open("Reminders.txt");
                cout<<"("<<"notebook"<<")~"<<"Reminder-# "<<"Welcome to Reminder section"<<endl;
                cout<<"("<<"notebook"<<")~"<<"Ad_Reminder/Type-# ";
                cin>>Type;
                reminder<<"Type "<<Type<<" ";
                cout<<"("<<"notebook"<<")~"<<"Ad_Reminder/Name-# ";
                cin>>name;
                reminder<<"Name "<<name;
                cout<<"("<<"notebook"<<")~"<<"Ad_Reminder/Time-# ";
                cin>>time;
                reminder<<"Time "<<time<<" "<<endl;
                reminder.close();
            }else{
                reminder.open("Event.txt",ios::app);
                cout<<"("<<"notebook"<<")~"<<"Ad_Reminder/Type-# ";
                cin>>Type;
                reminder<<"Type "<<Type<<" ";
                cout<<"("<<"notebook"<<")~"<<"Ad_Reminder/Name ";
                cin>>name;
                reminder<<"Name "<<name<<" ";
                cout<<"("<<"notebook"<<")~"<<"Ad_Reminder/Time-# ";
                cin>>time;
                reminder<<"Time "<<time<<" "<<endl;
                reminder.close();              

            }
    }
    void view_Reminder(){
        char options;
        ifstream reminder;
        reminder.open("Reminder.txt");
        if(!reminder){
            cout<<"("<<name<<"notebook"<<")~"<<"V_Reminder-# ";
            cout<<"("<<name<<"notebook"<<")~"<<"No Reminders found "<<endl;
            cout<<"("<<name<<"notebook"<<")~"<<"V_Reminder-# "<<"Add Reminder Y/N"<<endl;
            cout<<"("<<name<<"notebook"<<")~"<<"V_Reminder-# ";
            cin>>options;
            if(options='Y'){
                Add_Reminder();
            }
            else{
                system("clear");
                exit(0);
            }
        }
        else{
            string reminders;
            // ifstream event;
            // event.open("Event.txt");
            while(getline(reminder,reminders)){
                cout<<reminders<<endl;
            }
            reminder.close();            
            
        }


    }
    void delete_reminders(){
            char date[30];
            string all_reminders;
            cout<<"("<<name<<"notebook"<<")~Delete_Reminder -# "<<"Date of the Reminder"<<endl;
            cout<<"("<<name<<"notebook"<<")~Delete_Reminder -# ";
            cin>>date;
            ifstream reminder;
            ofstream newrem;
            newrem.open("new_rem.txt");
            reminder.open("Reminder.txt");
            if(!reminder){
                cout<<"("<<name<<"notebook"<<")~Delete_Reminder -#"<<"File not found"<<endl;
            }else{         
                ofstream newrem;
                newrem.open("new_rem.txt");
                ifstream reminder;
                reminder.open("Reminder.txt");
                while(getline(reminder,all_reminders)){
                    if(all_reminders!=date){
                        newrem<<all_reminders<<endl;
                    }
                }
                reminder.close();
                newrem.close();
                cout<<"("<<name<<"notebook"<<")~Delete_Reminder -# "<<"Reminder deleted sucessfully"<<endl;
                remove("Reminder.txt");
                rename("new_rem.txt","Reminder.txt");
            }

    }



};

class Choose:public Events,public Reminder
{
public:
    string choice;

    void menu()
    {

        cout<<"\t\t\t"<<setfill('*')<<setw(11)<<"*"<<" Menu "<<setfill('*')<<setw(12)<<"*"<<endl;
        cout<<"\t\t\t"<<setfill('-')<<setw(29)<<"-"<<endl;
        cout<<"\t\t\t"<<"*"<<setfill('-')<<setw(4)<<"-"<<" Add_Personal_info  "<<setw(4)<<"*"<<endl;
        cout<<"\t\t\t"<<"*"<<setfill('-')<<setw(4)<<"-"<<" View_Personal_info "<<setw(4)<<"*"<<endl;
        cout<<"\t\t\t"<<"*"<<setfill('-')<<setw(4)<<"-"<<"    Add_Reminder    "<<setw(4)<<"*"<<endl;
        cout<<"\t\t\t"<<"*"<<setfill('-')<<setw(4)<<"-"<<"   View_Reminder    "<<setw(4)<<"*"<<endl;
        cout<<"\t\t\t"<<"*"<<setfill('-')<<setw(4)<<"-"<<"  Delete_Reminder   "<<setw(4)<<"*"<<endl;
        cout<<"\t\t\t"<<"*"<<setfill('-')<<setw(4)<<"-"<<"    Add_Events      "<<setw(4)<<"*"<<endl;
        cout<<"\t\t\t"<<"*"<<setfill('-')<<setw(4)<<"-"<<"    View_Events     "<<setw(4)<<"*"<<endl;
        cout<<"\t\t\t"<<"*"<<setfill('-')<<setw(4)<<"-"<<"    Delete_Events   "<<setw(4)<<"*"<<endl;
        cout<<"\t\t\t"<<"*"<<setfill('-')<<setw(4)<<"-"<<"       Exit         "<<setw(4)<<"*"<<endl;
        cout<<"\t\t\t"<<setfill('-')<<setw(29)<<"-"<<endl<<endl<<endl;

        cout<<"\t\t\t"<<"Guide for using Digital notebook"<<endl;
        cout<<"\t\t\t"<<"Ad_info ---for personal_ info "<<endl;
        cout<<"\t\t\t"<<"V_per ---for View_personal_info"<<endl;
        cout<<"\t\t\t"<<"Ad_Events ---for Add_Events"<<endl;
        cout<<"\t\t\t"<<"V_Events ---for View events"<<endl;
        cout<<"\t\t\t"<<"D_Events ---for Delete events"<<endl;
        cout<<"\t\t\t"<<"Ad_Special ---for Add_Reminder"<<endl;
        cout<<"\t\t\t"<<"V_Reminder ---for View_Reminder"<<endl;
        cout<<"\t\t\t"<<"D_Reminder---for Delete_Reminder"<<endl;
        cout<<"\t\t\t"<<"Exit ---for Exit"<<endl<<endl<<endl;
        cout<<"("<<"notebook"<<")~"<<"menu-# ";
        cin>>choice;
        make_decision();
    }
    void options()
    {   
        string option;
        cout<<"("<<"notebook"<<")~"<<"Next-# ";
        cin>>option;
        if(option == "menu"){
        system("clear");
        menu();
        }else if(option=="Exit"){
        system("clear");
        exit(0);
        }else if(option=="help"){
            cout<<"("<<"notebook"<<")~"<<"help-# "<<endl;
            cout<<"\t\t\t"<<"menu --- for return in main menu"<<endl;
            cout<<"\t\t\t"<<"Exit --- for exit programme"<<endl;
            options();
        }else{
        cout<<"("<<"notebook"<<")~"<<"Next-# "<<"command not found"<<endl;
        system("echo '\a' ");
        options();
        }
        

    }
    void make_decision(){
        
        if(choice=="Ad_info")
        {
            get_info();
            options();
        }
        else if(choice=="V_info")
        {
            View_info();
            options();
            

        }
        else if(choice =="Ad_Events")
        {
            add_event();
            options();
            


        }
        else if(choice=="V_Events")
        {
            view_event();
            options();



        }
        else if(choice=="D_Events")
        {
            Delete_Events();
            options();


        }
        else if(choice=="Ad_Reminder")
        {
            


        }
        else if(choice=="V_Reminder")
        {
            exit(0);


        }
        else if(choice=="E_Reminder")
        {
            exit(0);


        }
        else if(choice=="Exit")
        {
            exit(0);
        }
        else
        {
            cout<<"("<<"notebook"<<")~"<<"-#\t"<<"Invalid choice"<<endl;
            sleep(2);
            system("clear");
            menu();
        }

    }



};
class Logins:public Choose{
    protected:
    char username[30];
    char password[30]; 
    public:
        void View();
        void username_Au();
};
void Logins::View(){
    cout<<endl<<"\t\t\t"<<setfill('-')<<setw(30)<<"-"<<endl;
    cout<<"\t\t\t"<<"-"<<"                            "<<"-"<<endl;
    cout<<"\t\t\t"<<"-"<<"             Login          "<<"-"<<endl;
    cout<<"\t\t\t"<<"-"<<"                            "<<"-"<<endl;
    cout<<"\t\t\t"<<setfill('-')<<setw(30)<<"-"<<endl<<endl;
    username_Au();
}
void Logins::username_Au(){
    cout<<"Login/Username-# ";
    cin>>username;
    cout<<"("<<"notebook"<<")~"<<"Login/pwd-# ";
    cin>>password;
    if(strcmp(username,"Happy")==0 && strcmp(password,"noteb@ok")==0){
        cout<<endl<<endl<<endl;
        cout<<"\t\t\t"<<"                AUTHENTICATING.................."<<endl;
        sleep(2);
        system("clear");
        cout<<" \n \n \n \n \n";
        cout<<"\t\t\t"<<"                PLEASE WAIT # # # #"<<endl;
        sleep(2);
        system("clear");
        cout<<" \n\n\n\n\n\n ";
        cout<<"\t\t\t"<<"                ## ACCESS GRANTED ##"<<endl;
        sleep(2);
        system("clear");
        menu();


    }else{
        system("clear");
        cout<<"("<<"notebook"<<")~"<<"Login/-# "<<"invalid username or password"<<endl<<endl;
        View();
    }
    



}



int main()
{
    Logins l;
    l.View();
    l.username_Au();


}
