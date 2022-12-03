#include<iostream>
#include<string.h>
using namespace std;
#define max 100

int counts=0;
class Customer{
    public:
    string name;
    int age;
    string phoneNo;
    string addr;
    int custId;
};
class Flight
{
    public:
    int planeId;
    string date;
    string dest;
    string start;
    int countCust;
    int seats;
    Customer cust[max]; 
    Flight addFlight(int);  
    void searchFlight(int);
    void displayFlight(Flight);  
};
Flight flights[max];
Flight Flight::addFlight(int fno)
{
    Flight fl;
    fl.planeId=fno;
    cout<<"Add Date"<<endl;
    cin>>fl.date;
    cout<<endl<<"Add destination"<<endl;
    cin>>fl.dest;
    cout<<endl<<"Add start point"<<endl;
    cin>>fl.start;
    cout<<"Flight added Successfully";
    fl.seats=100;
    fl.countCust=0;
    return fl;
}
void Flight::searchFlight(int fno)
{
    int found=0;
    int ct=0;
    for(int i=0;i<counts;i++)
    {
        if(flights[i].planeId==fno)
        {
            ct=i;
            found=1;
            break;
        }
    }
    if(found==0)
    {
        cout<<endl<<"Flight Not Found"<<endl;
        return;
    }
    else{
        cout<<"Flight Details :"<<endl;
        cout<<"Plane id : "<<fno;
        cout<<"Destination : "<<flights[ct].dest;
        cout<<"Start Point : "<<flights[ct].start;
        cout<<"Date : "<<flights[ct].seats;
        cout<<"Seats Available : "<<flights[ct].seats;
    }

}
void Flight::displayFlight(Flight tempfl)
{

        cout<<"Plane id : "<<tempfl.planeId<<endl;
        cout<<"Destination : "<<tempfl.dest<<endl;
        cout<<"Start Point : "<<tempfl.start<<endl;
        cout<<"Date : "<<tempfl.date<<endl;
        cout<<"Seats Available : "<<tempfl.seats<<endl;
}
class FlightManagementSystem : protected Flight{
    public:
    void bookfl();  
    void getAvailFlight();  
    void searchCustomer(string);  
    void guestSummaryReport();  
};
void FlightManagementSystem::guestSummaryReport()  
{  
  
    if (counts == 0)  
    {  
        cout << "\n No Flight booked overall!!";  
    }  
    for (int i = 0; i < counts; i++)  
    {  
        cout<<"\nFor Plane Id :"<<flights[i].planeId<<endl;
        if (flights[i].seats !=100)  
        {  
            for(int j=0;j<flights[i].countCust;j++)
            {
            cout << "\n Customer First Name : " << flights[i].cust[j].name;  
            cout << "\n Plane Id : " << flights[i].planeId;  
            cout << "\n Address (only city) : " << flights[i].cust[j].addr;  
            cout << "\n Phone : " << flights[i].cust[j].phoneNo;  
            cout << "\n---------------------------------------";  
            }  
        }
        else{
            cout<<"\nFlight empty !\n";
        }
    }  
}
void FlightManagementSystem::bookfl()
{
    int i=0,found=0,fno;
    cout<<"Enter Flight Number : "<<endl;
    cin>>fno;
    for(i=0;i<counts;i++)
    {
        if(flights[i].planeId==fno)
        {
            found=1;
            break;
        }
    }
    if(found==0)
    {
        cout<<"\nNo Flight Found!!!"<<endl;
        return;
    }
    else
    {
        cout<<"Enter Details here"<<endl;
        flights[i].cust[flights[i].countCust].custId=flights[i].countCust+1;
        cout<<"Enter Your Name :"<<endl;
        cin>>flights[i].cust[flights[i].countCust].name;
        cout<<"\nEnter Your age :"<<endl;
        cin>>flights[i].cust[flights[i].countCust].age;
        cout<<"\nEnter Your phoneNo :"<<endl;
        cin>>flights[i].cust[flights[i].countCust].phoneNo;
        cout<<"\nEnter Your address :"<<endl;
        cin>>flights[i].cust[flights[i].countCust].addr;
        flights[i].countCust++;
        cout<<"\nCustomer Added!!!";
        flights[i].seats--;
    }
}
void FlightManagementSystem::searchCustomer(string names)
{
    int found=0,i;
    int j=0;
    for(i=0;i<counts;i++)
    {
        if(flights[i].seats!=100)
        {
            while(j<flights[i].countCust)
            {
                if(flights[i].cust[j].name==names)
                {
                    cout<<"\nCustomer Found!!\n";
                    cout<<"\nCustomer Name :"<<flights[i].cust[j].name;
                    cout<<"\nPlane Id :"<<flights[i].planeId;
                    cout<<endl;
                    found=1;
                    break;
                }
            }
        }
    }
    if(found==0) cout<<"Not Found";
}
void FlightManagementSystem::getAvailFlight()  
{  
    int i, found = 0;  
    for (i = 0; i < counts; i++)  
    {  
        if (flights[i].seats != 0)  
        {  
            displayFlight(flights[i]);
            found = 1;  
        }  
    }  
    if (found == 0)  
    {  
        cout << "\nAll flights are reserved"; 
    }  
}  
void manageFlights()  
{  
    Flight fli;  
    int opt, rno, i, flag = 0;  
    char ch;  
    do  
    {
        cout << "\n### Manage Flights ###";  
        cout << "\n1. Add flight";  
        cout << "\n2. Search Flight";  
        cout << "\n3. Back to Main Menu";  
        cout << "\n\nEnter Option: ";  
        cin >> opt;  
  
        // switch statement  
        switch (opt)  
        {  
        case 1:  
            cout << "\nEnter Plane Id: ";  
            cin >> rno;  
            i = 0;  
            for (i = 0; i < counts; i++)  
            {  
                if (flights[i].planeId == rno)  
                {  
                    flag = 1;  
                }  
            }  
            if (flag == 1)  
            {  
                cout << "\nFlight is Present.\nPlease enter unique Number";  
                flag = 0; 
            }  
            else  
            {  
                flights[counts] = fli.addFlight(rno);  
                counts++ ;  
            }  
            break;  
        case 2 :  
            cout <<  " \n Enter Flight number :  " ;  
            cin >> rno ;  
            fli.searchFlight( rno ) ;  
            break ;  
        case 3 :  
            // nothing to do  
            break ;  
        default :  
            cout << " \n Please Enter correct option " ;  
            break ;  
        }  
    } while ( opt != 3 ) ;  
}  
int main()
{
    FlightManagementSystem hm;  
    int i, j, opt, rno;  
    char ch;  
    char pname[100];  
  
    do  
    {  
        cout << "\n######## flight Management #########\n";  
        cout << "\n1. Manage Flight";  
        cout << "\n2. Book Flight";  
        cout << "\n3. Available Flights";  
        cout << "\n4. Search Customer"; 
        cout << "\n5. Customer Summary Report";  
        cout << "\n6. Exit";  
        cout << "\n\nEnter Option: ";  
        cin >> opt;  
        switch (opt)  
        {  
        case 1:  
            manageFlights();  
            break;  
        case 2:  
            if (counts == 0)  
            {  
                cout << "\nFlight data is not available.\nPlease add the flights first.";
            }  
            else  
                hm.bookfl();  
            break;  
        case 3:  
            if (counts == 0)  
            {  
                cout << "\nFlights data is not available.\nPlease add the flights first.";
            }  
            else  
                hm.getAvailFlight(); 
            break;  
        case 4:  
            if (counts== 0)  
            {  
                cout << "\nflights are not available.\nPlease add the Flights first.";
            }  
            else  
            {  
                cout << "Enter Customer Name: ";  
                cin >> pname;  
                hm.searchCustomer(pname);  
            }  
            break;  
        case 5:  
            hm.guestSummaryReport();  
            break;  
        case 6:  
            cout << "\nTHANK YOU! FOR USING SOFTWARE";  
            break;  
        default:  
            cout << "\nPlease Enter correct option";  
            break;  
        }  
    } while (opt != 6);  
    return 0;
  
}