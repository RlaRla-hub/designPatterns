#include "Observer.h"


void Display::update(float temperature)
{
	std::cout << "Temperature = " << temperature << std::endl;
}


Logger::Logger()
{
	file.open("temperature.txt");
}

void Logger::update(float temperature)
{
	if (!file.is_open())
	{
		file << "Temperature written to file = " << temperature << std::endl;
	}
	std::cout << "Temperature write to file = " << temperature << std::endl;
}

Logger::~Logger()
{
	if (file.is_open())
	{
		file.close();
	}
}


void AlarmSystem::update(float temperature)
{
	if (temperature > 50)
	{
		std::cout << "ALARM!!!ALARM!!!ALARM!!!" << std::endl;
	}
	else
	{
		std::cout << "Not alarm" << std::endl;
	}
}


void WeatherStation::setTemperature(float temperature)
{
	if (currentTemperature != temperature)
	{
		currentTemperature = temperature;
		updateObservers(temperature);
	}
}

float WeatherStation::getTemperature()
{
	return currentTemperature;
}

void WeatherStation::addObserver(std::shared_ptr<Observer> ob)
{
	observers.push_back(ob);
}

void WeatherStation::updateObservers(float temperature)
{
	for (std::shared_ptr<Observer> ob : observers)
	{
		ob->update(temperature);
	}
}