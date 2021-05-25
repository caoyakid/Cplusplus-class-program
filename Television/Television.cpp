#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class Television{
private:
    string displayType;
    double dimension;
    string* connectivitySupport;
    int connectivitySupport_size;
public:
    Television() // default constructor
    {
        displayType = "LCD";
        dimension = 32.0;
        connectivitySupport = new string[3];
        *connectivitySupport = "VGA";
        *(connectivitySupport+1) = "DVI";
        *(connectivitySupport+2) = "HDMI";
        connectivitySupport_size = 3;
    }
    ~Television()
    {
        delete [] connectivitySupport;
        connectivitySupport = 0;
        connectivitySupport_size = 0;
    }
    void set_displayType(string Type){displayType = Type;}
    void set_dimension(double Inch){dimension = Inch;}
    void set_connectivitySupport(vector<string> Type){
        connectivitySupport = new string[Type.size()];
		connectivitySupport_size = Type.size();
		for (int i = 0; i < Type.size(); i++)
		    connectivitySupport[i] = Type[i];
    }
    string get_displayType(){return displayType;}
    double get_dimension(){return dimension;}
    string* get_connectivitySupport(){return connectivitySupport;}
    int get_connectivitySupport_size(){return connectivitySupport_size;}
    void display_data(){
        cout << "1.Type: "<<displayType <<endl;
        cout << "2.Dimension "<<dimension <<endl;
        cout << "3.Connectivity Support: ";
        for(int i = 0; i<connectivitySupport_size; i++)
        {
            cout << connectivitySupport[i] <<" ";
        }
        cout<<endl;
    }
};

int main(){
    // variable 
    int size, cus_number, tv_number;
    double dimension;
    string type, user, support;
    vector<string> connectivity_support;

    // client program
    Television tv;
    cout << "This is our plane TV: " <<endl;
    tv.display_data();
    cout << "------------------------------------------------" <<endl;
    cout << "Please tell me how many TVs you want to buy: " << endl;
    cin >> size;
    Television *TV = new Television[size];

    cout << "------------------------------------------------" <<endl;
    cout << "TV menu" << endl;
    for (int i = 0; i < size; i++){
        cout << "NO." << i+1 <<endl;
        cout << "Type: " ; cin >> type;
        cout << "Dimension(in inch): "; cin >> dimension;
        cout << "Support connectivity (Enter X as end): ";
        while((cin >> support) && (support != "X" && support != "x")){
            connectivity_support.push_back(support);
        }
        TV[i].set_displayType(type);
        TV[i].set_dimension(dimension);
        TV[i].set_connectivitySupport(connectivity_support);
        connectivity_support.clear();
    }

    cout << "------------------------------------------------" <<endl;
    // ask the user to if customization is required or not?
    do{
        cout << "Do you need Customization(Y/N)? ";
        while((cin >> user) && (user != "Y" && user != "y" && user != "N" && user != "n")){
            cout << "???What's going on???" <<endl;
            cout << "Need or not(Y/N)? ";
        }

        if(user == "N" || user == "n") {
            for (int i = 0; i < size; i++)
		    {
			cout << "TV NO. " << i + 1 << endl;
			TV[i].display_data();
		    }
            break;}
        else{
            cout << "Which one you want to customize? ";
            while((cin >> tv_number) && (tv_number > size || tv_number < 1)){
                cout << "Don't waste my time, sir! "<<endl;
                cout << "Which one???";
            }
            cout << "------------------------------------------------" <<endl;
            cout << "Customization mode: "<< endl;
            cout << "1)Customized type " <<endl;
            cout << "2)Customized dimension " << endl;
            cout << "3)Customized connectivity support " << endl;
            cout << "Choose Customized mode: ";
            while((cin >> cus_number) && (cus_number != 1 && cus_number != 2 && cus_number != 3)){
                cout << "Invalid input " <<endl;
                cout << "Choose Customized mode: ";
            }
            switch (cus_number)
            {
            case 1:
                cout << "Customized type " <<endl;
                cin >> type;
                TV[tv_number - 1].set_displayType(type);
                break;
            case 2:
                cout << "Customized dimension: ";
			    cin >> dimension;
			    TV[tv_number - 1].set_dimension(dimension);
                break;
            case 3:
                cout << "Customized connectivity support(Enter X as end): ";
			    vector<string> Support;
			    while ((cin >> support) && (support != "X" && support != "x"))
				Support.push_back(support);
			    TV[tv_number - 1].set_connectivitySupport(Support);
                break;
            // default:
            //     break;
            for (int i = 0; i < size; i++)
		    {
			cout << "TV NO. " << i + 1 << endl;
			TV[i].display_data();
		    }
            }            
        }
        
    }while(user == "Y" || user == "y");

    return 0;
}