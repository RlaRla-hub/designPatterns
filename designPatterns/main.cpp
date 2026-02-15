#include "Observer.h"
#include "State.h"


int main()
{
	//Observer
	std::cout << "OBSERVER \n";
	WeatherStation WS;
	std::shared_ptr<Observer> display(new Display);
	std::shared_ptr<Observer> logger(new Logger);
	std::shared_ptr<Observer> alarmSystem(new AlarmSystem);

	WS.addObserver(display);
	WS.addObserver(logger);
	WS.addObserver(alarmSystem);

	std::cout << "Current temperature = " << WS.getTemperature() << "\n";
	std::cout << "\n";
	WS.setTemperature(30);
	std::cout << "\n";
	WS.setTemperature(52);
	std::cout << "\n";
	WS.setTemperature(-4);
	std::cout << "\n";



	//State
	std::cout << "STATE \n";
	AudioPlayer player;

	player.next();
	player.previous();
	player.pause();
	player.play();

	std::cout << "\n";

	player.next();
	player.previous();
	player.play();
	player.pause();

	std::cout << "\n";

	player.next();
	player.previous();
	player.pause();
	player.play();

	return 0;
}

