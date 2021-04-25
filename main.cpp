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
    char name[20];
    char address[30];
    char DOB[20];

public:
    void get_info()
    {
        ofstream Per_file("Personal_info.txt");
        cout<<"-#Ad_per/"<<"Name ";
        cin.getline(name, 20);

        Per_file<<name<<" ";
        cout<<"("<<"notebook"<<")~"<<"-#Ad-per/"<<"Address ";
        cin.getline(address, 30);

        Per_file<<address<<" ";
        cout<<"("<<"notebook"<<")~"<<"-#Ad-per/"<<"DOB ";
        cin>>DOB;
        cin.ignore();

        Per_file << DOB << " ";
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
            cout<<"("<<"notebook"<<")~"<<"V_info-# "<<"No info exists"<<endl;
            cout<<"("<<"notebook"<<")~"<<"V_info-# "<<"Add info Y/N"<<endl;
            cout<<"("<<"notebook"<<")~"<<"V_info-# ";
            cin>>choice;
            cin.ignore();

            if(choice=='Y' | choice=='y')
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
			string last_name;
            while(Per_file >> name >> last_name >> address>> DOB)
            {
                cout<<"Name: "<<" "<<name<<" " <<last_name<<endl;
                cout<<"Address: "<<" "<<address<<endl;
                cout<<"DOB: "<<" "<<DOB<<endl;

            }
            Per_file.close();
        }


    }
    void Delete_perinfo(){
        ifstream Del_per_file;
        Del_per_file.open("Personal_info.txt");
        if(!Del_per_file){
            cout<<"("<<"notebook"<<")~"<<"D_info-# "<<"File Doesn't Exists"<<endl;
        }
        else{
            ifstream Del_per_file;
            Del_per_file.open("Personal_info.txt");
            remove("Personal_info.txt");
            cout<<"("<<"notebook"<<")~"<<"V_info-# "<<"Information Deleted sucessfully"<<endl;
        }
        
    }

};
class Events:public Personal_info{
    protected:
        int id;
        char Event_detail[200];
        char Name[20];
        char Time[30];
    public:
        void add_event(){
            ofstream event;
            if(!event){
                event.open("Event.txt");
                cout<<"("<<"notebook"<<")~"<<"Events-# "<<"Welcome to Event section"<<endl;
                cout<<"("<<"notebook"<<")~"<<"Ad_Events/ID-# ";
                cin>>id;
                cin.ignore();
                event << id << " "<< endl;

                cout<<"("<<"notebook"<<")~"<<"Ad_Events/Time-# ";
                cin>>Time;
                cin.ignore();
                event << Time << " "<<endl;

                cout<<"("<<"notebook"<<")~"<<"Ad_Events/Name-# ";
                cin.getline(Name, 20);
                event<<Name<<" "<<endl;

                cout<<"("<<"notebook"<<")~"<<"Ad_Events/Event_detail-# ";
	            cin.getline(Event_detail, 200);
                event<<Event_detail<<" "<<endl;

                event.close();
            }else{
                event.open("Event.txt",ios::app);
                cout<<"("<<"notebook"<<")~"<<"Ad_Events/ID-# ";
                cin>>id;
                cin.ignore();
                event<<id<<" "<<endl;

                cout<<"("<<"notebook"<<")~"<<"Ad_Events/Time-# ";
                cin>>Time;
                cin.ignore();
                event<<Time<<" "<<endl;

                cout<<"("<<"notebook"<<")~"<<"Ad_Events/Name "; 
				cin.getline(Name, 20);
                event<<Name<<" "<<endl;

                cout<<"("<<"notebook"<<")~"<<"Ad_Events/Event_detail-# ";
            	cin.getline(Event_detail,200);
                event<<Event_detail<<" "<<endl;
                event.close();              

            }

        }
        void view_event(){
            char options;
            
            ifstream event;
            event.open("Event.txt");
            if(!event){
                cout<<"("<<"notebook"<<")~"<<"V_Events-# ";
                cout<<"("<<"notebook"<<")~"<<"No Events found "<<endl;
                cout<<"("<<"notebook"<<")~"<<"V_Events-# "<<"Add Events Y/N"<<endl;
                cout<<"("<<"notebook"<<")~"<<"V_Events-# ";
                
                cin>>options;
                if(options=='Y'| options=='y'){
                    add_event();
                }
                else{
                    system("clear");
                    exit(0);
                }
            }
            else{
                string Events;
                ifstream event;
                event.open("Event.txt");
                while(getline(event,Events)){
                    cout<<Events<<" "<<endl;


                }
                event.close();

            }

        }
        void Delete_Events(){
            ifstream Del_event_file;
            Del_event_file.open("Event.txt");
            if(!Del_event_file){
                cout<<"("<<"notebook"<<")~"<<"D_Event-# "<<"File Doesn't Exists"<<endl;
            }
            else{
                ifstream Del_event_file;
                Del_event_file.open("Event.txt");
                remove("Event.txt");
                cout<<"("<<"notebook"<<")~"<<"D_Event-# "<<"Information Deleted sucessfully"<<endl;
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
            if(!reminder){
                reminder.open("Reminders.txt");
                cout<<"("<<"notebook"<<")~"<<"Reminder-# "<<"Welcome to Reminder section"<<endl;
                cout<<"("<<"notebook"<<")~"<<"Ad_Reminder/Type-# ";
                cin>>Type;
                cin.ignore();
                reminder<<Type<<endl;
                cout<<"("<<"notebook"<<")~"<<"Ad_Reminder/Name-# ";
                cin.getline(name, 20);
                reminder<<name<<endl;
                cout<<"("<<"notebook"<<")~"<<"Ad_Reminder/Time-# ";
                cin>>time;
                cin.ignore();
                reminder<<time<<" "<<endl;
                reminder.close();
            }else{
                reminder.open("Reminders.txt",ios::app);
                cout<<"("<<"notebook"<<")~"<<"Ad_Reminder/Type-# ";
                cin>>Type;
                cin.ignore();
                reminder<<Type<<" ";
                cout<<"("<<"notebook"<<")~"<<"Ad_Reminder/Name ";
                cin.getline(name, 20);
                reminder<<name<<" ";
                cout<<"("<<"notebook"<<")~"<<"Ad_Reminder/Time-# ";
                cin>>time;
                cin.ignore();
                reminder<<time<<" "<<endl;
                reminder.close();              

            }
    }
    void view_Reminder(){
        char options;
        char op_name[20];
        ifstream reminder;
        reminder.open("Reminders.txt");
        if(!reminder){
            cout<<"("<<"notebook"<<")~"<<"V_Reminder-# ";
            cout<<"("<<"notebook"<<")~"<<"No Reminders found "<<endl;
            cout<<"("<<"notebook"<<")~"<<"V_Reminder-# "<<"Add Reminder Y/N"<<endl;
            cout<<"("<<"notebook"<<")~"<<"V_Reminder-# ";
            cin>>options;
            cin.ignore();
            if(options=='Y' | options=='y'){
                Add_Reminder();
            }
            else{
                system("clear");
                exit(0);
            }
        }
        else{
            while(reminder>>Type>>name>>op_name>>time){
                cout<<"Type: "<<Type<<endl;
                cout<<"Name: "<<name<<" "<<op_name<<endl;
                cout<<"Time: "<<time<<endl;
                
            }
            reminder.close();            
        }


    }
    void delete_reminders(){
            ifstream Del_rem_file;
            Del_rem_file.open("Reminders.txt");
            if(!Del_rem_file){
                cout<<"("<<"notebook"<<")~"<<"D_Reminders-# "<<"File Doesn't Exists"<<endl;
            }
            else{
                ifstream Del_rem_file;
                Del_rem_file.open("Reminders.txt");
                remove("Reminders.txt");
                cout<<"("<<"notebook"<<")~"<<"D_Reminders-# "<<"Information Deleted sucessfully"<<endl;
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
        cout<<"\t\t\t"<<"*"<<setfill('-')<<setw(4)<<"-"<<" Delete_Per_info    "<<setw(4)<<"*"<<endl;
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
        cout<<"\t\t\t"<<"V_info ---for View_personal_info"<<endl;
        cout<<"\t\t\t"<<"D_info ---for Deleting personal info"<<endl;
        cout<<"\t\t\t"<<"Ad_Events ---for Add_Events"<<endl;
        cout<<"\t\t\t"<<"V_Events ---for View events"<<endl;
        cout<<"\t\t\t"<<"D_Events ---for Delete events"<<endl;
        cout<<"\t\t\t"<<"Ad_rem ---for Add_Reminder"<<endl;
        cout<<"\t\t\t"<<"V_rem ---for View_Reminder"<<endl;
        cout<<"\t\t\t"<<"D_rem---for Delete_Reminder"<<endl;
        cout<<"\t\t\t"<<"clear/cls ---for Exit"<<endl<<endl<<endl;
        cout<<"\t\t\t"<<"Exit/exit ---for Exit"<<endl<<endl<<endl;
        cout<<"("<<"notebook"<<")~"<<"menu-# ";
        cin>>choice;
        cin.ignore();
        make_decision(choice);
    }
    void options()
    {   
        string option;
        cout<<"("<<"notebook"<<")~"<<"Next-# ";
        cin>>option;
        cin.ignore();
        if(option == "menu"){
        system("clear");
        menu();
        }else if(option=="Exit"){
        system("clear");
        exit(0);
        }
        else if(option=="help" | option=="h"){
            cout<<"("<<"notebook"<<")~"<<"help-# "<<endl;
            cout<<"\t\t\t"<<"menu --- for return in main menu"<<endl;
            cout<<"\t\t\t"<<"Ad_info ---for personal_ info "<<endl;
            cout<<"\t\t\t"<<"V_info ---for View_personal_info"<<endl;
            cout<<"\t\t\t"<<"D_info ---for Deleting personal info"<<endl;
            cout<<"\t\t\t"<<"Ad_Events ---for Add_Events"<<endl;
            cout<<"\t\t\t"<<"V_Events ---for View events"<<endl;
            cout<<"\t\t\t"<<"D_Events ---for Delete events"<<endl;
            cout<<"\t\t\t"<<"Ad_rem ---for Add_Reminder"<<endl;
            cout<<"\t\t\t"<<"V_rem ---for View_Reminder"<<endl;
            cout<<"\t\t\t"<<"D_rem---for Delete_Reminder"<<endl;
            cout<<"\t\t\t"<<"clear/cls ---for Exit"<<endl<<endl<<endl;
            cout<<"\t\t\t"<<"Exit/exit --- for exit programme"<<endl;
            options();
        }
        else if(option=="clear" | option == "cls"){
            system("clear");
            options();
        }
        else{
            make_decision(option);

        }
        

    }
    void make_decision(string choice){
        
        if(choice=="Ad_info")
        {
            get_info();
            menu();
        }
        else if(choice=="V_info")
        {
            View_info();
            options();
            

        }
        else if(choice=="D_info")
        {
            string choose;
            cout<<"("<<"notebook"<<")~"<<"D_info-# "<<"Are you sure you want to Delete Personal info ?"<<endl;
            cout<<"("<<"notebook"<<")~"<<"D_info-# ";
            cin>>choose;
            cin.ignore();

            if(choose=="y" | choose== "Y" | choose== "yes" | choose== "Yes"){
                Delete_perinfo();
                options();

            }else{
                options();
            }
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
            string choose;
            cout<<"("<<"notebook"<<")~"<<"D_EVENTS-# "<<"Are you sure you want to Delete Event ?"<<endl;
            cout<<"("<<"notebook"<<")~"<<"WARNING# "<<"This will delete/remove the Event file !!!!"<<endl;
            cout<<"("<<"notebook"<<")~"<<"D_EVENTS-# ";
            cin>>choose;
            cin.ignore();

            if(choose=="y" | choose== "Y" | choose== "yes" | choose== "Yes"){
                Delete_Events();
                options();

            }else{
                options();
            }
            
        }
        else if(choice=="Ad_rem")
        {
            Add_Reminder();
            options();
            


        }
        else if(choice=="V_rem")
        {
            view_Reminder();
            options();


        }
        else if(choice=="D_rem")
        {
          string choose;
            cout<<"("<<"notebook"<<")~"<<"D_rem-# "<<"Are you sure you want to Delete reminder ?"<<endl;
            cout<<"("<<"notebook"<<")~"<<"WARNING# "<<"This will delete/remove the Reminders file !!!!"<<endl;
            cout<<"("<<"notebook"<<")~"<<"D_rem# ";
            cin>>choose;
            cin.ignore();

            if(choose=="y" | choose== "Y" | choose== "yes" | choose== "Yes"){
                delete_reminders();
                options();

            }else{
                options();
            }


        }
        else if(choice=="clear" | choice=="cls"){
            system("clear");
            menu();
        }
        else if(choice=="Exit" | choice=="exit")
        {
            exit(0);
        }
        else
        {
            cout<<"("<<"notebook"<<")~"<<"-#\t"<<"Command Not found"<<endl;
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
    ifstream pass;
    pass.open("password.txt");
    char au_pass[30];
    while(!pass.eof()){
        pass.getline(au_pass,30);

    }
    cout<<"Login/Username-# ";
    cin>>username;
    cin.ignore();

    cout<<"("<<"notebook"<<")~"<<"Login/pwd-# ";
    cin>>password;
    cin.ignore();
    
    if(strcmp(username,"Happy")==0 && strcmp(password,au_pass)==0){
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