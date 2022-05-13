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

// Interface del comando 
class Command
{
public:
	virtual void execute() = 0;
};
 
// la clase Receiver 
class Light 
{
public:
	void on() {
		cout << "The light is on\n";
	}
	void off() {
		cout << "The light is off\n";
	}
}; 

// Command para prender la luz
class LightOnCommand : public Command 
{
  Light *mLight;
public:
        LightOnCommand(Light *light) : mLight(light) {}
	void execute(){
		mLight->on();
	}	
};
 
// Command para apagar la luz
class LightOffCommand : public Command 
{
  Light *mLight;
public:
        LightOffCommand(Light *light) :mLight(light){}
	void execute(){
		mLight->off();
	}
};

// Invoker que vendría a ser el RemoteControl
class RemoteControl 
{
  Command *mCmd;
public:
	void setCommand(Command *cmd) {
		mCmd = cmd;
	}

	void buttonPressed() {
		mCmd->execute();
	} 
};
 
// El cliente
int main() 
{
	// Receiver 
	Light *light = new Light;

	// objetos de comando concretos
	LightOnCommand *lightOn = new       
  LightOnCommand(light);
	LightOffCommand *lightOff = new         
  LightOffCommand(light);

	// objeto invoker
	RemoteControl *control = new RemoteControl;

	// execute
	control->setCommand(lightOn);
	control->buttonPressed();
	control->setCommand(lightOff);
	control->buttonPressed();

	delete light, lightOn, lightOff, control;

	return 0;
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
