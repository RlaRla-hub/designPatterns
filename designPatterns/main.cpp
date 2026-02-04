#include "Observer.h"


int main()
{
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

	return 0;
}

