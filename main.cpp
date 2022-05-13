#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define f(i,m,n) for(int i = (m); i < (n); i++)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) sort(v.begin(),v.end())
#define sz(v) int(v.size())
const int MOD=1e9+7;
const int mod= 998244353;
typedef long long ll;
typedef vector<int> vi; 
typedef vector<ll> vll; 
typedef vector<pair<int,int>> vii; 

class Command {
  public:
	virtual ~Command()= default;
	virtual void execute() = 0;
};

class Light{
    private:
	string name;
	double luminosity;
	bool status;
	public:
	Light(string _name){
		name=_name;
		luminosity=0.0;
		status=0;
	}
	void setLuminosity(double x){
		luminosity=x;
	}
	double getLuminosity(){
		return luminosity;
	}
	void on(){
		status=1;
	}
	void off(){
		status=0;
	}
	bool isOn(){
		return status;
	}

};


class LuminosityCommand: public Command {
    private:
	Light* light;
	double luminosity;
	public:
	LuminosityCommand(Light* _light, double _luminosity): light(_light) , luminosity(_luminosity) {}
	void execute(){
		light->setLuminosity(luminosity);
	}


};


class RemoteControl{
	private:
	Command* cd;
	RemoteControl* remotecontrol;
    public:
	void setCommand(Command* c){
        cd=c;
	}
	void execute(){
		cd->execute();
	}
	RemoteControl* getInstance(){
		if(remotecontrol==nullptr){
			remotecontrol= new RemoteControl();
		}
		return remotecontrol;
	}
	
	
};




int main() {
    fastio;
    RemoteControl* remotecontrol =new RemoteControl;
	Light* orangelight =new Light("orange");
	LuminosityCommand* luminosityCommand = new LuminosityCommand(orangelight,20);
	remotecontrol->setCommand(luminosityCommand);



    
    
    
    	
}















/*class LightDevices{
	public:
    string name;
	bool status;
	double luminosity;
	LightDevices(string name_in): name{name_in}, status{false}, luminosity{0.0} {}
	void upDevice(){
		status=!status;
	}
	void updateLuminosity(float change){
		luminosity = change;
	}
	bool get_status() {return status;}
	string get_name() {return name;}
	double get_luminosity() {return luminosity;}
	
};


class RemoteControl{
	private:
	static RemoteControl* remotecontrol;
    string value;
    map<string,LightDevices*> m;
    RemoteControl(){
    	m["orange"]= new LightDevices("orange");
    	m["red"]= new LightDevices("red");
    	m["green"]= new LightDevices("green");
    	m["stop"]= new LightDevices("stop");
    }
    public:
	static RemoteControl* getInstance(){
		if(remotecontrol==nullptr){
			
			remotecontrol =new RemoteControl();
		}
		else{
			cout<<"Ya se ha creado"<<endl;
		}
		return remotecontrol;
	}
	LightDevices* makeLight(const string light){
		m[light]->status = 1;
		return m[light];
	}
	
	
};

class Command {
 public:
  virtual ~Command() {
  }
  virtual void Execute() const = 0;
};



int main() {
    fastio;
    
    auto orange=new LightDevices("orange");
    auto red=new LightDevices("red");
    auto green=new LightDevices("green");
    auto stop=new LightDevices("stop");
    
    RemoteControl* rc = RemoteControl::getInstance();
    //rc->getInstance();
    auto x = rc->makeLight("orange");
    cout<<x->status<<endl;
}
*/
